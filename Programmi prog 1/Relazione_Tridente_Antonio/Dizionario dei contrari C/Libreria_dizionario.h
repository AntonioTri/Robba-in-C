#ifndef LIBRERIA_DIZIONARIO_H
#define LIBRERIA_DIZIONARIO_H

#include <stdio.h>
#include <string.h>

typedef struct {
    char originale[50];
    char contrario[5][50];
} parola;

void mostra_es_parole_disp(parola *, int );
void rimpiazza_parole_scelte(parola *, char [200], int );
void rimpiazza_tutte_le_parole(parola *, char [200], int );
int appartiene(parola *, int, char *);
int scambia_parola(char *, int , char *, char *);




#endif /* Libreria_dizionario_h */