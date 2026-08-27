#include <stdio.h>
#include <stdint.h>

// ============================================================================
// 1. UNION TYPE DEFINITION (BLUEPRINT ONLY)
// ============================================================================
// Rule: You CANNOT assign default values inside this definition (e.g., uint32_t raw = 5;).
// No physical RAM is allocated here—this is simply a blueprint for the compiler.
typedef union {
    uint32_t raw;           // Member 1: 4 bytes (Determines total union size)
    uint8_t  bytes[4];      // Member 2: Array of 4 individual 1-byte slots
    struct {
        uint8_t  lsb;       // Member 3a: Least Significant Byte (Byte 0)
        uint8_t  mid_low;   // Member 3b: Byte 1
        uint8_t  mid_high;  // Member 3c: Byte 2
        uint8_t  msb;       // Member 3d: Most Significant Byte (Byte 3)
    } fields;
} WordView;

int main(void) {
    // ============================================================================
    // 2. INSTANTIATION AND INITIALIZATION
    // ============================================================================
    // Memory is allocated NOW. Designated initializers select which field to populate
    WordView data = {0}; // zeros padded bits meow practice
    WordView data = { .raw = 0x12345678 }; // meow

    // ============================================================================
    // 3. PROVING SHARED ADDRESSES AND FOOTPRINT CAPACITY
    // ============================================================================
    // The largest member (uint32_t raw) sets total union size to 4 bytes.
    // Every single member label starts at the EXACT SAME memory address (Offset 0).
    printf("--- 1. FOOTPRINT AND MEMORY ADDRESSES ---\n");
    printf("Total Union Size : %zu bytes\n", sizeof(WordView));
    printf("Address of .raw  : %p\n", (void*)&data.raw);
    printf("Address of .bytes: %p\n", (void*)&data.bytes);
    printf("Address of .lsb  : %p\n\n", (void*)&data.fields.lsb);

    // ============================================================================
    // 4. TYPE PUNNING (READING ONE VALUE THROUGH DIFFERENT LENSES)
    // ============================================================================
    // The single bit pattern in RAM can be interpreted as a 32-bit int or 4 bytes.
    printf("--- 2. TYPE PUNNING (VIEWING RAW BITS) ---\n");
    printf("Full 32-bit Raw Integer : 0x%08X\n", data.raw);
    printf("Byte Array View         : [0]:0x%02X, [1]:0x%02X, [2]:0x%02X, [3]:0x%02X\n",
           data.bytes[0], data.bytes[1], data.bytes[2], data.bytes[3]);
    printf("Named Fields View       : LSB=0x%02X, MSB=0x%02X\n\n",
           data.fields.lsb, data.fields.msb);

    // ============================================================================
    // 5. PARTIAL OVERWRITES & "LAST WRITE WINS" MECHANICS
    // ============================================================================
    // Writing to a smaller member modifies ONLY its overlapping byte slice (Byte 0).
    // The remaining upper bytes (Bytes 1-3) retain their previous binary values.
    printf("--- 3. MUTATING A SUB-SLICE (PARTIAL OVERWRITE) ---\n");
    printf("Executing: data.fields.lsb = 0xFF;\n");
    
    data.fields.lsb = 0xFF; // Overwrite only Byte 0

    printf("Updated LSB Field       : 0x%02X\n", data.fields.lsb);
    printf("Updated Byte Array      : [0]:0x%02X, [1]:0x%02X, [2]:0x%02X, [3]:0x%02X\n",
           data.bytes[0], data.bytes[1], data.bytes[2], data.bytes[3]);
    printf("Mutated Raw Integer     : 0x%08X\n\n", data.raw);

    // ============================================================================
    // 6. TOTAL OVERWRITE
    // ============================================================================
    // Writing to .raw replaces all 4 bytes, completely erasing the previous state.
    printf("--- 4. FULL OVERWRITE ---\n");
    printf("Executing: data.raw = 0x00000000;\n");
    
    data.raw = 0x00000000;

    printf("LSB field after raw reset: 0x%02X (Previous 0xFF is gone!)\n", data.fields.lsb);

    return 0;
}