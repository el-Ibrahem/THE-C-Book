#include <stdio.h> /*these are headers that include contents and utilities and more...*/
#include <stdlib.h>
/*
int main(){
    puts("Hello, World!");
    return EXIT_SUCCESS;
}
*/

int main(){
    if(puts("Hello, World!") == EOF){
    return EXIT_FAILURE;
    // code here never excutes  
    }
    return EXIT_SUCCESS;   
}
// this revise if the puts func returns an E0F
