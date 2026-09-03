#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdalign.h>
#include <unistd.h>
int main(void) {
    long line_size = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
    printf("L1 Data Cache Line Size: %ld bytes\n", line_size);
    return 0;
}