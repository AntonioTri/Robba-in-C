
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DIM_CAMPO 5

typedef struct 
{
    int x;
    int y;

}pallina;



typedef struct{
    int set;
    int punteggio;
    int win;
    int x; //riga
    int y; //colonna
}giocatori;

void posizione_palla(giocatori *giocatore, pallina *palla, int indice_battitore, int *out);
int confronto_giocatore_palla(giocatori *giocatore, pallina *palla, int indice_battitore);
void assegna_punti(giocatori *giocatore, int indice_battitore);
void campo( giocatori *giocatore, pallina *palla, int posizione);

int main()
{
    srand(time (NULL));
    giocatori giocatore[2]=
    {
        { 0, 0, 0, 0},
        { 0, 0, 0, 0}
    };


    pallina palla = { 2, 2 };

    
    int k=0;
    giocatore[0].set=0;
    giocatore[1].set=0;
    int posizione;



    while (giocatore[0].set<2 || giocatore[1].set<2)
    {

        giocatore[0].x=1;
        giocatore[0].y=2;



        giocatore[1].x=3;
        giocatore[1].y=2;

        campo(giocatore, &palla, posizione);

        printf("PALLA AL CENTRO set numero %d\n\n",k+1);

        giocatore[0].punteggio=0;
        giocatore[0].win=0;
        giocatore[1].punteggio=0;
        giocatore[1].win=0;

        giocatore[0].x=rand()%2;
        giocatore[0].y=rand()%5;

        giocatore[1].x=(rand()%2)+3;
        giocatore[1].y=rand()%5;

        posizione = 0;


        int indice_battitore = rand()%2; // ho creato questa variabli per conoscere chi batte
        printf(" IL GIOCATORE %d INIZIA IL SET BATTENDO LA PALLA\n", indice_battitore+1);
            

        while (giocatore[0].punteggio < 41 && giocatore[1].punteggio < 41)
        {

            int palla_colpita=0;
            posizione = 0;

            do
            {
                //giocatore[0].x=rand()%2;
                //giocatore[0].y=rand()%5;

                //giocatore[1].x=(rand()%2)+3;
                //giocatore[1].y=rand()%5;

                // Cambia la posizione della palla, assegna anche i punti di conseguenza se esce fuori
                posizione_palla(giocatore , &palla, indice_battitore, &posizione);

                // se la palla é dentro allora effettua i controlli
                if (posizione == 2 )
                {
                    // Cambio l'indice battitore, cosí da poter controllare se il ricevente la puó prendere
                        if (indice_battitore==0)
                        {
                            indice_battitore = 1;

                        } else if( indice_battitore == 1)
                        {    
                            indice_battitore = 0;
                        }

                    // Ristampa il campo
                    campo(giocatore, &palla, posizione);

                    // Questa invece mi mostra se la palla puó essere presa dal giocatore ricevente
                    if (indice_battitore == 1)
                    {
                            palla_colpita = confronto_giocatore_palla(giocatore, &palla, indice_battitore);
                    
                    } else if (indice_battitore == 0)
                    {
                            palla_colpita = confronto_giocatore_palla(giocatore, &palla, indice_battitore);

                    }

                    // SE non viene colpita dal ricevente, cambia l'indice
                    if (palla_colpita == 0)
                    {
                        if (indice_battitore==0)
                        {
                            indice_battitore = 1;

                        } else if( indice_battitore == 1)
                        {    
                            indice_battitore = 0;
                        }
                    }
                    

                } // Altrimenti se la palla é finita fuori o sulla rete, bisogna solo invertire l'indice del 
                  // battitore e dire che la palla non é stata colpita
                else if (posizione == 0 || posizione == 1)
                {
                    if (indice_battitore==0)
                    {
                        indice_battitore = 1;

                    } else if( indice_battitore == 1)
                    {    
                        indice_battitore = 0;
                    }

                    palla_colpita = 0;
                    
                }
                
                

            } while (palla_colpita==1);
            
            
            if (palla_colpita == 0)
            {
                if (indice_battitore == 0)
                {
                    printf("\nOra ribatte la palla il giocatore %d\n", indice_battitore+1);
                    palla.x=2;
                    palla.y=2;
                    campo(giocatore, &palla, posizione);


                }else if (indice_battitore == 1)
                {
                    printf("\nOra ribatte la palla il giocatore %d\n", indice_battitore+1);
                    palla.x=2;
                    palla.y=2;
                    campo(giocatore, &palla, posizione);
                }

            }

            if (giocatore[0].punteggio == 41)
            {
                giocatore[0].set++;

            } else if (giocatore[1].punteggio == 41)
            {
                giocatore[1].set++;
            }

        }

        k++;

        printf("\nPremi Invio per continuare...\n");
        while (getchar() != '\n');
    
}

    if (giocatore[0].set==3)
    {
        printf("HA VINTO la partita il giocatore 1!\n");
    }
    else if (giocatore[1].set==3)
    {
        printf("HA VINTO la partita il giocatore 2!\n");
    }
}





void campo( giocatori *giocatore, pallina *palla, int posizione)
{
     char campo[5][5]={{'+','-','-','-','+'},
                       {'|',' ',' ',' ','|'},
                       {'#','#','#','#','#'},
                       {'|',' ',' ',' ','|'},
                       {'+','-','-','-','+'}};

    campo[giocatore[0].x][giocatore[0].y]='1';
    campo[giocatore[1].x][giocatore[1].y]='2';

if (posizione == 1)
{
    campo[palla->x][palla->y] = 'X';
}else
    campo[palla->x][palla->y] = 'o';


    int i, j;
    for ( i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ",campo[i][j]);
        }
        printf("\n\n");
    }
}






void posizione_palla(giocatori *giocatore, pallina *palla, int indice_battitore, int *posizione)
{
    int probabilita;
    probabilita=(rand()%100)+1;
    *posizione = 0;

    if (probabilita<=70)
    {
        // La palla é finita sulla rete
        if(probabilita>0 && probabilita<=40)
        {

            printf("La palla e' finita sulla rete\n");

            if (indice_battitore==0)
            {
                printf("\nAssegnamo i punti al giocatore 2\n");
                assegna_punti(giocatore, 1);
                printf("Il Giocatore 1 e' a %d punti.\nIl Giocatore 2 e' a %d punti\n", giocatore[0].punteggio, giocatore[1].punteggio);
            }else{
                printf("\nAssegnamo i punti al giocatore 1\n");
                assegna_punti(giocatore, 0);
                printf("Il Giocatore 1 e' a %d punti.\nIl Giocatore 2 e' a %d punti\n", giocatore[0].punteggio, giocatore[1].punteggio);
            }

            palla->x=2;
            palla->y= rand() %4;
            
        }// La palla é finita fuori dal campo
        else if(probabilita>40 && probabilita<=70)
        {

            printf("La palla e' finita fuori dal campo\n");

             if (indice_battitore==0)
            {
                printf("\nAssegnamo i punti al giocatore 2\n");
                assegna_punti(giocatore, 1);
                printf("Il Giocatore 1 e' a %d punti.\nIl Giocatore 2 e' a %d punti\n", giocatore[0].punteggio, giocatore[1].punteggio);

            }else if(indice_battitore == 1){

                printf("\nAssegnamo i punti al giocatore 1\n");
                assegna_punti(giocatore, 0);
                printf("Il Giocatore 1 e' a %d punti.\nIl Giocatore 2 e' a %d punti\n", giocatore[0].punteggio, giocatore[1].punteggio);
            }

            // Se la palla va fuori la variabile posizione diventa vera
            palla->x=2;
            palla->y=2;
            *posizione =1;
        }
    } // La palla é stata ribattuta nel campo avversario
    else if(probabilita>70&&probabilita<=100)
    {
         if(indice_battitore==0)
        {

            palla->x=(rand()%2)+3;
            palla->y=rand()%5;
            printf("Posizione palla ( %d, %d )\n", palla->x, palla->y);
            

        }else if (indice_battitore == 1){

            palla->x=rand()%2;
            palla->y=rand()%5;
            printf("Posizione palla ( %d, %d )\n", palla->x, palla->y);
        }

        *posizione = 2;
        
    }
    
}





int confronto_giocatore_palla(giocatori *giocatore, pallina *palla, int indice_battitore)
{
    if(indice_battitore==1)
    {
        if(((giocatore[1].x == palla->x) && (giocatore[1].y == palla->y))     ||
           ((giocatore[1].x-1 == palla->x) && (giocatore[1].y-1 == palla->y)) ||
           ((giocatore[1].x-1 == palla->x) && (giocatore[1].y == palla->y))   ||
           ((giocatore[1].x-1 == palla->x) && (giocatore[1].y+1 == palla->y)) ||
           ((giocatore[1].x == palla->x) && (giocatore[1].y-1 == palla->y))   ||
           ((giocatore[1].x == palla->x) && (giocatore[1].y+1 == palla->y))   ||
           ((giocatore[1].x+1 == palla->x) && (giocatore[1].y-1 == palla->y)) ||
           ((giocatore[1].x+1 == palla->x) && (giocatore[1].y == palla->y))   ||
           ((giocatore[1].x+1 == palla->x) && (giocatore[1].y+1 == palla->y)))
           {
            printf("La palla puo' essere colpita dal giocatore 2\n");

            return 1;
           } 
            
        else
        {
             printf("La palla NON puo' essere colpita dal giocatore 2\n");
             assegna_punti(giocatore, 0);
             printf("Il Giocatore 1 e' a %d punti.\nIl Giocatore 2 e' a %d punti\n\n", giocatore[0].punteggio, giocatore[1].punteggio);
             //assegna_spareggio(giocatore, &indice_battitore);
            
             return 0;
        }
            
    }
    else if (indice_battitore == 0)
    {
        if(((giocatore[0].x == palla->x)&&(giocatore[0].y == palla->y))     ||
           ((giocatore[0].x-1 == palla->x)&&(giocatore[0].y-1 == palla->y)) ||
           ((giocatore[0].x-1 == palla->x)&&(giocatore[0].y == palla->y))   ||
           ((giocatore[0].x-1 == palla->x)&&(giocatore[0].y+1 == palla->y)) ||
           ((giocatore[0].x == palla->x)&&(giocatore[0].y-1 == palla->y))   ||
           ((giocatore[0].x == palla->x)&&(giocatore[0].y+1 == palla->y))   ||
           ((giocatore[0].x+1 == palla->x)&&(giocatore[0].y-1 == palla->y)) ||
           ((giocatore[0].x+1 == palla->x)&&(giocatore[0].y == palla->y))   ||
           ((giocatore[0].x+1 == palla->x)&&(giocatore[0].y+1 == palla->y)))
           {
             printf("La palla puo' essere colpita dal giocatore 1\n");
             
             return 1;

           } 
        else
        {
             printf("La palla NON puo' essere colpita dal giocatore 1\n");
             assegna_punti(giocatore, 1);
             printf("Il Giocatore 1 e' a %d punti.\nIl Giocatore 2 e' a %d punti\n\n", giocatore[0].punteggio, giocatore[1].punteggio);
             //assegna_spareggio(giocatore, &indice_battitore);
            return 0;

        }
    }

}


void assegna_punti(giocatori *giocatore, int indice_battitore)
{

    if (indice_battitore==0)
    {
        if (giocatore[0].win>2)
        {
            giocatore[0].punteggio++;
            //giocatore[0].win = giocatore[0].win+1;
        }
        else if (giocatore[0].win==2)
        {
            giocatore[0].punteggio+=10;
            giocatore[0].win = giocatore[0].win+1;
        }
        else
        {
            giocatore[0].punteggio+=15;
            giocatore[0].win = giocatore[0].win+1;
        }
        
    }
    else
    {
        if (giocatore[1].win>2)
        {
            giocatore[1].punteggio++;
            //giocatore[1].win = giocatore[1].win+1;
        }
        else if (giocatore[1].win==2)
        {
            giocatore[1].punteggio+=10;
            giocatore[1].win = giocatore[1].win+1;
        }
        else
        {
            giocatore[1].punteggio+=15;
            giocatore[1].win = giocatore[1].win+1;
        }


    }

    printf("\nLe win del gioc 1 %d\n", giocatore[0].win);
    printf("Le win del gioc 2 %d\n\n", giocatore[1].win);
    
}

