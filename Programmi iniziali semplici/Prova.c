#include <stdio.h>
void main()
{ /* Inizio del main */
int base,altezza,area;
printf("Inserire: base altezza\n");
scanf("%d %d",&base,&altezza); /* & restituisce l’indirizzo*/
/* Codici di formato per la scanf
 Codice Variabile
 %d intera
 %c carattere
 %f float
 %lf double */
area = base * altezza;
 printf("L'area del rett. di base");
 printf(" %d e alt. %d e' %d\n",base,altezza,area);
 
}