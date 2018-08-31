#include <stdio.h>
#include <stdlib.h>

typedef struct speople{
    int id;
    char name[80];
}People;

//void insertSorted(People* vetor,int size);
void selectionSort(People* vetor, int size);

int main(){
    People people[5];
    People a = {65,"Victor"};
    people[0] = a;
    People b = {75,"Lima"};
    people[1] = b;

    People c = {43,"Victor"};
    people[2] = c;
    People d = {20,"Lima2"};
    people[3] = d;
    People e = {9,"Oliveira"};
    people[4] = e; 

    //insertSorted(people,5);
    
    //bubbleSort(people,5);
    
    selectionSort(people,5);

    for(int i = 0;i < 5;i++){
        printf("ID: %d - NAME: %s\n",people[i].id,people[i].name);
    }


    return 0;
}

// Select sort e bubble sort O(n^2)

void selectionSort(People* vetor, int size){
    int i,j;
    int less;
    People aux;
    for(i = 0;i < size;i++){
        less = i;
        for(j = i+1; j < size;j++){
            if(vetor[j].id < vetor[less].id){
                less = j;
            }
        }
        if(i != less){
            //Swap
            aux = vetor[i];
            vetor[i] = vetor[less];
            vetor[less] = aux;
        }
    }
}
