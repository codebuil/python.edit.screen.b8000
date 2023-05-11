#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

int main(int argc, char *argv[]) {
    int octs[8];
    printf("\033c\033[44;37m\n");
    if (argc != 2) {
        printf("Usage: %s 00:00:00:00:00:00\n", argv[0]);
        return 1;
    }

    char *ips = argv[1];
    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    long long i;

    

 
        // Split line into fields
        i = 0;
        fields[i] = strtok(ips, ":");
        while (fields[i] != NULL && i < MAX_FIELDS) {
            i++;
            fields[i] = strtok(NULL, ":");
        }
       
        if(i!=6)exit(0);
        // Print fields separated by tabs
        for (int j = 0; j < i; j++) {
            octs[j]=strtol(fields[j], NULL, 16);
            if(octs[j]>=256 || octs[j]<=-1)exit(0);
        }
        i=0;
        i= ((long long) octs[0]) << 40 | ((long long) octs[1]) << 32 | ((long long) octs[2]) << 24 |
          ((long long) octs[3]) << 16 | ((long long) octs[4]) << 8 | ((long long) octs[5]);
        printf("%lld\r\n",i);
    

    
    return 0;
}
