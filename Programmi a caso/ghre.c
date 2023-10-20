#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int main(){

    char frase [100] = {"Prova di scrittura lenta!\n"};
    frase[strcspn(frase, "\n")] = '\0';

    for (int i = 0; i <= sizeof(frase); i++)
    {
        printf("%c",frase[i]);
        usleep(200000);
    }
    

}