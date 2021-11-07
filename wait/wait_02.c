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
 Coded: Sun, 07th Nov, 2021 / 18:22 PM
 ****************************************************/


#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* AIM: Wait system call with the PID*/
int main(int argc, char *argv[])
{
    pid_t p;
    if (p == 0)
    {
        printf("I'm child(p) of parent process: %d\r\n", getppid());
        printf("My process id: %d\r\n", getpid());
    }
    else
    {
        pid_t q = fork();
        if (q == 0)
        {
            waitpid(p, NULL, 0);
            printf("I'm child(q) of parent process: %d\r\n", getppid());
            printf("My process id: %d\r\n", getpid());
        }
        else
        {
            printf("I'm parent of the child : %d\r\n", q);
            printf("My process id: %d\r\n", getpid());
        }
    }

    return 0;
}