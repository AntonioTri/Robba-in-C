#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ricerca_massimo_DI(int [], int, int);

int main (){

    int  i, massimo, a[10], n = sizeof(a)/sizeof(a[0]);
    srand(time(0));

    for ( i = 0; i < n; i++)
    {
        a[i]=rand()%11;
    } 
    
    i=0;

    printf("L'array e': \n");
    for ( i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    } 

     printf("\n\n");
     i=0;

    massimo = ricerca_massimo_DI(a, i, n-1);

    printf("L'elemento massimo dell'array e': %d\n", massimo);

    
}

int ricerca_massimo_DI(int a[], int primo, int ultimo){

        int mediano;

        if ( primo == ultimo )
        {
            return a[ultimo];
        } else
        {
            mediano=(primo+ultimo)/2;

            int massimo_dx = ricerca_massimo_DI(a, primo, mediano);
            int massimo_sx = ricerca_massimo_DI(a, mediano+1, ultimo);

            if (massimo_dx>=massimo_sx)
                 return massimo_dx;
             else 
                 return massimo_sx;
            
            
        }
        
        
}


