/*
	Sviluppare una function C che, dati come parametri di input un array di char
	e il suo size, determina e restituisce come parametro di output il carattere 
	meno frequente. 
*/

#include <stdio.h>
#include <string.h>

char carattere_più_frequente(char [100], int);

int main (){

    char sequenza[100];
    char carattere;

    printf("Inserisci una sequenza di caratteri tutti attaccati (max 100):\n");
    gets(sequenza);
    strlwr(sequenza);
    int lunghezza = strlen(sequenza);

    carattere = carattere_più_frequente(sequenza, lunghezza);

    printf("Il carattere che compare meno volte nella tua sequenza e': %c", carattere);

}

char carattere_più_frequente(char sequenza[100], int size){

    char alfabeto[21] = {'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};
    int occorrenze[21];

    for (int z = 0; z < 21; z++)
    {
        occorrenze[z]=0;
    }
    

    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (sequenza[j]==alfabeto[i])
            {
                occorrenze[i]++;
            }
        }
        
        printf("Lettera '%c' trovata %d volte.\n", alfabeto[i], occorrenze[i]);
    
    }

int j=0;

    for (int k = 0; k < 21; k++)
    {
        if (occorrenze[k]<occorrenze[j])
        {
            j = k;
        }
        
    }
    
    return alfabeto[j];

}