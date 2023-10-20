/*
	Sviluppare una function C che, data come parametro di input una stringa che
	rappresenta un testo in italiano, determina e restituisce
	come parametro di output il numero di parole che terminano in are contenute nel 
	testo. Nel testo le parole sono separate da un unico spazio. 
*/

#include <stdio.h>
#include <string.h> 

int conta_parole_in_are(char [300]);

int main(){

    char frase[300];

    printf("Inserisci una frase (max 300 caratteri):\n");
    gets(frase);

    //printf("%s", frase);

    int nro_parole_in_are = conta_parole_in_are(frase); 

    printf("\nIl numero di parole che finiscono in are nella frase che hai inserito e': %d", 
            nro_parole_in_are);

}


int conta_parole_in_are(char frase[300]){

    char *parola_attuale;
    parola_attuale = strtok(frase, " ");
    int lunghezza_parola;
    int conta_parole;

    while (parola_attuale != NULL)
    {
        lunghezza_parola = strlen(parola_attuale);

        printf("\n\nceck1\n\n");
        if (strncmp(&parola_attuale[lunghezza_parola-3], "are", 3) == 0)
        {
            conta_parole++;
        }

        parola_attuale = strtok(NULL, " ");
        
    }
    
    return conta_parole;

}