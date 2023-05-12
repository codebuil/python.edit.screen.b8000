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
        printf("Usage: %s 0:0\n", argv[0]);
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
       
        if(i!=2)exit(0);
        // Print fields separated by tabs
        

 
        // Split line into fields
        i  = strtoull(fields[0], NULL, 10);
        sprintf(hex_string, "%016lx", i); 
        printf("%c",hex_string[0]);
        printf("%c",hex_string[1]);
        printf("%c",hex_string[2]);
        printf("%c:",hex_string[3]);
        printf("%c",hex_string[4]);
        printf("%c",hex_string[5]);
        printf("%c",hex_string[6]);
        printf("%c:",hex_string[7]);
        printf("%c",hex_string[8]);
        printf("%c",hex_string[9]);
        printf("%c",hex_string[10]);
        printf("%c:",hex_string[11]);
        printf("%c",hex_string[12]);
        printf("%c",hex_string[13]);
        printf("%c",hex_string[14]);
        printf("%c:",hex_string[15]);
        


 // Split line into fields
 
        i  = strtoull(fields[1], NULL, 10);
        sprintf(hex_string, "%016lx", i); 
        printf("%c",hex_string[0]);
        printf("%c",hex_string[1]);
        printf("%c",hex_string[2]);
        printf("%c:",hex_string[3]);
        printf("%c",hex_string[4]);
        printf("%c",hex_string[5]);
        printf("%c",hex_string[6]);
        printf("%c:",hex_string[7]);
        printf("%c",hex_string[8]);
        printf("%c",hex_string[9]);
        printf("%c",hex_string[10]);
        printf("%c:",hex_string[11]);
        printf("%c",hex_string[12]);
        printf("%c",hex_string[13]);
        printf("%c",hex_string[14]);
        printf("%c\r\n",hex_string[15]);
       
        
    
    return 0;
}
