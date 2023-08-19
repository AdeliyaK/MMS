#include <stdio.h>
#define MAX(x,y,z) (x<y && z<y)?(y):(x<z && y<z)?(z):(y)
#define MIN(x,y,z) (x>y && z>y)?(y):(x>z && y>z)?(z):(y)
#define SETBIT(mask,bit) (mask|(1ULL<<bit))?(1):(0)
#define CLEARBIT(mask,bit) mask&~(1ULL<<bit)
#define INVERSEBIT(mask,bit) mask^=(1ULL<<bit)
#define CHECKBIT(mask,bit) (mask&(1ULL<<bit))?(1):(0)
#define SWAP(a,b) int c=a;a=b;b=c
int main(void){
    int a=5,b=2;
    SWAP(a,b);
    printf("%d %d",a,b);
}

