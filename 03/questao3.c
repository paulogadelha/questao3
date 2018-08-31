#include <stdio.h>
#include <stdlib.h>

typedef struct speople{
    int id;
    char name[80];
}People;

People* findByIDBinary(People* p,int id,int size);
int main(){

    People people[5];

    People a = {0,"Victor"};
    people[0] = a;
    People b = {1,"Lima"};
    people[1] = b;

    People c = {2,"Victor"};
    people[2] = c;
    People d = {3,"Lima"};
    people[3] = d;
    People e = {4,"Lima2"};
    people[4] = e;

    People* find = findByIDBinary(people,4,5);
    
    printf("ID: %d - NAME: %s\n",find->id,find->name);
    
    return 0;
}
// O(log n)
People* findByIDBinary(People* p,int id,int size){
    int encontrado = 0;
    int inicio = 0;
    int fim = size-1; 
    int meio;
    
    while(inicio <= fim){
        meio = (fim+inicio)/2;
        if(id < p[meio].id){
            fim = meio-1;
        }else if(id > p[meio].id){
            inicio = meio+1;
        }else{
            return &p[meio];
        }
    }    
    return NULL;
}
