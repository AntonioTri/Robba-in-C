/*
	Due giocatori si sfidano lanciando un dado truccato. Il dado ha dei valori
	interi nell'intervallo[5,15]. A ogni turno vince il giocatore che ottiene un
	puntaggio maggiore. In caso di parità il punto viene assegnato a entrambi.
 	Simulare 10 sfide e visualizzare il giocatore che vince più volte.  
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int giocatore;
    int punteggio;

} partecipanti;



int main(){

    partecipanti giocatori[2];



    char risposta;

    do{

        srand(time(NULL));
        int k = 0;

        giocatori[0].giocatore = 1;
        giocatori[1].giocatore = 2;

        giocatori[0].punteggio = 0;
        giocatori[1].punteggio = 0;

        while (k<10)
        {         
            printf("\nPremi Invio per continuare...\n");
            while (getchar() != '\n');
            

            printf("\t\tTurno %d:\n\n", k+1);

            int tiro_gioc_1 = rand() %11 + 5;
            int tiro_gioc_2 = rand() %11 + 5;

            if ( tiro_gioc_1 > tiro_gioc_2 )
            {
                printf("Il Giocaore 1 tira il dado e ... e' uscito %d !\n", tiro_gioc_1);
                printf("Il Giocaore 2 tira il dado e ... e' uscito %d !\n", tiro_gioc_2);
                printf("Il turno %d lo vince il Giocatore 1!\n\n", k+1);
                giocatori[0].punteggio++;

                printf("Il Giocatore 1 e' a %d punti, ed il Giocatore 2 e' a %d punti\n", giocatori[0].punteggio, giocatori[1].punteggio);

                } else if (tiro_gioc_2 > tiro_gioc_1)
                    {
                        printf("Il Giocaore 1 tira il dado e ... e' uscito %d !\n", tiro_gioc_1);
                        printf("Il Giocaore 2 tira il dado e ... e' uscito %d !\n", tiro_gioc_2);
                        printf("Il turno %d lo vince il Giocatore 2!\n\n", k+1);
                        giocatori[1].punteggio++;

                        printf("Il Giocatore 1 e' a %d punti, ed il Giocatore 2 e' a %d punti\n", giocatori[0].punteggio, giocatori[1].punteggio);

                     } else if (tiro_gioc_1 == tiro_gioc_2)
                         {
                              printf("Il Giocaore 1 tira il dado e ... e' uscito %d !\n", tiro_gioc_1);
                              printf("Il Giocaore 2 tira il dado e ... e' uscito %d !\n", tiro_gioc_2);
                              printf("Il turno %d finisce pari!\n\n", k+1);

                              giocatori[0].punteggio++;
                              giocatori[1].punteggio++;

                              printf("Il Giocatore 1 e' a %d punti, ed il Giocatore 2 e' a %d punti\n", giocatori[0].punteggio, giocatori[1].punteggio);
            
                         }
        
            k++;

        }
        
        if (giocatori[0].punteggio > giocatori[1].punteggio)
        {
            printf("Questo match se lo aggiudica il Giocatore 1 con un totale di %d punti!\n", giocatori[0].punteggio);

        }else if (giocatori[0].punteggio < giocatori[1].punteggio)
        {
            printf("Questo match se lo aggiudica il Giocatore 2 con un totale di %d punti!\n", giocatori[1].punteggio);
        } else if (giocatori[0].punteggio = giocatori[1].punteggio)
        {
            printf("Questo match finisce in paritá!\n");
        }
        
        
        printf("\nVuoi fare un'altra simulazione? (s/n):\n");
        scanf("%c", &risposta);
        printf("/****************************************************************************/\n\n");

    } while (risposta == 's');
    

}