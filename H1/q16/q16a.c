/*
======================================================================================================================================================================
Name : handsonprog16.c
Author : Bhanuja Bhatt
Description : Write a program to perform mandatory locking.
		a. Implement write lock
		b. Implement read lock
Date: 25th Aug, 2024
======================================================================================================================================================================

======================================================================================================================================================================
Sample output:
Before locking the file for reading
Read lock acquired successfully....
Enter to unlock...
Before locking the file for writing

======================================================================================================================================================================
*/#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main(){
        struct flock fm;
        char s[100];
        int fq = open("a.txt", O_RDWR|O_CREAT, 0666);
        fm.l_type = F_RDLCK;
        fm.l_whence = SEEK_SET;
        fm.l_start = 0;
        fm.l_len = 0;
        fm.l_pid = getpid();
        printf("Before locking the file for reading\n");
        fcntl(fq, F_SETLKW, &fm);
        printf("Read lock acquired successfully....\n");
        printf("Enter to unlock...\n");
        getchar();
        fm.l_type = F_UNLCK;
        fcntl(fq, F_SETLK, &fm);
        printf("Finish\n");
        return 0;
}
