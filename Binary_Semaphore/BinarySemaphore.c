
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
 Coded: Sun, 24th Oct, 2021 / 11:45 AM
 ****************************************************/
 
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdint.h>
#include <unistd.h>

/* Global Semaphore handler*/
sem_t MySem;
void *EmployeeThread(void *p)
{
  for(;;)
  {
      /* Getting the semaphoe from the boss thread */
      sem_wait(&MySem);
      printf("Employee: Task has been complated :)\r\n");
  }
}

void *BossThread(void *p)
{
   for(;;)
   {
      printf("Boss: Let me allocate the task To employee\r\n");
      /* Sending the  sempahore to the employee */
      sem_post(&MySem);
      sleep(1);
   }
}

int main(void)
{

    pthread_t th1, th2;

    /* Creating the Binary semaphore */
    sem_init(&MySem, 0, 1);
    pthread_create(&th2, NULL, BossThread, NULL);
    pthread_create(&th1, NULL, EmployeeThread, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return 0;
}
