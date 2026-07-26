#include <stdio.h>
#include <stdlib.h>

/*
int main(){
    char *src; // src has a type of char* [pointer]
    char C; // c has a type of char
    int x; // x has a type of int
    int y[5]; // y is an array of 5 elements of type int
    int n[15][3]; // n is an array of 15 arrays of 3 elements of type int
}
*/

void swap(int *pa, int *pb){
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
    printf("swap: a = %d, b = %d \n",a,b);
}

int main(){
    int a = 21;
    int b = 17;
    swap(21, 17);
    printf("main: a = %d, b = %d \n",a,b);
}