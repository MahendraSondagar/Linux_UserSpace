
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
 Coded: Sun, 24th Oct, 2021 / 15:30 PM
 ****************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>

/* Global Mutex handler */
pthread_mutex_t lock;

/* shared resource between two or more thread */
void SharedResource(void)
{
    /* SPI, I2C, UART Port etc */
}

void *Thread_1(void *p)
{
    for (;;)
    {
        pthread_mutex_lock(&lock);
        printf("Thread_1 got the shared resource\r\n");
        SharedResource();
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
}

void *Thread_2(void *p)
{
    for (;;)
    {
        pthread_mutex_lock(&lock);
        printf("Thread_2 got the shared resource\r\n");
        SharedResource();
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
}

int main(void)
{
    pthread_t th1, th2;
    /* Creating the mutex */
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        perror("Mutex init failed!\r\n");
        exit(1);
    }
    pthread_create(&th1, NULL, Thread_1, NULL);
    pthread_create(&th2, NULL, Thread_2, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    return 0;
}
