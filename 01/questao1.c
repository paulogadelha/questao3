#include <stdio.h>
#include <stdlib.h>

typedef struct speople{
    int id;
    char name[80];
}People;

People* findByID(People* p,int id,int size);
int main(){
    People people[5];
    People a = {1,"Victor"};
    people[0] = a;
    People b = {2,"Lima"};
    people[1] = b;

    People c = {3,"Victor"};
    people[2] = c;
    People d = {4,"Lima"};
    people[4] = d;

    People* find = findByID(people,2,5);
    
    printf("ID: %d - NAME: %s\n",find->id,find->name);
    
    return 0;
}

People* findByID(People* p,int id,int size){
    int i;
    for(i = 0; i < size;i++){
        if(p[i].id == id){
            return &p[i];
        }
    }
    return NULL;
}