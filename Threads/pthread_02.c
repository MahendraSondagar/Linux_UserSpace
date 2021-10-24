

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
 Coded: Sun, 24th Oct, 2021 / 15:00 PM
 ****************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>


/* AIM: Thread aruments & cencelling the thread! */
typedef struct
{
    const char *Info;
    uint16_t ID;
} ThreadPayload_t;

/* Thread global handler */
pthread_t th1;

void *Thread_func1(void *p)
{
    uint32_t Idx = 0;
    ThreadPayload_t *ThreadPayload = (ThreadPayload_t *)p;
    for (;;)
    {
        printf("Thread Info: %s & ID: 0x%02x\r\n", ThreadPayload->Info, ThreadPayload->ID);
        if (Idx++ >= 50)
        {
            printf("Cancelling the thread\r\n");
            pthread_cancel(th1);
        }
        sleep(1);
    }
}

int main(void)
{
    /*Thread payload  */
    ThreadPayload_t ThreadPaylaod =
        {
            .Info = "Hello world",
            .ID = 0X3231,
        };

    /* Creating the thread with arguments*/
    pthread_create(&th1, NULL, Thread_func1, (void *)&ThreadPaylaod);
    pthread_join(th1, NULL);
    return 0;
}
