#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <windows.h>


void stampaStringa(char *, int );
void atto1_presentazioni();
void test();
void menu();


char * copione[] = {

    //frase 0
    "Ciao ragazzi e ragazze.",
    //frase 1
    "Voglio fare un gioco con voi ...",
    //frase 2
    "Quella che voglio proporvi e' una sfida affrontata da molti",
    //frase 3
    "ma che nessuno e' mai riuscito a risolvere.",
    
    //frase 4
    "Il vostro scopo sara' quello di risolvere degli enigmi ideati da me e di darmi le loro risposte.",
    //frase 5
    "Niente di piu' semplice",
    //frase 6
    "vero?",
    //frase 7
    "Bene :)",
    //frase 8
    "Direi che possiamo iniziare",
    //frase 9
    
    "Se avete capito tutti fate scrivere \"Acido Desossiribonucleico\" al vostro capitano.",
    //frase 10
    "Per confermare dovra' premere il tasto INVIO:",
    //frase 11
    "Ottimo, iniziamo con il piede giusto :D ...",
    //frase 12
    "HA HAAA, vedo che vi ho gia' messo in difficolta' >:D",
    //frase 13
    "Ad ogni modo, non importa, era solo un test.",
    //frase 14
    "Ora pero' iniziamo con le cose serie >:)",

    //frase 15
    "Gli enigmi che dovrete risolvere sono 4, ognuno di loro vi portera' ad un passo verso la fine",
    //frase 16
    "OH, ma state tranquilli",
    //frase 17
    "tanto, non ce la farete mai a risolverli tutti HAHAHAHAHA! >XD",
    //frase 18
    "Quello che dovrete fare e' sceglierne uno in base al numero ad esempio il primo e' il numero \"1\"",
    //frase 19
    "Il secondo e' il numero \"2\" e cosi' via fino al 4 :)",
    //frase 20
    "ATTENZIONE! UNA VOLTA CHE INIZIATE UN ENIGMA NON POTETE SCEGLIERNE UN ALTRO!",
   
    //frase 21
    "Detto cio'",
    //frase 22
    "iniziate ...",
    //frase 23
    "INIZIATE A BALLARE MIE PICCOLE MARIONETTE! >:D",

    //frase 24
    "Premete INVIO per continuare.",

    //frase 25
    "Scegliete un puzzle, vi ricordo che fin quando non lo risolverete non potrete passare ad un altro!",
    //frase 26
    "Vi restano ancora da svelare i seguenti enigmi:",





};



int main() {


    atto1_presentazioni();

    test();

    spiegazione_menu();

    stampaStringa(copione[25], 50000);
    menu();

    return 0;
}



//Stampa delle stringhe con velocitá
void stampaStringa(char *str, int velocita) {
    
    char frase [1000];

    strcpy(frase, str);    
    frase[strcspn(frase, "\n")] = '\0';

    for (int i = 0; i <= (int)strlen(str); i++)
    {
        printf("%c",frase[i]);
        usleep(velocita);
    }

    printf("\n");

}

//Presentazioni iniziali
void atto1_presentazioni(){

    stampaStringa(copione[0], 60000);
    sleep(3);
    stampaStringa(copione[1], 50000);
    sleep(2);
    stampaStringa(copione[2], 50000);
    stampaStringa(copione[3], 80000);

    sleep(2);
    printf("\n");
    stampaStringa(copione[4], 50000);
    sleep(1);
    stampaStringa(copione[5], 90000);
    sleep(2);
    stampaStringa(copione[6], 200000);
    sleep(4);

    printf("\n");
    stampaStringa(copione[7], 70000);
    sleep(1);
    stampaStringa(copione[8], 70000);
    printf("\n");

    sleep(2);
    stampaStringa(copione[9], 50000);
    stampaStringa(copione[10], 50000);



}

//Test dopo le presentazioni
void test(){

    char test [30];

    fflush(stdin);
    fgets(test, sizeof(test), stdin);
    test[strcspn(test, "\n")] = '\0';
    strlwr(test);

    if(strcmp(test, "acido desossiribonucleico") == 0){

        sleep(2);
        stampaStringa(copione[11], 60000);
        sleep(2);
        stampaStringa(copione[14], 90000);
        sleep(2);
        system("cls");

    } else {

        sleep(1);
        stampaStringa(copione[12], 60000);
        sleep(1);
        stampaStringa(copione[13], 60000);
        sleep(2);
        stampaStringa(copione[14], 90000);
        sleep(2);
        system("cls");

    }

}

//Spiegazione del menu
void spiegazione_menu(){

    stampaStringa(copione[15], 50000);
    sleep(1);
    stampaStringa(copione[16], 80000);
    sleep(2);
    stampaStringa(copione[17], 90000);
    sleep(2);
    printf("\n");

    stampaStringa(copione[18], 60000);
    stampaStringa(copione[19], 60000);
    sleep(1);
    stampaStringa(copione[20], 50000);
    sleep(3);
    printf("\n");

    stampaStringa(copione[21], 100000);
    sleep(3);
    stampaStringa(copione[22], 100000);
    sleep(2);
    printf("\033[0;31m");
    stampaStringa(copione[23], 120000);
    printf("\033[0m");
    sleep(4);
    
    stampaStringa(copione[24], 50000);
    while (getchar() != '\n');
    system("cls");

    

}

//Comparsa menu
void menu(){

    stampaStringa(copione[26], 50000);
    sleep(1);

    for (short i = 0; i <= 3; i++)
    {
        printf("%d\n", i+1);
        sleep(1);
    }
    


}


















