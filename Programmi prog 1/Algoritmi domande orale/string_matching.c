/* Questo algoritmo si pone come obbiettivo quello di controllare se all'interno di un testo é presente o no una determinata sequenza
   di caratteri, una parola ad esempio, una chiave, una sequenza di numeri o altro.
   
   L'algoritmo procede a passi iterativi scorrendo il testo per ogni suo indice fino alla sua lunghezza meno la lunghezza della chiave
   da trovare, questo accade perché se la chiave si trovasse alla fine del testo, non ci sarebbe motivo di proseguire oltre data l'assenza di ulteriori
   indirizzi allocati successivi all'ultimo. Ad ogni passo, vengono confrontate una sottoporzione del testo e la chiave, se questi sono uguali, 
   viene aumentato il numero di volte in cui la chiave é stata trovata, altrimenti si prosegue al passo successivo,
   
   Implementato in linguaggio C osserviamo che la sua complessitá di spazio, dato che l'algoritmo lavora in place, é uguale alla dimensione
   del testto piú quella della chiave, quindi m+n, Riguardo la complessitá di tempo invece, dobbiamo ricordarci che varia sempre in base alla
   lunghezza dei dati di input,  e dal numero di confronti tra di essi, l'unico confronto effettuato é quello nello strncmp , che viene eseguito
   una volta per iterazione del for, che esegue m-n passi, di conseguenza é diretto capire che la complessitá di tempo é uguale a T(m*n) = T(m*n+1),
   La sua complessitá asintotica é dunque uguale a O(m*n). */



#include <stdio.h>
#include <string.h>

int main(){

    char testo[200];
    char chiave[30];
    int presenza;

    printf("Inserisci un testo:\n");
    gets(testo);
    printf("\nOra inserisci una chiave che vuoi vedere se e' presente all'interno del testo:\n");
    gets(chiave);

    presenza = string_matching(testo, chiave);

    printf("La chaive e' stata trovata %d volte!", presenza);
    


}


int string_matching(char testo[200], char chiave[30]){

    int n, m, i, conta = 0;

    n = strlen(chiave);
    m = strlen(testo);

    for ( i = 0; i < m-n; i++)
    {
        if (strncmp(chiave, &testo[i], n)==0)
        {
            conta++;
        }
        
    }
    
    return conta;

}

