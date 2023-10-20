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
int appartiene(parola *, int, char *);
int StrReplaceSingle(char *, int , char *, char *);

int main (){
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
    {"responsaile",{"irresponsabile","inaffidaile","incosciente","frivolo","superficiale"}},
    {"scuro",{"chiaro","limpido","luminoso","bianco","sereno"}},
    {"sicuro",{"insicuro","dubbioso","ditubante","indeciso","incerto"}},
    {"sorprendente",{"noioso","normale","naturale","comune","ordinario"}},
    {"sporco",{"pulito","limpido","terso","lavato","integerrimo"}},
    {"utile",{"inutile","inadatto","inutilizzabile","improduttivo","inefficace"}}
    

    };


    char parola[10];
    strcpy(parola, dizionario[4].contrario[2]);

    printf("La parola e': %s", parola);





}
     