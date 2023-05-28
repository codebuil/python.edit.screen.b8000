#include <stdlib.h>
#include <stdio.h>
//bcc -N -o hello hello.c
int main()
{
	printf("\033c\033[41;30m\nhello world\n");
	return 0;
}
