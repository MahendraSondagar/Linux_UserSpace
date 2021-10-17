#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int PID, PPID;
    PID = getpid();
    PPID = getppid();
    printf("Process ID: %d \r\n");
    printf("Parent process ID: %d\r\n", PPID);
    return 0;
}