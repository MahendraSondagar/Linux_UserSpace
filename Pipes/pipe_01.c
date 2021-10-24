
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
#include <wait.h>

/*AIM : Creating the simple inter process using pipe  */
int main(int argc, char *argv[])
{
    int fd[2];
    /*
      fd[0] -> read from pipe
      fd[1] -> write to the pipe
    */
    /* Creating the Pipe */
    if (pipe(fd) == -1)
    {
        perror("Failed to create the pipe\n");
        exit(EXIT_FAILURE);
    }
    printf("Pipe created\n");
    int id = fork();
    if (id == 0)
    {
        /* Child process */
        int x;
        close(fd[0]);
        printf("Enter the variable: ");
        scanf("%d", &x);
        write(fd[1], &x, sizeof(x));
        /* Wait for the child to send pipe data */
        wait(NULL);
        close(fd[1]);
    }
    else if (id > 0)
    {
        /* Parent process */
        int y;
        close(fd[1]);
        read(fd[0], &y, sizeof(y));
        printf("Data Received from child process is: %d\r\n", y);
        close(fd[0]);
    }
    else
    {
        perror("Failed to fork\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}
