/* Questo algoritmo si pone come obbiettivo quello di fondere due array ordinati in un unico aray la cui dimensione size_c é al piú 
    size_a + size+b, l'idea di base dell'algoritmo é quella di confrontare ad ogni passo l'elemento di indice i_a con l'elemento di 
    indice i_b ed inserire il minore dei due nell'indice i_c dell'array fusione c[], successivamente incrementare gli indici i_c e l'indice
    dell'array di appartenenza dell'elemento inserito. Ció avverrá fin quando uno dei due array non finirá gli elementi da inserire, in questo 
    caso basterá inserire gli elementi rimanenti dell'altro array all'interno dell'array fusione per completare l'algoritmo
    
    
    la complessitá di spazio di questo algoritmo datoche non lavora in place, é al piú 2n, poiché data n la grandezza dei due array da 
    fondere, la loro fusione nel caso peggiore, ovvero quella in cui gli array hanno la stessa dimensione, quello generato sará un 
    array di gradezza 2n.
    Riguardo la complessitá di tempo invece possiamo dire che l'operazione dominante nell'algoritmo é l'operazione di confronto all'interno
    dell'if tra un elemento di a ed un elemento di b, nelle alre parti dell'algoritmo non troviamo altre operazioni dominanti di conseguenza 
    possiamo affermare che la sua complessitá di tempo é uguale al piú nel caso peggiore ad n=size_a + size_b, dunque a T(n). Troviamo la
    complessitá asintotica lineare pari ad O(n).   */


#include <stdio.h>

int main (){   

    int a[20] = {1,2,3,4,5,6,7,8,9,10,12,12,13,14,15,16,17,18,1920,1921};
    int b[20] = {1,3,5,7,9,10,12,14,16,18,20,23,25,27,29,31,33,35,37,39};
    int c[40];
    int size_a = 20, size_b = 20, size_c;

    printf("L'array a e': \n");
    for (int i = 0; i < size_a; i++)
    {
        printf("%d ", a[i]);
    }
    
    printf("\n");
    printf("L'array b e': \n");
    for (int i = 0; i < size_b; i++)
    {
        printf("%d ", b[i]);
    }


    fusione_array(a, size_a, b, size_b, c, &size_c);


    printf("\nLa loro fusione e':\n");
    for (int i = 0; i < size_c; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n\n");




}

/*
void fusione_array(int a[], int size_a, int b[], int size_b, int c[], int *size_c){

    int i_a=0, i_b=0, i_c;

    for ( i_c = 0; i_c < size_a+size_b; i_c++)
    {
        if(i_a<size_a && i_b < size_b)
        {
            if (a[i_a] < b[i_b])
            {
                c[i_c] = a[i_a];
                i_a++;
            } else {

               c[i_c] = b[i_b];
               i_b++;     

            }
            
        } else if (i_b >= size_b)
        {
            c[i_c] = a[i_a];
            i_a++;
        } else {

            c[i_c] = b[i_b];
            i_b++;
        }
        
    }

    *size_c = i_c+1;

}
*/


void fusione_array(int a[], int size_a, int b[], int size_b, int c[], int *size_c){

    int i_a=0, i_b=0, i_c=0;

    while (i_a<size_a && i_b < size_b)
    {
        if (a[i_a] < b[i_b])
            c[i_c++] = a[i_a++];
        else
            c[i_c++] = b[i_b++];
        
    }
    
    while (i_a <= size_a)
            c[i_c++] = a[i_a++];
    while(i_b <= size_b)
            c[i_c++] = b[i_b++];


    *size_c = i_c-2;    

}

