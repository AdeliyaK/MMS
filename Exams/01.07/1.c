#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *func(char *A,int n){
    char *newArray=malloc(sizeof(char)*n+1);
    int i;
    for(i=0;A[i];i++){
        if(!(i%2))
            newArray[i]=A[i]+'A'-'0';
        else 
            switch (A[i])
            {
            case '0':
                newArray[i]='!';
                break;
            case '1':
                newArray[i]='#';
                break;
            case '2':
                newArray[i]='/';
                break;
            case '3':
                newArray[i]='~';
                break;
            case '4':
                newArray[i]='=';
                break;
            case '5':
                newArray[i]='`';
                break;
            case '6':
                newArray[i]='\\';
                break;
            case '7':
                newArray[i]='>';
            case '8':
                newArray[i]='.';
            case '9':
                newArray[i]=',';
            default:
                break;
            }
    }
    newArray[i]='\0';
    return newArray;
}
int main(void){
    char A[500];
    scanf("%s",A);
    char *a=func(A,strlen(A)+1);
    printf("%s",a);
    free(a);
    return 0;
}