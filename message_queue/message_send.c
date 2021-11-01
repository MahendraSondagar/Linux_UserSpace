

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
#include <stdint.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <errno.h>

#define PERMISSON 0644
/* Message buff structure */
typedef struct
{
    long msg_id;
    char msgbuff[20];
} msgbuf_t;

int main(int argc, char *argv[])
{
    key_t key;
    int msgid;
    msgbuf_t msgbuf;

    if (system("touch msg.txt") == -1)
    {
        perror("File create");
        exit(EXIT_FAILURE);
    }

    /*Creating the symmetric key */
    if ((key = ftok("msg.txt", 'B')) == -1)
    {
        perror("key create");
        exit(EXIT_FAILURE);
    }
    /* Creating the msg ID */

    if ((msgid = msgget(key, PERMISSON | IPC_CREAT)) == -1)
    {
        perror("msgID");
        exit(EXIT_FAILURE);
    }
    
    msgbuf.msg_id =0x5532;
    printf("Enter the data which you want to send : ");
    while (fgets(msgbuf.msgbuff, sizeof(msgbuf), stdin)!=NULL)
    {
        printf("-");
        int len = strlen(msgbuf.msgbuff);
        if(msgbuf.msgbuff[len-1]== '\n')
        {
            /* append the NULL to the end of string */
            msgbuf.msgbuff[len-1]= '\0';
            if(msgsnd(msgid, &msgbuf, sizeof(msgbuf), 0)== -1)
            {
                perror("Send");
                exit(EXIT_FAILURE);
            }
        }
    }

    if(msgctl(msgid, IPC_RMID, NULL)==-1)
    {
        perror("message queue remove");
        exit(EXIT_FAILURE);
    }

    printf("Message has been sent buy message queue\r\n");
    return 0;
}
