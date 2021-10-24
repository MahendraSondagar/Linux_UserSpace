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
 Coded: Sun, 24th Oct, 2021 / 10:00 AM
 ****************************************************/
 
#include <stdio.h>
#include <time.h>

static void My_Test_Function(void)
{
    printf("Entering in to the function \r\n");
    printf("Press any key to exit the function: ");
    for (;;)
    {
        if (getchar())
        {
            break;
        }
    }
    printf("Exiting from the function \r\n");
}

int main(void)
{
    /* Capture the initial time before calling function */
    clock_t Previous= clock();
    My_Test_Function();
    /* Time taken by the function */
    clock_t current = clock()-Previous;
    double Fun_time_taken = ((double)current/ CLOCKS_PER_SEC);
    printf("Time take by Function: %f\r\n", Fun_time_taken);
    return 0;
}
