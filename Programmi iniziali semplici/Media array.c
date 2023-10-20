#include <stdio.h>

int main (){

    int a[10], somma=0, i;
    float media;

    // Inserimento elementi array

    for ( i = 0; i < 10; i++)
    {
        printf ("Inserisci l'elemento intero %d di 10\n", i+1);
        scanf("%d", &a[i]);

    }

    for ( i = 0; i < 10; i++)
        somma=somma+a[i];
    
        media=(float)somma/10;
        
        printf("\nLa somma degli elementi inseriti e' %d\n", somma);
        printf("La loro media invece e' %.1f\n", media);
    

}