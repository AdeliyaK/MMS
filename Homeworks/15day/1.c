#include <stdio.h>

#define LeftShift(value,shift) ((int)value>> (shift-1))


void printbits(void *value, unsigned int size)
{
    unsigned long *var = (unsigned long *) value;
    
    printf("bit%lx\n",*var);

    for(unsigned int i=0; i < size; i++)
    {

        if(i==52)
            putchar('\n');
        if(i==(size-1))
            putchar('\n');
        printf("bit%d=%ld ",i,(*var&1));
        
        
        *var >>=1;
    }
    putchar('\n');

    

}




void main (void)
{

    unsigned int sign, exponent, mantis;
    double value;
    char b;
    int size=32;



    while(1)
    {
        printf("Enter value: ");
        scanf("%lf",&value);
        // scanf("%d",&b);

        printbits(&value, sizeof(value)*8 );
        // printbits(&b, sizeof(b)*8 );

    }



    printf("Double - %ld\nFload - %ld\n",sizeof(double),sizeof(float));





}