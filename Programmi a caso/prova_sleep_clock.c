#include <stdio.h>
#include <unistd.h>
#include <time.h>

void main(){

    int tempo_iniziale, tempo_finale;

    printf("Inizio a dormire...");

    tempo_iniziale = clock();

    sleep(3.5);

    tempo_finale = clock();

    double sec_trascorsi;

    sec_trascorsi = (double)(tempo_finale - tempo_iniziale)/1000;

    printf("\n\nSono passati %0.1f secondi da quando ho iniziato a dormire\n", sec_trascorsi);

    printf("\nClock iniziale %d.\nClock finale %d.\n\n", tempo_iniziale, tempo_finale);


}