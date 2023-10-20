/*
	Scrivere un programma per simulare l'inserimento di un PIN per il telefonino.
	Nella prima fase viene costruito il PIN di riferimento,che deve essere di
	lunghezza 5 e che deve essere costruito in modo casuale.
	Nella seconda fase l'utente inserisce il codice di tentativo e ha al massimo
	3 tentativi per indovinarlo. 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (){

    srand(time(NULL));
    int pin;
    int pin_inserito;
    char risposta;

    do {

        int tentativi = 2;
        pin = 10000 + rand() + rand() + rand() % 22766;
        printf("Il Pin generato e': %d\n", pin);
    
        while (tentativi >= 0){

            printf("\nInserisci PIN:\n");
            scanf("%d", &pin_inserito);

            if (tentativi == 0)
            {
                printf("\nHai finito i tentativi!\n\n");
                break;
            }


            if (pin_inserito != pin)
            {
                printf("\nHai sbagliato! Ti restano %d tentativi.\n", tentativi);
                tentativi--;

            } else {
            
                printf("\nCongratuazioni! Hai inserito il PIN giusto.\n\n");
                break;

            }

        }

        printf("Vuoi riprovare? (s/n): ");
        scanf(" %c", &risposta);
        printf("\n*****************************\n\n");


    } while (risposta == 's');
    
    

}