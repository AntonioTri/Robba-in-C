/*
	Sviluppare una function C che, dati come parametri di input un array di char
 	e il suo size, determina e restituisce come parametro di output l'array
 	(di size 21) del numero delle occorrenze delle 21 lettere dell'alfabeto
 	italiano (per es. il numero di occorrenze della lettera a è il numero di
	volte in cui la lettera a compare nel testo).
*/

//legge il testo e controla tutte le volte in cui c'é 'a', e memorizza il valore nella prima posizione dell'array, e cosí via

#include <stdio.h>
#include <string.h>

void conta_occorrenze(char [100], int , int *);

int main(){

    char alfabeto[21]={'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};
    char sequenza_caratteri[100];
    int size;
    int ricorrenze[21];

    printf("Inserisci una frase di caratteri tutti attaccati (max 100):\n");
    gets(sequenza_caratteri);

    size = strlen(sequenza_caratteri);
    conta_occorrenze(sequenza_caratteri, size, ricorrenze);

    printf("Ecco a te la lista delle occorrenze trovate:\n\n");

    for ( int i = 0; i < 21; i++)
    {
        printf(" #) %c = %d volte.\n", alfabeto[i], ricorrenze[i]);
    }
    

}

void conta_occorrenze(char sequenza[100], int size, int *ricorrenze){

    char alfabeto[21]={'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};

    if (size == 0 || sequenza == NULL)
    {
        return;
    }
    

    for (int i = 0; i < 21; i++)
    {
        ricorrenze[i] = 0;  
    }

    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (alfabeto[i] == sequenza[j])
            {
                ricorrenze[i]++;
            }   
        }
    }
}

