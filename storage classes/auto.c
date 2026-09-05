#include <stdio.h>
#include <stdlib.h>

#define TYPE_NAME(x) _Generic((x), \
    int: "int", \
    int *: "int *", \
    unsigned int: "unsigned int", \
    long: "long", \
    float: "float", \
    double: "double", \
    char *: "char *", \
    void *: "void *", \
    default: "unmapped/user-defined type" \
)

static auto buffer = 64;
static auto buffer_p = &buffer;


int main(){
    printf("buffer type: %s\n", TYPE_NAME(buffer));
    printf("buffer_p type: %s\n", TYPE_NAME(buffer_p));
    printf("%d wow\n",buffer);
    return EXIT_SUCCESS;
}