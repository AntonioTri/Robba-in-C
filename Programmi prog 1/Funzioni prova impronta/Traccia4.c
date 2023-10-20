/*
	Sviluppare una function C che, dati come parametri di input un array 2D di double, il
	numero delle righe e il numero delle colonne, determina e restituisce come parametro
	di output il massimo tra le somme degli elementi di ogni colonna.
*/ 

/* !!!! OSSERVASINE IMPORTANTE !!!!!

    QUESTE SCRITTE SONO PROCEDURE E NON FUNZIONI, DATO CHE PER FARE IL PROGRAMMA PIU' CARINO
    HO VOLUTO COME OUTPUT PIU' DI UN PARAMETRO, E DI CONSEGUENZA HO FATTO USO DI UNA PROCEDURA,
    NON UNA FUNZIONE CHE PUO' RESTITUIRE SOLO UN OUTPUT DA ASSEGNARE POI AD UNA VASIABILE

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NRO_RIGHE 5
#define NRO_COLONNE 5

void massimo_somme_el_col(double [][NRO_COLONNE], int , int , double *, int *);


int main (){

    int i, j;
    int righe = NRO_RIGHE, colonne = NRO_COLONNE;
    double a[NRO_RIGHE][NRO_COLONNE];
    double massimo_somme_col;

    srand(time(NULL));

    for ( i = 0; i < righe; i++)
    {
        for ( j = 0; j < colonne; j++)
        {
            a[i][j] = (double) rand() / RAND_MAX * 10;
        }
        
    }
    
    i=0;
    j=0;

    printf("La matrice generata e': \n\n");

    for ( i = 0; i < righe; i++)
    {
        for ( j = 0; j < colonne; j++)
        {
            printf("%.2lf  ", a[i][j]);
        }
        printf("\n\n");
    }
    i=0;
    j=0;
    
    printf("\n");

     massimo_somme_el_col(a, righe, colonne, &massimo_somme_col, &i);

    printf("La colonna con la somma massima e' la %d, e la sua somma e': %.2lf\n", i, massimo_somme_col);

}


void massimo_somme_el_col(double a[][NRO_COLONNE], int righe, int colonne, double *max_somma_col, int *Indice_colonna){

        int i,j;
        *max_somma_col = 0;

        for ( j = 0; j < colonne; j++)
        {
            double somma_colonne = 0;

            for ( i = 0; i < righe; i++)
            {
                somma_colonne += a[i][j];
            }

            if (somma_colonne >= *max_somma_col)
            {
                *max_somma_col = somma_colonne;
                *Indice_colonna = j+1;
            }
            
        }
        

}