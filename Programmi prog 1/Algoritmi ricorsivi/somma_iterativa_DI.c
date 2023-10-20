#include <stdio.h>

int somma_ricorsiva(int [], int );
int somma_DI(int [], int , int);


int main ( ){

    int n=10, somma, i, a[11]={1,2,3,4,5,6,7,8,9,10};

        printf("L'array e': \n");

    for ( i = 0; i < n; i++)
    {
        printf("%d ", a[i]);

    }

    i=0;

     printf("\n\n");
     printf("La somma ricorsiva/DI e':\n");
     printf("%d", somma_DI(a, i, n));
     
}


//funzione somma itertiva [][][][][][][][][][][]
int somma_ricorsiva(int a[], int n){

    if (n==1)
    {
    return a[0];
    
    } else
    return a[n-1]+somma_ricorsiva(a, n-1);
    
    //somma_ricorsiva(a[]);
}

//funzione somma divide et impera
int somma_DI(int a[], int primo, int ultimo ){

    int mediano;

    if (primo==ultimo)
    {
        return a[primo];

    } else {

      mediano = (primo+ultimo)/2;
      return (somma_DI(a, primo, mediano) + somma_DI(a, mediano+1, ultimo));   	

    }
    
}

