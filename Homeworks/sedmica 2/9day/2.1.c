#include <stdio.h>
#include <math.h>
typedef struct Point {
    double x;
    double y;
    double z;
} Point;
void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*)){
    int max=0;
    for(int i=1;i<n;i++){
        if(cmp(arr+max*elem_s,arr+i*elem_s)==1)
            max=i;
    }
    return arr+max*elem_s;
}
int pointsCmp(void *a1,void *a2){
    Point *fp=a1,*sp=a2;
    double fDis,sDis;
    fDis=sqrt(fp->x*fp->x+fp->y*fp->y);
    fDis=sqrt(fp->z*fp->z+fDis*fDis);
    sDis=sqrt(sp->x*sp->x+sp->y*sp->y);
    sDis=sqrt(sp->z*sp->z+sDis*sDis);
    return fDis>sDis;
}
int main(void){
    Point A[]={{0,0,1},{1,2,3},{1,4,6}};
    Point *p=findMax(A,sizeof(A)/sizeof(A[0]),sizeof(Point),pointsCmp);
    printf("%f %f %f",p->x,p->y,p->z);
    return 0;
}