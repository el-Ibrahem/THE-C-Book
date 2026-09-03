#ifndef COUNTER_H
#define COUNTER_H

// DECLARATION: Promises the compiler that 'global_count' exists in another file.
// Allocates NO memory here.
extern int global_count;

// Function declarations (implicitly extern)
void increment_counter(void);
void reset_counter(void);

#endif