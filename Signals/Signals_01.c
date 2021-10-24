
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
#include <unistd.h>
#include <signal.h>

/* AIM: implimentation of the signal */
/*
Signal is the Asyncronous events which is occuring by the any external events
               to stop or terminating the process 
*/

void SignalHandler(int sig)
{
    printf("Signal occuring : %d\r\n", sig);
    exit(1);
}

int main(void)
{
    /* Attaching the signal */
    signal(SIGINT, SignalHandler);
    while (1)
    {
        printf("MainLoop is Running...\r\n");
        sleep(1);
    }
}
