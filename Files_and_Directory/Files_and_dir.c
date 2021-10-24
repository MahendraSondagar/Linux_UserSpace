
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
 Coded: Sun, 24th Oct, 2021 / 10:30 AM
 ****************************************************/
 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <error.h>

/* AIM : To test the files and directory at the user space */

int main(void)
{
    /* Creating the directory with the R&W permisson */
    int ret = mkdir("/home/mahendra/Desktop/Test", 0777);
    if (ret != 0)
    {
        perror("Falied to create the directiry...\r\n");
        exit(1);
    }

    printf("Would you like to delete the directory(Y/N)?");
    char ch;
    while (ch = getchar())
    {
        if (ch == 'Y' || ch == 'y')
        {
            ret = rmdir("/home/mahendra/Desktop/Test");
            if (ret != 0)
            {
                perror("Failed to delete the directory\r\n");
                exit(1);
            }
        }
        else
        {
            exit(1);
        }
    }

    return 0;
}
