#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

int main(int argc, char *argv[]) {
    long long octs[16];
    char hex_string[1024];
    printf("\033c\033[44;37m\n");
    if (argc != 2) {
        printf("Usage: %s 0000:0000:0000:0000:0000:0000:0000:0000\n", argv[0]);
        return 1;
    }

    char *ips = argv[1];
    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    long long i;
    long long ii;
    

 
        // Split line into fields
        i = 0;
        fields[i] = strtok(ips, ":");
        while (fields[i] != NULL && i < MAX_FIELDS) {
            i++;
            fields[i] = strtok(NULL, ":");
        }
       
        if(i!=8)exit(0);
        // Print fields separated by tabs
        for (int j = 0; j < i; j++) {
            octs[j]=strtol(fields[j], NULL, 16);
            if(octs[j]>=(256*256) || octs[j]<=-1)exit(0);
        }

        i=0;
        ii=0;
        i=  ((long long) octs[4]) << 48 | ((long long) octs[5]) << 32 |
          ((long long) octs[6]) << 16 | ((long long) octs[7]);
         ii=  ((long long) octs[0]) << 48 | ((long long) octs[1]) << 32 |
          ((long long) octs[2]) << 16 | ((long long) octs[3]);
        
        strcpy(hex_string,"");
        sprintf(hex_string, "%016llx", ii); 
        printf("%s",hex_string);
        strcpy(hex_string,"");
        sprintf(hex_string, "%016llx", i); 
        printf("%s\r\n",hex_string);

    
    return 0;
}
