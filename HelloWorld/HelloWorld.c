#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	while(1)
	{
		printf("Hello world from STM32MP1_DK1\r\n");
		sleep(1);
	}
	return 0;
}

