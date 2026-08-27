#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

    void f(int i) {  // block scope of i begins
        int j = 1;  // block scope of j begins; hides file-scope j
        i++;  // i refers to the function parameter
        for (int i = 0; i < 2; i++) { // block scope of loop-local i begins
            int j = 2;  // block scope of the inner j begins; hides outer j
            printf("%d\n", j); // inner j is in scope, prints 2
        }  // block scope of the inner i and j ends
        printf("%d\n", j);  // the outer j is in scope, prints 1
    } // the block scope of i and j ends

int main (void){
    int j; // file scope of j begins
    f(j);
    printf("%d",j);
    // j has function prototype scope; hides file-scope j
}