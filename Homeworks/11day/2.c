#include <stdio.h>
#include <stdlib.h>
int main(void){
    char A[50];
    gets(A);
    int a,b;
    a=atoi(&A[0]);
    char c;
    for(int i=2;A[i];i++){
        while(A[i]==' ') i++;
        b=atoi(&A[i]);
        i++;
        while(A[i]==' ') i++;
        c=A[i];
        switch (c)
        {
        case '+':
            a+=b;
            break;
        case '-':
            a-=b;
            break;
        case '*':
            a*=b;
            break;
        case '/':
            a/=b;
            break;
        default:
            break;
        }
        i++;
    }
    printf("%d",a);
}