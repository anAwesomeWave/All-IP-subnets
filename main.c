#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc == 2) {
        int subnet= 32;
        char* s = strtok(argv[1], ".");
        int partsOfIp = 4;
        int arr[4];
        int cnt = 0;
        while(s != NULL) {
            arr[cnt ++] =  atoi(s);
            printf("%d\n", arr[cnt - 1]);
            s = strtok(NULL, ".");
        }
    } else {
        printf("Wrong number of args\nExpected: 1, got %d", argc-1);
    }
    return 0;
}
