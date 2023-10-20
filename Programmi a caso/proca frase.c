#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 400

typedef struct {
    char originale[50];
    char contrario[5][50];
} parola;

int StrReplaceSingle(char *, int , char *, char *);


int main() {

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

    char miastringa[300];
    char risposta;

    strcpy(miastringa, "Quel ramo del lago di Como");

    printf("sostituire? s per si': ");
    scanf(" %c", &risposta);
    printf("%c\n", risposta);

    char parola[5]= "lago";          // FUNZIONA!
    char sostitutivo[8];// FUNZIONA!
    strcpy(sostitutivo, dizionario[5].contrario[2]);

    if (risposta == 's')
    {
        printf("\nprova 1\n");
        StrReplaceSingle(miastringa, 80, parola, sostitutivo);
    }

      printf(miastringa);


}


int StrReplaceSingle(char *str, int lungh_max_frase, char *parola, char *contrario)
{
         int i, j;
         int lunghezza_frase = strlen(str);
         int lunghezza_parola = strlen(parola);
         int lunghezza_contrario = strlen(contrario);
         int diff;

         if ((lunghezza_frase - lunghezza_parola + lunghezza_contrario) >= lungh_max_frase)
                   return -1;        // not enough space

         for (i = 0; i <= (lunghezza_frase - lunghezza_parola); i++)
         {
                   if (strncmp(&str[i], parola, lunghezza_parola) == 0)    // if found
                   {
                            if (lunghezza_parola == lunghezza_contrario)
                            {
                                      strncpy(&str[i], contrario, lunghezza_contrario);
                                      return 1;
                            }
                            else if (lunghezza_parola > lunghezza_contrario)
                            {
                                      diff = lunghezza_parola - lunghezza_contrario;
                                      strncpy(&str[i], contrario, lunghezza_contrario);
                                      // compact
                                      
                                      for (j = i + lunghezza_contrario; j<lunghezza_frase - diff; j++)
                                               str[j] = str[j + diff];
                                      str[j] = '\0';
                                      return 1;
                            }
                            else // lensearch < lensubst
                            {
                                      diff = lunghezza_contrario - lunghezza_parola;
                                      // expand
                                      j = lunghezza_frase - lunghezza_parola + lunghezza_contrario;
                                      str[j] = '\0';
                                      for (; j > i + lunghezza_parola; j--)
                                               str[j] = str[j - diff];
                                      strncpy(&str[i], contrario, lunghezza_contrario);
                                      return 1;
                            }
                   }
         }
         return 0;
}