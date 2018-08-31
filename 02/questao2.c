#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct speople{
    int id;
    char name[80];
    struct speople* next;
}People;

typedef struct slist{
    int counter;
    People* first;
}List;

List* newList();
void addName(People data, List* list);
void listPeoples(List* list);
People* findNameById(List* list, int id);

int main(){

    List* l = newList();
    People p = {10,"Victor Lima"};
    addName(p,l);
    People d = {10,"Oscar"};
    addName(d,l);

    People a = {10,"Lima"};
    addName(a,l);
    People b = {10,"Jailson"};
    addName(b,l);

    //listPeoples(l);

    People* result = findNameById(l,2);
    printf("ID: %d - NAME: %s\n",result->id,result->name);

    return 0;
}

List* newList(){
    List* list = (List*)malloc(sizeof(List));
    list->counter = 0;
    list->first = NULL;
    return list;
}


void addName(People data, List* list){
    // Alocando elemento
    People* allocatedData = (People*)malloc(sizeof(People));
    allocatedData->id = list->counter;
    strcpy(allocatedData->name,data.name);
    allocatedData->next = NULL;
    
    if(list->first == NULL){
        list->first = allocatedData;
    }else if(list->first != NULL && list->first->next == NULL){
        list->first->next = allocatedData;
    }else{
        People* tempElement = list->first;
        People* lastElement = list->first;
        while(tempElement != NULL){
            lastElement = tempElement;
            tempElement = tempElement->next;
        }
        lastElement->next = allocatedData;
    }

    list->counter++;
}

void listPeoples(List* list){
        People* tempElement = list->first;
        while(tempElement != NULL){
            printf("ID: %d - Nome: %s\n",tempElement->id,tempElement->name);
            tempElement = tempElement->next;
        }
}

People* findNameById(List* list, int id)
{
    People* tempElement = list->first;
    while(tempElement != NULL){
        if(tempElement->id == id){
            return tempElement;
        }
        tempElement = tempElement->next;
    }
    
    return NULL;
}