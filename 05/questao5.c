#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int idade;
    char nome[80];
}Pessoa;

typedef struct{
    int count, maxSize;
    Pessoa** items;
}HashTable;


int calcHash(int size, int key){
    return ((key & 0x7FFFFFFF)%size);
}

HashTable* newHashTable(int size){
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->count =0;
    table->maxSize = size;
    table->items = (Pessoa**)calloc(table->maxSize,sizeof(Pessoa*));
    return table;
}

int stringValue(char* str){
    int i, valor = 7;
    int tam = strlen(str);
    for(i =0;i < tam;i++){
        valor = 31 * valor + (int)str[i];
    }
    return valor;
}

void deleteHashTable(HashTable* table){
    if(table != NULL){
        int i;
        for(i = 0; i < table->maxSize;i++){
            free(table->items[i]);
        }
        free(table->items);
        free(table);
    }
}

int insertInHash(HashTable* table, char* key, Pessoa value){
    int pos = calcHash(table->maxSize,stringValue(key));
    if(table != NULL){
        Pessoa* newPerson = (Pessoa*)malloc(sizeof(Pessoa));
        *newPerson = value;
        table->items[pos] = newPerson;
        table->count++;
        return 1;
    }else{
        return 0;
    }
}

Pessoa findByKey(HashTable* table, char* key){
    int pos = calcHash(table->maxSize,stringValue(key));
    Pessoa p;
    if(table->items[pos] != NULL){
        p.idade = table->items[pos]->idade;
        strcpy(p.nome, table->items[pos]->nome);
        return p;
    }else{
        strcpy(p.nome,NULL);
        p.idade = -1;
        return p;
    }
}

int main(){
    HashTable* myTable = newHashTable(157);
    //deleteHashTable(myTable);

    Pessoa p = {19,"Victor Lima"};
    insertInHash(myTable,"Victor",p);
    printf("\n %d - %s \n",findByKey(myTable,"Victor").idade,findByKey(myTable,"Victor").nome);

    return 0;
}