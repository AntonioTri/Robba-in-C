/*
	Dato un elenco (array) di persone partecipanti a un concorso, ordinare l'elenco in ordine alfabetico
 	in base al campo cognome. La struttura che identifica il partecipante come:
 	struct persona {char *nome; char *cognome;};
 	typedef struct persona id;
 	struct partecipante {id *utente; unsigned short codice; }; 
*/

#include <stdio.h>
#include <string.h>

typedef struct 
{
    char *nome;
    char *cognome;
} persone ;

void ordina_lista_per_cognome(persone *, int);

int main(){

    int size = 20;

    persone lista[20] = {
        {"Mario","Rossi"},
        {"Gianfranco","Pippo"},
        {"Asdruable","Saggio"},
        {"Genoveffa","Scotta"},
        {"Gerry","Scotti"},
        {"Antonio","Salvi"},
        {"Bisdio","Farina"},
        {"Sara","Melassa"},
        {"Maria","Buonpane"},
        {"Pippo","Torcia"},
        {"Zio","Franco"},
        {"Emanuele","Sgari"},
        {"Giorgia","Meloni"},
        {"Mario","Brosio"},
        {"Pippo","Baudo"},
        {"Papa","Francesco"},
        {"Albert","Heinstein"},
        {"Isac","Newtoon"},
        {"Steven","Hauking"},
        {"Alambrosio","Arapa"}
    };

    printf("La lista dei partecipanti e':\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d)\t %s %s.\n", i+1, lista[i].nome, lista[i].cognome);
    }
    
    ordina_lista_per_cognome(lista, size);

    printf("La lista dei partecipanti ordinata per cognome e':\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d)\t %s %s.\n", i+1, lista[i].cognome, lista[i].nome);
    }

}


void ordina_lista_per_cognome(persone *lista, int size){

    int i,j;
    persone tmp;

    for ( i = 0; i < size; i++)
    {
        j=i-1;
        tmp = lista[i];

            while (j>=0 && strcmp(tmp.cognome, lista[j].cognome)<0)
            {
                lista[j+1]=lista[j];
                j--;
            }
            
        lista[j+1]=tmp;

    }
    
}
