/* Questo algoritmo ha il compito di ordinare un insieme di dati che hanno tra loro una relazione di
ordine, come ad esempio un array di numeri, caratteri o stringhe di caratteri.
Prendiamo ad esempio un array di numeri interi di n elementi, l'algoritmo di pone il problema di
trovare il minimo dell'array ed il suo indice e successivamente di effettuare uno swap tra esso
ed il primo elemento, all'istanza successiva peró, l'algoritmo ricercherá il minimo non piú in
tutto l'array, ma nella porzione successiva alla prima posizione, quindi dall'indice 1, fino all'indice
n-1, una volta definito il processo di scambio avverrá tra il minimo trovato in questa nuova porzione
e l'elemento di indice 1, alla prossima iterazione l'indice passerá a 2, e la nuova porzione sará 
tra 2 ed n-1, vengono effettuate queste operazioni fino all'indice n-2, poiché in questo caso
gli ultimi 2 elementi saranno sicuramente ordinati.

La complessita di spazio é pari ad n, perché l'algoritmo lavora in place.
Per quanto riguarda quella di tempo invece le cose si diversificano; Le operazioni dominanti le
possiamo trovare all'interno della ricerca del minimo locale e dello scambio di questo con
il primo elemento della sua porzione di appartenenza. Nella funzione di ricerca del minimo,
troviamo n-1 confronti, alla istanza successiva n-2, poi n-3, fino ad un solo confronto (da
notare che non sono confronti di caso peggiore ma assoluti, ció significa che vengono effettuati
sempre tutti), la loro somma é riducibile alla formula di gauss per cui T(n)= n(n-1)/2, 
la sua complessitá asintotica é per tanto O(n^2) (ricordo che la complessitá asintotica é la
complessita che la funzione assume al tendere di n all'infinito). Per la funzione swap invece
troviamo una complessitá di tempo diversa poiché effettua uno scambio ad ogni iterazione del 
ciclo for e di conseguenza ha complessitá T(n)= n-1, la sua complessitá asintotica é per tanto
lineare O(n). */




#include <stdio.h>

int main(){

    int a[20] = {2,534,6,2,354,65,2,34,54,654,3,234,213,54,546,34,45,56,54,5};
    int n = 20;

    printf("L'array e':\n");
    for(int i=0; i<n; i++){

        printf("%d ", a[i]);

    } printf("\n");


    ordinamentoricercaperminimo(a, n);

    printf("Ordinato e': \n");    
    for(int i=0; i<n; i++){

        printf("%d ", a[i]);

    } printf("\n");


}




void ordinamentoricercaperminimo(int a[], int n){

    int i;
    int min;
    int indice_min;

    for (i=0; i<n-1; i++){

        ricercaminvalind(&a[i], n-i, &indice_min);
        swap(&a[i], &a[indice_min+i]);

    }


}



void ricercaminvalind(int a[], int n, int *indice_min){

    int i;
    int min=a[0];
    *indice_min=0;

    for(i=1; i<n; i++){
    
        if(a[i]<min){

            min = a[i];
            *indice_min = i;

        }

    }

}



void swap(int *a, int *b){

    int tmp;

    tmp = *a;
    *a=*b;
    *b=tmp;

}
