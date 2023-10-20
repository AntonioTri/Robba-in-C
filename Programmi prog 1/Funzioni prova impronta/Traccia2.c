#include <stdio.h>
#include <math.h>

#define N 3

typedef struct 
{
    double x;
    double y;
} punto ;

void distanza_minima(punto *, int , int *, int *);

int main (){

    int n=N;
    punto punti[N];
    int indice1;
    int indice2;

    for (int j = 0; j < N; j++)
    {
        printf("Inserisci ascissa del punto %d: ", j+1);
        scanf("%lf", &punti[j].x);
        printf("Inserisci ordinata del punto %d: ", j+1);
        scanf("%lf", &punti[j].y);
    }
    
    for ( int i = 0; i < N; i++)
    {
        printf("Il punto %d ha ascissa %.2lf ed ordinata %.2lf\n", i+1, punti[i].x, punti[i].y);
    }
    
    distanza_minima(punti, n, &indice1, &indice2);

    printf("La distanza minima la hanno i punti %d e %d", indice1+1, indice2+1);

}


void distanza_minima(punto *punti, int n, int *indice1, int *indice2){

        int i, j;
        double distanza_minima=21000000;
        double dist;

        for ( i = 0; i < n; i++)
        {
            for ( j = i+1; j < n; j++)
            {
                dist = sqrt(pow(punti[i].x + punti[j].x, 2) + pow(punti[i].y + punti[j].y, 2));

                if (dist < distanza_minima)
                {
                    distanza_minima = dist;
                    *indice1=i;
                    *indice2=j;
                    
                }
                
            }
            
        }
        
}