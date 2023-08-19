#include <stdio.h>
#include <stdint.h>
#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT8_T 5
#define TUINT16_T 6
#define UINT32_T 7
#define UINT64_T 8
void printValue(const void *valuePtr, uint8_t flag){
    printf("Value:");
    switch (flag)
    {
    case 1:
        printf("%d",*((int *)valuePtr));
        break;
    case 2:
        printf("%c",*((char *)valuePtr));
        break;
    case 3:
        printf("%lf",*((double *)valuePtr));
        break;
    case 4:
        printf("%f",*((float *)valuePtr));
        break;
    case 5:
        printf("%d",*((uint8_t *)valuePtr));
        break;
    case 6:
        printf("%d",*((uint16_t *)valuePtr));
        break;
    case 7:
        printf("%d",*((uint32_t *)valuePtr));
        break;
    case 8:
        printf("%ld",*((uint64_t *)valuePtr));
        break;
    default:
        break;
    }
    printf("\n");
}
int main(void){
    int num = 23;
    printValue(&num, TINT);
    double num2 = 3.14;
    printValue(&num2, TDOUBLE);
    char symbol = 'A';
    printValue(&symbol, TCHAR);



}