/*
	Sviluppare una function C che, dati come parametri di input un array 2D di int,
	il numero delle righe e il numero delle colonne, determina e restituisce
	come parametro di output il massimo tra le somme degli elementi di ogni riga.
*/

/* !!!! OSSERVASINE IMPORTANTE !!!!!

    QUESTE SCRITTE SONO PROCEDURE E NON FUNZIONI, DATO CHE PER FARE IL PROGRAMMA PIU' CARINO
    HO VOLUTO COME OUTPUT PIU' DI UN PARAMETRO, E DI CONSEGUENZA HO FATTO USO DI UNA PROCEDURA,
    NON UNA FUNZIONE CHE PUO' RESTITUIRE SOLO UN OUTPUT DA ASSEGNARE POI AD UNA VASIABILE

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NRO_RIGHE 5
#define NRO_COLONNE 5

void massima_somma_righe(int a[][NRO_COLONNE], int , int, int*, int*);

int main (){

    int i, j, a[NRO_RIGHE][NRO_COLONNE];
    int righe = NRO_RIGHE, colonne = NRO_COLONNE;
    int massimo_righe, indice;
    char fine;


    do{

    int massimo_righe = 0, indice = 0;

    srand(time(NULL));

    for ( i = 0; i < righe; i++)
    {
        for ( j = 0; j < colonne; j++)
        {
            a[i][j] = rand() % 10;
        }
        
    }

    i=0;
    j=0;

    printf("La matrice generata e': \n\n");
    for ( i = 0; i < righe; i++)
    {
        for ( j = 0; j < colonne; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
        
    }
    
    massima_somma_righe(a, righe, colonne, &massimo_righe, &indice);

    printf("\nLa riga con la somma massima e' la %d, e la sua somma e' %d\n", indice, massimo_righe);

    printf("Scrivi \" Y \" se vuoi uscire: ");
    scanf("%s", &fine);

} while (fine != 'Y');


}

void massima_somma_righe(int a[][NRO_COLONNE], int righe, int colonne, int *massimo_righe, int *indice){

        int i,j;
        *massimo_righe = 0;

        for ( i = 0; i < righe; i++)
        {
            int somma_riga = 0;
            for ( j = 0; j < colonne; j++)
            {
                somma_riga+= a[i][j];
            }
            if (somma_riga>=*massimo_righe)
            {
                *massimo_righe = somma_riga;
                *indice = i+1;
            }
            
        }
        
}





