#include <stdio.h>
double diff(double n,double mid,double *start, double *end)
{
    if (n > (mid*mid*mid)){
        *start=mid;
        return (n-(mid*mid*mid));
    }
    else{
        *end=mid;
        return ((mid*mid*mid) - n);
    }
}
double cubicRoot(double n) { // - използваме двоично търсене
    double start = 0, end = n; // - задаване начало и край на търсения резултат
    double e = 0.0001; // - до каква точност искаме резултата
 
    while (1) {
        double mid = (start + end)/2;
        double error = diff(n, mid,&start,&end);
        if (error <= e)
            return mid;
 
    }
}
 
// Driver code
int main()
{
    double n ;
    printf("Enter the number: ");
    scanf("%lf",&n);
    printf("Cubic root of %.4lf is %.4lf\n",n, cubicRoot(n));
    return 0;
}