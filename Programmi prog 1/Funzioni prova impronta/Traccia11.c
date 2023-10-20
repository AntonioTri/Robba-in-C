/*
	Sviluppare una function C che, data come parametro di input una stringa che
	rappresenta un testo in italiano, determina e restituisce
 	come parametro di output il numero delle parole contenute nel testo che
	hanno almeno 5 vocali. Nel testo le parole sono separate da
 	un unico spazio.
*/

#include <stdio.h>
#include <string.h>

int conta_parole_5_vocali(char [300]);

int main(){

    char frase[300];

    printf("Inserisci una frase (max 300 caratteri):\n");
    gets(frase);

    //printf("%s", frase);

    int nro_parole_5_vocali = conta_parole_5_vocali(frase); 

    printf("\nIl numero di parole che hanno almeno 5 vocali nella frase che hai inserito e': %d", 
            nro_parole_5_vocali);

}

int conta_parole_5_vocali(char frase[300]){

    char *parola_attuale = strtok(frase, " ");
    int i;
    int conta_parole;
    int lunghezza_parola;
    int conta_lettere;

    while (parola_attuale != NULL)
    {
        lunghezza_parola = strlen(parola_attuale);
        conta_lettere=0;

        for ( i = 0; i < lunghezza_parola; i++)
        {
            char lettera = parola_attuale[i];
            
            if (lettera == 'a' || lettera == 'e' || lettera == 'i' || lettera == 'o' || lettera == 'u')
            {
                conta_lettere++;
            }
            
        }

        if (conta_lettere >=5)
        {
            conta_parole++;
        }    
        parola_attuale=strtok(NULL, " ");
    }
    
    return conta_parole;

}