#include <stdio.h>
#include <stdint.h>

    union {
        float f;
        struct {
            uint32_t significand : 23; // Bits 0-22  (LSB)
            uint32_t exponent    : 8;  // Bits 23-30
            uint32_t sign        : 1;  // Bit 31     (MSB)
        };
    } float_encoding = {0}; // = {0} to set padded bits to zero meow practice

int main(void) {

    float_encoding.f = 2.24f;

    printf("--- IEEE 754 BITFIELD DECODER ---\n");
    printf("Float Value     : %f\n", float_encoding.f);
    printf("Sign Bit        : %u (%s)\n", 
           float_encoding.sign, float_encoding.sign ? "-" : "+");
    printf("Biased Exponent : %u (0x%02X)\n", 
           float_encoding.exponent, float_encoding.exponent);
    printf("Unbiased Exp    : %d (2^%d)\n", 
           (int)float_encoding.exponent - 127, (int)float_encoding.exponent - 127);
    printf("Significand Hex : 0x%06X\n", float_encoding.significand);
    printf("Significand Dec : %u\n", float_encoding.significand);

    return 0;
}