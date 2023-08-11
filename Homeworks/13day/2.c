#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define COUNT 5
typedef struct Book{
    char title[20];
    char author[20];
    int pages;
    float price;
    struct Book *next;
}Book;
void insert(Book **ptr, Book in) {
    Book *new = malloc(sizeof(Book));
    *new = in;
    new->next = NULL;

    Book *prev = NULL;
    Book *current = *ptr;

    while (current != NULL) {
        int i = 0;
        while (tolower(current->title[i]) == tolower(in.title[i]))
            i++;

        if (tolower(current->title[i]) > tolower(in.title[i]))
            break;

        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        new->next = *ptr;
        *ptr = new;
    } else {
        prev->next = new;
        new->next = current;
    }
}

void print(Book *begin){
    while(begin!=NULL){
        printf("%s %s %d %f\n",begin->title,begin->author,begin->pages,begin->price);
        Book *help=begin;
        begin=help->next;
        free(help);
    }
}
int main(void){
    Book *begin=NULL;
    Book help;
    for(int i=0;i<COUNT;i++){
        int j;
        for(j=0;j<19;j++){
            if(rand()%2)
                help.title[j]='a'+rand()%('z'-'a');
            else 
                help.title[j]='A'+rand()%('Z'-'A');
        }
        help.title[j]='\0';
        for(j=0;j<19;j++){
            if(rand()%2)
                help.author[j]='a'+rand()%('z'-'a');
            else 
                help.author[j]='A'+rand()%('Z'-'A');
        }
        help.author[j]='\0';
        help.pages=5+rand()%1995;
        help.price=1+rand()%99999/100.;
        if(i==0){
            begin=malloc(sizeof(Book));
            help.next=NULL;
            *begin=help;
        }
        else       
            insert(&begin,help);
    }
    print(begin);
    return 0;
}
