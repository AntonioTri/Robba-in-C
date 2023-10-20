/*
	Sviluppare una function C che, dati come parametri di input un array di char
	e il suo size, determina e restituisce come parametro di output l'array occorrenze 
	(di size 21) del numero delle occorrenze dell'evento a precede ognuna delle 21 
	lettere dell'alfabeto italiano (cioè occorrenze[0] è il numero di volte in cui 
	accade che a precede a, cioè che nel testo compare aa, occorrenze[1] è il 
	numero di volte in cui accade che a precede b, cioè che nel testo compare ab,
	occorrenze[2] è il numero di volte in cui accade che a precede c, cioè che 
	nel testo compare ac).
*/

#include <stdio.h>
#include <string.h>

void conta_occorrenze_ax(char [100], int , int *);

int main(){

    char alfabeto[21]={'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};
    char sequenza_caratteri[100];
    int size;
    int ricorrenze[21];

    printf("Inserisci una frase di caratteri tutti attaccati (max 100):\n");
    gets(sequenza_caratteri);

    size = strlen(sequenza_caratteri);
    conta_occorrenze_ax(sequenza_caratteri, size, ricorrenze);

    printf("Ecco a te la lista delle occorrenze trovate:\n\n");

    for ( int i = 0; i < 21; i++)
    {
        printf(" #) a%c = %d volte.\n", alfabeto[i], ricorrenze[i]);
    }
    

}

void conta_occorrenze_ax(char sequenza[100], int size, int *ricorrenze_ax){

    char alfabeto[21]={'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};

    if (size == 0 || sequenza == NULL)
    {
        return;
    }
    
    for (int i = 0; i < 21; i++)
    {
        ricorrenze_ax[i]=0;
    }
    
    for (int i = 0; i < size; i++)
    {
        if (sequenza[i] == 'a')
        {
            for (int j = 0 ; j < 21 ; j++)
            {
                if (sequenza[i+1] == alfabeto[j])
                {
                    ricorrenze_ax[j]++;
                }
            }
        }
    }

}

