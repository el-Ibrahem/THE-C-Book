#include <stdio.h>
#include <stdlib.h>

/*
int main(){
    int n = 30;
    int *p = &n;
    int **pp;
    pp = &p;
    printf("n:%d ,\np:%d , *p:%d ,\npp:%d , **pp:%d",n ,p,*p ,pp ,**pp);

    EXIT_SUCCESS;
}
*/

int main(){
    int *ip = 0;
    char *cp = NULL;
    
    printf("%d , %d",*ip,*cp);

}