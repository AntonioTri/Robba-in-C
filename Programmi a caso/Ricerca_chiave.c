#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SYZE 80
#define SEQ_LENGHT 3

void ricerca_chiave(char [], char [], int , int, int *);

int main (){

    int i, j, indice=-1;
    int size_a=ARRAY_SYZE;
    int size_key=SEQ_LENGHT;
    char a[ARRAY_SYZE];
    char key[SEQ_LENGHT];
    char carattere;
    
    srand(time(NULL));

    for ( i = 0; i < ARRAY_SYZE; i++)
    {
        a[i]=  'A' + rand() % 26;
    }
    
    i=0;
    printf("L'array e':\n\n");
    for ( i = 0; i < ARRAY_SYZE/2; i++)
    { 
        printf("%c ", a[i]);
    } 
    
    i=0; 
    printf("\n");
    for ( i = (ARRAY_SYZE/2)+1; i < ARRAY_SYZE; i++)
    { 
        printf("%c ", a[i]);
    }    
    printf("\n\n");

    for ( int j = 0; j < SEQ_LENGHT; j++)
    {
        printf("Inserisci la lettera %d di %d della sequenza che vuoi ricercare:\n", j+1, SEQ_LENGHT);
        scanf(" %c", &key[j]);
    }

    strupr(key);
    j=0;
    
    printf("\n");
    printf ("La tua sequenza da ricercare e': \n");

    for ( j = 0; j < SEQ_LENGHT; j++)
    {
        printf("%c ", key[j]);
    }
    printf("\n");

    ricerca_chiave(a, key, size_a, size_key, &indice);

    if (indice>=0)
    {
        printf("\nLa sequenza e' stata trovata all' indice %d\n", indice);
    } else
    {
        printf("\nLa chiave non e' stata trovata.\n");
    }
    
    
}


void ricerca_chiave(char a[], char key[], int size_a, int size_key, int *indice){

    int i;

    for ( i = 0; i < size_a-size_key+1; i++)
    {
        if (a[i]==key[0] && a[i+1]==key[1] && a[i+2]==key[2])
        {
            *indice=i;
             break;
        }
           
    }

}

/*
int ricerca_chiave(int a[], int key[], int size_a, int size_key, int *indice){

    int i;
    for ( i = 0; i < size_a - size_key; i++)
    {
        
        if (a[i] == key[0])
        {   
            int flag = 1;

            for ( int k = 0; k < size_key; k++)
            {   
                if (a[i+k] != key[k])
                {
                    flag = 0;
                    break;
                }
                if (flag){
                    *indice =1;
                    return 1;
                }

            } 
            
        }  
            
    }  
    return 0;
}
*/