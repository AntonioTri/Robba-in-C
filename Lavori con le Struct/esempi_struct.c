#include <stdio.h>

typedef struct
{
    char nome[20];
    char cognome[20];
    float altezza;
    int anni;
} Persona;

int main (){

  Persona Persona1 = {"Francesco", "Cantone", 1.80, 21};
  Persona Persona2 = {"Antonio", "Tridente", 1.80, 21};

    printf("\n");
    printf("Persona1 si chiama %s %s, e' alto %.2f ed ha %d anni.\n", Persona1.nome, Persona1.cognome, Persona1.altezza, Persona1.anni);
    printf("Persona1 si chiama %s %s, e' alto %.2f ed ha %d anni.\n", Persona2.nome, Persona2.cognome, Persona2.altezza, Persona2.anni);

}