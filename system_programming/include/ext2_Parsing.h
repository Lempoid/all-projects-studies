/*  API for EXT2 File System	*/
/*  Group: ILRD CR8 			*/
/*  Created:  			*/
/*  Modified: 			*/
/*  Version:  0.0.1				*/

#ifndef __EXT2_PARSING_H_CR8__
#define __EXT2_PARSING_H_CR8__

#include "ext2_linux-2.h" /* Usage: ext2 file system */

typedef struct fs_s FS_t;

/******************************************************************************
 * Open a file system.
 * Return pointer to file system, null on failure.
 * *disk_name: path of RAM drive
 * Time Complexity: O(1)
 */

FS_t* FSOpen(const char* disk_name);


/******************************************************************************
 * Close the file system.
 * file_system: pointer to the file system
 * Time Complexity: O(1)
 */
int FSClose(FS_t* file_system);

/******************************************************************************
 * Return inode number of a file, -1 if not found. 
 * *fs: pointer to the file system
 * *file_path: path of file in string
 * Time Complexity: O(h)
 */
long GetInode(FS_t* file_system, const char* file_path);


/****************************************************************************** 
 * Prints file's content to the screen 
 * *file_system: pointer to the file system
 * *inode_num: Inode of the file by the path (GetInode())
 * Time Complexity: O(1)
 */
void PrintFileContent(FS_t* file_system, long inode_num);

#endif /* 	__EXT2_PARSING_H_CR8__	*/