
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
 Coded: Sun, 24th Oct, 2021 / 15:15 PM
 ****************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <error.h>


/*Thread Callback Function */
static void *Thread_func1(void *p)
{
    for(;;)
    {
        printf("Thread_1 is Running...\r\n");
        sleep(1);
    }
}
int main(void)
{
     pthread_t th1;
     int ret;
     /*@brief:  Creating the thread
     @arg1: Thread handler
     @arg2: Thread attributes 
     @arg3: Thread Callback Function
     @arg4: Thread param
     */
     ret= pthread_create(&th1, NULL, Thread_func1, NULL);
     if(ret!= NULL)
     {
         perror("Failed to Create the thread!\r\n");
         exit(1);
     }
     /* attaching the thread */
     pthread_join(th1, NULL);
     return 0;

}
