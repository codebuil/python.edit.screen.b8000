#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

int main(int argc, char *argv[]) {
    int octs[8];
    printf("\033c\033[44;37m\n");
    if (argc != 2) {
        printf("Usage: %s 0\n", argv[0]);
        return 1;
    }

    char *ips = argv[1];
    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    int i;

    

 
        // Split line into fields
        i = atoi(ips);
        octs[0]=i>>24 & 255;
        octs[1]=i>>16 & 255;
        octs[2]=i>>8 & 255;
        octs[3]=i & 255;
        printf("%d.%d.%d.%d\r\n",octs[0],octs[1],octs[2],octs[3]);
        

    
    return 0;
}
