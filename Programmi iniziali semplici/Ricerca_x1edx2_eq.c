#include <stdio.h>
#include <math.h>

int main (){

int a,b,c;
float x1, x2, delta;
 
    printf("Inserisci i coefficienti a, b, c della equazione\n");
    scanf("%d %d %d", &a, &b, &c);
    printf("Hai inserito a = %d, b = %d, c = %d \n", a, b, c);

    delta = b*b - 4*(a*c);

    if (a == 0){

    printf("Hai inserito a = 0, l'equazione non e' di secondo grado brutto mongolo!\n");    
    
        } else if (delta > 0) {

    printf("il delta e' uguale a %.1f\n", delta);

    x1 = (-b + sqrt(delta))/2*a;
    x2 = (-b - sqrt(delta))/2*a;

    printf("E' maggiore di 0 quindi le soluzioni sono:\n x1 = %.1f \n x2 = %.1f \n", x1, x2);
    
        } else if (delta == 0) {

    printf("il delta e' uguale a %.1f\n", delta);

    x1 = -b/2*a;

    printf("Quindi la soluzione e' unica ed uguale a \n %.1f \n", x1, x2);

        } else{
         printf("il delta e' uguale a %.1f\n", delta);
         printf("E' minore di 0 quindi non ci sono soluzioni reali.");
    }
    

}


