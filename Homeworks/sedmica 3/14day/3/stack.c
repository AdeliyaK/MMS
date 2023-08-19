#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

void push(Data d){
    if(cur==SIZE){
        printf("ERROR");
        exit(1);
    }
    Stack[cur]=d;
}
Data pop(void){
    if(cur==0){
        print("ERROR");
        exit(1);
    }
    cur--;
    Data help;
    help=Stack[cur];
    Stack[cur].a=0;
    return help;
}

void print(){
    for(int i=0;i<SIZE;i++)
        printf("%d",Stack[i].a);
}