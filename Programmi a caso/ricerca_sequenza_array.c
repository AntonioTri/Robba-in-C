#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 160
#define SEQUENCE_LENGTH 3

int main()
{
    char letters[ARRAY_SIZE];
    char sequence[SEQUENCE_LENGTH];
    int flag;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random upper case letters
    for (int i = 0; i < ARRAY_SIZE; i++)
        letters[i] = 'A' + rand() % 26;
    // Generate random upper case letters sequence to found
    for (int i = 0; i < SEQUENCE_LENGTH; i++)
        sequence[i] = 'A' + rand() % 26;        

        printf("La sequenza e':\n ");
    for (int i = 0; i < ARRAY_SIZE/4; i++)
        printf("%c ", letters[i]);
        printf("\n");
    for (int i = (ARRAY_SIZE/4)+1; i < ARRAY_SIZE/2; i++)
        printf(" %c", letters[i]);
        printf("\n");
    for (int i = (ARRAY_SIZE/2)+1; i < (ARRAY_SIZE/4)*3; i++)
        printf(" %c", letters[i]);
        printf("\n");
    for (int i = ((ARRAY_SIZE/4)*3)+1; i < ARRAY_SIZE; i++)
        printf(" %c", letters[i]);
        printf("\n");


        printf("La sequenza da trovare e':\n ");
    for (int i = 0; i < SEQUENCE_LENGTH; i++)
        printf("%c ", sequence[i]);  
        printf("\n");      

    // Search for a sequence of three consecutive letters
    for (int i = 0; i < ARRAY_SIZE - SEQUENCE_LENGTH + 1; i++)
    {
        for (int j = 0; j < SEQUENCE_LENGTH; j++)
        {
            if (letters[i + j] != sequence[j])
            {
                flag = 1;
                break;
            } else 
                flag = 0;
        }

        if (flag==0)
        {
            printf("La sequenza e' stata trovata all'indice %d: ", i);
            for (int j = 0; j < SEQUENCE_LENGTH; j++)
                printf("%c", letters[i + j]);
            printf("\n");
            break;
        }
    }

    if (flag!=0)
        printf("Sequence not found\n");

    return 0;
}
