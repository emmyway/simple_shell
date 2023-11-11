#include <stdio.h>
#ifdef _GNU_SOURCE
#define HAS_GETLINE
#endif

int main() {
    #ifdef HAS_GETLINE
    printf("getline is supported.\n");
    #else
    printf("getline is not supported.\n");
    #endif

    return 0;
}
