#include <stdio.h>

void ordinamento_per_minimo(int [], int );
void ricerca_min_val_ind(int [], int , int, int *, int *);
void swap(int *, int *);



int main ( ){

    int i, n=15, a[15]={4,2,5,7,1,91,1,1,1,1,10,3,6,8,100};

        printf("L'array e': \n");

    for ( i = 0; i < n; i++)
    {
        printf("%d ", a[i]);

    }

    printf("\n");

    ordinamento_per_minimo(a, n);

    printf("L'array ordinato per minimi e': \n");

    for ( i = 0; i < n; i++)
    {
        printf("%d ", a[i]);

    }
}


//funzione ordinamento per minimo
void ordinamento_per_minimo(int a[], int n){

    int i, minimo, indice;
    for ( i = 0; i < n; i++)
    {
        ricerca_min_val_ind(a, i, n, &minimo, &indice);
        swap(&a[i], &a[indice]);
    }
}
 
//funzione ricerca minimo e suo indice
void ricerca_min_val_ind(int a[], int n, int size, int *minimo, int *indice){

    int i;
    *minimo= a[n];
    *indice= n;

    for ( i = n; i < size-1; i++)
    {
        if (a[i+1]<*minimo)
        {
            *minimo=a[i+1];
            *indice=i+1;
        }
        
    }
}

//funzione swap
void swap(int *c1, int *c2){
    
    int temp;
    temp=*c1;
    *c1=*c2;
    *c2=temp;

}
