/*
	Sviluppare una function C che, data come parametro di input una stringa che
	rappresenta un testo in italiano, determina e restituisce
 	come parametro di output il numero di parole che iniziano con a e terminano
	con e contenute nel testo. Nel testo le parole sono separate
 	da un unico spazio.  
*/

#include <stdio.h>
#include <string.h>

int conta_parole_a_e(char [300]);

int main(){

    char frase[300];

    printf("Inserisci una frase (max 300 caratteri):\n");
    gets(frase);

    int nro_parole_a_e = conta_parole_a_e(frase); 

    printf("\nIl numero di parole che iniziano per a e finiscono per e nella frase che hai inserito e': %d", 
            nro_parole_a_e);

}

int conta_parole_a_e(char frase[300]){

int conta_parole=0;
char *parola_attuale = strtok(frase, " ");

printf("\nCeck1");
    while (parola_attuale != NULL)
    {
        printf("\nCeck2");
        if ((parola_attuale[0] == 'a') && (parola_attuale[strlen(parola_attuale)-1] == 'e'))
        {
            printf("\nCeck3");
            conta_parole++;
        }

        parola_attuale = strtok(NULL, " ");
    
    }

    return conta_parole;

}