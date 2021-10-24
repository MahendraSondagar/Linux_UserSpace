
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
 Coded: Sun, 24th Oct, 2021 / 16:26 PM
 ****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/unistd.h>
#include <wait.h>
#include <error.h>


/* AIM : to test the muti threading with pipe for the inter thread communication*/
int fd[2];

void *SenderThread(void *p)
{
    char tx = 'A';
    for (;;)
    {
        printf("Sending: %c\r\n", tx);
        write(fd[1], &tx, sizeof(tx));

        if (tx == 'Z')
        {
            tx = 'A' - 1;
        }
        tx++;

        sleep(1);
    }
}

void *ReceiverThread(void *p)
{
    char rx;
    for (;;)
    {
        read(fd[0], &rx, sizeof(rx));
        printf("Received: %c\r\n", rx);
        sleep(1);
    }
}

int main(int argc, char *argv[])
{
    pthread_t th1, th2;

    if (pipe(fd) == -1)
    {
        perror("Failed to create pipe\r\n");
        exit(EXIT_FAILURE);
    }

    pthread_create(&th1, NULL, SenderThread, NULL);
    pthread_create(&th2, NULL, ReceiverThread, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    return 0;
}