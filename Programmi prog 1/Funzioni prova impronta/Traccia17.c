/*
	Sviluppare una function C che, dati come parametri di input un array di char
	e il suo size, determina e restituisce come parametro un dato logico che
	indica se il testo nell'array è un pangramma, ovvero un testo che contiene,
	almeno una volta, tutte le 21 lettere dell'alfabeto italiano.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool pangramma(char [100], int );

int main (){

    char sequenza[100];
    int size;
    bool valore_pangr;

    printf("Scrivi una sequenza di caratteri tutti attaccati (Max 100  caratteri):\n");
    gets(sequenza);
    size = strlen(sequenza);

    valore_pangr = pangramma(sequenza, size);

    if (valore_pangr == true)
    {
        printf("\nLa sequenza da te inserita e' un pangramma.\n");
    } else if (valore_pangr == false)
    {
        printf("\nLa sequenza da te inserita NON e' un pangramma.\n");
    }
    
    
}

bool pangramma(char sequenza[100], int size ){

    char alfabeto[21] = {'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};
    int occorrenze[21];
    int flag;
    strlwr(sequenza);

    //i Inizializzazione di occorrenze
    for (int k = 0; k < 21; k++)
    {
        occorrenze[k] = 0;
    }
    
    // Controllo se sono presenti le lettere dell'alfabeto, se una lettera è presente viene settata ad 1
    // la posizione di quella lettera nell'array occorrenze (per dire che c'è)
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (sequenza[i] == alfabeto[j])
            {
                occorrenze[j] = 1;
                printf("Lettera '%c' trovata!\n", alfabeto[j]);
            }   
        }
    }

    // se almeno una lettera non è stata trovata ritorna false, non è un pangramma
    for (int k = 0; k < 21; k++)
    {
        if (occorrenze[k] == 0)
        {
            return false;
        }
    }
    
    // atrimenti ritorna true, è un pangrammma
    return true;
}