#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define NRO_PAROLE 20

typedef struct {
    char originale[50];
    char contrario[5][50];
} parola;

void mostra_es_parole_disp(parola *, int );
void rimpiazza_parole_scelte(parola *, char [], int );
void rimpiazza_tutte_le_parole(parola *, char [], int );
int appartiene(parola *, int, char *);
int scambia_parola(char *, int , char *, char *);

int main (){

    // Vengono inizializzati il numero delle parole ed il dizionario con le parole ed i 
    // loro corrispettivi 5 contrari
    int n=NRO_PAROLE;
    parola dizionario[20]={
    
    {"alto",{"basso","piccolo","fioco","smorzato","minuto"}},
    {"bello",{"brutto","sgradevole","orrendo","orribile","squallido"}},
    {"chiaro",{"scuro","cupo","tetro","torbido","nebbioso"}},
    {"curvo",{"diritto","retto","eretto","ritto","impettito"}},
    {"deserto",{"popolato","frequentato","animato","riempito","affollato"}},
    {"elegante",{"trascurato","trasandato","sciatto","dozzinale","banale"}},
    {"freddo",{"caldo","infuocato","caloroso","ardente","torrido"}},
    {"impeccabile",{"imperfetto","sbagliato","disordinato","trasandato","trascurato"}},
    {"ingombrante",{"minuto","piccolo","ridotto","minuscolo","misurato"}},
    {"liscio",{"ruvido","rugoso","irregolare","brullo","difforme"}},
    {"noioso",{"interessante","attraente","piacevole","gradevole","divertente"}},
    {"nebbioso",{"chiaro","limpido","sereno","terso","trasparente"}},
    {"piegato",{"raddrizzato","spiegato","distolto","svolto","dritto"}},
    {"provocatorio",{"rassicurante","buono","cortese","gentile","umile"}},
    {"responsabile",{"irresponsabile","inaffidaile","incosciente","frivolo","superficiale"}},
    {"scuro",{"chiaro","limpido","luminoso","bianco","sereno"}},
    {"sicuro",{"insicuro","dubbioso","ditubante","indeciso","incerto"}},
    {"sorprendente",{"noioso","normale","naturale","comune","ordinario"}},
    {"sporco",{"pulito","limpido","terso","lavato","integerrimo"}},
    {"utile",{"evitabile","inadatto","inutilizzabile","improduttivo","inefficace"}}
    

    };
     
    
    srand(time(NULL));
    char frase[200];

    // Si dá il benenuto all'utente e si consigliano delle parole consigliate
    printf("Benvenuto nel dizionario dei contrari!\nScrivi una frase in cui vorresti i contrari.\n\n");
    mostra_es_parole_disp(dizionario, n);

    // Si chiede all'utente di inserire una frase che viene assegnata al char 'frase';
    printf("\nInserisci una frase (max 200 caratteri):\n");
    gets(frase);
    printf("\n");
    
    // Si effettua la chiamata alla funzione che permette di scegliere quali delle parole inserite, e comprese nel
    // dizionario, si desidera sostituire
    printf("/---------------------------------------------------------------------------/\n\n");
    rimpiazza_parole_scelte(dizionario, frase, n);
    
    // Si procede a richiamare la funzione che sostituisce tutte le parole che l'utente ha scelto di non sostituire
    rimpiazza_tutte_le_parole(dizionario, frase, n);
    printf("/--------------------------------------------------------------------------/");
    printf("\n");

}

//La procedura che ci consiglia delle parole da usare tra quelle disponibili
void mostra_es_parole_disp(parola *dizionario, int nro_parole){

    int i;

    printf("Ecco degli esempi di parole che potresti usare:\n");
    for ( i = 0; i < 3; i++)
    {
        //genera un intero casuale con la funzine rand per scegliere un assortimento di 3 parole
        //da consigliare all'utente
        int parola_randomica = rand() % nro_parole;

        //stampa a schermo una parola casuale ad ogni iterazione del for
        printf("%d) %s ", i+1, dizionario[parola_randomica].originale);
    }
    printf("\n");
    
}

// Funzione per sostituire le parole scelte, in input ha il dizionario, la frase inserita dell'utente ed
// in fine il numero di parole comprese nel dizionario
void rimpiazza_parole_scelte(parola *dizionario, char frase[200], int n){

    /* Vengono definite due variabili, 'risposta' per memorizzare la scelta dell'utente riguardo a se cambiare
       o no la parola in questione, e l'array di caratteri 'frase_copia', dato che la funzione strtok(), 
       durante la creazione dei token, modifica la struttura del'array di carattere in questione, conserviamo dunque
       il valore di 'frase' in una variabile diciamo "cavia" da dare alla strtok()  */
    char risposta;
    char frase_copia[200];
    int k=0;
    strcpy(frase_copia, frase);

    // Inizializziamo il puntatore 'parola_attuale' alla prima parola della frase utilzzando la strtok()
    char *parola_attuale = strtok(frase_copia, " ");

    // Entriamo ora nel ciclo while che analizza ogni parola della frase passata dalla strtok()...
    while (parola_attuale != NULL)
    {
           // ... controlla se quest'ultima appartiene al dizionario restituiendo la sua posizione all'interno 
           // del dizionario stesso in caso affermativo...
           int indice = appartiene(dizionario, n, parola_attuale);

           if (indice != -1 )
           {
                // Viene impostato localmente l'indice 'k' per controllare se sono state trovate corrispondenze
                k=1;
                // ... e si chiede all'utente se vuole sostituire la parola con un suo contrario
                printf("Vuoi sostituire la parola '%s' con un suo contrario? (s/n): ", parola_attuale);
                scanf(" %c", &risposta);
                printf("\n");

                /* In caso affermativo viene generato un numero casuale con la funzione rand() tra 0 e 4 per scegliere
                 il contrario da utilizzare. Il suo valore viene conservato ad una variabile di "passaggio"
                 che ci permette di darla come argomento alla  funzione 'scambia_parola' */
                if (risposta == 's')
                {
                    int nro_contrario = rand() % 5;
                    char contrario_sostitutivo [20] ;
                    strcpy(contrario_sostitutivo, dizionario[indice].contrario[nro_contrario]);
        
                    scambia_parola(frase, 200, parola_attuale, contrario_sostitutivo);
                }     
          }
          /* Finito tutti i controlli/modifiche della parola, si passa alla prossima riutilizzando la strtok()
             e passandole come argomento 'NULL', così da farla riprendere al punto in cui si era fermata */
          parola_attuale = strtok(NULL, " ");
    }

    // Se il valore 'k' è stato impostato ad uno significa che è stata trovata almeno una corrispondenza
    // e quindi si mostra la frase modificata
    if (k==1)
    {
    printf("/---------------------------------------------------------------------------/\n");
    printf("\nLa frase con le parole scelte per i loro contrari e':\n#) %s ", frase);
    printf("\n\n");
    }else if (k==0) // Altrimenti, dato che k non è stato modificato, il programma riferisce che non sono 
                    //state trovate corrispondenze
    {
        printf("Nella frase che hai inserito non sono state trovate corrispondenze.\n\n");
    }
    
    

}


/* Funzione che rimpiazza tutte le parole. Il suo procedimento è attivarsi in secondo luogo, dopo la funzione
   'rimpiazza_parole_selte', per sostituire tutte le parole per le quali l'utente ha scelto "no", ed è perfettamente
   uguale alla sua "sorella maggiore", con l'unica eccezione che non chiede all'utente se vuole sostituire la parola,
   ma lo fa direttamente */
void rimpiazza_tutte_le_parole(parola *dizionario, char frase[200], int n){

    char risposta;
    char frase_copia[200];
    int k=0;

    strcpy(frase_copia, frase);
    char *parola_attuale = strtok(frase_copia, " ");

    while (parola_attuale != NULL)
    {

           int indice = appartiene(dizionario, n, parola_attuale);

           if (indice != -1 )
           {

                    k=1;
                    int nro_contrario = rand() % 5;
                    char contrario_sostitutivo [20] ;
                    strcpy(contrario_sostitutivo, dizionario[indice].contrario[nro_contrario]);
        
                    scambia_parola(frase, 200, parola_attuale, contrario_sostitutivo);
                
          }
          parola_attuale = strtok(NULL, " ");
    }

    // Se il valore 'k' è stato impostato ad uno significa che è stata trovata almeno una corrispondenza
    // e quindi si mostra la frase modificata
    if (k==1)
    {
    printf("/---------------------------------------------------------------------------/\n");
    printf("\nLa frase con tutte le parole sostituite con tutti i loro contrari e':\n#) %s ", frase);
    printf("\n\n");
    }else if (k==0) // Altrimenti, dato che k non è stato modificato, il programma riferisce che non sono 
                    //state trovate corrispondenze
    {
        printf("/---------------------------------------------------------------------------/\n\n");
        printf("Nella frase che hai inserito non sono state trovate corrispondenze.\n\n");
    }
    

}


/* Questa funzione prende in input il dizionario e la sua grandezza, e la parola n-esima 
   della frase inserita per controllare se essa esiste nel dizionario, restituisce l'indice 'i' della 
   sua posizione se viene trovata una corrispondenza, altrimenti restituisce '-1' cosí da permettere
   all'if della funzione chiamante 'rimpiazza_parole_scelte' di passare alla parola successiva */

int appartiene(parola *dizionario, int n, char *parola_da_cercare) {

    for (int i = 0; i < n; i++) {
        if (strcmp(dizionario[i].originale, parola_da_cercare) == 0) {
           
            return i;
        }
    }
    return -1;
}


// Questa é l'effettiva funzione che scambia due parole e che riordina la farse per adeguarla alle dimensioni della nuova parola
int scambia_parola(char *str, int lungh_max_frase, char *parola, char *contrario)
{
         int i, j;

         //vengono definite le grandezze delle parole e della frase
         int lunghezza_frase = strlen(str);
         int lunghezza_parola = strlen(parola);
         int lunghezza_contrario = strlen(contrario);
         int diff;

        // qui la funzione controlla se l'array di caratteri che contiene la frase ha abastanza spazio per cotenere 
        // i nuovi contrari nel caso questi abbiano una dimensione maggiore rispetto alla parola che devono sostituire,
        // in tal caso ritorna '-1'
         if ((lunghezza_frase - lunghezza_parola + lunghezza_contrario) >= lungh_max_frase)
                   return -1;

        // In caso contrario dobbiamo analizzare i 3 casi...
         for (i = 0; i <= (lunghezza_frase - lunghezza_parola); i++)
         {

                   if (strncmp(&str[i], parola, lunghezza_parola) == 0)   
                   {
                            // Caso in cui le parole abbiano la stessa lunghezza (non c'è bisogno di modificare la posizione
                            // degli altri caratteri della stringa)
                            if (lunghezza_parola == lunghezza_contrario)
                            {
                                      strncpy(&str[i], contrario, lunghezza_contrario);
                                      return 1;
                            }
                            // Caso in cui la lunghezza della parola sia maggiore della lunghezza del suo contrario
                            // bisigna di conseguenza modificare la posizione dei caratteri della stringa 'str' che contiene la
                            // nostra farse, spostandoli verso sinistra
                            else if (lunghezza_parola > lunghezza_contrario)
                            {
                                      diff = lunghezza_parola - lunghezza_contrario;
                                      strncpy(&str[i], contrario, lunghezza_contrario);
                                      
                                      // "Compattamento"                                      
                                      for (j = i + lunghezza_contrario; j<lunghezza_frase - diff; j++)
                                               str[j] = str[j + diff];
                                      str[j] = '\0';
                                      return 1;
                            }
                            // Caso in cui la lunghezza del contrario sia maggiore della lunghezza della parola che deve sostituire
                            // caso in cui la stringa è costretta ad allargarsi
                            else 
                            {
                                      diff = lunghezza_contrario - lunghezza_parola;
                                      
                                      // "Espansione"
                                      j = lunghezza_frase - lunghezza_parola + lunghezza_contrario;
                                      str[j] = '\0';
                                      for (j = lunghezza_frase - lunghezza_parola + lunghezza_contrario; j > i + lunghezza_parola; j--)
                                               str[j] = str[j - diff];
                                      strncpy(&str[i], contrario, lunghezza_contrario);
                                      return 1;
                            }
                   }
         }
         return 0;
}
