#include <stdio.h> /*these are headers that include contents and utilities and more...*/
#include <stdlib.h>
/*
    int main(){
        printf("%s\n" , "Hellow world!");
        return EXIT_SUCCESS;
    }
*/

int main(){
    if (printf("%s\n" , "Hellow world!") < 0) 
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}