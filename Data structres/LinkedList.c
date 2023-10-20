#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int dato;
    char nome;
    void *next;

}nodo;

nodo *testa = NULL;

void Stampa_lista();
void menu();
nodo *aggiungi_nodo(int);
int Rimuovi_nodo(int);
nodo *Inserisci_elemento(int, int);



int main()
{

    int scelta = -1;

    do
    {

        menu();
        scanf("%d",&scelta);
        printf("\n");
        int valore;
        int posizione;
      
            switch (scelta)
            {
            case 1:

                // funzone inserimento
                printf("Che valore inserisci? \n");
                scanf("%d",&valore);
                nodo *nuovo = aggiungi_nodo(valore); 

                break;
            
            case 2:
                //funzione eliminazione

                if (testa == NULL)
                {
                    printf("La lista e' vuota, operazine non valida!\n");

                } else {

                    printf("Che valore vuoi eliminare? \n");
                    scanf("%d",&valore);
            
                    int risultato = Rimuovi_nodo(valore);
                    if(risultato == 1)
                    {
                        printf("rimozione avvenuta con successo!\n");

                    } else if (risultato == 0)
                    {
                        printf("valore non trovato!\n");
                    }
                }

                break;

            case 3:   
                // funzione inserimento nel mezzo  

                if (testa == NULL)
                {
                    printf("La lista e' vuota, operazine non valida!\n");

                } else {

                    printf("Che valore inserisci? \n");
                    scanf("%d",&valore);      

                    printf("\nIn che posizione vuoi inserire \n");
                    scanf("%d",&posizione);

                    if (posizione == 1)
                    {
                        nodo *new = aggiungi_nodo(valore);

                    } else {

                        nodo *new = Inserisci_elemento(valore, posizione);
                    
                    }
                }

                break;
            
            case 4:   

                // funzione stampa lista
                Stampa_lista();

                break;

            }

    
    } while (scelta != 5);

}


void menu(){

        printf("\n/***********************************************/\n\n");
        printf("Selezionare una operazione:\n\n");
        printf("\t1: Aggungi elemento alla testa\n");
        printf("\t2: Togli elemento dalla lista\n");
        printf("\t3: Inserisci un elemento nella lista\n");
        printf("\t4: Stampa la lista\n");
        printf("\t5: EXIT\n\n");

    } 

nodo *aggiungi_nodo(int dato){

        nodo *new = NULL;
            if (testa==NULL)
            {
                new = malloc(sizeof (nodo));
                if(new==NULL)
                return NULL;

                new->dato = dato;
                testa = new;
                new->next = NULL;
            }
            else{

                new = malloc(sizeof(nodo));
                if(new==NULL)
                return NULL;

                new->dato = dato;
                new->next = testa;
                testa = new;

            }

      return new;

}



void Stampa_lista(){
    nodo *attuale = testa;
    while (attuale != NULL) 
    {
        printf("%d -> ",attuale->dato);
        attuale = attuale->next;
    }
    printf("\n");
}


int Rimuovi_nodo(int dato){

    nodo *attuale = testa;
    nodo *precedente = testa;

    while (attuale != NULL)
    {
        if(dato == attuale->dato)
        {
            if(attuale == testa)
            {
                testa = attuale->next;
                free(attuale);
                attuale = NULL;

            } else {

                precedente->next = attuale->next;
                free(attuale);
                attuale = NULL;
            }
            return 1;
        }

        precedente = attuale;
        attuale = attuale->next;
    }

    return 0;

}


nodo *Inserisci_elemento(int dato, int pos){

    nodo *attuale = testa;
    nodo *prec = testa;

    nodo *new = malloc(sizeof(nodo));
    if(new == NULL)
       return NULL;

    new->dato = dato;

        for (int i = 0; i < pos-1; i++)
        {
            if(attuale == NULL)
            {
                printf("sei uscito dalla lista!\n");
                return NULL;
            }

            prec = attuale;
            attuale = attuale->next;
        }

    new->next = prec->next;
    prec->next = new;

    return new;
}





