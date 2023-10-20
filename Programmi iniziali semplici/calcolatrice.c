#include <stdio.h>


int main () {

float num1, num2, ris;
char op;

printf("Scegli l'operazione che vuoi ( + - * / )\n");
scanf("%c", &op);     
// posso controllare se ha registrato l'operazione con  printf ("%c", op);
if (op == "+" || "-"|| "*" || ""){
    
    printf("Inserisci il primo numero: \n");
    scanf("%f", &num1);
    printf("Inserisci il secondo numero:\n");
    scanf("%f", &num2);

    switch (op)
    {
    case '+':
        ris = num1+num2;
        printf("Il risultato e': %.1f", ris);
        break;
    case '-':
        ris = num1-num2;
        printf("Il risultato e': %.1f", ris);
        break;
    case '*':
        ris = num1*num2;
        printf("Il risultato e': %.1f", ris);       
        break;
    case '/':
        ris = num1/num2;
        printf("Il risultato e': %.1f", ris);
        break;
    default:
        printf("Non hai inserito un operatore corretto!\n");
        break;
    }

   } else {

    printf("Non hai inserito un operatore valido. \n");

   }
return 0;
}