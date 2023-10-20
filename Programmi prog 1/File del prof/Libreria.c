//
//  Libreria.c
//  Esercitazione_2_A_A_2021_2022
//
//  Created by Angelo Ciaramella on 06/10/21.
//

#include "Libreria.h"
float circon(float raggio)
{
    const float pi_greco = 3.1415926F;
    
    return 2.0F * pi_greco * raggio;
}


void circ(float raggio, float *c)
{
    const float pi_greco = 3.1415926F;
    
    *c = 2.0F * pi_greco * raggio;
}


float area_cerchio(float raggio)
{
    const float pi_greco = 3.1415926F;
    
    return pi_greco * raggio * raggio;
}


float area_corona(float raggio_max, float raggio_min)
{
    
    return area_cerchio(raggio_max) - area_cerchio(raggio_min); 
}


float valore_assolutoF(float x)
{
    
    if(x>=0.0F)
        return x;
    else
        return -x;
}

float errore_relativoF(float x, float y)
{
    return valore_assolutoF(x-y)/valore_assolutoF(x); 
}


float distanza_origF(float ascissa, float ordinata)
{
    return sqrt((float)pow(ascissa,2) +(float)pow(ordinata,2));
}




/* function per il fattoriale di n (restituisce un int)*/
 int fattorialeI(int n)
 {
  int fatt,i;
  fatt = 1;
  if (n > 1)
     for (i = 2; i <= n; i++)
        fatt = fatt * i;
  return fatt;
 }

/*function per il fattoriale di n(restituisce un float)*/
 float fattorialeF(int n)
 {
  int i;
  float fatt = 1.0F;
  if (n > 1)
     for (i = 2; i <= n; i++)
        fatt = fatt * (float)i;
  return fatt;
 }


void legge_da_tastiera_aD(double v[], int n)
{
    int i;
    
    printf("Inserisci gli elementi nel vettore \n");
    
    for(i = 0 ; i < n ; i++)
    {
        printf("inserisci l'%d-esimo elemento \n", i);
        scanf("%lf", &v[i]);
    }
    
}

void visualizza_aD(double v[], int n)
{
    int i;
    
    printf("\n Gli elementi del vettore sono \n");
    
    for(i = 0 ; i < n ; i++)
        printf("l'%d-esimo elemento e' %lf\n", i, v[i]);
    
    
}

void legge_da_tastiera_apD(double *v, int n)
{
    int i;
    
    printf("Inserisci gli elementi nel vettore \n");
    
    for(i = 0 ; i < n ; i++)
    {
        printf("inserisci l'%d-esimo elemento \n", i);
        scanf("%lf", (v + i));
    }
    
}

void visualizza_apD(double *v, int n)
{
    int i;
    
    printf("\n Gli elementi del vettore sono \n");
    
    for(i = 0 ; i < n ; i++)
        printf("l'%d-esimo elemento e' %lf\n", i, *(v + i));
    
    
}

int somma_aI(int v[], int n)
{
    int i, s = 0;

    for(i = 0 ; i < n ; i++)
        s += v[i];
    
    return s;
}

int max_aI(int v[], int n)
{
    int i, max = *v;

    for(i = 1 ; i < n ; i++)
        if (v[i] > max)
            max = v[i];
        
    return max;
}

void max_pos_aI(int v[], int n, int *max, int *pos)
{
    int i;
    
    *max = v[0];
    *pos = 0;
    
    for (i = 1 ; i < n ; i++)
        if (v[i] > *max)
        {
            *max = v[i];
            *pos = i;
        }
    
}


void max_min_aI(int v[], int n, int *max, int *min)
{
    int i;
    
    *max = v[0];
    *min = v[0];
    
    for(i = 1 ; i < n ; i++)
        if (v[i] > *max)
            *max = v[i];
        else if (v[i] < *min)
            *min = v[i]; 
        
}

int appartiene_aF(float chiave, float a[], int n)
{
    
    int i = 0, flag = 0;
    
    while( i < n && flag == 0)
    {
        
        if (chiave == a[i])
            flag = 1;
        
        i++;
    }
    
    return flag;
    
    
    int i;
    
    for(i = 0; i < n; i++)
        if (chiave == a[i])
            return 1;
        

    return 0;
}




void visualizza_a2DI(int A[][3], int m, int n)
{
 int i,j;
 for (i=0; i < m; i++)
   {
     for (j=0; j<n; j++)
         printf("%5d", A[i][j]);
     printf("\n");
   }
}

void visualizza_a2DIp(int *pa, int n_col, int m, int n)
{
 int i,j;
 for (i=0; i < m; i++)
   {
     for (j=0; j<n; j++)
         printf("%5d", *(pa + n_col*i + j));
     printf("\n");
   }
}


void legge_da_tastiera_a2Dp(double *A, int n_col, int n, int m)
{
    int i , j;
    
for (i=0;i<n;i++)
    for (j=0;j<m;j++)
    {
        printf("\n Dammi l'elemento A[%d][%d]", i, j);
        scanf("%lf", (A + n_col * i + j));
    }
}

void viasualizza_a2Dp(double *A, int n_col, int n, int m)
{
    int i , j;
    
for (i=0;i<n;i++)
    for (j=0;j<m;j++)
    {
        printf("\n Dammi l'elemento A[%d][%d] = %lf", i, j, *(A + n_col*i + j));
    }
    
    printf("\n");
}


void calcolo_media_riga_a2Dp(double *A, int n_col, int n, int m, double media_riga[])
{
    int i, j;
    
    double somma;
    
    for (i=0; i<n; i++)
     {
       somma = 0.0;
         for (j=0;j<m;j++){
             somma += *(A + n_col * i + j);
             
         }
         
       media_riga[i] = somma/m;
      }

}

void conta_tutto(char *testo, int *conta_c, int *conta_p, int *conta_l)
{
  int i, in_p;
    i = 0;
    *conta_c = 0;
    *conta_p = 0;
    *conta_l = 0;
  
    in_p = 0;
    
    while (testo[i] != '\0')
    {
        (*conta_c)++;
        if (testo[i] == '\n')
            (*conta_l)++;
        if (testo[i] == ' '|| testo[i]== '\n' || testo[i]== '\t')
            in_p = 0;
        else if (in_p == 0)
           {
               in_p = 1;
               (*conta_p)++;
            }
        
        i++;
  }
    (*conta_l)++;
}


int conta_tutto_strtok(char *testo)
{
    char separatori[] = {' ', '\n', '\t', '\0'}, *token = NULL;
    
    int cont = 0;
    
    token = strtok(testo, separatori);
    
    while( token != NULL)
    {
        //cont++;
        
        printf("%s", token);
       
        getchar();
    
        
        if (token[strlen(token) - 1] == 'e')
            cont++;
    
       
        token = strtok(NULL, separatori);
    }
    
    return cont;
}

int conta_tutto_standard(char *testo)
{
    int i = 0, in_p = 0, cont=0, flag = 0, j = 0;
    
    char temp[strlen(testo)];
    
    while (testo[i] != '\0')
    {
        
        if (testo[i] == ' '|| testo[i]== '\n' || testo[i]== '\t')
        {
            in_p = 0;
            
            j = 0;
            
            if(testo[i-1] == 'e' && flag )
            {
                cont++;
                flag = 0;

            }
        }
        else if (in_p == 0)
           {
               in_p = 1;
               
               temp[j++] = testo[i];
               
               if(testo[i] == 'a')
                   flag = 1;
               else
                   flag = 0;
               
               //cont++;
            }
        
        i++;
  }
    
    return cont;
}

void ord_ins(int a[], int n)
{
    int i, j, el_da_ins;
    
    for(i = 1 ; i < n ; i++)
    {
        el_da_ins = a[i];
        
        j = i - 1;
        
        while(j >= 0 && el_da_ins < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[ j + 1 ] = el_da_ins;
    }
}


void ord_sel_min(int a[], int n)
{
    int i, min, pos;
    
    for(i=0; i < n - 1 ; i++)
    {
        min_val_ind(&a[i], n - i, &min, &pos);
        swap(&a[i], &a[ i + pos]);
    
    }
    
}

void ord_sel_max(int a[], int n)
{
    int i; //, max, pos;
    
    for(i = n - 1; i > 0; i--)
    {   
        swap(&a[i], &a[max_val_pos(&a[0], i + 1)]);

    }
    
}



void swap(int *a, int *b)
{
    int temp;
    
    temp = *a;
    
    *a = *b;
    
    *b = temp;
    
}


void min_val_ind (int v[], int n, int *min, int *pos)
{
    int i;
    
    *min = v[0];
    *pos = 0;
    
    for (i = 1 ; i < n ; i++)
        if (v[i] < *min)
        {
            *min = v[i];
            *pos = i;
        }
    
}

int max_val_pos (int v[], int n)
{
    int i, max, pos;
    
    max = v[0];
    pos = 0;
    
    for (i = 1 ; i < n ; i++)
        if (v[i] > max)
        {
            max = v[i];
            pos = i;
        }

    return pos;
    
}



void max_val_ind (int v[], int n, int *max, int *pos)
{
    int i;
    
    *max = v[0];
    *pos = 0;
    
    for (i = 1 ; i < n ; i++)
        if (v[i] > *max)
        {
            *max = v[i];
            *pos = i;
        }
    
}


int string_matching(char s[], char chiave[])
{
    int i, n_occ = 0, n, m;
    
    n = (int)strlen(s);
    m = strlen(chiave);
    
    for(i = 0 ; i <= n - m ; i++)
        if(strncmp(chiave, &s[i], m) == 0)
            n_occ++;
    
    return n_occ;
}


int best_string_matching(char *chiave, char *testo)
{
    
    int i, punteggio_max, punteggio, indice, n, m;
    
    n = strlen(testo);
    m = strlen(chiave);
    
    indice = 0;
    punteggio_max = 0;
    
    for(i = 0 ; i <= n-m; i++)
    {
        punteggio = punteggio_matching(chiave, &testo[i], m);
        
        if (punteggio > punteggio_max)
        {
            punteggio_max = punteggio;
            indice = i;
        }
        
    }

    return indice;
}

int punteggio_matching(char *chiave, char *testo, int n)
{
    int i, count = 0;
    
    for(i = 0; i < n; i++)
        if(chiave[i] == testo[i])
            count++;
    
    return count;
}


int max_ind_S(char Stringhe[][50], int n)
{
    int i, i_max;
    
    i_max = 0;
    
    for(i = 0 ; i < n; i++){
        
        if(strcmp(Stringhe[i], Stringhe[i_max]) > 0)
            i_max = i;
        
    }
    return i_max; 
}

void ord_sel_max_S(char array_Stringhe[][50], int n)
{
    int i = 0;
    
    for (i = n-1; i > 0; i--)
    {
        swap_S(array_Stringhe[i], array_Stringhe[max_ind_S(array_Stringhe, i + 1)]);
        
    }
    
}

void swap_S(char *s1, char *s2)
{
    char temp[100];
    strcpy(temp, s1);
    strcpy(s1, s2);
    strcpy(s2, temp);
}


int somma_n_numeri_ric(int n)
{
    // istanza banale
    
    if (n == 0)
        return 0;
    
    else
        // autoattivazione
        return n + somma_n_numeri_ric(n-1);
    
}


int fattoriale(int n)
{
    // istanza banale
    
    if (n == 0)
        return 1;
    
    else
        // autoattivazione
        return n * fattoriale(n-1);
    
}


int Fibonacci(int n)
{
    // istanza banale
    
    if (n <= 1)
        return n;
    
    else
        return Fibonacci(n-1) + Fibonacci(n-2);
    
}
