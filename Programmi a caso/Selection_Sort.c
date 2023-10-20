#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Selection_Sort(int [], int);
void min_ind(int [], int , int *);
void swap(int *, int *);


int main(){

  //  int *a, num;
  /*
    int *a, num;
    srand(time(NULL));
    char ris;

    do
    {
    
        puts("Quanto lungo lo vuoi?");
        scanf("%d", &num);

        a =(int *) malloc(num * sizeof(int));

        for (int i = 0; i < num; i++)
        {
            a[i] = rand() %num+1;

            printf("[%d] ",a[i]);
        }*/
        char ris;
    do{
        int a[10] = {10,9,8,7,6,5,4,3,2,1};
        int num = 10;

        Selection_Sort(a, num);

        printf("\nl'array ordinato e':\n");

        for (int i = 0; i < num; i++)
        {
             printf("[%d] ",a[i]);
        }
        

        //free(a);


        printf("\n\n vuoi riprovare? (s/n)\n");

        //fflush(stdin);

        scanf("%c", &ris);

    } while (ris == 's');
}



void Selection_Sort(int a[], int num){

    int indice, i;

    for (i = 0; i < num-1; i++)
    {
        min_ind(&a[i], num-i,  &indice);
        swap(&a[i], &a[indice+i]);
    }
    
}

void min_ind(int a[], int size, int *indice){

    int min = a[0];
    *indice = 0;
    int i;

    for (i = 1; i < size; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            *indice = i+1;
        }
    }

}

void swap(int *a, int *b){

    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
