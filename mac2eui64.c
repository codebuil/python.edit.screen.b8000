#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

int main(int argc, char *argv[]) {
    unsigned long long octs[16];
    char hex_string[1024];
    printf("\033c\033[44;37m\n");
    if (argc != 2) {
        printf("Usage: %s 0:0:0:0:0:0\n", argv[0]);
        return 1;
    }

    char *ips = argv[1];
    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    unsigned long long i;
    unsigned long long ii;

       // Split line into fields
        i = 0;
        fields[i] = strtok(ips, ":");
        while (fields[i] != NULL && i < MAX_FIELDS) {
            i++;
            fields[i] = strtok(NULL, ":");
        }
       
        if(i!=6)exit(0);
        // Print fields separated by tabs
        

 
        // Split line into fields
        printf("%02s:",fields[0]);
        printf("%02s",fields[1]);
        printf(":%02s",fields[2]);
        printf("FF:FE%02s",fields[3]);
        printf(":%02s",fields[4]);
        printf("%02s\n\r",fields[5]);
        
        


 
    
    return 0;
}
