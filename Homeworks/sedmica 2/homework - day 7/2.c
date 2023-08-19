#include <stdio.h>
int sum(int a,int b){
    return a+b;
}
int multi(int a,int b){
    return a*b;
}
int root(int a,int b){
    int r=1;
    for(int i=0;i<b;i++)
        r*=a;
    return r;
}
int atoi(char *str,int *i){
    int a=0;
    while(*(str+*i)>='0' && *(str+*i)<='9'){
        a*=10;
        a+=(*(str+*i)-'0');
        (*i)++;
    }
    return a;
}
int res(char *str){
    int a,b;
    char c;
    static int i=0;
    i++;
    if(str[i]=='(')
        a=res(str);
    else 
        a=atoi(str,&i);
    c=str[i++];
    if(str[i]=='(')
        b=res(str);
    else 
        b=atoi(str,&i);
    if(c=='+'){
        i++;
        return sum(a,b);
    }
    else if (c=='*'){
        i++;
        return multi(a,b);
    }
    else if (c=='^'){
        i++;
        return root(a,b);
    }
    
}
int main(void){
    char A[100];
    scanf("%s",A);
    printf("%d",res(A));
    return 0;
}