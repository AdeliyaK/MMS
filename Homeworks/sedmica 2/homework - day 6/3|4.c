#include <stdio.h>
void filter_and_map(const int arr[],size_t n,int (*filter_f)(int),int (*map_f)(int),int dest[],size_t* dest_cnt){
    *dest_cnt=0;
    for(int i=0;i<n;i++)
        if(filter_f(arr[i])){
            dest[*dest_cnt]=map_f(arr[i]);
            (*dest_cnt)++;
        }
}

int isPositive(int a){
    if(a<0)
        return 0;
    else 
        return 1;
}

int isNegative(int a){
    if(a<0)
        return 1;
    else 
        return 0;
}
int addOne(int a){
    return a+1;
}
int odd(int a){
    return !(a%2);
}
int returnNum(int a){return a;}
int isSimple(int a){
    for(int i=a-1;i>1;i++)
        if(!(a%i))
            return 0;
    return 1;
}
int powByTwo(int a){
    return a*a;
}
int howManyOnes(int a){
    int n=0;
    for(int i=0;i<(sizeof(a)*8);i++)
        if(a&(1<<i))
            n++;
    return n;
}
int main(void){
    int arr[8]={1,2,3,4,-1,-2,11,-100};
    int dest[10];
    size_t new_size;
    // filter_and_map(arr,8,isPositive,addOne,dest,&new_size);      //- зад 3
    // filter_and_map(arr,8,odd,returnNum,dest,&new_size);          //- зад 4а
    // filter_and_map(arr,8,isSimple,powByTwo,dest,&new_size);      //- зад 4б
    filter_and_map(arr,8,isNegative,howManyOnes,dest,&new_size);    //- зад 4в
    for(int i=0;i<new_size;i++)
        printf("%d\t",dest[i]);
}