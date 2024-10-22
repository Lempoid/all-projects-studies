#include <stdio.h> /*fprintf printf*/
#include "ext2_Parsing.h"


/*For now used Chananiya's test as I had 10 minutes to finish assignment*/
int main(int argc, char *argv[])
{
    const char *disk_name;
    const char *file_path;
    FS_t* fs;
    long inode_num;

    if (argc != 3)  /*Checks command line arguments*/
    {
        fprintf(stderr, "Usage: %s <disk_image> <file_path>\n", argv[0]);
        return 1;
    }

    disk_name = argv[1];
    file_path = argv[2];

    printf("Opening disk: %s\n", disk_name);
    fs = FSOpen(disk_name);  /*Opens the file system*/

    if (fs == NULL) 
    {
        fprintf(stderr, "Failed to open %s\n", disk_name);
        return 1;
    }

    printf("Getting inode for file: %s\n", file_path);
    inode_num = GetInode(fs, file_path);  /*Gets the inode number for the specified file*/

    if (inode_num == -1) 
    {
        fprintf(stderr, "Failed to find inode for %s\n", file_path);
        FSClose(fs);
        return 1;
    }

    printf("Inode number for %s: %ld\n", file_path, inode_num);

    printf("Printing contents of %s:\n", file_path);
    PrintFileContent(fs, inode_num);

    FSClose(fs);

    return 0;
}
