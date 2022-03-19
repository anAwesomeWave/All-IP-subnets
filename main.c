#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc == 2) {
        char* s = strtok(argv[1], ".");
        int partsOfIp = 4;
        int arr[4];
        int mask[4]; // 4 255 numbers
        int ptr = 3; // pointer to integer in mask array
        int subnet= 32;
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
            for(int i = 0; i < 4; i ++)
                mask[i] = 255;
            while(subnet > -1) {
                //printf("%d", 193 & 254);
                for(int i = 0 ; i < 4; i ++) {
                    printf("%d ", *(mask+i));
                }
                printf("\n");
                mask[ptr] = (mask[ptr] & ~(1<<(8-subnet+ptr*8)));
                if(*(mask+ptr) == 0)
                    ptr --;
                subnet --;
            }
        }
    } else {
        printf("ERROR:Wrong number of args\nExpected: 1, got %d\n", argc-1);
    }
    return 0;
}
