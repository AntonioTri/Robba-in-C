//Scrivere una funzione in c che restituisce il secondo elemeno piu' grande

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

int main (){

    int a[10];
    int n=SIZE; 
    int i;
    //int sec_max;
    srand(time(NULL));

    for ( i = 0; i < SIZE; i++)
    {
        a[i]= rand() % 31;
    } i=0;
    printf("L'array e':\n");
    for ( i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nIl secondo massimo e' %d\n", scnd_max(a, n));

}


int scnd_max(int a[], int n){

    int i;
    int massimo;
    int sec_max;

    if (a[0]>a[1])
    {
        massimo=a[0];
        sec_max=a[1];
    } else
        {
            massimo=a[1];
            sec_max=a[0];
        }
    
    for ( i = 2; i < n; i++)
    {
        if (a[i]>massimo)
        {

            sec_max=massimo;
            massimo=a[i];

        }else if(a[i]>sec_max)

			sec_max=a[i];
        
    }

    return sec_max;

}

