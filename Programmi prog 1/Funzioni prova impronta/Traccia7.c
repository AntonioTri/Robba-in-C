/*
	Scrivere una funzione che dati in input due array di strutture del seguente tipo
	struct prodotto {char *nome; int codice; double prezzo;};
	restituisce in output 1 se i due array di struct sono uguali, 0 se non lo sono.
	Si noti che due dati struct sono uguali se sono uguali tutti i loro campi.
*/ 

#include <stdio.h>

typedef struct {
    char *nome;
    int codice;
    double prezzo;
} prodotto;

int confronta_liste(prodotto *, prodotto *, int);


int main(){

    prodotto listaA[3] = {
        {"Portafoglio", 12345, 10.00},
        {"Pentola", 56789, 20.00},
        {"Centrotavola", 12389, 30.01}
    };

    prodotto listaB[3] = {
        {"Portafoglio", 12345, 10.00},
        {"Pentola", 56789, 20.00},
        {"Centrotavola", 12389, 30.01}
    };

    int uguaglianza;

    printf("Gli oggetti della prima lista sono:\n\n");
        for (int i = 0; i < 3; i++)
        {
            printf("%d) %s. Codice: %d. Prezzo %.2lf Euro\n", i+1, listaA[i].nome, listaA[i].codice, listaA[i].prezzo);
        }
        printf("\n");

    printf("Gli oggetti della seconda lista sono:\n\n");
        for (int j = 0; j < 3; j++)
        {
            printf("%d) %s. Codice: %d. Prezzo %.2lfEuro\n", j+1, listaB[j].nome, listaB[j].codice, listaB[j].prezzo);
        }
        printf("\n");

    uguaglianza = confronta_liste(listaA, listaB, 3);

    if (uguaglianza == 1)
    {
        printf("Le due liste sono uguali");
    } else {
        printf("Le due liste sono diverse");
    }
    
}


int confronta_liste(prodotto *listaA, prodotto *listaB, int nro_el){

    int i, j, flag;

    for ( i = 0; i < nro_el; i++)
    {
        for ( j = i; j < nro_el; j++)
        {
            if (listaA[i].nome == listaB[j].nome &&
                listaA[i].codice == listaB[j].codice &&
                listaA[i].prezzo == listaB[j].prezzo)
            {
                flag = 1;
            } 
            else 
            {
                flag = 0;
                break;
            }
        }
    }
         if (flag == 1)
        {
            return 1;
        } else
            return 0;
    

}