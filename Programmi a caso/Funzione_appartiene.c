#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int appartiene(int [], int, int);

int main (){

    int x, exit_value, a[10]={1,2,3,4,5,6,7,8,9,10}, n = sizeof(a)/sizeof(a[0]);
    char risposta;

    do
    {
      
        printf("Inserisci un numero tra 1 e 10\n");
        scanf("%d", &x);
        printf("\n");
    
          if (appartiene(a, n, x)==1)
         {
             printf("Il numero inserito e' un numero tra 1 e 10\n");
         }else if (appartiene(a, n, x)==0)
         {
             printf("Il numero non e' compreso tra 1 e 10\n");
         }

        printf("\n Vuoi rifarlo? (Y/N):\n");
        scanf("%c");
        scanf("%c", &risposta);
        risposta = toupper(risposta);
  
    } while (risposta == 'Y');
     
    printf("Se e' comparsa questa scritta significa che sei uscito dal do while\n\n");

}


int appartiene(int a[], int n, int x){

    int i, flag = 0;

    for ( i = 0; i < n; i++)
    {
       if (a[i]==x)
       {
        flag=1;
       }      
    }

    return flag;
    
}
