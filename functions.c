#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int f(void);
int fprime();
int *fip();
void g(int i, int j);
void h(int, int);

int max(int a, int b){
    return a > b ? a : b; 
    /*"ternary expression"--> [condition] ? [value if true] : [value if false]*/
}