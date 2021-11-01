
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
 Coded: Mon, 1st Nov 2021 / 23:13 PM
 ****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <errno.h>

/* AIM : message queue implimentation  */

#define PERMISSON 0644
/* structure to receive the queue */
typedef struct 
{
   long msg_id;
   char msgbuff[20];
}msgbuf_t;

int main(int argc, char *argv[])
{
   key_t key;
   int msgid;
   msgbuf_t msgbuf;
   if((key=ftok("msg.txt", 'B'))==-1)
   {
      perror("Key create");
      exit(EXIT_FAILURE);
   }

   if((msgid = msgget(key, PERMISSON))==-1)
   {
       perror("Create queue");
       exit(EXIT_FAILURE);
   }

   while(1)
   {
       if(msgrcv(msgid, &msgbuf, sizeof(msgbuf), 0,0)==-1)
       {
           perror("msgrecv");
           exit(EXIT_FAILURE);
       }
       printf("Received: %s\r\n", msgbuf.msgbuff);
   }
   return 0;
}