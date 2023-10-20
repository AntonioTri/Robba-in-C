#include <stdio.h>
#include <time.h>
#include <stdlib.h>


typedef struct
{
    int cartella[3][5];

}giocatori;


void crea_cartella(giocatori *, int );
void stampa_cartella(giocatori *, int );
int  numero_estratto(int [], int *);
int  verifica_numero(giocatori *, int , int );
int  appartiene(int [], int , int *);
void combinazioni(giocatori *, int , int*, int*, int*, int*, int*);


int main()
{
    
    srand(time (NULL));

    giocatori giocatore[5];

    int nri_estratti[90];
    int conta_n;
    char risposta;

    do
    {

        conta_n = 0;


        //Si resetta la lista dei numeri estratti;
        for (int i = 0; i < 90; i++)
        {
            nri_estratti[i] = 0;
        }
        
        //Si impostano i valori dei punteggi a 0
        int ambo = 0; int terna = 0; int quaterna = 0; int quintina = 0; int tombola = 0;

        //Si creano le cartelle
        for (int i = 0; i < 5; i++)
        {
            printf("la cartella del giocatore %d e' la seguente\n", i+1);
            crea_cartella(giocatore, i);
            stampa_cartella(giocatore, i);
        }

        system("PAUSE");

        //Fino a quando la tombola non viene fatta, si continua a fare l'estrazione di un numero e tutti
        //i controlli del caso
        while (tombola != 1)
        {

            //Si estrae un numero
            int nro = numero_estratto(nri_estratti, &conta_n);
            printf("/----------------------------------------------/\n\n");
            printf("Il numero estratto e' il numero: %d\n", nro);
        

            //Si controlla se il numero appartiene ai giocatori 
            for (int i = 0; i < 5; i++)
            {
                int k;

                k=verifica_numero(giocatore, nro, i);

                if (k==1)
                {
                    printf("\nIl giocatore %d possiede il numero %d!\n", i+1, nro);
                    stampa_cartella(giocatore, i);

                }
            }

            //Si controllano gli ambi, le terne, le quaterne e le quintine con la variabile z
            //che sará impostata sul numero del giocatore che ha fatto tombola nel caso di vittoria

            for (int i = 0; i < 5; i++)
            {
                combinazioni(giocatore, i, &ambo, &terna, &quaterna, &quintina, &tombola);
            }


/*
            //Si mostrano di nuovo le cartelle dei giocatori
            for (int i = 0; i < 5; i++)
            {
                printf("\t   Giocatore %d\n", i+1);
                stampa_cartella(giocatore, i);
            }
*/
            //Si mostra il tabellone con la lista di tutti i numeri fino a 90, estratti e non
            //estratti

            system("PAUSE");

        }

        //Si chiede all'utente se vuole fare un'altra simulazione
        printf("\nVuoi eseguire un'altra simulazione? (s/n): ");
        scanf("%c", &risposta);

    } while (risposta == 's');

}

//Funzione che crea la cartella giocatore
void crea_cartella(giocatori *giocatore, int n)
{
    //In questa parte del codice si crea la cartella del gicatore n
    int i, j;
    int pippo=0;
    int incremento=0;
    for ( j = 0; j < 5; j++)
    {
        for ( i = 0; i < 3; i++)
        {
            pippo=pippo+(rand()%3)+1;
            giocatore[n].cartella[i][j]=pippo+incremento;    
        }

        pippo=0;

        int x=rand()%2;
        if (x==0)
        {
            incremento=incremento+10;
    
        }
        else if(x==1)
        {
            incremento=incremento+20;
        }
    }

}

//Qui invece si mostra la cartella del giocatore n
void stampa_cartella(giocatori *giocatore, int n){

    
    printf("\n|-----------------------------|\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("  %d ",giocatore[n].cartella[i][j]);
        }
        printf("\n");
    }
    printf("|-----------------------------|\n\n\n");

}

//Funzione che verifica se un giocatore ha il numero estratto
int verifica_numero(giocatori *giocatore, int numero, int n)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (giocatore[n].cartella[i][j]==numero)
            {
                giocatore[n].cartella[i][j]=0;
                return 1;

            }
        }
    }

    return 0;

}

//Funzione di estrazione del numero
int numero_estratto(int nri_estratti[], int *conta_n)
{
    int nro;

    /*
        Questa sintassi é un ciclo for infinito, perché dato che potrebbe essere estratto
        un numero giá uscito, dobbiamo continuare ad estrarre fino a quando non esce un numero nuovo
        Quando viene estratto un numero nuovo, verrá registrato nella lista dei numeri giá usciti
        e con un breack si uscirá dal ciclo for infinito, ritornando infine il numero estratto 
    */

    for(;;)
    {
        nro = (rand()%90) +1;

        if (appartiene(nri_estratti, nro, conta_n) == 0)
        {   
            nri_estratti[*conta_n] = nro;
            *conta_n = *conta_n + 1;

            break;
        }
    }

    return nro;
}

//Funzione per controllare se il numero estratto é giá uscito
int appartiene(int nri_estratti[], int nro, int *conta_n){

    for (int i = 0; i < *conta_n; i++)
    {
        if (nri_estratti[i] == nro)
        {
            return 1;
        }
    }

    return 0;
}

//Funzione per controllare le combinazioni e la possibile vincita
void combinazioni(giocatori *giocatore, int n, int *ambo, int *terna, int *quaterna, int *quintina, int *tombola){


    int combinazione;

    /*
        Nella funzione verifica_numero, i numeri che sono sono usciti e che appartenevano ad un 
        giocatore sono stati impostati a 0, possiamo quindi contare per ogni riga, quanti 0 ci sono per
        capire in quale combinazione ci troviamo.
    
        Se la combinazione passata come puntarore é == 0 allora si puó assegnare la combinazione
        corrente al giocatore n ed impostarla ad 1, cosí da non farla riassegnare quando lo stesso
        giocatore od un altro giocatore fa qualla combinazione 
    */

    for (int i = 0; i < 3; i++)
    {
        combinazione = 0;

        for (int j = 0; j < 5; j++)
        {

            if (giocatore[n].cartella[i][j] == 0)
            {
                combinazione ++;
            }
            
        }

        /*
            Prima di controllare una nuova riga, si fanno questi controlli per verificare se sono
            state fatte le combinazioni in estrazioni precedenti, se non sono state fatte allora vengono 
            annunciate ed il loro valore passa ad 1, cosí da indicare in caso di estrazioni succesive 
            che non devono piú essere annunciati
        */


        if (combinazione == 2 && *ambo == 0 )
        {
            printf("Il giocatore %d ha fatto AMBO!\n\n", n+1);
            *ambo = 1;

        } else if (combinazione == 3 && *terna == 0)
        {
            printf("Il giocatore %d ha fatto TERNA!\n\n", n+1);
            *terna = 1;

        } else if (combinazione == 4 && *quaterna == 0)
        {
            printf("Il giocatore %d ha fatto QUATERNA!\n\n", n+1);
            *quaterna = 1;

        } else if (combinazione == 5 && *quintina == 0)
        {
            printf("Il giocatore %d ha fatto QUINTINA!\n\n", n+1);
            *quintina = 1;

        }

    }
    
    //Fuori dai cicli delle combinazioni si effettua il controllo sulla tombola tramite una flag
    //che viene impostata ad 1 se l'attuale giocatore non ha fatto tombola, per poi riessere 
    //reimpostata a 0 quando si passa ad un altro giocatore

    int flag = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (giocatore[n].cartella[i][j] != 0)
            {
                flag = 1;
                break;
            }

        }

    }
    
    //Se tutti i numeri in una cartella giocatore erano uguali a 0, significa che ha fatto tombola
    //E che di conseguenza si puó annunciare il vincitore

    if (flag == 0)
    {
        printf("** IL GIOCATORE %d HA FATTO TOMBOLA E VINCE LA PARTITA! **\n\n", n+1);
        *tombola = 1;
    }
    
}