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

    int punteggio;
    int win;
    int x; //riga
    int y; //colonna

}giocatori;

void campo( giocatori *giocatore, pallina palla);


int main()
{
    srand(time (NULL));
    giocatori giocatore[2]=
    {
        { 0, 0, 0, 0},
        { 0, 0, 0, 0}
    };
    pallina palla;

    giocatore[0].x=rand()%2;
    giocatore[0].y=rand()%5;

    giocatore[1].x=(rand()%2)+3;
    giocatore[1].y=rand()%5;

    campo(giocatore, palla);

    int vittoria=1;

    while (!vittoria /* ci volgiono pure i set mi sa */)
    {
        /* code */
    }
    


    
    
  

    /*while (SET==3)
    {
        punteggio giocatore1 =0
        punteggio giocatore2=0
        while(giocato[0].punteggio>40||giocatore[1].punteggio>40)
        {
            if(indice==0)
            {
                ha vinto il giocatore1
            }
            else(indice==1)
            {
                ha vinto il giocatore 2
            }

            if(se entrmbi sono a 40)
            {
                (win giocatore1-wingiocatore2)=2
            }
        }
        set++
    }*/
    
}

void campo( giocatori *giocatore, pallina palla)
{
     char campo[5][5]={{'+','-','-','-','+'},
                       {'|',' ',' ',' ','|'},
                       {'#','#','#','#','#'},
                       {'|',' ',' ',' ','|'},
                       {'+','-','-','-','+'}};


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