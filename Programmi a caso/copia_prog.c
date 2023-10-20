#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

void campo( giocatori *giocatore, pallina palla);
void posizione_palla(giocatori *giocatore, pallina palla, int *indice_battitore);
int confronto_giocatore_palla(giocatori *giocatore, pallina palla, int indice_battitore);
void assegna_punti(giocatori *giocatore, int indice_battitore);


int main()
{
     srand(time (NULL));
    giocatori giocatore[2]=
    {
        { 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0}
    };
    
    pallina palla;
    
    int vittoria=0;
    int indice_battitore;



    while (giocatore[0].set < 3 && giocatore[1].set < 3) // principale
    {
        indice_battitore=rand()%2;
        printf("sta battendo il giocatore %d\n", indice_battitore+1);

        
        giocatore[0].punteggio=0;
        giocatore[1].punteggio=0;

        giocatore[0].win=0;
        giocatore[1].win=0;
    
    
    
       while (giocatore[0].punteggio<41 && giocatore[1].punteggio<41) //secondo
       {
        
        posizione_palla(giocatore, palla, &indice_battitore);



            if ((giocatore[0].punteggio==40) && (giocatore[1].punteggio==40))
            {
                int differenza_spareggio=0;
                

                
                while ((differenza_spareggio>-2)&&(differenza_spareggio<2)) //spareggio
                {

                   posizione_palla(giocatore, palla, &indice_battitore); 

                   differenza_spareggio = giocatore[0].punteggio-giocatore[1].punteggio;



                   if (differenza_spareggio==2)
                   {
                    giocatore[0].set = giocatore[0].set+1;
                    
                    printf("IL GIOCATORE 1 HA VINTO IL SUO SET NUMERO=%d\n", giocatore[0].set);

                   }
                   else if (differenza_spareggio==-2)
                   {

                    giocatore[1].set = giocatore[1].set+1;
                    
                    printf("IL GIOCATORE 2 HA VINTO IL SUO SET NUMERO=%d\n", giocatore[1].set);
                    

                   }
                   
                   
                }
                
            }
                

            if ((giocatore[0].punteggio==41) && (giocatore[1].punteggio<40))
            {
                giocatore[0].set = giocatore[0].set+1;

                printf("IL GIOCATORE 1 HA VINTO IL SUO SET NUMERO=%d\n", giocatore[0].set);

                
                break;

            }
            else if ((giocatore[1].punteggio==41) && (giocatore[0].punteggio<40))
            {
                giocatore[1].set = giocatore[1].set+1;
                printf("IL GIOCATORE 2 HA VINTO IL SUO SET NUMERO=%d\n", giocatore[1].set);
                
                break;

            }

         system("PAUSE");
        }

    system("PAUSE");
    }
    
    printf("LA PARTITA E' STATA VINTA DAL GIOCATORE %d\n", indice_battitore+1);

}



void campo( giocatori *giocatore, pallina palla)
{
     char campo[5][5]={{'+','-','-','-','+'},
                       {'|',' ',' ',' ','|'},
                       {'#','#','#','#','#'},
                       {'|',' ',' ',' ','|'},
                       {'+','-','-','-','+'}};



    giocatore[0].x=rand()%2;
    giocatore[0].y=rand()%5;

    giocatore[1].x=(rand()%2)+3;
    giocatore[1].y=rand()%5;


    campo[giocatore[0].x][giocatore[0].y]='1';
    campo[giocatore[1].x][giocatore[1].y]='2';


    campo[palla.x][palla.y]='o';


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

void posizione_palla(giocatori *giocatore, pallina palla, int *indice_battitore)
{
    int pippo=-1;
    int probabilita;
    probabilita=(rand()%100)+1;

    if (probabilita<=70)
    {
        if(probabilita>0&&probabilita<=40)
        {
            palla.x=2;
            palla.y=4;

            printf("la palla e' andata fuori\n");
            if (*indice_battitore==0)
            {
                assegna_punti(giocatore, 1);
                *indice_battitore=1;
                printf("il battitore attuale e il giocatore:%d\n", *indice_battitore+1);
                
            }
            else if(*indice_battitore==1)
            {
                assegna_punti(giocatore, 0);
                *indice_battitore=0;
                printf("il battitore attuale e il giocatore:%d\n", *indice_battitore+1);
            }

        }
        else if(probabilita>40&&probabilita<=70)
        {
            palla.x=2;
            palla.y=2;
            printf("la palla e' sulla rete\n");
             if (*indice_battitore==0)
            {
                assegna_punti(giocatore, 1);
                *indice_battitore=1;
                printf("il battitore attuale e il giocatore:%d\n", *indice_battitore+1);
            }
            else if(*indice_battitore==1)
            {
                assegna_punti(giocatore, 0);
                *indice_battitore=0;
                printf("il battitore attuale e il giocatore:%d\n", *indice_battitore+1);
            }
        }
    campo(giocatore, palla);
        
    }
    else if(probabilita>70&&probabilita<=100)
    {
        printf("la palla e' in campo\n");
         if(*indice_battitore==0)
        {
            palla.x=(rand()%2)+3;
            palla.y=rand()%5;
            printf(" la palla e' in x=%d e y=%d\n", palla.x, palla.y);

        }
        else if(*indice_battitore==1)
        {
            palla.x=rand()%2;
            palla.y=rand()%5;

            printf(" la palla e' in x=%d e y=%d\n", palla.x, palla.y);

        }

        campo(giocatore, palla);


        pippo = confronto_giocatore_palla(giocatore, palla, *indice_battitore);


        if (*indice_battitore==0)
        {
            if (pippo==1)
            {
                 printf("La palla puo' essere colpita dal giocatore2\n");

                *indice_battitore=1;

                printf("il battitore attuale e il giocatore:%d\n", *indice_battitore+1);
            }
            else if(pippo==0)
            {
                printf("La palla  non puo' essere colpita dal giocatore2\n");
                assegna_punti(giocatore, 0);

                *indice_battitore=0;

                printf("il battitore attuale e il giocatore :%d\n", *indice_battitore+1);

            }
            
        }
        else
        {
            if (pippo==1)
            {
                 printf("La palla puo' essere colpita dal giocatore1\n");

                *indice_battitore=0;

                printf("il battitore attuale e il giocatore:%d\n", *indice_battitore+1);
            }
            else if(pippo==0)
            {
                printf("La palla  non puo' essere colpita dal giocatore1\n");
                assegna_punti(giocatore, 1);
                *indice_battitore=1;

                printf("il battitore attuale e il giocatore :%d\n", *indice_battitore+1);

            }

        }
        
    }
    
}

int confronto_giocatore_palla(giocatori *giocatore, pallina palla, int indice_battitore)
{

    if(indice_battitore==0) 
    {
        if(((giocatore[1].x== palla.x)&&(giocatore[1].y==palla.y))|| //stesso
           ((giocatore[1].x-1==palla.x)&&(giocatore[1].y-1==palla.y))|| //angoloSinistra
           ((giocatore[1].x-1==palla.x)&&(giocatore[1].y==palla.y))|| //sopra
           ((giocatore[1].x-1==palla.x)&&(giocatore[1].y+1==palla.y))|| //angoloDestra
           ((giocatore[1].x==palla.x)&&(giocatore[1].y-1==palla.y))|| //suaSinistra
           ((giocatore[1].x==palla.x)&&(giocatore[1].y+1==palla.y))|| //suaDestra
           ((giocatore[1].x+1==palla.x)&&(giocatore[1].y-1==palla.y))|| //angoloSinistrabass
           ((giocatore[1].x+1==palla.x)&&(giocatore[1].y==palla.y))||//sotto
           ((giocatore[1].x+1==palla.x)&&(giocatore[1].y+1==palla.y)))//angolobassodestra
            {
                printf("11\n");
                return 1;
            }
            else 
            {
                printf("12\n");
                return 0;
            }
    }
            
    else
    {
        if(((giocatore[0].x==palla.x)&&(giocatore[0].y==palla.y))||
           ((giocatore[0].x-1==palla.x)&&(giocatore[0].y-1==palla.y))||
           ((giocatore[0].x-1==palla.x)&&(giocatore[0].y==palla.y))||
           ((giocatore[0].x-1==palla.x)&&(giocatore[0].y+1==palla.y))||
           ((giocatore[0].x==palla.x)&&(giocatore[0].y-1==palla.y))||
           ((giocatore[0].x==palla.x)&&(giocatore[0].y+1==palla.y))||
           ((giocatore[0].x+1==palla.x)&&(giocatore[0].y-1==palla.y))||
           ((giocatore[0].x+1==palla.x)&&(giocatore[0].y==palla.y))||
           ((giocatore[0].x+1==palla.x)&&(giocatore[0].y+1==palla.y)))
           {
            printf("21\n");
           return 1;
           }
        else 
           { 
            printf("22\n");
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

    printf("il punteggio del gioc 1 %d\n", giocatore[0].punteggio);
    printf("Le punteggio del gioc 2 %d\n\n", giocatore[1].punteggio);

}