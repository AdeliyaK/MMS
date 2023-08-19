#include <stdio.h>
#include <stdlib.h>
#define ID_LEN 10
typedef struct{
    char name[100];
    char id[ID_LEN];
    int birthYear : 2;
    int birthMonth : 1;
    int birthDay : 1;
    char gender;
}Person;
void *initArray(size_t capacity){
    void *ptr=malloc(sizeof(Person)*capacity);
    return ptr;
}
int addPerson(char *name, unsigned short birthYear, unsigned char birthDay, char gender, Person *ptr){
    for(int i=0;name[i];i++)
        ptr->name[i]=name[i];
    ptr->birthYear=birthYear;
    ptr->birthDay=birthDay;
    ptr->gender=gender;
    for(int i=0;i<ID_LEN;i++){
        if(rand()%2)
            ptr->id[i]='A'+rand()%('Z'-'A');
        else
            ptr->id[i]='a'+rand()%('z'-'a');
    }
    return 0;
}
int removePerson(char *id,Person *ptr,int n){
    for(int i=0;i<n;i++){
        int j;
        for(j=0;ptr[i].id[j]==id[j];j++);
        if(!id[j]){
            ptr[i].birthDay=0;
            ptr[i].birthMonth=0;
            ptr[i].birthYear=0;
            ptr[i].gender=0;
            ptr[i].name[0]='\0';
            ptr[i].id[0]='\0';
            return 0;
        }
    }
    return -1;
}
int printPerson(char *id,Person *ptr, int n){
    for(int i=0;i<n;i++){
        int j;
        for(j=0;ptr[i].id[j]==id[j];j++);
        if(!id[j]){
            printf("%s %s %d.%d.%d",ptr->name,ptr->id,ptr->birthDay,ptr->birthMonth,ptr->birthYear);
            return 0;
        }
    }
    return -1;
}
int main(void){
    
    return 0;
}