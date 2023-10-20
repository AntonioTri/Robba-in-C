/*
	Sviluppare una function C che, data come parametro di input una stringa che
	rappresenta un testo in italiano, determina e restituisce
 	come parametri di output la parola di lunghezza massima contenuta nel testo
	e la sua lunghezza. Nel testo le parole sono separate da
 	un unico spazio. 
*/

#include <stdio.h>
#include <string.h>

void parola_piu_lunga(char [300], char *, int *);

int main(){

    char frase[300];
    char parola[20];
    int lunghezza;

    printf("Inserisci una frase (max 300 caratteri):\n");
    gets(frase);

    parola_piu_lunga(frase, &parola[0], &lunghezza);

    printf("\nLa parola piu' lunga che hai scritto nella frase che hai inserito e': '%s' \n La sua lunghezza invece e': '%d'", parola, lunghezza);

}


void parola_piu_lunga(char frase[300], char *parola_piu_lunga, int *lunghezza){

    char *parola_attuale = strtok(frase, " ");
    int lunghezza_attuale;
    int i;
    *lunghezza = 0;

    while (parola_attuale!= NULL)
    {
       lunghezza_attuale = strlen(parola_attuale);

       if (lunghezza_attuale >= *lunghezza)
       {
            *lunghezza = lunghezza_attuale;
            strcpy(parola_piu_lunga, parola_attuale);
       }
       
       parola_attuale = strtok(NULL, " ");

    }
    

}