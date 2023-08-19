#include <stdio.h>
#include "stack.h"
int main(void){
    LL *begin=init_linked_list();
    Data data;
    data.val=4;
    push_front(data,begin);
    print_linked_list(begin);
    data.val=3;
    push_front(data,begin);
    print_linked_list(begin);
    data.val=1;
    push_front(data,begin);
    print_linked_list(begin);
    data.val=2;
    push_front(data,begin);
    print_linked_list(begin);
    Data result;
    pop_front(begin,&result);
    printf("%d",result.val);
    pop_front(begin,&result);
    printf("%d",result.val);
    pop_front(begin,&result);
    printf("%d",result.val);    
    deinit_linked_list(begin);
}