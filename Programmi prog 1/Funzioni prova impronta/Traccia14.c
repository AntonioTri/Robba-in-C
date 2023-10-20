/*
	Sviluppare una function C che, data come parametro di input una stringa che
	rappresenta un testo in italiano, determina e restituisce come parametri di 
	output la parola di lunghezza minima contenuta nel testo e la posizione di 
	inizio della parola nella stringa. Nel testo le parole sono separate da un 
	unico spazio.  
*/


#include <stdio.h>
#include <string.h>

void parola_minima_posizione(char [300], char *, int *);

int main(){

    char frase[300];
    char parola[20];
    int posizione;

    printf("Inserisci una frase (max 300 caratteri):\n");
    gets(frase);

    parola_minima_posizione(frase, &parola[0], &posizione);

    printf("\nLa parola piu' corta che hai scritto nella frase che hai inserito e': '%s' \n La sua posizione nella frase invece e': %d\n", parola, posizione);

}

void parola_minima_posizione(char frase[300], char *parola_piu_corta, int *posizione){

    char *parola_attuale = strtok(frase, " ");
    int lunghezza = strlen(frase);
    int lunghezza_attuale;
    int lung_precedente = 0;
    *posizione = 0;

    while (parola_attuale != NULL)
    {
        lunghezza_attuale = strlen(parola_attuale);

            if (lunghezza_attuale <= lunghezza)
            {
                lunghezza = lunghezza_attuale;

                *posizione = lung_precedente;
                strcpy(parola_piu_corta, parola_attuale);

            }

        lung_precedente += lunghezza_attuale+1;

        parola_attuale = strtok(NULL, " ");
    
    }
    
}