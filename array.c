#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char str[11];
// Total bytes = N * sizeof(type) 
// a[i] = *(a + i) , pointer addition : a + i means take the memory location a and take i steps

int main(){

    for (unsigned int i = 0;i < 10;i++) {
        str[i] = '0' + i;
        // chars are integers with storage of 1 byte range from {-128 - 127} or {0 - 255}
        // when performed arthimatic operations upon C convert it into full integer
        // if the number > 255 : top bit sliced off eg 300[1 0010 1100] --> 44[0010 1100] ASCII for ','
        // if the nymber is decimel : C rounds it down eg 51.14 --> 51 ASCII for '3'
        // '0' maps to the ASCII 48 from the ASCII{48 - 57} represent numbers{0 - 9}
    }
    str[10] = '\0'; // index 10 maps to byte 11 \0 is a null terminator

    printf("%s \n",str+2); // str decays into chars printf ready byte by byte until it reaches null terminator
    // since arrays cant be mathematically mainpulated in C the compilers replace str with &str[2]
    // printf(str[6]); // doesnt work tries to read a the value char in a memory location
    printf("%s", (&str[6])); // %S derefrence it resulting in values from 6 --> null terminator 
    printf("%p", (void *)(&str[6])); // print the the adress of index 6   
    printf("\n%c \n", str[6]); // prints the value of index 6
    printf("%p",str[6]);
    
}