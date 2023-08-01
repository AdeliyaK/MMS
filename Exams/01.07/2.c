#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char model[20];
    uint8_t maxspeed;
    double price;
}Car;
int CompareAscendingByModel(const void *c,const void *d){
    int i;
    const Car *a=c,*b=d;
    for(i=0;a->model[i]==b->model[i];i++);
    if(strlen(a->model)<i && strlen(b->model)<i)
        return a->model[0]==a->model[0];
    return a->model[i]-b->model[i];
}
int CompareDescendingByModel(const void *c,const void *d){
    int i;
    const Car *a=c,*b=d;
    for(i=0;a->model[i]==b->model[i];i++);
    if(strlen(a->model)<i && strlen(b->model)<i)
        return a->model[0]==a->model[0];
    return b->model[i]-a->model[i];
}
int MaxSpeedAscending(const void *c,const void *d){
    const Car *a=c,*b=d;
    return a->maxspeed-b->maxspeed;
}
int MaxSpeedDescending(const void *c,const void *d){
    const Car *a=c,*b=d;
    return b->maxspeed-a->maxspeed;
}
int PriceDescending(const void *c,const void *d){
    const Car *a=c,*b=d;
    return a->price-b->price;
}
int PriceAscending(const void *c,const void *d){
    const Car *a=c,*b=d;
    return (b->price)-(a->price);
}
int (*getComparator(int n))(const void*, const void*){
    switch (n) {
    case 1:
        return &CompareAscendingByModel;
    case 2:
        return &CompareDescendingByModel;
    case 3:
        return &MaxSpeedAscending;
    case 4:
        return &MaxSpeedDescending;
    case 5:
        return &PriceAscending;
    case 6:
        return &PriceDescending;
    default:
        return NULL;
    }
}
int main(void){
    Car arr[10];
    for(int i=0;i<10;i++){
        for(int j=0;j<19;j++){
            int z=rand()%3;
            if(z==0)
                arr[i].model[j]='A'+rand()%('Z'-'A');
            else if(z==1)
                arr[i].model[j]='a'+rand()%('z'-'a');
            else if(z==2)
                arr[i].model[j]='3'+rand()%('9'-'3')+1;
        }
        arr[i].model[19]='\0';
        arr[i].maxspeed=100+rand()%200;
        arr[i].price=1000+(rand()%9900000/100.);
    }
    int s;
    scanf("%d",&s);
    qsort(arr, sizeof(arr)/sizeof(arr[0]),sizeof(arr[0]),getComparator(s));
    for(int i=0;i<10;i++){
        printf("%s\t",arr[i].model);
        printf("%d\t",arr[i].maxspeed);
        printf("%lf\n",arr[i].price);
    }
    return 0;
}