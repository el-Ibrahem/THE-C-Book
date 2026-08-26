#include <stdio.h>
#include <string.h>

// Blueprint definition
struct sigrecord {
    int signum;
    char signame[20];
    char sigdesc[100];
} sigline,*sigline_p;

int main(void) {
    // struct sigrecord sigline; // can replace sigline,*sigline_p
    // struct sigrecord *sigline_p;

    // 2. Direct access using dot (.) operator
    sigline.signum = 5;
    strcpy(sigline.signame, "SIGINT");
    strcpy(sigline.sigdesc, "Interrupt from keyboard");

    printf("Direct (.) access:    [%d] %s: %s\n", 
           sigline.signum, sigline.signame, sigline.sigdesc);

    // 3. Point sigline_p to the memory address of sigline
    sigline_p = &sigline;

    // 4. Indirect access using arrow (->) operator
    sigline_p->signum = 9;
    strcpy(sigline_p->signame, "SIGKILL");
    strcpy(sigline_p->sigdesc, "Kill signal");

    printf("Indirect (->) access: [%d] %s: %s\n", 
           sigline_p->signum, sigline_p->signame, sigline_p->sigdesc);

    // 5. Proving (*sigline_p). is identical to sigline_p->
    (*sigline_p).signum = 15;
    strcpy((*sigline_p).signame, "SIGTERM");
    strcpy((*sigline_p).sigdesc, "Termination signal");

    printf("Explicit (*p). syntax:[%d] %s: %s\n", 
           sigline.signum, sigline.signame, sigline.sigdesc);

    return 0;
}