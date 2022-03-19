#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if(argc == 2) {
        int subnet= 32;
        char* s = strtok(argv[1], ".");
        while(s != NULL) {
            printf("%s\n", s);
            s = strtok(NULL, ".");
        }
    } else {
        printf("Wrong number of args\nExpected: 1, got %d", argc-1);
    }
    return 0;
}
