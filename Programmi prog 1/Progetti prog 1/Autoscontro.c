#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define GRANDEZZA_PISTA 8

typedef struct {
  int x;
  int y;
} posizione ;

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
        
        // Ed ora si effettua il controllo tramite un algoritmo sequenziale se due macchine hanno la stessa posizione
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


// Qui troviamo la procedura che ci mostra la pista con le auto
void stampa_pista(posizione *pos_auto, int n){

    // Andiamo a definire la pista come una matrice n x n di tutti 0 e ...
    int pista[n][n];
    for (int i = 0; i < n; i++)
    {
        for ( int j = 0; j < n; j++)
        {
            pista[i][j] = 0;
        }
    }
    
    // ... sostituiamo con 1, 2, 3, 4 le 4 macchine presenti sulla pista
    int k=1;
    for (int i = 0; i < 4; i++){

        pista[pos_auto[i].x][pos_auto[i].y] = k;
        k++;
    
    }
    // nel caso ci sia uno scontro, tramite qusto controllo 
    // viene segnato il punto con il numero '5'

        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                // se due auto hanno la stessa posizione viene "attivato" lo stato di scontro
                if (pos_auto[i].x == pos_auto[j].x && pos_auto[i].y == pos_auto[j].y)
                {
                    pista[pos_auto[i].x][pos_auto[j].y] = 5;   
                }
            }
            
        }
    
    // ora si mostra la pista a schermo 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", pista[i][j]);
        }
        printf("\n");
    }
    // ! Osservazione, a tutti gli indici i e j vengono fatte le assegnazioni all'interno dei cicli for per facilitare la lettura
    //   del codice e per resettare il loro valore ad ogni iterazione della funzione in modo piú semplice !
}

// Procedura per il movimento delle auto
void muovi_macchina(posizione *pos_auto, int nro_macchina, int n){

    // Creo delle variabili locali per il calcolo proabilistico delle percentuali, a e b saranno gli estremi 
    // insiemistici della percentuale da utilizzare per le funzioni movimento
    int nro = 0;
    int a = 0;
    int b = 0;

    // genero un numero casuale da usare come proabilitá di percentuale
    nro = rand() % 100 + 1;

    // In base all'indice i del ciclo for dedicato al movimento all'interno della funzione main, scegliamo 
    // il caso della macchina in cui ci troviamo con uno swich case: 

    switch (nro_macchina)
    {

        /* Quando siamo nel caso 0, nelle percentuali di movimento a sinistra e destra, 
           che equivalgono sommate al 30% dei casi, richiamo la funzione del movimento due volte; 
           la prima volta passo come argomento l'attuale indice dell'auto '0', la seconda invece gli sommo 1,
           cosí da permettere anche alla due di muoversi come la 1 al 30% dei casi.

           Negli restante 70 % dei casi rimanenti, richiamo invece funzioni di movimento opposte,
           cosí da fare muovere la macchina 1 e la 2, in direzioni diverse, sempre pareti permettendo */
      
        case 0:

            if (nro <11) // 6
            {
                a=1; b=11;
                /* Percentuale del 10%, movimento a sinistra per la 1 e la 2 */

                movimento_sinistra(pos_auto, nro_macchina, nro, a, b, n);
                movimento_sinistra(pos_auto, nro_macchina+1, nro, a, b, n);           

            } else if (nro > 10 && nro < 31)
            {
                a=11; b=30;
                /* Percentuale del 30%, movimento a destra per la 1 e la 2 */

                movimento_destra(pos_auto, nro_macchina, nro, a, b, n);
                movimento_destra(pos_auto, nro_macchina+1, nro, a, b, n);
            
            } else if (nro > 30 && nro < 61)
            {
                a=31; b=60;
                /* Percentuale del 30%, movimento in giú per la 1, in sú per la 2*/

                movimento_in_basso(pos_auto, nro_macchina, nro, a, b, n);
                movimento_in_alto(pos_auto, nro_macchina+1, nro, a, b, n);

            } else if (nro > 60 && nro <101)
            {
                a=61; b=100;
                /* Percentuale del 40%, movimento in sú per la 1, ed in giú per la 2 */

                movimento_in_alto(pos_auto, nro_macchina, nro, a, b, n);
                movimento_in_basso(pos_auto, nro_macchina+1, nro, a, b, n);
            }
            
            break;

        // Il caso 1 non é presente poiché incorporato nel caso 0

        // Caso 2 per il movimento della macchina 3, 
        case 2:

            if (nro > 5 && nro <26) // 6
            {
                a=6; b=25;
                /* Movimento a sinistra per il 20% */

                movimento_sinistra(pos_auto, nro_macchina, nro, a, b, n);
                
            } else if (nro > 25 && nro < 56)
            {
                a=26; b=55;
                /* Movimento a destra per il 30% */

                movimento_destra(pos_auto, nro_macchina, nro, a, b, n);

            } else if (nro > 55 && nro < 101)
            {
                a=56; b=100;
                /* Movimento in giú per il 45% */

                movimento_in_basso(pos_auto, nro_macchina, nro, a, b, n);                 

            } else if (nro < 6)
            {
                a=1; b=5;
                /* Movimento in sú per il 5% */

                movimento_in_alto(pos_auto, nro_macchina, nro, a, b, n);

            }
            
            break;

        /* É un caso diverso dagli altri poiché questa macchina non si muove randomicamente ma 'insegue'
            le altre macchine utilizzando una funzione ricorsiva */
        case 3:

                /* Viene assegnato il valore alla direzione ad 1, 2, 3 o 4, valore restituito dalla funzione
                    di scelta movimento */
                int direzione = scelta_movimento_ricorsiva(pos_auto, 20, 20, 20, 20);

                /* In base al suo valore si sceglie la direzione che la 4 deve prendere per insegure la macchina
                   piú vicina a lei */
                if (direzione == 1)
                {
                    //La macchina va in alto
                    movimento_in_alto(pos_auto, nro_macchina, 100, 1, 100, n);

                } else if (direzione == 2)
                {
                    // La macchina va a destra
                    movimento_destra(pos_auto, nro_macchina, 100, 1, 100, n);

                } else if (direzione == 3)
                {
                    // La macchina va a sinistra
                    movimento_sinistra(pos_auto, nro_macchina, 100, 1, 100, n);

                } else if (direzione == 4)
                {
                    // La macchina va in basso
                    movimento_in_basso(pos_auto, nro_macchina, 100, 1, 100, n);

                }
                
            break;

       default:

            break;
    }

}

// Procedura movimento verso destra
void movimento_destra(posizione *pos_auto, int nro_macchina, int nro, int a, int b, int n){

            /* Vengono calcolati i valori per le probailitá di 1/2 e di 1/3 per i casi in cui
               vi sia una parete sulla destra che impedisce il movimento in quella direzione. Il calcolo
               viene svolto utilizzando i parametri insiemistici a e b richiamati dalla funzione muovi_macchina */

            int mediano_a_b = (a+b)/2;
            int primo_terzo = a + ((b - a) / 3.0);
            int secondo_terzo = a + (2 * ((b - a) / 3.0));

                    /* destra */

                // Se si trova dalla colonna 0 alla 6 il movimento é permesso
                if (pos_auto[nro_macchina].y < n - 1)
                {
                    pos_auto[nro_macchina].y++;

                } // altrimenti se si trova alla colonna di estrema destra, deve controllare i tre casi
                else if (pos_auto[nro_macchina].y == n - 1)
                {

                // se si trova in alto a destra, i movimenti permessi sono a sinistra ed in basso
                if (pos_auto[nro_macchina].x==0)
                {
                    if (nro<mediano_a_b)
                        pos_auto[nro_macchina].y--;
                     else
                        pos_auto[nro_macchina].x++;    

                } // se si trova in basso a destra, movimenti permessi sono sù e sinistra
                else if(pos_auto[nro_macchina].x==7)
                {
                     if (nro<mediano_a_b)
                        pos_auto[nro_macchina].y--;
                     else
                        pos_auto[nro_macchina].x--;
                } // colonna di estrema destra, esclusi gli angoli, movimenti permessi giù, sù, sinistra
                else if (pos_auto[nro_macchina].x > 0 && pos_auto[nro_macchina].x < n - 1 )
                    {
                        if (nro>=a && nro<primo_terzo)
                            pos_auto[nro_macchina].x--;
                        else if (nro>= secondo_terzo && nro < secondo_terzo)
                            pos_auto[nro_macchina].x++;
                        else if (nro >= secondo_terzo)
                            pos_auto[nro_macchina].y--;
                    
                    }
                
                                   
            }  

}

// Procedura movimento verso sinistra
void movimento_sinistra(posizione * pos_auto, int nro_macchina, int nro, int a, int b, int n){

            int mediano_a_b = (a+b)/2;
            int primo_terzo = a + ((b - a) / 3.0);
            int secondo_terzo = a + (2 * ((b - a) / 3.0));

                    /* sinistra */

                // Se si trova dalla colonna 1 in poi i movimenti a sinistra sono permessi
                if (pos_auto[nro_macchina].y > 0)
                {
                    pos_auto[nro_macchina].y--;

                } // altrimenti bisogna controllare in quale delle tre posizioni della colonna 0 si trova 
                else if (pos_auto[nro_macchina].y == 0)
                {
                    // in alto a sinistra, permette quindi solo movimenti in basso e a destra
                    if (pos_auto[nro_macchina].x==0)
                    {
                        if (nro<mediano_a_b)
                            pos_auto[nro_macchina].y++; 
                         else
                            pos_auto[nro_macchina].x++;  

                    } // in basso a sinistra, permette solo movimenti in alto e a destra
                    else if(pos_auto[nro_macchina].x==7)
                    {
                        if (nro<mediano_a_b)
                            pos_auto[nro_macchina].y++;
                         else
                            pos_auto[nro_macchina].x--;

                    } // in una posizione sul bordo sinistro che non siano gli angoli, movimenti permessi
                      // alto, basso, destra
                    else if (pos_auto[nro_macchina].x > 0 && pos_auto[nro_macchina].x < n -1 )
                        {
                            if (nro>=a && nro<primo_terzo)
                                pos_auto[nro_macchina].x--;
                            else if (nro >= primo_terzo && nro <secondo_terzo)
                                pos_auto[nro_macchina].x++;
                            else if (nro >=secondo_terzo && nro < b)
                                pos_auto[nro_macchina].y++;

                    }
                    
                                       
                }
}

// Procedura movimento verso l'alto
void movimento_in_alto(posizione * pos_auto, int nro_macchina, int nro, int a, int b, int n){

            int mediano_a_b = (a+b)/2;
            int primo_terzo = a + ((b - a) / 3.0);
            int secondo_terzo = a + (2 * ((b - a) / 3.0));

                /* sú */

                // se la posizione è dalla riga 1 in giù, sono permessi movimenti verso l'alto    
                if (pos_auto[nro_macchina].x > 0)
                {
                    pos_auto[nro_macchina].x--;
                } 
                // altrimenti ci sono i tre casi
                else if (pos_auto[nro_macchina].x == 0 )
                {
                    // caso in alto a sinistra, movimenti permessi destra ed in basso
                    if (pos_auto[nro_macchina].y==0)
                    {
                        if (nro<mediano_a_b)
                            pos_auto[nro_macchina].y++;
                         else
                            pos_auto[nro_macchina].x++; 

                    } // caso in alto a destra, movimenti permessi in basso e a sinistra
                    else if(pos_auto[nro_macchina].y==7)
                    {
                        if (nro>=mediano_a_b)
                            pos_auto[nro_macchina].y--;
                         else
                            pos_auto[nro_macchina].x++;

                    } // caso riga 0 esclusi gli angoli, movimenti permessi giù, sinistra, destra
                    else if (pos_auto[nro_macchina].y > 0  && pos_auto[nro_macchina].y <  n - 1)
                        { 
                            if (nro >= a && nro < primo_terzo)
                                pos_auto[nro_macchina].y--;
                            else if (nro >= primo_terzo && nro < secondo_terzo)
                                pos_auto[nro_macchina].y++;
                            else if (nro>=secondo_terzo)
                                pos_auto[nro_macchina].x++;
                            
                        }
                            
                                       
                }               
}

// Procedura movimento verso il basso
void movimento_in_basso(posizione * pos_auto, int nro_macchina, int nro, int a, int b, int n){

            int mediano_a_b = (a+b)/2;
            int primo_terzo = a + ((b - a) / 3.0);
            int secondo_terzo = a + (2 * ((b - a) / 3.0));

                /* giú */

                // se la posizione orizzontale è massimo fino alla riga 6, può ancora scendere di 1
                if (pos_auto[nro_macchina].x < n - 1)
                {
                    pos_auto[nro_macchina].x++;

                } // altrimenti se la sua posizione è nella riga finale bisogna vedere se é nell' ... 
                else if (pos_auto[nro_macchina].x == 7 )
                {
                    // ... angolo in basso a sinistra, movimenti permessi sù e destra
                    if (pos_auto[nro_macchina].y==0)
                    {
                        if (nro<mediano_a_b)
                            pos_auto[nro_macchina].y++;
                         else
                            pos_auto[nro_macchina].x--; 

                    } // ... angolo in basso a destra, movimenti permessi sù e sinistra
                    else if(pos_auto[nro_macchina].y==7)
                    {
                        if (nro>=mediano_a_b)
                            pos_auto[nro_macchina].y--;
                         else
                            pos_auto[nro_macchina].x--;

                    } // ... riga finale eccetto gli angoli, movimenti permessi sù, destra, sinistra
                    else if (pos_auto[nro_macchina].y >0 && pos_auto[nro_macchina].y <  n- 1)
                        { 
                            if (nro >= 31 && nro < 41)
                                pos_auto[nro_macchina].y--;
                            else if (nro >= 41 && nro < 51)
                                pos_auto[nro_macchina].y++;
                            else if (nro>=51)
                                pos_auto[nro_macchina].x--;
                            
                        }
                            
                                       
                }                    
}

// Funzione della quarta auto, per la scelta del movimento 
int scelta_movimento_ricorsiva(posizione *pos_auto, float N, float S, float E, float W){

    /* L'idea dietro all'algoritmo é la seguente:
       bisogna ricercare dalla 4 l'auto che ha la distanza minima da essa e conservarne il suo indice. 
       Successivamente analizzare quale delle 4 direzioni cardinali rispetto al punto 4, 
       ha la distanza minima dall'auto di indice minimo trovata precedentemente. Far spostare poi l'auto 4 
       nella sua direzione cardinale con minore distanza rispetto all'auto piú vicina. */ 
    

    // Ora, l'algoritmo funziona nel seguente modo:

    /* Caso base: le posizioni cardinali non sono calcolate inizialmente, cosí come non lo é la distanza minima 
       tra le auto. Il caso base viene cosí saltato. Durante la chiamata ricorsiva peró, i valori di N, S, E, W
       saranno stati calcolati e tramite i seguenti confronti, si decide quale valore ritornare alla funzione: 
       muovi_macchina() per decidere il movimento della 4 */ 

    if (N != 20 && S != 20 && E != 20 && W != 20 )
    {
          //Se la distanza NORD é la minore la funzione ritorna 1
        if (N < S && N <= E && N <= W )
        {
         return 1;

        } //Se la distanza OVEST é la minore la funzione ritorna 2
        else if (W < E && W <= S && W <= N)
        {
          return 2;

        } //Se la distanza SUD é la minore la funzione ritorna 4
        else if (S < N && S <= W && S <= E )
        {
          return 4;

        } //Se la distanza EST é la minore la funzione ritorna 3
        else if (E < W && E <= S && E <= N)
        {          
          return 3;

        }
            
    } else // Vengono calcolati i casi base necessari alla ricorsione
    {

      int i=0;
      int ind_auto_piu_vicina;
      float distaza_attuale = 0;
      float distanza_minima = 15;

      // Andiamo a trovare qui il numero della macchina piú vicina tramite un calcolo ricorsivo della distanza e ...
      for ( i = 0; i < 3; i++)
      {

            distaza_attuale = distanza_ricorsiva(pos_auto[3].x, pos_auto[3].y, pos_auto[i].x, pos_auto[i].y);

            if (distaza_attuale <= distanza_minima)
            {
              distanza_minima = distaza_attuale;
              ind_auto_piu_vicina = i;
            }
                
      }
      
      // ... lo andiamo ad utilizzare per calcolare la distanza, sempre in modo ricorsivo tra i punti cardinali e la macchina piú vicina

      N = distanza_ricorsiva(pos_auto[3].x-1, pos_auto[3].y, pos_auto[ind_auto_piu_vicina].x, pos_auto[ind_auto_piu_vicina].y);
      S = distanza_ricorsiva(pos_auto[3].x+1, pos_auto[3].y, pos_auto[ind_auto_piu_vicina].x, pos_auto[ind_auto_piu_vicina].y);
      W = distanza_ricorsiva(pos_auto[3].x, pos_auto[3].y+1, pos_auto[ind_auto_piu_vicina].x, pos_auto[ind_auto_piu_vicina].y);
      E = distanza_ricorsiva(pos_auto[3].x, pos_auto[3].y-1, pos_auto[ind_auto_piu_vicina].x, pos_auto[ind_auto_piu_vicina].y);

    /*  La funzione ora si richiama da sola con i valori cardinali calcolati
        permettendole cosí di restitire un valore intero con il quale, nella funzione movimento,
        scegliere dove andare */

      return scelta_movimento_ricorsiva(pos_auto, N, S, E, W);

    }
    
    
}

// Funzione calcolo distanza ricorsiva
float distanza_ricorsiva( float xp1, float yp1, float xp2, float yp2) {
    
  /* Il caso base é quello in cui la distanza tra un punto ed il mediano, é minore di 1, si richiede quindi
     una certa precisione.
     
     La funzione utilizza i mediani per le ascisse e le ordinate e calcola la distanza tra punto ed il mediano. Quando la distanza 
     tra una coordinata ed il suo mediano é abbastanza precisa, ritorna il valore della distaza della prima metá, sommata alla distanza
     della seconda metá.
     L'approccio utilizzato é dunque l' "Appriccio DIVIDE ET IMPERA" */

    // Si calcola l'attuale distanza
     float dist = sqrt(pow(xp2-xp1, 2) + pow(yp2-yp1, 2));

  // Si controlla la sua precisione e si restituisce in caso vada bene (si é scelto 1 perché é la distanza tra due macchine adiacenti)
  if (dist<=1) 
  {
    return dist;

  } // Altrimenti vengono fatti i calcoli dei mediani e vengono richiamati dalla funzione stessa durante la sua ricorsivitá
   else {

   
        float midX = (xp1 + xp2) / 2;
        float midY = (yp1 + yp2) / 2;
      
        float dist1 = distanza_ricorsiva(xp1, yp1, midX, midY);
        float dist2 = distanza_ricorsiva(midX, midY, xp2, yp2);
        
        // La funzione restituisce la somma dei due segmenti se le due funzioni richiamate precedentemente hanno raggiunto i loro casi base
        return dist1 + dist2;

    }
}