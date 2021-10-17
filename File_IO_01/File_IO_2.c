#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <stdint.h>
#include <string.h>

/* AIM : Writing the binary format to file */

typedef struct
{
    const char *name;
    uint8_t age;
    float height;
    int roll_no;
} Student_Info_t;

int main(void)
{
    FILE *fp;
    fp = fopen("Info.txt", "wb");
    if(fp == NULL)
    {
        perror("Failed to open the file!\r\n");
        exit(1);
    }
    printf("Writing the file int to binary format...\r\n");
     Student_Info_t StudentInfo[]= {
        {"Mahendra", 29, 5.4, 52},
        {"Chetan", 24, 5.4, 42},
        {"Payal", 26, 5.2, 20},
    };
   
    fwrite(StudentInfo, sizeof(StudentInfo), 1, fp);
    fclose(fp);

    fp = fopen("Info.txt", "rb");
    if(fp == NULL)
    {
        perror("Failed to open the file to read!\r\n");
        exit(1);
    }

    printf("Reading the file...\r\n");
    memset(&StudentInfo, 0x00, sizeof(StudentInfo));

    fread(&StudentInfo, sizeof(StudentInfo), 1, fp);

    for(int i=0; i<3; i++)
    {
        printf("Name= %s\t, age= %d\t, height= %0.2f\t, roll_no=%d\r\n", StudentInfo[i].name, StudentInfo[i].age,StudentInfo[i].height, StudentInfo[i].roll_no );
    }
    fclose(fp);

    return 0;
}