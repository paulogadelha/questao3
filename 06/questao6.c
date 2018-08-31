#include <stdio.h>
#include <stdlib.h>

typedef struct speople{
    int id;
    char name[80];
}People;

void bubbleSort(People* vetor,int size);

int main(){
    People people[5];
    People a = {120,"Victor"};
    people[0] = a;
    People b = {-1,"Lima"};
    people[1] = b;

    People c = {-92,"Victor"};
    people[2] = c;
    People d = {56,"Lima2"};
    people[3] = d;
    People e = {-342,"Oliveira"};
    people[4] = e;

    bubbleSort(people,5);

    for(int i = 0;i < 5;i++){
        printf("ID: %d - NAME: %s\n",people[i].id,people[i].name);
    }
    
    return 0;
}

void bubbleSort(People* vetor,int size){
    int i;
    int j;
    People aux;
    for(i = 0; i < (size-1);i++){
        for(j = 0; j < (size-1);j++){
            if(vetor[j].id > vetor[j+1].id){
               People aux = vetor[j];
               vetor[j] = vetor[j+1];
               vetor[j+1] = aux; 
            }
        }
    }
}