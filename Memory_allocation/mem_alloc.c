

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
 Coded: Sun, 24th Oct, 2021 / 11:25 AM
 ****************************************************/
 
#include <stdio.h>
#include <stdlib.h>

/* AIM: Intro to memory allocations */

static void Display_Elements(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d is stored at %p\r\n", *(ptr + i), (ptr + i));
    }
}

int main(void)
{
    int size, extra;
    int i = 0;
    printf("Enter the size of the memory block \r\n");
    scanf("%d", &size);
    int *ptr = (int *)calloc(size, sizeof(int));
    if (ptr == NULL)
    {
        printf("Failed to allocate the memory block\r\n");
        exit(1);
    }

    printf("Enter the memory Elements...\r\n");
    for (i = 0; i < size; i++)
    {
        printf("ptr[%d]= ", i);
        scanf("%d", &ptr[i]);
    }

    Display_Elements(&ptr[0], size);

    printf("Enter the size to store extra elements...\r\n");
    scanf("%d", &extra);

    ptr = realloc(ptr, extra);
    if (ptr == NULL)
    {
        printf("Failed to re-allocate memory block\r\n");
        exit(1);
    }

    printf("Enter the Extra elements...\r\n");
    for (; i < size + extra; i++)
    {
        printf("ptr[%d]= ", i);
        scanf("%d", &ptr[i]);
    }
    
    Display_Elements(&ptr[0], size+extra);
    return 0;
}
