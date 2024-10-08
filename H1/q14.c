/*
======================================================================================================================================================================
Name : handsonprog14.c
Author :Bhanuja Bhatt
Description : Write a program to find the type of a file.
		a. Input should be taken from command line.
		b. program should be able to identify any type of a file
Date: 25th Aug, 2024
======================================================================================================================================================================

======================================================================================================================================================================
Sample Output:
File type: regular file
I-node number: 2904960

======================================================================================================================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
	struct stat m;
	if(argc < 2){
		printf("Error: no file specified\n");
		return 0;
	}
	if(lstat(argv[1], &m) == -1) {
               perror("lstat");
        }

        printf("File type: ");
        switch (m.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device file\n");  
		   	  break;
           case S_IFCHR:  printf("character device file\n");  
		    	  break;
           case S_IFDIR:  printf("directory\n");     
			  break;
           case S_IFIFO:  printf("FIFO file or pipe\n");   
	      		  break;
           case S_IFLNK:  printf("symlink file\n");   
	    		  break;
           case S_IFREG:  printf("regular file\n");  
			  break;
           case S_IFSOCK: printf("socket\n");
			  break;
           default:       printf("unknown?\n");         
		   	  break;
        }
        printf("I-node number: %ld\n", m.st_ino);
	return 0;
}
