#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node;
struct Node *begin=NULL;
void addElement(int data_){
    if(begin==NULL){
        begin=(Node *)malloc(sizeof(Node));
        begin->data=data_;
        begin->next=begin;
    }
    else{
        Node *p=(Node *)malloc(sizeof(Node));
        p->data=data_;
        Node *c;
        for(c=begin->next;c->next!=begin;c=c->next);
        c->next=p;
        p->next=begin;
    }
}
void deleteList(void) {
    if (begin == NULL) {
        return;
    }
    Node *c = begin->next;
    while (c != begin) {
        Node *t = c;
        c = c->next;
        free(t);
    }
    free(begin);
    begin = NULL;  
}
void print(struct Node *cll){
    printf("%d ",cll->data);
    for(Node *c=cll->next;c!=cll;c=c->next){
        printf("%d ",c->data);
    }
}
struct Node* insertAfter(struct Node *cll, int skipCount, int newElem){
    Node *p=cll;
    for(int i=0;i<skipCount-1;i++)
        p=p->next;
    Node *help=p->next;
    p=p->next;
    p=(Node *)malloc(sizeof(Node));
    p->data=newElem;
    p->next=help;
    return p;
}
int main(int argc, char** argv){
    int n=atoi(argv[1]);
    if(argc-1!=n) printf("Error");
    for(int i=0;i<n;i++){
        addElement(atoi(argv[i+2]));
    }
    Node *t=begin;
    insertAfter(t, 2, 5);
    print(t);
    deleteList();
    return 0;
}