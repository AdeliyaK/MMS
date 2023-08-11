#include <stdio.h>
#include <stdlib.h>
int main(void){
    int n,m,p;
    scanf("%d",&n);
    float *ptr=malloc(sizeof(float)*n);
    for(int i=0;i<n;i++){
        ptr[i]=(rand()%10)/10.;
    }
    scanf("%d",&m);
    ptr=realloc(ptr,sizeof(float)*(n+m));
    for(int i=n;i<(m+n);i++){
        ptr[i]=1+(rand()%10)/10.;
    }
    scanf("%d",&p);
    ptr=realloc(ptr,sizeof(float)*(n+m+p));
    for(int i=n+m;i<(p+n+m);i++){
        ptr[i]=2+(rand()%10)/10.;
    }
    for(int i=0;i<(p+m+n);i++)
        printf("%.1f ",ptr[i]);
    free(ptr);
    return 0;
}