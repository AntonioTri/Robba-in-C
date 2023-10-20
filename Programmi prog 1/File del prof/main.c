//
//  main.c
//  Esercitazione_2_A_A_2021_2022
//
//  Created by Angelo Ciaramella on 05/10/21.
//

#include "Libreria.h"

int main() {
    
    char testo[100];


    printf("inserire il testo:\n");
    gets(testo);

    //printf ("conta_tutto con strtok: %d\n", conta_tutto_strtok(testo));

    printf ("conta_tutto con standard: %d\n", conta_tutto_standard(testo));
    
    /*
    int n;
    
    printf("Dammi n per il calcolo della somma di Fibonacci \n");
    
    scanf("%d", &n);
    
    printf("\n La somma %d-esima di Fibonacci e': %d \n", n, Fibonacci(n));
    
    */
    
    /*
    int n, i;
    char elenco[][50]={"Pippo","Gastone","Qui","Pluto","zio Paperone","Paperino","Paperina"};
      n = 7;
    
      printf("elenco non ordinato \n");
      for (i=0;i<n;i++)
        printf(" %s\n",elenco[i]);
    
      ord_sel_max_S(elenco,n);
    
    printf("\n elenco ordinato \n");
      for (i=0;i<n;i++)
        printf(" %s\n",elenco[i]);

    */
    /*
    int indice_bm,i;
    char miotesto[50],miachiave[10];
    
    printf("inserire la chiave: ");
    gets(miachiave);
      
    printf("inserire il testo:\n");
    gets(miotesto);
    
    indice_bm = best_string_matching(miachiave, miotesto);
    
    puts("Risultato del best matching\n");
    printf("inizio sottostringa: %d\n sottostringa di best matching:", indice_bm);
      for (i=0; i<strlen(miachiave); i++)
          putchar(miotesto[indice_bm+i]);

    printf("\n"); */
    
    /*
    char miotesto[100], miachiave[20];
     
    int n_occorrenze;
    
    puts("inserire il testo:\n");
    gets(miotesto);

    puts("\ninserire la chiave:\n");
    gets(miachiave);
    
    n_occorrenze = string_matching(miotesto, miachiave);
    
    printf("\n la stringa %s appare %d volte nel testo \n %s\n", miachiave, n_occorrenze, miotesto);
     
     */

    
    /*
    int a[] = {3 , 8 , 1 , 10 , 2}, i;
    
    //ord_ins(a, 5);
    //ord_sel_min(a, 5);
    ord_sel_max(a, 5);
    
    for(i = 0; i < 5 ; i++)
        printf("\n a[%d] = %d", i, a[i]);
    
    printf("\n");
    
     */
    /*
    char testo[100];
    
    //int conta_c,conta_p,conta_l;
    
    printf("dammi il testo \n");
    
    gets(testo);
    
    //conta_tutto(&testo[0], &conta_c, &conta_p, &conta_l);
    
    //printf ("numero di caratteri= %d\n numero di parole = %d\n numero di linee = %d\n",conta_c,conta_p,conta_l);

    printf ("numero di cont %d \n", conta_tutto_strtok(testo));

    */
    
    /*
    char c;
    int conta_c,conta_p,conta_l,in_p;
    conta_c = 0; conta_p = 0; conta_l = 0; in_p = 0;
    
    printf("Inserisci i caratteri \n");
    
    while ((c = getchar())!= EOF) {
        conta_c++;
        if (c == '\n')
           conta_l++;
        if (c == ' '|| c== '\n' || c== '\t')
           in_p = 0;
          else if (in_p == 0) {
               in_p = 1;
                conta_p++;
                }
      }
     printf ("numero di caratteri= %d\n numero di parole = %d\n numero di linee = %d\n",conta_c,conta_p,conta_l);

    */
    
    
    /*
    double A[100][100], media_riga[100];
    int n,m;
    
    printf("inserire il numero di righe (<=100):");
    scanf("%d",&n);
    
    printf("inserire il numero di colonne (<=100):");
    scanf("%d",&m);
    
    legge_da_tastiera_a2Dp(&A[0][0], 100, n, m);
    
    calcolo_media_riga_a2Dp(&A[0][0], 100, n, m, &media_riga[0]);
    
    viasualizza_a2Dp(&A[0][0], 100, n, m);
    
    visualizza_aD(media_riga, n); */

    
    /*
    //int matrice[2][4] = {{1, 2 , 3, 4}, {5, 6, 7, 8}};
    int matrice[2][3] = {{1, 2 , 3}, {4, 5, 6}};
   
    
    visualizza_a2DIp(&matrice[0][0], 3, 2, 2);

    //visualizza_a2DI(matrice, 2, 2);
    */
    /*
    float a[]={76.F,66.F,11.F,-7.F,1.F,18.F,14.F,51.f,44.f,39.F}, massimo;
     int i_ini,i_fin, indice_max;
     
    printf("inserire indice iniziale porzione(<= 10): \n");
     scanf("%d", &i_ini);
     printf("inserire indice finale porzione(>%d e <=10): \n", i_ini);
     scanf("%d", &i_fin);

    max_val_ind(&a[i_ini], i_fin - i_ini + 1, &massimo, &indice_max);
    printf (" \n massimo della porzione %d .. %d: %f\n indice :%d \n",
         i_ini,i_fin,massimo,i_ini + indice_max);

*/
    
    /*
    float a[] = {1.0F, -1.0F, 2.0F, 1.0F, 1.0F, 4.0F, 1.0F , 0.0F}, chiave = -2.0F;

    if(appartiene_aF(chiave, a, 8))
        printf("La chiave appartiene \n");
    else
        printf("La chiave non appartiene \n");
    
    */
    
    /*
    int max, min, a[] = {1, -1, 2, 1, 1, 4, 1 , 0};

    // somma = somma_aI(a, 5);
    
    //max = max_aI(a, 5);
    
    //max_pos_aI(a, 8, &max, &pos);
    
    max_min_aI(a, 8, &max, &min);
    
    printf("Il massimo e' %d e il minimo e' %d\n", max, min); */
    
    
    
    
    /*
    double a[4];
    
    int n;
    
    printf("\n Quanti elementi vuoi inserire (<= 100)? \n");
    scanf("%d", &n);
    
    legge_da_tastiera_apD(&a[0], n);
    
    visualizza_apD(a, n); */
    

    
    
    /*
    int n, f_int;
    float f_float;
    printf("valore di n     fattorialeI      fattorialeF\n");
    for (n = 1; n <= 14; n++)
     {
      f_int = fattorialeI(n);
      f_float = fattorialeF(n);
      printf("%7d %15d %15.0f \n",n,f_int,f_float);

     } */

    
    
    
  /*
    int a, b;
    
    printf("Dammi a:\n");
    scanf("%d", &a);
   
    printf("Dammi b:\n");
    scanf("%d", &b);
   
    swap(&a,&b);
    
    printf("Il valore di a e' %d e il valore di b e' %d \n", a, b);*/
    
    
    /*
    float raggio, circonferenza = 10.0;
    
    printf("Dammi il raggio:\n");
    scanf("%f", &raggio);
    
    circ(raggio, &circonferenza);
    

    printf("La cironferenza del cerchio con raggio %f e' %f \n", raggio, circonferenza);
    
    */
    /*
    float valoreX, valoreY;
    
    
    printf("Dammi il valore x:\n");
    scanf("%f", &valoreX);
 
    printf("Dammi il valore y:\n");
    scanf("%f", &valoreY);
    
    printf("La distanza dall'origine di x = %f e y = %f e' %f \n", valoreX, valoreY, distanza_origF(valoreX, valoreY)); */
    /*
    float valore;
    
    printf("Dammi il valore :\n");
    scanf("%f", &valore);
    
    printf("Il valore assoluto del numero %f e' %f \n", valore, valore_assolutoF(valore));
    */
    
    /*float raggioMax, raggioMin, areaCorona;
    
    printf("Dammi il raggio Max del cerchio :\n");
    scanf("%f", &raggioMax);
    
    printf("Dammi il raggio Min del cerchio :\n");
    scanf("%f", &raggioMin);
    
    areaCorona = area_corona(raggioMax, raggioMin);
    
    printf("L'area dell corona cirocolare e' %f \n", areaCorona);*/
    
    
    
    /*
    float raggio, circonferenza, area;
    
    printf("Dammi il raggio:\n");
    scanf("%f", &raggio);
    
    circonferenza = circon(raggio);
    
    area = area_cerchio(raggio);
    
    printf("La cironferenza del cerchio con raggio %f e' %f e l'area e' %f \n", raggio, circonferenza, area); */
    
    return 0;
}



