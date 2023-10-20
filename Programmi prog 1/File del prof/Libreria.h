//
//  Libreria.h
//  Esercitazione_2_A_A_2021_2022
//
//  Created by Angelo Ciaramella on 06/10/21.
//

#ifndef Libreria_h
#define Libreria_h

#include <stdio.h>
#include <math.h>
#include <string.h>

float circon(float);

void circ(float, float *);

float area_cerchio(float);

float area_corona(float, float);

float valore_assolutoF(float);

float errore_relativoF(float, float);

float distanza_origF(float, float);

void swap(int *, int *); 

int fattorialeI(int);


float fattorialeF(int);

void legge_da_tastiera_aD(double [], int);

void visualizza_aD(double [], int);

void legge_da_tastiera_apD(double *, int);

void visualizza_apD(double *, int);

int somma_aI(int [], int);

int max_aI(int [], int);

void max_pos_aI(int [], int, int *, int *);

void max_min_aI(int [], int, int *, int *);

int appartiene_aF(float chiave, float a[], int n); 

void min_val_ind(int [], int , int *, int *);

void visualizza_a2DI(int [][3], int , int );

void visualizza_a2DIp(int *, int , int , int );

void legge_da_tastiera_a2Dp(double *, int , int , int );

void viasualizza_a2Dp(double *, int , int , int );

void calcolo_media_riga_a2Dp(double *, int , int, int, double []); 


void conta_tutto(char *, int *, int *, int *);

int conta_tutto_strtok(char *);

int conta_tutto_standard(char *);

void ord_sel_min(int [], int);


void ord_ins(int [], int );

void ord_sel_max(int a[], int n);

void max_val_ind (int [], int , int *, int *); 

int max_val_pos (int [], int ); 

int string_matching(char [], char []);

int best_string_matching(char *, char *);

int punteggio_matching(char *, char *, int);

int max_ind_S(char [][50], int);

void ord_sel_max_S(char [][50], int);

void swap_S(char *s1, char *s2);

int somma_n_numeri_ric(int);

int fattoriale(int); 

int Fibonacci(int); 

/*
int conta_tutto_strtok(char *); */


#endif /* Libreria_h */
