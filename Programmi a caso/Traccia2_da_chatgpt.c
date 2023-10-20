#include <stdio.h>
#include <stdlib.h>

#define INFINITY 210000000

typedef struct
{
    double x;
    double y;
} punto ;


#define SIZE 10

int main() {
    punto punti[SIZE];

    // Chiedi all'utente di inserire i valori x ed y dei punti
    for (int i = 0; i < SIZE; i++) {
        printf("Inserisci il valore di x per il punto %zu: ", i + 1);
        scanf("%lf", &punti[i].x);
        printf("Inserisci il valore di y per il punto %zu: ", i + 1);
        scanf("%lf", &punti[i].y);
    }

    int indice_punto_1, indice_punto_2;
    distanza_minima(punti, SIZE, &indice_punto_1, &indice_punto_2);

    printf("Gli indici dei punti con distanza minima sono: %zu e %zu\n", indice_punto_1, indice_punto_2);

    return 0;
}


void distanza_minima(punto* punti, size_t size, size_t* indice_punto_1, size_t* indice_punto_2) {
    double distanza_minima = INFINITY;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            double distanza = sqrt(pow(punti[i].x - punti[j].x, 2) + pow(punti[i].y - punti[j].y, 2));
            if (distanza < distanza_minima) {
                distanza_minima = distanza;
                *indice_punto_1 = i;
                *indice_punto_2 = j;
            }
        }
    }
}