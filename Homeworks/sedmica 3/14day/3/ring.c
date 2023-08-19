#include <stdio.h>
#include "ring.h"
#include <stdlib.h>

void push_R(Data_Ring a){
    if(cur_pop==cur_push && r[cur_pop].a!=0){
        printf("ERROR");
        exit(1);
    }
    r[cur_push++]=a;
    if(cur_push==SIZE_QUEUE)
        cur_pop=0;
}
Data_Ring pop_R(void){
    if(cur_pop==cur_push && r[cur_pop].a==0){
        printf("ERROR");
        exit(1);
    }
    Data_Ring help;
    help=r[cur_pop++];
    if(cur_pop==SIZE_QUEUE)
        cur_pop=0;
    return help;
}
void print_Queue(){
    int help=cur_pop;
    for(;help!=cur_push;help++){
        if(help==SIZE_QUEUE) help=0;
        printf("%d",r[help].a);
    }
}