
/* Questo algorimto ha come scopo quello di ordinare una struttura dati come un array contenente elementi
che hanno relazione d'ordine fra loro, come numeri, parole,caratteri.
L'idea dell'algoritmo é quella di prendere una istanza e risolvere un sottoproblerma all'interno di 
essa. Prendiamo ad esempio un array e scendiamon nel dettaglio, diciamo che l'array ha dimensione 8,
noi partiamo dall'istanza i, e prendiamo l'elemento i, lo confrontiamo con gli elementi
dall'indice i-1 all'indice 0, per capire in quale posizione inserirlo correttamente. Una volta
trovata la posizione adeguata ed inserito, si passa alla istanza successiva, quindi alla i+1,
e cosí via fino a quando non arriviamo all'elemento n, ovvero quello finale.
La complessitá di spazio di questo algoritmo dato cher lavora in place é n, ovvero la dimensione
del nostro array. La complessitá di tempo varia in base al numero di dati e di operazioni dominanti 
che vengono svolte durante l'esecuzione, in questo caso dobbiamo analizzare il tutto sotto
l'ottica di caso peggiore, che per la cronaca é il caso in cui l'array sia ordinato in ordine 
decrescente, e possiamo osservare come ad ogni passo del problema, il numero di operazioni dominanti
che in questo caso sono i confronti nell'if, sia uguale ad n-1, nella iterazione successiva ad n-2
fino ad arrivare a 2 e poi ad 1, possiamo racchiudere questro comportamento nella formula di gaus
n(n-1)/2, e quindi definire la complessita di tempo T(n) = 1/2(n^2-n), la sua complessitá asintotica
é di conseguenza uguale ad O(n^2).  */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordinamento_per_inserimento(int [], int );

int main (){

srand(time(NULL));

int a[20];
int n=20;

for (int i = 0; i < n; i++)
{
    a[i] = rand() % 10;
}

printf("L'array generato e':\n");
for (int i = 0; i < n; i++)
{
    printf("%d ", a[i]);
}
printf("\n");

ordinamento_per_inserimento(a, n);

printf("L'array ordinato per inserimento e':\n");
for (int i = 0; i < n; i++)
{
    printf("%d ", a[i]);
}
printf("\n");

}



void ordinamento_per_inserimento(int a[], int n){

    int i, j;
    int tmp;

    for ( i = 1; i < n; i++)
    {
        tmp = a[i];
        j=i-1;

            while (j>=0 && a[j] > tmp)
            {
                a[j+1]=a[j];
                j--;
            }
            
            a[j+1] = tmp;
    }
}






