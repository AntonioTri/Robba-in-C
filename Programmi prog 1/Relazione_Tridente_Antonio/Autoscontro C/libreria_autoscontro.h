#ifndef libreria__autoscontro_h
#define libreria__autoscontro_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct 
{
    int x;
    int y;
} posizione;


void stampa_pista(posizione *, int);

void muovi_macchina(posizione *, int , int );

int scelta_movimento_ricorsiva(posizione *, float , float , float , float );

float distanza_ricorsiva( float, float, float, float);

void movimento_destra(posizione *, int , int , int , int , int );

void movimento_sinistra(posizione *, int , int , int , int , int );

void movimento_in_basso(posizione *, int , int , int , int , int );

void movimento_in_alto(posizione *, int , int , int , int , int );

#endif /* libreria__autoscontro_h */