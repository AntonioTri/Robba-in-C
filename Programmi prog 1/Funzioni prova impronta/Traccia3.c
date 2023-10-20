/* !!!! OSSERVASINE IMPORTANTE !!!!!

    QUESTE SCRITTE SONO PROCEDURE E NON FUNZIONI, DATO CHE PER FARE IL PROGRAMMA PIU' CARINO
    HO VOLUTO COME OUTPUT PIU' DI UN PARAMETRO, E DI CONSEGUENZA HO FATTO USO DI UNA PROCEDURA,
    NON UNA FUNZIONE CHE PUO' RESTITUIRE SOLO UN OUTPUT DA ASSEGNARE POI AD UNA VASIABILE

*/

#include <stdio.h>
#include <math.h>

#define NRO_PUNTI 4

typedef struct 
{
    double x;
    double y;
} punto;

void distanza_massima_punti(punto *, int , double *);

int main (){

    int i, n = NRO_PUNTI;
    punto punti[NRO_PUNTI];
    double distanza_massima;


    for ( i = 0; i < NRO_PUNTI; i++)
    {
        printf("Inserisci la x del punto %d: ", i+1);
        scanf("%lf", &punti[i].x);
        printf("Inserisci la y del punto %d: ", i+1);
        scanf("%lf", &punti[i].y);

    }
    i=0;

    for ( i = 0; i < NRO_PUNTI; i++)
    {
        printf("\nIl punto %d ha x = %.2lf ed y = %.2lf\n", i+1, punti[i].x, punti[i].y);
    }

    
    distanza_massima_punti(punti, n, &distanza_massima);

    printf("\nLa distanza massima che esiste tra i punti e': %.2lf\n", distanza_massima);
}


void distanza_massima_punti(punto *punti, int n, double *distanza_max){

    int i,j;
    *distanza_max=0;
    double distanza;

    for ( i = 0; i < n; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            distanza = sqrt(pow(punti[i].x-punti[j].x, 2)+pow(punti[i].y-punti[j].y, 2));

            if (distanza >= *distanza_max)
            {
                *distanza_max=distanza;
            }
           
        }
        
    }

}