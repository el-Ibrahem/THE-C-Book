#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t power_on   : 1; // 1 bit (0..1)
    uint8_t mode       : 3; // 3 bits (0..7)
    uint8_t error_code : 4; // 4 bits (0..15)
} StatusRegister;

int main(void) {
    StatusRegister status = { .power_on = 0, .mode = 5, .error_code = 12 };

    // Passed by value — compiler handles value extraction automatically
    printf("Power On:   %u\n", status.power_on);
    printf("Mode:       %u\n", status.mode);
    printf("Error Code: %u (0x%X in hex)\n", status.error_code, status.error_code);

    return 0;
}