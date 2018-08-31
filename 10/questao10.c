#include <stdio.h>
#include <stdlib.h>

typedef struct speople{
    int id;
    char name[80];
}People;

void shellSort(People* p, int size);

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
    
    shellSort(people,5);

    for(int i = 0;i < 5;i++){
        printf("ID: %d - NAME: %s\n",people[i].id,people[i].name);
    }


    return 0;
}

// Pior caso O(n log n) e heap tb

void shellSort(People* p, int num){
    int i, j, k;
    People tmp;

    for (i = num / 2; i > 0; i = i / 2)

    {

        for (j = i; j < num; j++)

        {

            for(k = j - i; k >= 0; k = k - i)

            {

                if (p[k+i].id >= p[k].id)

                    break;

                else

                {

                    tmp = p[k];

                    p[k] = p[k+i];

                    p[k+i] = tmp;

                }

            }

        }

    }
}
