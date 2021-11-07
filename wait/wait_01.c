#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

/* AIM: Wait system call test */
int main(int argc, char *argv[])
{
    pid_t p;
    p = fork();
    if (p == 0)
    {
        printf("Child process...\r\n");
        printf("My Parent id: %d\r\n", getppid());
    }
    else
    {
        /* wait system call is used to wait the parent, untill the child process finish the job*/
        wait(NULL);
        printf("Parent process...\r\n");
        printf("I'm parent having the child is : %d\r\n", p);
    }
    return 0;
}