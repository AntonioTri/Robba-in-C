#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define NRO_PAROLE 20

typedef struct {
    char originale[50];
    char contrario[5][50];
} parola;


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


