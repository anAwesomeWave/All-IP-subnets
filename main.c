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
        int error = 0;
        while(s != NULL) {
            arr[cnt ++] =  atoi(s);
            printf("%d\n", arr[cnt - 1]);
            if(arr[cnt-1] < 0 || arr[cnt-1] > 255) {
                error = 1;
            }
            s = strtok(NULL, ".");
        }
        if(cnt != 4 || error) {
            printf("ERROR: Wrong format of string\nExpected x.x.x.x, where 0 <= x <= 255\n");
        }else {
            printf("OK");
        }
    } else {
        printf("ERROR:Wrong number of args\nExpected: 1, got %d\n", argc-1);
    }
    return 0;
}
