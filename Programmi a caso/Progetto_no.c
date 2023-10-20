#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int i, j;
    int n=10;
    int m=10; 
    int a[n][m];
    int c;
    int r;
    int b[c][r];
    int el_comuni=0;

    srand(time(NULL));

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            a[i][j]= rand() % 2;
        }
        
    }

    i=0; j=0;

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
        
    }
   
    i=0; j=0;

    printf("Qui creiamo la tua matrice. Inserisci un valore c tra 1 e 9 per le righe \n");
    scanf("%d", &c);
    printf("Inserisci un valore r tra 1 e 9 per le colonne \n ");
    scanf("%d", &r);

    for  (i = 0; i < c; i++)
    {
        for ( j = 0; j < r; j++)
        {
            printf("Inserisic l'elemento %d %d: \n", i, j);
            scanf("%d", &b[i][j]);
        }
        
    }

    i=0; j=0;

    printf("La tua matrice e':\n");

    for ( i = 0; i < c; i++)
    {
        for ( j = 0; j < r; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
        
    }
}
//dobbiamo scorrere la matrice grande, e passare alla funiozne bbestmaching
//gli indici di scorrimento attuali della grande, le matrici, e ci deve restituire:
//l'indice in cui si trova ed il valore di elementi in comune.

void bets_matching(int a[][50], int b[][50], int i, int j, int c, int r, int *el_comuni){


        do
        {
             do
             {
                //qua ci va il best matching
                if (a[i][j] == b[i][j])
                {
                    *el_comuni++;
                }
                
                j++;

             } while (j<=(j+r)-1);

             i++;

        } while (i<=(i+c)-1);

}        
        
