#include <stdio.h>
#include <stddef.h>
#include <stddef.h>

static const size_t LEGACY_SIZE = 128; // Pre-C23: Read-only memory variable
constexpr size_t C23_SIZE = 256;       // C23: True compile-time constant

void demonstrate_differences(void) {
    const int runtime_size = 64; // Read-only at runtime

    int vla_stack_array[runtime_size]; // Allocates dynamic VLA on stack
    int fixed_stack_array[C23_SIZE];  // Fixed compile-time allocation

    printf("--- 1. Memory Storage vs Inlining ---\n");
    printf("static const : %zu | Address: %p (Stored in memory/flash)\n", LEGACY_SIZE, (void *)&LEGACY_SIZE);
    printf("constexpr    : %zu | Inlined directly into assembly CPU instructions\n\n", C23_SIZE);

    printf("--- 2. Stack Frame Allocation ---\n");
    printf("Local const array : %zu bytes (Treated as dynamic VLA)\n", sizeof(vla_stack_array));
    printf("constexpr array   : %zu bytes (Guaranteed compile-time size)\n\n", sizeof(fixed_stack_array));

    printf("--- 3. Constant Expression Context ---\n");
    switch (256) {
        case C23_SIZE:
            printf("Matched case %zu: Valid because constexpr is a constant expression.\n", C23_SIZE);
            break;
        default:
            break;
    }
}

int main(void) {
    demonstrate_differences();
    return 0;
}