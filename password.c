#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(int argc, char* argv[]) {
    // assignment
    const char* lcc  = "abcdefghijklmnopqrstuvwxyz";
    const char* ucc  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* nums = "0123456789";
    const char* spsy = "!@#$%^&*()_+-=[]{}|;':,.<>?";
    char* pool = NULL; 
    int l, c;

    // input processing
    if (argc != 3 || !isdigit(*argv[1]) || !isdigit(*argv[2])) {
        printf("\nUsage: %s <length> <complexity>\n0 < Length; Complexity in range 1 to 4\n ", argv[0]);
        return 1;
    }

    l = atoi(argv[1]);
    c = atoi(argv[2]);

    if (l <= 0 || c < 1 || c > 4) {
        printf("\nUsage: %s <length> <complexity>\n0 < Length; Complexity in range 1 to 4\n ", argv[0]);
        return 1;
    }

    switch (c) {
        case 1:
            pool = (char*)lcc;
            break;
        case 2:
            pool = (char*)malloc(52*sizeof(char));
            snprintf(pool, 53, "%s%s", lcc, ucc);
            break;
        case 3:
            pool = (char*)malloc(62*sizeof(char));
            snprintf(pool, 63, "%s%s%s", lcc, ucc, nums);
            break;
        case 4:
            pool = (char*)malloc(94*sizeof(char));
            snprintf(pool, 95, "%s%s%s%s", lcc, ucc, nums, spsy);
            break;
        default:
            fprintf(stderr, "when did we go so wrong");
            return 1;
    }

    srand(time(NULL));

    for (int i=0; i<l; ++i) {
        printf("%c", pool[rand() % strlen(pool)]);
    }

    free(pool);

    return 0;
}