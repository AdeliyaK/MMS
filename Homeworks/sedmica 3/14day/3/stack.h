#ifndef STACK_H
#define STACK_H
#define SIZE 5
typedef struct {
    int a;
}Data;

Data Stack[SIZE];
int cur;

void push(Data d);
Data pop(void);
void print();
#endif 