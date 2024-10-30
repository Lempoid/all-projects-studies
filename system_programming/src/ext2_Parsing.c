/*
EXT2 parser that finds a file and prints it.
Can change permissions of RWX as well

Author: Alex Breger
Review: Elisheva Dori 22.10.24
*/

#include <stdio.h>  /*frpintf*/
#include <stdlib.h> /*free malloc*/
#include <fcntl.h>  /*open read seek*/
#include <unistd.h> /*ssize_t*/
#include <string.h> /*strcmp strcpy strtok*/
#include <math.h>   /*pow*/
#include "ext2_Parsing.h"

struct fs_s
{
  int file_descriptor;
  size_t block_size;
  size_t inodes_count;
  size_t blocks_count;
  size_t groups_count;
  size_t inodes_per_group;
  size_t inode_size;
  size_t inode_table;
};

/******************************************************************************
 * Open a file system.
 * Return pointer to file system, null on failure.
 * *disk_name: path of RAM drive
 * Time Complexity: O(1)
 */

FS_t *FSOpen(const char *disk_name)
{
  struct ext2_super_block super_block;

  FS_t *file_system = malloc(sizeof(FS_t));
  if (NULL == file_system)
  {
    return NULL;
  }

  file_system->file_descriptor = open(disk_name, O_RDWR);
  if (-1 == file_system->file_descriptor)
  {
    free(file_system);
    return NULL;
  }

  if (-1 == lseek(file_system->file_descriptor, 1024, SEEK_SET))
  {
    fprintf(stderr, "Failed to get to superblock");
    close(file_system->file_descriptor);
    free(file_system);
    return NULL;
  }

  if (sizeof(super_block) != read(file_system->file_descriptor, &super_block, sizeof(super_block)))
  {
    fprintf(stderr, "Failed to read superblock");
    close(file_system->file_descriptor);
    free(file_system);
    return NULL;
  }

  if (EXT2_SUPER_MAGIC != super_block.s_magic)
  {
    fprintf(stderr, "Invalid ext2 filesystem (incorrect magic number)\n");
    close(file_system->file_descriptor);
    free(file_system);
    return NULL;
  }

  file_system->block_size = 1024 << super_block.s_log_block_size;
  file_system->inodes_count = super_block.s_inodes_count;
  file_system->blocks_count = super_block.s_blocks_count;
  file_system->groups_count = (super_block.s_blocks_count - super_block.s_first_data_block - 1) / super_block.s_blocks_per_group + 1;
  file_system->inodes_per_group = super_block.s_inodes_per_group;
  file_system->inode_size = super_block.s_inode_size;

  return file_system;
}

/******************************************************************************
 * Close the file system.
 * file_system: pointer to the file system
 * Time Complexity: O(1)
 */
int FSClose(FS_t *file_system)
{
  if (NULL == file_system)
  {
    return 0;
  }

  close(file_system->file_descriptor);
  free(file_system);

  return 1;
}

/******************************************************************************
 * Return inode number of a file, -1 if not found.
 * *fs: pointer to the file system
 * *file_path: path of file in string
 * Time Complexity: O(h)
 */
long GetInode(FS_t *file_system, const char *file_path)
{
  size_t block_size;
  size_t inodes_per_group;
  size_t inode_size;
  size_t path_length;
  size_t group_number;
  size_t inode_index_within_group;
  size_t inode_block;
  size_t inode_offset_within_block;
  size_t seek_position;
  size_t current_inode_number;
  size_t i;
  ssize_t size_of_ext2_group_desc;
  ssize_t size_of_ext2_inode;
  ssize_t size_of_ext2_dir_entry_2;
  int file_descriptor;
  int found_next_directory;
  char *path_copy;
  char *current_directory;
  struct ext2_inode current_inode;
  struct ext2_dir_entry_2 directory_entry;
  struct ext2_group_desc group_desc;

  found_next_directory = 0;
  size_of_ext2_dir_entry_2 = sizeof(struct ext2_dir_entry_2);
  size_of_ext2_inode = sizeof(struct ext2_inode);
  size_of_ext2_group_desc = sizeof(struct ext2_group_desc);
  file_descriptor = file_system->file_descriptor;
  block_size = file_system->block_size;
  inodes_per_group = file_system->inodes_per_group;
  inode_size = file_system->inode_size;
  current_inode_number = EXT2_ROOT_INO;
  path_length = strlen(file_path) + 1;
  path_copy = malloc(path_length);
  if (NULL == path_copy)
  {
    fprintf(stderr, "Failed to allocate memory");
    return -1;
  }

  strcpy(path_copy, file_path);

  current_directory = strtok(path_copy, "/");

  while (NULL != current_directory)
  {
    group_number = (current_inode_number - 1) / inodes_per_group;
    inode_index_within_group = (current_inode_number - 1) % inodes_per_group;

    seek_position = block_size + (group_number * size_of_ext2_group_desc);

    if (-1 == lseek(file_descriptor, seek_position, SEEK_SET))
    {
      fprintf(stderr, "Failed to seek to group descriptor");
      free(path_copy);
      return -1;
    }

    if (size_of_ext2_group_desc != read(file_descriptor, &group_desc, size_of_ext2_group_desc))
    {
      fprintf(stderr, "Failed to read group descriptor");
      free(path_copy);
      return -1;
    }

    inode_block = group_desc.bg_inode_table + (inode_index_within_group * inode_size) / block_size;
    inode_offset_within_block = (inode_index_within_group * inode_size) % block_size;

    seek_position = inode_block * block_size + inode_offset_within_block;

    if (-1 == lseek(file_descriptor, seek_position, SEEK_SET))
    {
      fprintf(stderr, "Failed to seek to inode");
      free(path_copy);
      return -1;
    }

    if (size_of_ext2_inode != read(file_descriptor, &current_inode, size_of_ext2_inode))
    {
      fprintf(stderr, "Failed to read inode");
      free(path_copy);
      return -1;
    }

    if (0x4000 != (current_inode.i_mode & 0x4000))
    {
      fprintf(stderr, "Not a directory");
      free(path_copy);
      return -1;
    }

    for (i = 0; i < EXT2_NDIR_BLOCKS; ++i)
    {
      if (0 != current_inode.i_block[i])
      {
        seek_position = current_inode.i_block[i] * block_size;

        if (-1 == lseek(file_descriptor, seek_position, SEEK_SET))
        {
          fprintf(stderr, "Failed to seek to directory block");
          free(path_copy);
          return -1;
        }

        while (size_of_ext2_dir_entry_2 == read(file_descriptor, &directory_entry, size_of_ext2_dir_entry_2))
        {
          if (0 == strncmp(directory_entry.name, current_directory, directory_entry.name_len))
          {
            current_inode_number = directory_entry.inode;
            found_next_directory = 1;
            break;
          }

          lseek(file_descriptor, directory_entry.rec_len - size_of_ext2_dir_entry_2, SEEK_CUR);
        }

        if (1 == found_next_directory)
          break;
      }
    }

    if (0 == found_next_directory)
    {
      fprintf(stderr, "Could not find directory: %s", current_directory);
      free(path_copy);
      return -1;
    }

    current_directory = strtok(NULL, "/");
  }

  free(path_copy);
  return current_inode_number;
}

/******************************************************************************
 * Prints file's content to the screen
 * *file_system: pointer to the file system
 * *inode_num: Inode of the file by the path (GetInode())
 * Time Complexity: O(1)
 */
void PrintFileContent(FS_t *file_system, long inode_num)
{
  size_t block_size;
  size_t inodes_per_group;
  size_t inode_size;
  size_t group_number;
  size_t inode_index_within_group;
  size_t inode_block;
  size_t inode_offset_within_block;
  size_t seek_position;
  ssize_t size_of_ext2_group_desc;
  ssize_t size_of_ext2_inode;
  size_t i;
  size_t total_bytes_read;
  ssize_t bytes_to_read;
  int file_descriptor;
  struct ext2_inode current_inode;
  struct ext2_group_desc group_desc;
  char *buffer_for_file_content_per_block;
  char *buffer_for_whole_file;

  size_of_ext2_inode = sizeof(struct ext2_inode);
  size_of_ext2_group_desc = sizeof(struct ext2_group_desc);
  file_descriptor = file_system->file_descriptor;
  block_size = file_system->block_size;
  inodes_per_group = file_system->inodes_per_group;
  inode_size = file_system->inode_size;
  total_bytes_read = 0;

  group_number = (inode_num - 1) / inodes_per_group;
  inode_index_within_group = (inode_num - 1) % inodes_per_group;

  seek_position = (group_number * size_of_ext2_group_desc) + block_size;

  if (-1 == lseek(file_descriptor, seek_position, SEEK_SET))
  {
    fprintf(stderr, "Failed to seek to group descriptor");
    return;
  }

  if (size_of_ext2_group_desc != read(file_descriptor, &group_desc, size_of_ext2_group_desc))
  {
    fprintf(stderr, "Failed to read group descriptor");
    return;
  }

  inode_block = group_desc.bg_inode_table + (inode_index_within_group * inode_size) / block_size;
  inode_offset_within_block = (inode_index_within_group * inode_size) % block_size;

  seek_position = (inode_block * block_size) + inode_offset_within_block;

  if (-1 == lseek(file_descriptor, seek_position, SEEK_SET))
  {
    fprintf(stderr, "Failed to seek to inode");
    return;
  }

  if (size_of_ext2_inode != read(file_descriptor, &current_inode, size_of_ext2_inode))
  {
    fprintf(stderr, "Failed to read inode");
    return;
  }

  if (0x8000 != (current_inode.i_mode & 0x8000))
  {
    fprintf(stderr, "Not a regular file");
    return;
  }

  buffer_for_file_content_per_block = malloc(block_size);
  buffer_for_whole_file = malloc(current_inode.i_size);

  for (i = 0; i < EXT2_NDIR_BLOCKS; ++i)
  {
    if (0 != current_inode.i_block[i] && total_bytes_read < current_inode.i_size)
    {
      seek_position = current_inode.i_block[i] * block_size;
      if (-1 == lseek(file_descriptor, seek_position, SEEK_SET))
      {
        fprintf(stderr, "Failed to seek to read location");
        free(buffer_for_file_content_per_block);
        free(buffer_for_whole_file);
        return;
      }

      bytes_to_read = block_size;

      if (total_bytes_read + bytes_to_read > current_inode.i_size)
      {
        bytes_to_read = current_inode.i_size - total_bytes_read;
      }

      if (bytes_to_read != read(file_descriptor, buffer_for_file_content_per_block, bytes_to_read))
      {
        fprintf(stderr, "Failed to read data");
        free(buffer_for_file_content_per_block);
        free(buffer_for_whole_file);
        return;
      }

      memcpy(buffer_for_whole_file + total_bytes_read, buffer_for_file_content_per_block, bytes_to_read);
      total_bytes_read += bytes_to_read;
    }
  }

  write(STDOUT_FILENO, buffer_for_whole_file, current_inode.i_size);

  free(buffer_for_file_content_per_block);
  free(buffer_for_whole_file);
}

int Chmode(FS_t *file_system, long inode_num, char *new_mode)
{
  size_t block_size;
  size_t inodes_per_group;
  size_t inode_size;
  size_t group_number;
  size_t inode_index_within_group;
  size_t inode_block;
  size_t inode_offset_within_block;
  size_t seek_position;
  ssize_t size_of_ext2_group_desc;
  ssize_t size_of_ext2_inode;
  size_t new_mode_string_length;
  int file_descriptor;
  struct ext2_inode current_inode;
  struct ext2_group_desc group_desc;
  unsigned int new_permission_bits;
  char owner;
  char group;
  char others;
  unsigned int file_type;
  
  size_of_ext2_inode = sizeof(struct ext2_inode);
  size_of_ext2_group_desc = sizeof(struct ext2_group_desc);
  file_descriptor = file_system->file_descriptor;
  block_size = file_system->block_size;
  inodes_per_group = file_system->inodes_per_group;
  inode_size = file_system->inode_size;
  new_mode_string_length = strlen(new_mode);

  group_number = (inode_num - 1) / inodes_per_group;
  inode_index_within_group = (inode_num - 1) % inodes_per_group;

  seek_position = (group_number * size_of_ext2_group_desc) + block_size;

  if (NULL == new_mode || 3 > new_mode_string_length)
  {
    fprintf(stderr, "Check that your mode is in the format xxx or yyyy, or if it is initialized");
    return -1;
  }

  if (-1 == lseek(file_descriptor, seek_position, SEEK_SET))
  {
    fprintf(stderr, "Failed to seek to group descriptor");
    return -1;
  }

  if (size_of_ext2_group_desc != read(file_descriptor, &group_desc, size_of_ext2_group_desc))
  {
    fprintf(stderr, "Failed to read group descriptor");
    return -1;
  }

  inode_block = group_desc.bg_inode_table + (inode_index_within_group * inode_size) / block_size;
  inode_offset_within_block = (inode_index_within_group * inode_size) % block_size;

  seek_position = (inode_block * block_size) + inode_offset_within_block;

  if (-1 == lseek(file_descriptor, seek_position, SEEK_SET))
  {
    fprintf(stderr, "Failed to seek to inode");
    return -1;
  }

  if (size_of_ext2_inode != read(file_descriptor, &current_inode, size_of_ext2_inode))
  {
    fprintf(stderr, "Failed to read inode");
    return -1;
  }

  file_type = current_inode.i_mode & ~0777;

  owner = new_mode[0] - '0';
  group = new_mode[1] - '0';
  others = new_mode[2] - '0';

  if (owner > 7 || group > 7 || others > 7)
  {
    fprintf(stderr, "Invalid permission values\n");
    return -1;
  }

  new_permission_bits = (owner << 6) | (group << 3) | others;

  current_inode.i_mode = file_type | new_permission_bits;

  if (-1 == lseek(file_descriptor, seek_position, SEEK_SET))
  {
    fprintf(stderr, "Failed to seek to inode\n");
    return -1;
  }

  if (size_of_ext2_inode != write(file_descriptor, &current_inode, size_of_ext2_inode))
  {
    fprintf(stderr, "Failed to write to inode\n");
    return -1;
  }

  return 1;
}