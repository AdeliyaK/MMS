#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define COUNT 5
typedef struct{
    char Title[150];
    char Author[100];
    int NumberOfPages;
    float price;
}Book;
int ASDAuthor(const void *c,const void *d){
    Book *a=c,*b=d;
    int i;
    for(i=0;a->Author[i]==b->Author[i];i++)
        if(!a->Author[i])
            return a->Author[i]==a->Author[i];
    return tolower(a->Author[i])-tolower(b->Author[i]);
}
int DESCAuthor(const void *c,const void *d){
    Book *a=c,*b=d;
    int i;
    for(i=0;a->Author[i]==b->Author[i];i++)
        if(!a->Author[i])
            return a->Author[i]==a->Author[i];
    return b->Author[i]<a->Author[i];
}
int ASDTitle(const void *c,const void *d){
    Book *a=c,*b=d;
    int i;
    for(i=0;a->Author[i]==b->Author[i];i++)
        if(!a->Author[i])
            return a->Author[i]==a->Author[i];
    return tolower(a->Author[i])-tolower(b->Author[i]);
}
int DESTitle(const void *c,const void *d){
    Book *a=c,*b=d;
    int i;
    for(i=0;a->Author[i]==b->Author[i];i++)
        if(!a->Author[i])
            return a->Author[i]==a->Author[i];
    return tolower(b->Author[i])-tolower(a->Author[i]);
}
int ASDNumberOfPages(const void *c,const void *d){
    Book *a=c,*b=d;
    return a->NumberOfPages-b->NumberOfPages;
}

int DESNumberOfPages(const void *c,const void *d){
    Book *a=c,*b=d;
    return b->NumberOfPages-a->NumberOfPages;
}
int ASDPrice(const void *c,const void *d){
    Book *a=c,*b=d;
    return a->price-b->price;
}

int DESPrice(const void *c,const void *d){
    Book *a=c,*b=d;
    return b->price-a->price;
}
int main(void){
    Book array[COUNT];
    for(int i=0;i<COUNT;i++){
        int z=10+rand()%10;
        int j;
        for(j=0;j<z;j++){
            if(rand()%2)
                array[i].Title[j]='A'+rand()%('Z'-'A');
            else 
                array[i].Title[j]='a'+rand()%('z'-'a');
        }
        array[i].Title[j]='\0';
        z=10+rand()%10;
        for(j=0;j<z;j++){
            if(rand()%2)
                array[i].Author[j]='A'+rand()%('Z'-'A');
            else 
                array[i].Author[j]='a'+rand()%('z'-'a');
        }
        array[i].Author[j]='\0';
        array[i].NumberOfPages=5+rand()%1995;
        array[i].price=(100+rand()%100000)/100.;
    }
    qsort(array,COUNT,sizeof(Book),DESCAuthor);
    for(int i=0;i<COUNT;i++){
        printf("%s %s %d %.2f\n",array[i].Author,array[i].Title,array[i].NumberOfPages,array[i].price);
    }
    return 0;
}