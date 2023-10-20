/*
	Scrivere una unzione che dati in input due array ordinati (rispetto al campo matricola)
	di elementi della seguente struttura:
	struct studente {
		char *nome;
		char *cognome;
		int matricola;
	};
	restituisca in output l'array fusione dei due array.
	La fusione deve avvenire in base al campo matricola.
 */
#include <stdio.h>

typedef struct 
{
    char *nome;
    char *cognome;
    int matricola;
} studente ; 

void fusione_array(studente *, int ,studente *, int ,studente *);

int main ()
{
    studente listaC[100];
    studente listaA[5]={
        {"francesco", "cantone", 10},
        {"tonino", "rossi", 5},
        {"maestro", "cane", 4},
        {"antonio", "tridente", 17},
        {"andrea","priscilla", 20}
        
    };
    studente listaB[5]={
        {"rosario","bianco",3},
        {"mariacarla","staffa", 21},
        {"raffaele","montella",6},
        {"angelo","sputazza",7},
        {"ciaramella","giunta",16}
    };
     
    // traccia6(listaA, 5, listaB, 5, &listaC[100]);
    fusione_array(listaA, 5, listaB, 5, listaC);
     for (int i = 0; i < 10; i++)
     {
        printf("stampami le matricole degfli studenti %d \n", listaC[i].matricola);
     }
     


}





void fusione_array(studente *array1, int n1,studente *array2, int n2, studente *risultato) {

    int n3=n1+n2;
    
    studente temp;

    for (int i = 0; i < n1; i++)
    {
        risultato[i]=array1[i];
    }
    for ( int i = n1; i < n2; i++)
    {
        risultato[i]=array2[i];
    }

    
    for (int i = 0; i < n3; i++)
    {
        temp=risultato[i];
        int j=i-1;
        while (j >= 0 && risultato[j].matricola > temp.matricola)
        {
         risultato[j+1]=risultato[j];
         j--;   
        }
        risultato[j+1]=temp;
        
    }//algoritmo ensosciort
}