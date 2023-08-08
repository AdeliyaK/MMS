#include <stdio.h>
#include <stdlib.h>
void printHeximal(const unsigned char* data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%x", data[i]);
        putchar(' ');
    }
}

void printBinary(const unsigned char* data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        for (int j = 7; j >= 0; j--) {
            printf("%d",(data[i]&(1<<j)));
        }
        putc(' ',stdout);
    }
}

int main(int argc, char** argv) {
    
    FILE* file = fopen(argv[1], "rb");
    if (!file) {
        fprintf(stderr, "ERROR OPENING\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char* data = (unsigned char*)malloc(fileSize); //заделяне на динамично памет за целия файл
    if (!data) {
        fprintf(stderr, "ERROR DYNAMIC DATA\n");
        return 1;
    }

    fread(data, 1, fileSize, file);
    fclose(file);

    char printMode = argv[2][1];

    if (printMode=='H') {
        printHeximal(data, fileSize);
    } 
    else if (printMode=='B') {
        printBinary(data, fileSize);
    } 
    else {
        fprintf(stderr, "Invalid mode");
        free(data);
        return 1;
    }

    free(data);
    return 0;
}