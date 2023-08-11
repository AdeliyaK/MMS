#include <stdio.h>
#include <stdlib.h>

typedef struct Deque{
    int data;
    struct Deque* front;
    struct Deque* prev;
} Deque ;

Deque* createNewDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    if (deque == NULL) {
        printf("ERROR");
        exit(1);
    }
    deque->front = NULL;
    deque->prev = NULL;
    return deque;
}

void pushFront(Deque* deque, int data) {
    Deque* newDeque = (Deque*)malloc(sizeof(Deque));
    if (newDeque == NULL) {
        printf("ERROR");
        exit(1);
    }
    newDeque->data = data;
    newDeque->prev = NULL;
    newDeque->front = deque->front;
    
    if (deque->front == NULL) {
        deque->front = newDeque;
        deque->prev = newDeque;
    } else {
        deque->front->prev = newDeque;
        deque->front = newDeque;
    }
}

void pushPrev(Deque* deque, int data) {
    Deque* newDeque = (Deque*)malloc(sizeof(Deque));
    if (newDeque == NULL) {
        printf("ERROR");
        exit(1);
    }
    newDeque->data = data;
    newDeque->prev = deque->prev;
    newDeque->front = NULL;
    
    if (deque->front == NULL) {
        deque->front = newDeque;
        deque->prev = newDeque;
    } else {
        deque->prev->front = newDeque;
        deque->prev = newDeque;
    }
}

int popFront(Deque* deque) {
    if (deque->front == NULL) {
        printf("ERROR");
        exit(1);
    }
    int data = deque->front->data;
    Deque* temp = deque->front;
    deque->front = deque->front->front;
    
    if (deque->front == NULL) {
        deque->prev = NULL;
    } else {
        deque->front->prev = NULL;
    }
    
    free(temp);
    return data;
}

int popPrev(Deque* deque) {
    if (deque->front == NULL) {
        printf("ERROR");
        exit(1);
    }
    int data = deque->prev->data;
    Deque* temp = deque->prev;
    deque->prev = deque->prev->prev;
    
    if (deque->prev == NULL)
        deque->front = NULL;
    else 
        deque->prev->front = NULL;
    
    free(temp);
    return data;
}

void freeDeq(Deque* deque) {
    while (!(deque->front == NULL))
        popFront(deque);
    free(deque);
}

int main() {
    Deque* deque = createNewDeque();
    
    pushFront(deque, 3);
    pushFront(deque, 2);
    pushPrev(deque, 4);
    pushFront(deque, 5);
    pushFront(deque, 1);
    pushPrev(deque, 7);

    printf("Element on front %d\n", popFront(deque));
    printf("Element on back %d\n", popPrev(deque));
    
    freeDeq(deque);
    
    return 0;
}