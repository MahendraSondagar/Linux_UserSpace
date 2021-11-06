
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
 Coded: Mon, 7th Nov 2021 / 00:13 PM
 ****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

/* AIM: Shared memory example showcase */
int main(int argc, char *argv[])
{
    key_t key;
    int shmid;

    /* Generating key */
    key = ftok("MyShared", 65);
    /* Creating the shared memory */
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if(shmid<0)
    {
        perror("shmid");
        exit(EXIT_FAILURE);
    }
    /* attaching the shared memory  */
    char *str = (char *)shmat(shmid, (void *)0, 0);
    printf("Write the date which you need to send: ");
    gets(str);
    /* Deatching the shared memory */
    shmdt(shmid);
    
    return 0;

}