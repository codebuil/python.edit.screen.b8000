#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

int main(int argc, char *argv[]) {
    long octs[8];
    char hex_string[1024];
    printf("\033c\033[44;37m\n");
    if (argc != 2) {
        printf("Usage: %s 0\n", argv[0]);
        return 1;
    }

    char *ips = argv[1];
    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    long i;

    

 
        // Split line into fields
        i  = strtoull(argv[1], NULL, 10);
        sprintf(hex_string, "%016lx", i); 
        printf("%c",hex_string[4]);
        printf("%c:",hex_string[5]);
        printf("%c",hex_string[6]);
        printf("%c:",hex_string[7]);
        printf("%c",hex_string[8]);
        printf("%c:",hex_string[9]);
        printf("%c",hex_string[10]);
        printf("%c:",hex_string[11]);
        printf("%c",hex_string[12]);
        printf("%c:",hex_string[13]);
        printf("%c",hex_string[14]);
        printf("%c",hex_string[15]);
        

    
    return 0;
}
