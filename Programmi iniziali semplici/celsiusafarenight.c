#include <stdio.h>
//#include <math.h>

int main(){

    float temp;

    printf("Inserisci i gradi Centigradi da convertire in frhenit: \n");
    scanf("%f", & temp);
    
    temp = (temp * 9 / 5) + 32;

    printf("%.1f gradi farhenit\n", temp);

}