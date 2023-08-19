#include <stdio.h>
#include <stdint.h>
#include <math.h>
typedef union {
    int64_t f;
    double s;
}Vdouble;
typedef struct {
    int sign : 1;
    unsigned int exponent;
    int64_t mantisa;
}PiecesOfDouble;

void PrintBits(const Vdouble a){
    for(int i=8*8-1;i>-1;i--){
        if(!!(a.f&(1ULL<<i))){
            printf("1");
        }
        else 
            printf("0");
    }
}
void printDec(const Vdouble a){
    PiecesOfDouble b;
    b.exponent=0;
    b.mantisa=0;
    for(int i=63;i>-1;i--){
        if(i==63)
            b.sign=!!(a.f&(1ULL<<i));
        else if(i>51)
            b.exponent+=((a.f&(1ULL<<i))>>52);
        else 
            b.mantisa+=(a.f&(1ULL<<i));
    }
    printf("%d %d %ld",b.sign,b.exponent,b.mantisa);
}
int main(void){
    Vdouble a;
    a.s=3.14;
    PrintBits(a);
    printf("\n");
    printDec(a);
}