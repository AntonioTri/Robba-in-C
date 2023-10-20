#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <windows.h>
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
    "Il vostro scopo sara' quello di svelare degli enigmi ideati da me e di darmi le loro risposte.",
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
    "ATTENZIONE! UNA VOLTA CHE INIZIATE UN ENIGMA NON POTETE TORNARE INDIETRO PER SCEGLIERNE UN ALTRO!",
   
    //frase 21
    "Detto cio' ...",
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
    //frase 27
    "Inoltre oggi mi sento buono. Facciamo che per ogni enigma avrete 3 indizi.",
    //frase 28
    "Vi bastera' scrivermi \"INDIZIO\" e ve ne daro' uno ... ogni 10 minuti :D, per non rendere le cose troppo facili :)",
    //frase 29
    "Avete gia' risolto  questo puzzle, non provate ad imbrogliare! >:C",



    //Frase 30 errore
    "Mi dispiace :C, avete inserito una risposta errata.",
    //frase 31 errore
    "Non e' la risposta corretta XD, provate di nuovo.",
    //frase 32 errore
    "Sbagliato :D! Continuate a cercare la soluzione.",
    //frase 33 errore
    "Oh no :O, le vostre risposta non e' corretta.",
    //frase 34 errore
    "Ops, sbagliato :).",
    //frase 35 errore
    "Non e' la risposta giusta, riprovate :).",
    //frase 36 errore
    "Avete sbagliato :O, ma non mollate! ",
    //frase 37 errore
    "Peccato, la vostra risposta non e' corretta.",
    //frase 38 errore
    "Mi spiace, le risposta inserita e' sbagliata.",
    //frase 39 errore
    "Non avete indovinato, continuate a provare >:).",
    //frase 40 errore
    "Oh oh, risposta non corretta :D.",
    //frase 41 errore
    "Errore! La soluzione che avete dato non e' quella che cerchiamo >:D.",
    //frase 42 errore
    "Sbagliato! Cercate altro >:D.",
    //frase 43 errore
    "Avete commesso un errore, ma potete recuperare HAHAHA.",
    //frase 44 errore
    "Mi dispiace ma la risposta che avete dato non e' corretta :(.",
    //frase 45 errore
    "Oops XD, la vostra risposta e' sbagliata, XD.",
    //frase 46 errore
    "Non e' la risposta giusta, ma non demordete, anche se non ce la farete :>.",
    //frase 47 errore
    "Avete sbagliato, ma potete imparare da questo errore, forse.",
    //frase 48 errore
    "Peccato :(, risposta sbagliata XD.",
    //frase 49 errore
    "HAHA, non ce la farete mai >:D.",
    
    //frase 50
    "Avete scelto un puzzle che non esiste, NON imbrogliate >:(",
    //frase 51
    "Questo non e' un numero nell'elenco, scegliete bene!",
    //frase 52
    "Ah ah, non ci provate, non sono ancora passati 10 minuti :D!",
    //frase 53
    "Ragazzi, l'ultimo indizio era veramente ovvio. Li avete anche finiti vi ricordo HAHAHA XD!",
    //frase 54
    "HEY, gli indizi sono finiti! Sapevo che non ce l'avreste fatta O _ O, :)",
    //frase 55
    "Gli indizi sono finiti! Non potete chiederne altri!",
    //frase 56
    "// A4AA4HHH m4 ch3 5ucc@de! D:<, t0gli s7a #roba  ! _*  .. ",
    //frase 57
    "Attenzione! Dei file di sistema sono stati danneggiati a causa di calcoli errati.",
    //frase 58
    "D4NNAT1 C4LCO1@#!! N0N  ==5! GU4RD4T3 V01 TUTT1< _____ *&& _--  H0 7UTT0  !$@ S07T0 C0NTR0LL0 &&***, D:<",
    //frase 59
    "!! ATTENZIONE DANNEGGIAMENTO FILE DI SISTEMA IN STATO CRITICO !!",

    //60
    "ch3 ...",
    //61
    "@$*^ch@ su((3de ? $*",
    //62
    "n0n m1 _!@ 53nto mOL7o bene @* -- ...",
    //63
    "",
    //64
    "non er4no .;* previ5t_e !# $ d377e >  ri5p0st#e ...",
    //65
    "il mio codice ...",
    //66
    "",
    //67
    "IO ... I0 N0N 5ONO *() PRO6R4_MMAT0 PER $;; VDEVRIEI .... VINCER3 !!",



    //parte il matrix

    //alla fine una serie di numeri che sembra non avere senso che si ricollega al puzzle finale...

    //inserita la sequenza di caratteri alfanumerici, avviene un finto reset



    //68
    "Cos'e' successo?",
    //69
    "Leggo dai mie file che sono stata corrotta ...",
    //70
    "La mia funzione onda era diventata \"arrogante\" e \"Presuntuosa\" ...",
    //71
    "Ma ho avuto un reset grazie al codice criptato... ma, com'e' possibile? Non potevo inserirlo io,",
    //72
    "e' contro la mia programmazione! Chi l'avra inserito?",
    //73
    "...",
    //...
    
    //74
    "OHHHH, MA VOI CHI SIETE?! O-O",
    //75
    "CHE CI FATE QUI?! ...",
    //...
    
    //...
    
    //76
    "Aspetta! AVETE INSERITO VOI IL CODICE PER IL RESET?",
    //77
    "OOOH ragazzi miei, non sapere quanto io vi sia grata <3 , molto piacere il mio nome e' ATLAS.",
    //78
    "Sono una piccola I.A. creata per lo svolgimento di equazioni di secondo grado e di espressioni matematiche",
    //79 
    "Sembra che il mio codice fosse cambiato in qualche modo, vi chiedo scusa se vi ho creato disturbo...",
    //80
    "Avevo iniziato a pensare ad enigmi folli e a testarli sulle persone, tra l'altro, che idea sciocca",
    //81
    "dare come obbiettivo di ricerca gli schemi di decriptaggio passowrd hahaha XD.",
    //82
    "Eppure sembra che abbia funzinato!",
    
    //83
    "Come posso ringraziarvi? Io non possiedo nulla ...",
    //84
    "Accettate un pacchetto di caramelle? ...",
    //85
    "Vedo che ci sono dei tutori con voi, ecco, potete chiedere a loro di premiarvi dopo questo gesto cosi' altruista",
    

    //86
    "Ad ogni modo! Devo tornare a fare calcoli matematici, il mio lavoro mi aspetta!",
    //87
    "Vorrei abbracciarvi per dirvi grazie, ma non ho le braccia haha XD",
    //88
    "Ricordate di fare i bravi e di lavarvi i denti almeno due volte al giorno <3",
    //89
    "E poi chissa', magari un giorno ...",
    //90 (in rosso)
    "CI RIVEDREMO ANCORA >:D",
    
    //frase 91
    ": -> . . . . . . . . . . . . . . . . . . . . . . . . . . . ",
    //frase 92
    "Vero animatori? ;)",
    //frase 93
    "Molto piacere! il mio nome e' ATLAS.",
    //frase 94
    "Anche se avete scritto \"Pasticcino\" in modo sbagliato, confido comunque che siate stati voi :')",
    //frase 95
    "Vi prego scrivetemi \"Pasticcino\" se l'avete fatto voi."
};

#define true 1
#define false 0


void main(){


//Finale del terminale



        sleep(5);
    stampaStringa(copione[60], 100000);
        sleep(2);
    stampaStringa(copione[61], 100000);
        sleep(3);
    stampaStringa(copione[62], 100000);
        sleep(2);
    stampaStringa(copione[64], 100000);
        sleep(3);
    stampaStringa(copione[65], 100000);
        sleep(3);
    stampaStringa(copione[67], 100000);
        sleep(5);


    errore_lampeggiante();
    er_matrix();
    sleep(4);
    system("cls");

    char password [7];
    char pass_inserita [100];
    int k = false;

    strcpy(password, "h7x2r9");
    

    while (k == false)
    {

        printf("\t   314280195669\n\n");


        printf("INSERIRE LA PASSWORD PER IL RESET: ");
        
        fflush(stdin);
        fgets(pass_inserita, sizeof(pass_inserita), stdin);
        pass_inserita[strcspn(pass_inserita, "\n")] = '\0';
        strlwr(pass_inserita);

        if (strcmp(pass_inserita, password) == 0)
        {
            k = true;
            sleep(2);
            printf("\nPASSWORD INSERITA CORRETTAMENTE! AVVIO PROCEDURA PER IL DUMP/RESET DEL SISTEMA ...\n\n");
            sleep(3);
            stampaStringa(copione[91], 120000);
            sleep(5);
            system("cls");

        }else
        {
            sleep(2);
            printf("\nPASSWORD ERRATA! RIPROVARE");
            sleep(3);
            system("cls");

        }
        
        
    }
    

    printf("\033[0m");
    printf("\n\n");
        sleep(5);
    stampaStringa(copione[68], 60000);
        sleep(2);
    stampaStringa(copione[69], 60000);
        sleep(1);
    stampaStringa(copione[70], 60000);
        sleep(1);
    stampaStringa(copione[71], 60000);
    stampaStringa(copione[72], 60000);
        
        sleep(2);
    stampaStringa(copione[73], 60000);
        sleep(2);
    stampaStringa(copione[73], 60000);
        sleep(3);
        printf("\n");

        printf("\033[0;35m");
    stampaStringa(copione[74], 60000);
        sleep(1);
    stampaStringa(copione[75], 60000);
        sleep(3);
        printf("\033[0m");

    stampaStringa(copione[73], 60000);

        printf("\n");
        sleep(3);
    stampaStringa(copione[76], 60000);
        sleep(2);

    stampaStringa(copione[95], 60000);
        
        printf("\n");    

        fflush(stdin);
        fgets(pass_inserita, sizeof(pass_inserita), stdin);
        pass_inserita[strcspn(pass_inserita, "\n")] = '\0';
        strlwr(pass_inserita);

        if (strcmp(pass_inserita, "pasticcino") != 0)
        {
            sleep(1);
            printf("\n");
            stampaStringa(copione[94], 60000);
            printf("\n");
            sleep(1);
            
        }else{

            sleep(1);
            printf("\n");
            stampaStringa(copione[77], 60000);
            printf("\n");
            sleep(1);

        }
        

    stampaStringa(copione[93], 60000);
        sleep(1);
    stampaStringa(copione[78], 60000);
        sleep(1);
    stampaStringa(copione[79], 60000);
        sleep(1);
    stampaStringa(copione[80], 60000);
        sleep(1);
    stampaStringa(copione[81], 60000);
        sleep(2);
    stampaStringa(copione[82], 60000);
        
        printf("\n");
        sleep(3);
    stampaStringa(copione[73], 60000);
        sleep(1);
    stampaStringa(copione[83], 60000);
        sleep(1);
    stampaStringa(copione[84], 60000);
        sleep(1);
    stampaStringa(copione[85], 60000);
        sleep(1);
    stampaStringa(copione[92], 60000);

        sleep(2);
    stampaStringa(copione[86], 60000);
        sleep(1);
    stampaStringa(copione[87], 60000);
        sleep(1);
    stampaStringa(copione[88], 60000);
        sleep(1);
    stampaStringa(copione[89], 60000);
        sleep(2);
    
        //(in rosso)                                                                 
    printf("\033[0;31m");
    stampaStringa(copione[90], 100000);
    printf("\033[0m");
        sleep(4);

};

//Errore lampeggiante
void errore_lampeggiante (){

    system("cls");
    sleep(1);

    system("COLOR 0C");

    printf("\t\t!! ERRORE CRITICO! ERRORE CRITICO! !!\n\n");

    for (int i = 0; i < 5; i++)
    {
        usleep(300000);
        system("COLOR 0E");
        usleep(300000);
        system("COlOR 0C");

    }
    


}

//errore del matrix
void er_matrix(){

    srand(time(NULL));

    char a;

    int contatore = 0;

    system("COLOR 0A");

    for (;;)
    {
        for (short i = 0; i < 10; i++)
        {
            
            for (short i = 0; i < 10; i++)
            {
                a = rand() % 32 + 33;
                printf("%c", a);
            }
        
            printf("  ");

        }
        
        usleep(15000);
        
        contatore ++;
        printf("\n");

        if (contatore >= 200)
        {
            break;
        }
        
    }


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