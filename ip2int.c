#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

int main(int argc, char *argv[]) {
    int octs[8];
    printf("\033c\033[44;37m\n");
    if (argc != 2) {
        printf("Usage: %s filename.csv\n", argv[0]);
        return 1;
    }

    char *ips = argv[1];
    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    int i;

    

 
        // Split line into fields
        i = 0;
        fields[i] = strtok(ips, ".");
        while (fields[i] != NULL && i < MAX_FIELDS) {
            i++;
            fields[i] = strtok(NULL, ".");
        }
        if(i!=4)exit(0);
        // Print fields separated by tabs
        for (int j = 0; j < i; j++) {
            octs[j]=atoi( fields[j]);
            if(octs[j]>=256 || octs[j]<=-1)exit(0);
        }
        i=0;
        i=octs[0]<<24 | octs[1]<<16 |  octs[2]<<8 | octs[3];
        printf("%d\r\n",i);
    

    
    return 0;
}
