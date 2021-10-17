#include <stdio.h>
#include <stdlib.h>
#include <error.h>

int main(void)
{
    FILE *fp;
    char ch;
    /* Writing the text with the file*/
    fp = fopen("Test.txt", "w");
    if (fp == NULL)
    {
        perror("Unable to open the file to write...\r\n");
        goto EXIT;
    }

    printf("Enter the data with the file: ");
    while ((ch = getchar()) != '\n')
    {
        putc(ch, fp);
    }
    fclose(fp);

    fp = fopen("Test.txt", "r");
    if (fp == NULL)
    {
        perror("Unable to open the file to read\r\n");
        goto EXIT;
    }
    /* Reading the text from the file */
    printf("Reading the data from the file...\r\n");
    while ((ch = getc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(fp);

    return 0;

EXIT:
    fclose(fp);
    exit(1);
}