#ifndef Stack_H
#define Stack_H

typedef struct Data {
    int val;
} Data;

typedef struct Node {
    Data d;
    struct Node *next;
} Node;

typedef struct LL {
    Node *head;
    Node *tail;
} LL;

void print_linked_list(LL *ll);
void push_front(Data new_data, LL *ll);
void pop_front(LL *ll, Data *result);
LL* init_linked_list();
void deinit_linked_list(LL* ll);



#endif