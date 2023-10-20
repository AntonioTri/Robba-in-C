#include <stdio.h>

int fattoriale_iterativo(int [], int);
int fattoriale_DI(int [], int , int);


int main ( ){

    int n=10, i, a[10]={1,2,3,4,5,6,7,8,9,10};

        printf("L'array e': \n");

    for ( i = 0; i < n; i++)
    {
        printf("%d ", a[i]);

    }

    i=0;

     printf("\n\n");
     printf("Il fattoriale iterativo/DI e':\n");
     printf("%d", fattoriale_DI(a, i, n));
     
}


//funzione fattoriale iterativo
int fattoriale_iterativo(int a[], int n){


    if (n==1)
    {
        return a[0];
    } else {
        
        return a[n-1]*fattoriale_iterativo(a, n-1);

    }
    
}

//funzione fattoriale divide et impera
int fattoriale_DI(int a[], int primo, int ultimo){

    int mediano;

    if (primo==ultimo)
        {
            return a[primo];
        } else {

            mediano = (primo+ultimo)/2;
            return fattoriale_DI(a, primo, mediano)*fattoriale_DI(a, mediano+1, ultimo);


        }


}


