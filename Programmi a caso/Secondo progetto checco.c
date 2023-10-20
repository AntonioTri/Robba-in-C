#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    char nome[50];
    int codice;
    float costo;
    int scorta;
    char soddisfa_requisiti[2];

}prodotti;


void controllo_scorta(prodotti *prodotto);
void rifornimento_prodotto(prodotti *prodotto);
int lista_prodotti_venduti(int scorte, int n, int vendite);

int main()
{
     prodotti prodotto[20]={{"computer", 10, 350.50, 10, "si"},
                            {"mouse", 11, 14.99, 10, "si"},
                            {"tastiera", 12, 20.00, 10, "si"},
                            {"stampante", 13, 147.45, 10, "si"},
                            {"monitor", 14, 100.00, 5, "si"},
                            {"tv", 15, 760.66, 10, "si"},
                            {"modem", 16, 25.00, 10, "si"},
                            {"cuffie", 17, 12.49, 10, "si"},
                            {"cellulare", 18, 275.00, 10, "si"},
                            {"scheda video", 19, 95.00, 10, "si"},
                            {"caricabatterie", 20, 43.00, 10, "si"},
                            {"orologio", 21, 153.45, 10, "si"},
                            {"fornello", 22, 82.69, 10, "si"},
                            {"scheda madre", 23, 270.50, 10, "si"},
                            {"phon", 24, 18.50, 10, "si"},
                            {"tablet", 25, 325.50, 10, "si"},
                            {"dischi", 26, 0.50, 10, "si"},
                            {"mp3", 27, 7.89, 10, "si"},
                            {"radio", 28, 12.30, 10, "si"},
                            {"usb", 29, 4.25, 10, "si"},
                            {"stereo", 30, 10.00, 10, "si"}
                          };

    
    int giorni=1;
    int codice; 
    int vendite;
    




    int i;
    
    for ( i = 0; i < 10; i++)
    {
        giorni++;

        if(giorni==7)
        {
        
           controllo_scorta(prodotto);
        }


        if (giorni==5)
        {
        
            rifornimento_prodotto(prodotto);
        }
    
    }


    printf("Nel magazzion sono presenti:\n\n");
    for ( i = 0; i < 20; i++)
    {
        printf("il prodotto: %s, \t\tcon codice: %d\n",prodotto[i].nome,prodotto[i].codice);
        
    }
    printf("\n\ninserisci il codice del prodotto del quale sei interessato a vedere\nil numero di vendite: ");
    scanf("%d",&codice);


    int k;
    i=0;
    for ( i = 0; i < 20; i++)
    {
        printf("pro di%d\n", i);
        if (prodotto[i].codice==codice)
        {
            k=i;
        }
        
    }
    
    if (giorni==10)
    {

     vendite= lista_prodotti_venduti(prodotto[k].scorta, 10, 0);
    }

    printf("\nil prodotto da te selezionato con codice %d e' stato venduto %d volte.\n", codice, vendite);
}


void controllo_scorta(prodotti *prodotto)
{
    int i;

    for ( i = 0; i < 20; i++)
    {
        if (prodotto[i].scorta<5)
        {
            printf("il prodotto %s ha disponibilita di %d pezzi\n", prodotto[i].nome, prodotto[i].scorta);
        }
        
    }
    
}

void rifornimento_prodotto(prodotti *prodotto)
{
    int i;
    for ( i = 0; i < 20; i++)
    {
    
        if (prodotto[i].scorta==0)
        {
            printf("I PRODOTTI CHE VERRANNO RIFORNITI SONO:\n");
            printf("il prodotto: %s con codice: %d\n", prodotto[i].nome, prodotto[i].codice);
            prodotto[i].scorta=10;

        }

    }
    
}


int lista_prodotti_venduti(int scorte, int n, int vendite)
{
    if (n==scorte)
    {
        //se n è uguale ad a deve tornare il numero di volte
        //in cui il prodotto è stato venduto al fine dei 10 giorni
       return vendite;
    }

    else
    {
        return lista_prodotti_venduti(scorte, n-1, vendite+1);
        
    }
    
}