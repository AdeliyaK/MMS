#include <stdio.h>
#include <stdarg.h>
int my_printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int count = 0;
    char c;
    int i;
    for(i=0;fmt[i];i++) {
        c=fmt[i];
        if (c == '%') {
            c=fmt[++i];
            switch (c) {
                case 'd': 
                    vprintf("%d", args);
                    count++;
                    break;
                case 'f': 
                    vprintf("%f", args);
                    break;
                case 'c': 
                    vprintf("%c",args);
                    break;
                case '%':
                    putchar('%');
                    break;
                case 's':
                    vprintf("%s",args);
                    break;
                default:
                    break;
            }
        } else {
            putchar(c);
        }
    }

    va_end(args);
}

int main() {
    int num = 100;
    double dbl = 3.14;
    char ch = 'A';
    char A[10]="string";
    my_printf("Print iNt: %d\nPrint double: %f\nPrint character: %c\nPrint string: %s\nPrint percent: %%\n", num, dbl, ch, A);
    return 0;
}