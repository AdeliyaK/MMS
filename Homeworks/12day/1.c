#include<stdio.h>
//#include<conio.h>
#include<time.h>
#include <stdarg.h>
void time_print(const char *f,...){
    va_list args;
    va_start(args,f);
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("[%d.%d.%d - %d:%d:%d]\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min,tm.tm_sec);
    vprintf(f,args);
    va_end(args);
    
}
int main()
{
    time_print("%d %d",10,20);
    return 0;
}