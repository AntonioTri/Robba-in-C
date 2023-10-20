        //system("COlOR 0C"); questa funzione cambia il colore di quello che viene scritto
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

#define true 1
#define false 0


typedef struct{

    char domanda[200];
    char risposta[20];
    int flag;

    char descrizione[300];
    char congrat[100];
    char indizio[3][200];
    int conta_indizi;


}Domande;


typedef struct 
{
    char ris[10];

} Risposte;


void scelta_puzzle(Domande *, Risposte *, short, int *);
void stampaStringa(char *, int );
void inizializzazione(Domande *);
void atto1_presentazioni();
void spiegazione_menu();
void test();
void menu(Domande *);
void indizio(Domande *, int *, time_t *, short);
short simulazione_errori(int,int,int,int);
void atto3();
void errore_lampeggiante();
void er_matrix();

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
    "OOOH ragazzi miei, non sapete quanto io vi sia grata <3.",
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

int main(){

    //Dichiarazione delle variabili in gioco
    Domande puzzle[4];
    Risposte risposta[4];

    srand(time(NULL));

    //Inizializzazione delle variabili
    inizializzazione(puzzle);

    //scelta_difficolta'();

    int a = true;

    short quiz;

    printf("Premi Invio per continuare...\n");
    while (getchar() != '\n');
    
    //Atto 1
    atto1_presentazioni();

    //test per vedere se stanno attenti
    test();
    
    //Spiegazione del menu
    spiegazione_menu();




    while (a == true)
    {

        fflush(stdin);
        //Se sono stati risolti tutti inizia l'ATTO 3, altrimenti viene generato un evento falla funzione
        if (simulazione_errori(puzzle[0].flag, puzzle[1].flag, puzzle[2].flag, puzzle[3].flag) == 4)
        {
            atto3();
            a = false;
            sleep(5);

        //ATTO 2, inizio quiz
        }else{

            //Viene mostrato il menu' delle opzioni ancora disponibili
            menu(puzzle);
            fflush(stdin);
            scanf("%hd", &quiz);

            quiz = quiz-1;

            //In base alla risposta viene selezionato il puzzle e si entra nella sequenza atomica
            //Quando un puzzle viene risolto la sua flag si alza e non verrá piu' mostrato
            switch (quiz) {
                
                case 0:

                    scelta_puzzle(puzzle, risposta, quiz, &puzzle[0].flag);

                    break;
                
                case 1:

                    scelta_puzzle(puzzle, risposta,  quiz, &puzzle[1].flag);

                    break;
                
                case 2:

                    scelta_puzzle(puzzle, risposta, quiz, &puzzle[2].flag);

                    break;

                case 3:

                     scelta_puzzle(puzzle, risposta, quiz, &puzzle[3].flag);

                    break;
                
                default:

                    //Messaggio nel caso in cui venga cliccata una lettera per sbaglio od un numero
                    //Che non é nell'elenco
                    int nro_ = (rand() % 2) + 50;
                    stampaStringa(copione[nro_], 50000);
                    sleep(3);
                    system("cls");
                    fflush(stdin);
                    
                    break;

            }

        }

    }

}
    



//Funzione che gestisce il puzzle scelto tramite la struct e l'indice scelto
void scelta_puzzle(Domande *puzzle, Risposte *risposta, short i, int *flag_risoluzione ){


    int b = true;
    int conta = 0;

    system("cls");

    if (puzzle[i].flag == 0)
    {

        //Si introduce il titolo del puzzle e la sua descrizione
        sleep(2);
        stampaStringa(puzzle[i].domanda, 40000);
        sleep(3);
        printf("\n");
        stampaStringa(puzzle[i].descrizione, 70000);
        printf("\n");

        time_t tempo_inizio = time(NULL);

        while (b)
        {

            //Tutto sto casino di comandi serve a prendere la risposta
            fflush(stdin);
            fgets(risposta[i].ris, sizeof(risposta[i].ris), stdin);
            risposta[i].ris[strcspn(risposta[i].ris, "\n")] = '\0';
            strlwr(risposta[i].ris);


            //Se la rispostra é corretta vengono attivate alcune flag per la gestione e viene
            //scritto un messaggio di stupore per poi tornare nel while di chiamata e proseguire con
            //Gli altri enigmi
            if (strcmp(puzzle[i].risposta, risposta[i].ris) == 0)
            {
                printf("\n");
                stampaStringa(puzzle[i].congrat, 50000);
                b = false;
                *flag_risoluzione = true;
                sleep(5);
                fflush(stdin);
                system("cls");

            //I ragazzi possono chiedere degli indizi al conduttore e viene gestito 
            //un limite di tempo per la loro richiesta
            
            //!!!!DA IMPLEMENTARE
            }else if (strcmp(risposta[i].ris, "indizio") == 0){

                indizio(puzzle, &conta, &tempo_inizio, i);
                fflush(stdin);

            //In generale se la risposta e' sbagliata viene stampato un messaggio di risposta sbagliata
            //tra un set di risp[oste randomiche
            } else {

                int nro = (rand() %20) + 30;
                printf("\n");
                stampaStringa(copione[nro], 50000);
                printf("\n");
                fflush(stdin);

            }


        }

    } else
    {
        stampaStringa(copione[29], 50000);
        sleep(2);
        fflush(stdin);
        system("cls");

    }

}

//Inizializzazione del puzzle
void inizializzazione(Domande * puzzle){

    strcpy(puzzle[0].domanda, "Avete scelto il puzzle numero 1: \"Lettere e parole ...\"");
    strcpy(puzzle[0].descrizione, "cane");
    strcpy(puzzle[0].indizio[0], "Indizio 1");
    strcpy(puzzle[0].indizio[1], "Indizio 2");
    strcpy(puzzle[0].indizio[2], "Indizio 3");
    strcpy(puzzle[0].congrat, "Vedo che siete riusciti a risolvere l'enigma, i miei complimenti...");
    strcpy(puzzle[0].risposta, "cane");
    puzzle[0].flag = 0;
    puzzle[0].conta_indizi = 0;

    strcpy(puzzle[1].domanda, "Avete scelto il puzzle numero 2: \"Sequenza...\"");
    strcpy(puzzle[1].descrizione, "casa");
    strcpy(puzzle[1].indizio[0], "Indizio 1");
    strcpy(puzzle[1].indizio[1], "Indizio 2");
    strcpy(puzzle[1].indizio[2], "Indizio 3");
    strcpy(puzzle[1].congrat, "Oh, finalmente l'avete risolto! Non pensavo ce l'avreste fatta.");
    strcpy(puzzle[1].risposta, "casa");
    puzzle[1].flag = 0;
    puzzle[1].conta_indizi = 0;

    strcpy(puzzle[2].domanda, "Avete scelto il puzzle numero 3: \"Messaggi subliminali...\"");
    strcpy(puzzle[2].descrizione, "pane");
    strcpy(puzzle[2].indizio[0], "Indizio 1");
    strcpy(puzzle[2].indizio[1], "Indizio 2");
    strcpy(puzzle[2].indizio[2], "Indizio 3");
    strcpy(puzzle[2].congrat, "Siete riusciti a risolvere l'enigma? ... sconvolgente, avevo previsto un vostro miserabile fallimento.");
    strcpy(puzzle[2].risposta, "pane");
    puzzle[2].flag = 0;
    puzzle[2].conta_indizi = 0;

    strcpy(puzzle[3].domanda, "Avete scelto il puzzle numero 4: \"Luce ed ombra...\"");
    strcpy(puzzle[3].descrizione, "acqua");
    strcpy(puzzle[3].indizio[0], "Indizio 1");
    strcpy(puzzle[3].indizio[1], "Indizio 2");
    strcpy(puzzle[3].indizio[2], "Indizio 3");
    strcpy(puzzle[3].congrat, "Non pensavo ci sareste riusciti fra nemmeno cent'anni D: Ma come ... ... non importa");    
    strcpy(puzzle[3].risposta, "acqua");
    puzzle[3].flag = 0;
    puzzle[3].conta_indizi = 0;



};

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

    system("cls");

    sleep(3);
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

    //Viene scannerizzato il test;
    fflush(stdin);
    fgets(test, sizeof(test), stdin);
    test[strcspn(test, "\n")] = '\0';
    strlwr(test);

    //Se la risposta e' sbagliata o corretta avvengono due eventi diversi che sono solo di
    //Scenografia
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

    printf("\n");
    stampaStringa(copione[27], 60000);
    stampaStringa(copione[28], 60000);
    printf("\n");

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
    
    printf("\n");
    stampaStringa(copione[24], 50000);
    while (getchar() != '\n');
    system("cls");

    

}

//Comparsa menu
void menu(Domande * puzzle){

    stampaStringa(copione[26], 50000);
    printf("\n");
    sleep(1);

    for (short i = 0; i <= 3; i++)
    {

        if (puzzle[i].flag == 0)
        {
            printf("Numero: - -  %d  - -\n", i+1);
            sleep(1);

        }
        
    }

    printf("\n");
    
}

//Gestione degli indizi
void indizio(Domande *puzzle, int *conta, time_t *tempo_inizio, short i){

    
        time_t tempo_ora = time(NULL);

        if (((tempo_ora - *tempo_inizio) > 5) && (*conta <3))
        {
            printf("\n- - - - - - - - - - - - - - - - INDIZIO %d DELL'ENIGMA %d - - - - - - - - - - - - - - - - \n\n", *conta + 1, i+1);
            sleep(2);
            stampaStringa(puzzle[i].indizio[*conta], 60000);
            sleep(1);
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n");
           
            *tempo_inizio = time(NULL);
            ++(*conta);

        }else if (*conta >= 3 )
        {
            printf("\n");
            sleep(1);
            int _nro = (rand() % 3) + 53;
            stampaStringa(copione[_nro], 60000);
            sleep(1);
            printf("\n");

        } else {

            printf("\n");
            sleep(1);
            stampaStringa(copione[52], 60000);
            sleep(1);
            printf("\n");


        }
        

}

//conta delle flag per impostare eventi di lore
short simulazione_errori(int a, int b, int c, int d){

    short nro_flag = 0;

    if (a == true)
    {
        nro_flag ++;
    }
    
    if (b == true)
    {
        nro_flag ++;
    }
    
    if (c == true)
    {
        nro_flag ++;
    }
    
    if (d == true)
    {
        nro_flag ++;
    }


    switch (nro_flag)
    {
    case 1:

        sleep(2);
        system("COLOR 0E");
        printf("Line/Col: 68/5 PLS-00103: Encountered the symbol \"ELSE\" when expecting one of the following\n");
        usleep(500000);
        printf("The symbol \";\" was substituted for \"ELSE\" to continue\n");
        sleep(2);
        system("cls");

        break;
    
    case 2:

        

        usleep(500000);
        printf("Line/Col: 20/5 PL/SQL: SQL Statement ignored\n");
        usleep(500000);
        printf("!!!ERROR!!!\n");
        usleep(500000);
        printf("Line/Col: procedure not accomplished: identifier ')(@&*$)/// errore' must be declared\n");
        usleep(500000);
        printf("Line/Col: wrong calculus: identifier 'risposta' must be not found\n");
        usleep(500000);

        printf("\n");
        sleep(2);
        system("COLOR 6");
        stampaStringa(copione[57], 50000);
        sleep(2);
        printf("\n");
        stampaStringa(copione[56], 80000);
        sleep(4);
        system("cls");

        break;
    	
    case 3:

        
            printf("Errors: PROCEDURE\n");
            usleep(500000);
            printf("The symbol \";\" was substituted for \"COGNOME\" to continue.\n");
            usleep(500000);
            printf("Line/Col: 53/37 PLS-00103: Encountered the symbol \"RISPOSTA\" when expecting one of the following:\n");
            usleep(500000);
            printf("25/5 PL/Enigma_4: Statement ignored\n");
            usleep(500000);
            printf("#&!HTGRE?: 21/5 PL/SQLEnigma_3: ORA-00904: : invalid identifier\n");
            usleep(500000);
            printf("Line/Col: 20/5 PL/C++Enigma_2: SQL Statement ignored\n");
            usleep(500000);
            printf("..//??^@$!: 10/36 PLS-00208: identifier 'TYE' is not a legal cursor attribute\n");
            usleep(500000);
            printf("Line/Col: 0/0 PL/SQL: Compilation unit analysis terminated\n");
            usleep(500000);
            printf(":= ( ; not null range default character\n");
            usleep(500000);
            printf("PLS-00103: Encountered the symbol \"BEGIN\" when expecting one\n");

            sleep(3);
            printf("\n");
            system("COlOR 0C");
            stampaStringa(copione[59], 40000);
            sleep(3);
            printf("\n");
            stampaStringa(copione[58], 100000);
            sleep(4);
            system("cls");

        break;

    default:

        break;

    }


    return nro_flag;


}

//Finale del terminale
void atto3(){


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






































