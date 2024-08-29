/*
======================================================================================================================================================================
Name : handsonprog9.c
Author :Bhanuja Bhatt
Description : Write a program to print the following information about a given file.
	a. inode
	b. number of hard links
	c. uid
	d. gid
	e. size
	f. block size
	g. number of blocks
	h. time of last access
	i. time of last modification
	j. time of last change
Date: 18th Aug, 2024
======================================================================================================================================================================

======================================================================================================================================================================
Sample Output:
Details of file: a.txt
1. Inode number: 2904960
2. Hard link count: 1
3. UID: 1000
4. GID: 1000
5. File size in bytes: 989
6. Block size: 4096
7. Number of blocks allocated: 8
8. Last access time: Thu Aug 29 11:30:44 2024
9. Last modification time: Tue Aug 20 22:20:11 2024
10. Last status change time: Tue Aug 20 22:20:11 2024
======================================================================================================================================================================
*/  
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
	struct stat str;

	if(argc < 2){
		perror("Error: Provide the file name as argument");
		return 1;
	}

	if(stat(argv[1], &str) == -1){
	       perror("stat");
	}

	printf("Details of file: %s\n", argv[1]);
	printf("1. Inode number: %ld\n", str.st_ino);
	printf("2. Hard link count: %lu\n", str.st_nlink);
	printf("3. UID: %u\n", str.st_uid);
	printf("4. GID: %u\n", str.st_gid);
	printf("5. File size in bytes: %ld\n", str.st_size);
	printf("6. Block size: %ld\n", str.st_blksize);
	printf("7. Number of blocks allocated: %ld\n", str.st_blocks);
	printf("8. Last access time: %s", ctime(&str.st_atime));
	printf("9. Last modification time: %s", ctime(&str.st_mtime));
	printf("10. Last status change time: %s", ctime(&str.st_ctime));

	return 0;
}		
