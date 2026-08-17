#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
enum colour {red,green,blue}; /* red=0, green=1, blue=2 tag:colour*/
enum speed {slow,normal,fast}; /*slow=0, normal=1, fast=2 tag:speed*/
enum a : unsigned long long { a0 = 0xFFFFFFFFFFFFFFFFULL };
bool valid (enum colour c){
    return(red < c && c < blue);
    /*condition: {red(0) < c < blue(2)} , then c must be in ]0,1[ to be true*/
}
int main (){
    if (valid(normal) == true){
        puts("nice \n");
    }
}