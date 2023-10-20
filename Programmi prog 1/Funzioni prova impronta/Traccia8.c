/*
	Sviluppare una function C che, data come parametro di input una stringa che
	rappresenta un testo in italiano, determina e restituisce
	come parametro di output il numero di parole di tre lettere contenute nel
	testo. Nel testo le parole sono separate da un unico spazio. 
*/

#include <stdio.h>
#include <string.h>

int restituire (char [500]);

int main()
{
    char testo[500];
    int parola;

    printf("inserire il testo\n");
    gets (testo);
    
    
    parola= restituire (testo);

    printf("il numero delle parole di 3 caratteri e' %d", parola);


    
}

int restituire (char testo[500])
{
    int parole=0;
    char *parolapunt;
    int lunghezzaparola;

    parolapunt = strtok(testo, " ,.:;"); //inizializza soltanto

    while (parolapunt != '\0')
    {
        lunghezzaparola=strlen(parolapunt);

        if(lunghezzaparola==3)
        {
            parole++;
        }
        parolapunt = strtok(NULL, " ,.:;"); 

        //permette di scorrere la frase
        /* praticamente riga 34 strtok dice che, la prima parola ora non vale(lo dice con
        NULL), ora vai da \0 (perchè ora \0 ha preso il
        posto della prima parola) avanti e fermati al prossimo " " e fermati
        MA se noi mettevamo "z" si fermava alla prossima z*/
    }
     return parole;
}