#include <stdio.h>
#include <unistd.h>

/* Aim : To understand the fork () & exec() system call */
/*
* fork()- systemCall is used to create the saperate duplicate process 
          Cretaed new process is exact replica of the process from where it has been created 
          But it sould have the diffrent process id 
          return value of the child process is 0 & parent process is child id 
*/
int main(void)
{
    if(fork()== 0)
    {
        printf("I'm a child of the parent\r\n");
    }else
    {
        printf("Hey! this is parent, having ID: %d\r\n", getpid());
    }
    return 0;
}