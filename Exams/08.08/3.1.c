#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double old_price;
    double new_price;
    unsigned int id;
    char product_type;
    char product_name[11];
} Product;

void printProductInfo(Product *product) {
    printf("ID: %u\nName: %s\nOld Price: %.2lf\nNew Price: %.2lf\nProduct Type: %c\n", product->id, product->product_name, product->old_price, product->new_price, product->product_type);
}

int main(void) {
    FILE *file = fopen("Product.bin", "rb");
    if (file == NULL) {
        printf("ERROR");
        exit(1);
    }
    Product product;
    while (fread(&product, sizeof(Product), 1, file)) {
        printProductInfo(&product);
        printf("\n");
    }

    fclose(file);
    return 0;
}