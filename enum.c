#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
enum colour {red,green,blue}; /* red=0, green=1, blue=2 tag:colour*/
enum speed {slow,normal,fast}; /*slow=0*/
bool valid (enum colour c){
    return(red < c && c < blue);
}
int main (){
    if (valid(normal) == true){
        puts("nice \n");
    }
}