
/* ******************************************************************************
 DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 Version 2, December 2021
 Copyright (C) 2021 Mahendra Sondagar <mahendrasondagar08@gmail.com>
 Everyone is permitted to copy and distribute verbatim or modified
 copies of this license document, and changing it is allowed as long
 as the name is changed.
 DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 0. You just DO WHAT THE FUCK YOU WANT TO.
 Coded: Sun, 24th Oct, 2021 / 16:03 PM
 ****************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/unistd.h>
#include <error.h>
#include  <wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd[2];
    char string[]= "Hello universe";
    if (pipe(fd) < 0)
    {
        perror("Failed to create the pipe\r\n");
        exit(EXIT_FAILURE);
    }
    printf("Pipe created!\n");
    int id = fork();
    if (id == 0)
    {
        close(fd[0]);
        printf("Child process\r\n");
        write(fd[1], string, strlen(string));
        wait(NULL);
        close(fd[1]);
    }
    else if (id > 0)
    {
        char buff[]={0};
        close(fd[1]);
        printf("parent process\r\n");
        read(fd[0],buff, strlen(string));
        printf("string received from child process is : %s\r\n", buff);
        close(fd[0]);
    }
    else
    {
        perror("Failed to creat the process\r\n");
        exit(EXIT_FAILURE);
    }
}
