#include <stdio.h>
#include <stdint.h>
void swapBytes(uint16_t *word){
    uint16_t help=*word;
    //char a=(char) help;
    *word=help<<8;
    *word+=(help>>8);
}
int main(void){
    uint16_t a=32770;
    printf("%d\n",a);
    swapBytes(&a);
    printf("%d",a);
    return 0;
}