#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "libreria_autoscontro.h"

#define GRANDEZZA_PISTA 8

void stampa_pista(posizione *, int);

void muovi_macchina(posizione *, int , int );

int scelta_movimento_ricorsiva(posizione *, float , float , float , float );

float distanza_ricorsiva( float, float, float, float);

void movimento_destra(posizione *, int , int , int , int , int );

void movimento_sinistra(posizione *, int , int , int , int , int );

void movimento_in_basso(posizione *, int , int , int , int , int );

void movimento_in_alto(posizione *, int , int , int , int , int );

int main (){

    //creo l'array struct delle posizioni ed assegno i valori di partenza alle auto
    posizione pos_auto[4];

    pos_auto[0].x = 0; // ! x é la riga !
    pos_auto[0].y = 4; // ! y é la colonna !

    pos_auto[1].x = 3; // ! x é la riga !
    pos_auto[1].y = 0; // ! y é la colonna !

    pos_auto[2].x = 4; // ! x é la riga !
    pos_auto[2].y = 7; // ! y é la colonna !

    pos_auto[3].x = 7; // ! x é la riga !
    pos_auto[3].y = 3; // ! y é la colonna !

    // Creo delle variabili per la posizione dello scontro e per l'avenimento di quest'ultimo
    int scontro = 0;
    int posizione_scontro_x, posizione_scontro_y;
    int n = GRANDEZZA_PISTA;
    int z = 1;

    // Imposto il seed per la funzione rand() che genera numeri pseudocasuali dandole come argomento 
    // il tempo di utilizzo della macchina su cui parte il codice
    srand(time(NULL));

    // Mostro la pista a valori iniziali
    printf("    Partenza!\n\n");
    stampa_pista(pos_auto, n);

    // Scrivo l'attuale posizione delle auto
    printf("\nLa posizione di partenza delle auto e':\n");
        for (int i = 0; i < 4; i++){
            printf("L'auto %d si trova in: (%d, %d).\n", i+1, pos_auto[i].x+1, pos_auto[i].y+1);
        }
        printf("\n");

    // Inizio a ciclare i movimenti fin quando due auto non sono nella stessa posizione (ció indicherebbe uno scontro)
    while (!scontro)
    {
        printf("\nPremi Invio per continuare...\n");
        while (getchar() != '\n');

        // Ora tramite una procedura, vado a modificare in base alle condizioni individuali delle auto
        // la posizione di ogniuna di esse tramite la funzione muovi_macchina()
        for (int i = 0; i < 4; i++)
            muovi_macchina(pos_auto, i, n);
        printf("\n    Turno %d:\n", z);
        z++;

        //Si mostra la pista con le posizioni variate
        stampa_pista(pos_auto, n);

        // Scrivo l'attuale posizione delle auto
        printf("\nLa posizione attuale delle auto e':\n");
        for (int i = 0; i < 4; i++)
            printf("L'auto %d si trova in: (%d, %d).\n", i+1, pos_auto[i].x+1, pos_auto[i].y+1);
        printf("\n");        
        
        // Ed ora tramite questi cicli for annidati si effettua il controllo per vedere se due macchine hanno la stessa posizione
        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                // Se due auto hanno la stessa posizione viene "attivato" lo stato di scontro
                // e vengono registrate le sue coordinate
                if (pos_auto[i].x == pos_auto[j].x && pos_auto[i].y == pos_auto[j].y)
                {    
                    scontro = 1;
                    posizione_scontro_x = pos_auto[i].x;
                    posizione_scontro_y = pos_auto[i].y;
                    break;
                }

            }
            
        }

    
    }

    // Usciti dal while nel caso in cui avvenga uno scontro si stampa il punto in cui esso é avvenuto 
    // e la simulazione finisce :)
    printf("\nLo scontro e' avvenuto alla posizione (%d, %d) nel turno %d.\n", posizione_scontro_x+1, posizione_scontro_y+1, z-1);

}


