#include "counter.h"

// DEFINITION: Physically allocates 4 bytes of memory in the .data segment.
int global_count = 0;

void increment_counter(void) {
    global_count++;
}

void reset_counter(void) {
    global_count = 0;
}