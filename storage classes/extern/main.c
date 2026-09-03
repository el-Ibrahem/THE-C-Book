#include <stdio.h>
#include "counter.h" // Preprocessor pastes the 'extern int global_count;' declaration here

int main(void) {
    printf("Initial count: %d\n", global_count); // Reads the shared memory location

    increment_counter();
    increment_counter();
    printf("Count after increments: %d\n", global_count);

    // Direct modification through external linkage
    global_count = 100;
    printf("Count after direct update: %d\n", global_count);

    reset_counter();
    printf("Count after reset: %d\n", global_count);

    return 0;
}