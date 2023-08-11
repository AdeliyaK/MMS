#include "ring.h"
#include "stack.h"
#include <stdio.h>
int main(void){
    printf("STACK\n");
    Data help;
    help.a=1;
    push(help);
    help.a=2;
    push(help);
    print();
    help=pop();
    printf("%d",help.a);
    
    printf("\n\nRING\n");
    Data_Ring help2;
    help2.a=2;
    push_R(help2);
    help2.a=5;
    push_R(help2);
    help2=pop_R();
    printf("%d",help2.a);
    return 0;
    
}