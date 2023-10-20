#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(){

    srand(time(NULL));

    char a;

    int contatore = 0;

    system("COLOR 0A");

    for (;;)
    {
        for (short i = 0; i < 10; i++)
        {
            
            for (short i = 0; i < 10; i++)
            {
                a = rand() % 32 + 33;
                printf("%c", a);
            }
        
            printf("  ");

        }
        
        usleep(15000);

        //Sleep(40);
        
        contatore ++;
        printf("\n");

        if (contatore >= 200)
        {
            break;
        }
        
    }

}