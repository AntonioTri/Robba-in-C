#include <stdio.h>

void ordin_per_massimo(int [], int );
void ricerca_massimo_indirizzo( int [], int , int *, int *);
void swap (int *, int *);



int main ( ){

    int i, n=15, a[15]={4,2,5,7,1,91,1,1,1,1,10,3,6,8,100};

        printf("L'array e': \n");

    for ( i = 0; i < n; i++)
    {
        printf("%d ", a[i]);

    }

    printf("\n");
    
    ordin_per_massimo(a, n);

    printf("L'array ordinato per massimo e': \n");

    for ( i = 0; i < n; i++)
    {
        printf("%d ", a[i]);

    }
}


//funzione ordinamento per massimo
void ordin_per_massimo(int a[], int n){

    int massimo, indice;

    for(int i=n-1; i>0; i--){

        ricerca_massimo_indirizzo(&a[0], i+1, &massimo, &indice);
        swap(&a[i], &a[indice]);

    }

}

//funzione ricerca massimo e suo indice
void ricerca_massimo_indirizzo( int a[], int n, int *massimo, int *indice){

*massimo=a[0];                                    //[0][1][2][3][4][5][6]
*indice =0;

for(int i=1; i<n; i++){

    if(a[i]>*massimo){
        *massimo=a[i];
        *indice=i;
        
    }
  }
}

//funzione swap
void swap (int *c1, int *c2){

int temp;

temp=*c1;
*c1=*c2;
*c2=temp;

}
