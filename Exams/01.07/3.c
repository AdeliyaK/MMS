#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int comp(char A[]){
    if(A[0]=='0'){
        if(A[1]=='x' || A[1]=='X')
            return 1;
        else 
            return 2;
    }
    for(int i=0;A[i];i++){
        if(A[i]=='.')
            return 3;
    }
    return 4;
}
int main(int argc, char *argv[]){
    double *A=malloc(sizeof(double)*(argc-1));
    for(int i=1;i<argc;i++){
        int w=comp(argv[i]);
        if(w==1){
            int z;
            sscanf(&(argv[i][2]),"%x",&z);
            A[i-1]=z;
        }
        else if(w==2){
            int z;
            sscanf(&(argv[i][1]),"%o",&z);
            A[i-1]=z;
        }
        else if(w==3){
            A[i-1]=atof(argv[i]);
        }
        else if(w==4){
            A[i-1]=atoi(argv[i]);
        }
    }
    double sum=0;
    for(int i=0;i<(argc-1);i++){
        sum+=A[i];
    }
    printf("%.2lf",sum);
    free(A);
}