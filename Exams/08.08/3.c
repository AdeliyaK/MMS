#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct {
    double old_price;       //8
    double new_price;       //8
    unsigned int id;        //4
    char product_type;      //1
    char product_name[11];   //11
}Product;
void ProductPrint(Product arr[]){
    for(int i=0;i<40;i++){
        printf("%.2lf %.2lf %s %c %d\n",arr[i].old_price,arr[i].new_price,arr[i].product_name,arr[i].product_type,arr[i].id);
    }
}
int funcBySort(const void *c,const void *d) {
    const Product *a = (const Product *)c;
    const Product *b = (const Product *)d;
    double diff = (a->new_price - a->old_price) - (b->new_price - b->old_price);
    if (fabs(diff)>-0.01) 
        return 1;
    else if (a->product_type != b->product_type) {
            return a->product_type - b->product_type;
    } 
    else {
            int nameDiff = strcmp(a->product_name, b->product_name);
            if (nameDiff != 0) {
                return nameDiff;
            } else {
                return a->id - b->id;
            }
        }   
}
void writeProductsToFile(Product *arr, int size) {
    FILE *file = fopen("Product.bin", "wb");
    fwrite(arr, sizeof(Product), size, file);

    fclose(file);
}
int main(void){
    Product arr[40];
    for(int i=0;i<40;i++){
        arr[i].old_price=4.99+rand()%10045/100.;
        arr[i].new_price=4.99+rand()%10045/100.;
        arr[i].product_type='A'+rand()%('D'-'A'+1);

        for(int i=0;i<40;i++){
            for(int j=0;j<10;j++)
                arr[i].product_name[j]='a'+rand()%('z'-'a');
            arr[i].product_name[10]='\0';
        }
        arr[i].id=rand()%4294967295;
    }
    qsort(arr,40,sizeof(Product),&funcBySort);
    writeProductsToFile(arr,40);
    ProductPrint(arr);
    return 0;
}
