#ifndef RING_H
#define RING_H
#define SIZE_QUEUE 10

typedef struct {
    int a;
}Data_Ring;

Data_Ring r[SIZE_QUEUE];
int cur_pop,cur_push;

void push_R(Data_Ring a);
Data_Ring pop_R(void);
void print_Queue();
#endif
