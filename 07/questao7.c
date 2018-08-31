#include <stdio.h>
#include <stdlib.h>

typedef struct speople{
    int id;
    char name[80];
}People;

void insertSorted(People* vetor,int size);

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

    insertSorted(people,5);
    
    //bubbleSort(people,5);
    
    for(int i = 0;i < 5;i++){
        printf("ID: %d - NAME: %s\n",people[i].id,people[i].name);
    }


    return 0;
}

// O(n) quando a lista esta ordenada
// O(n^2) quando esta desordenada

void insertSorted(People* vetor,int size){
    int i,j;
    People aux;
    for(i = 1; i < size;i++){
        aux = vetor[i];
        j = i -1;
        while(j >= 0 && aux.id < vetor[j].id){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = aux;
    }
}
