#include <stdio.h> 
#include <stdlib.h>

//Se mi serve globale posso decommentare la linea successiva
//#define LUN 26

void push(char, char *, short *);
void pop(char *, char *, short *);
void inverti_array(char *, short);

void main() { 

    //65 é il numero ascii da dove partono le lettere maiuscole

    short lun;
    char *lista;

    char risposta;




    do
    {   puts("\n/*********************************************/\n");

        printf("Inserisci la lunghzza dell'array di caratteri: ");
        scanf("%d", &lun);
        int k = 0;
        
            lista = (char *)calloc(lun, sizeof(char));

            for (short i = 65; i < 65+lun; i++)
            {   
                lista[k++] = (char)i;
            }
    
            printf("\nArray di size %d PRIMA dell'inversione:\n\n", lun);
            for (short i = 0; i < lun; i++)
            {
                printf("a[%d]\t=\t%c\n", i+1, *(lista + i));
            }

            inverti_array(lista, lun);

            printf("\nArray di size %d DOPO dell'inversione:\n\n", lun);
            for (short i = 0; i < lun; i++)
            {
                printf("a[%d]\t=\t%c\n", i+1, *(lista + i));
            }


        printf("\nVuoi riprovare? (s/n): ");
        fflush(stdin);
        scanf("%c", &risposta);
        
        free (lista);

    } while (risposta == 's');
    
}



void inverti_array(char *lista, short lun){

    short head = -1;

    char *p_temp;

    p_temp = (char *)calloc(lun, sizeof(char));

    for (short i = 0; i < lun; i++)
    {
        push(*(lista + i), p_temp, &head);
    }
    
    for (short i = 0; i < lun; i++)
    {
        pop(&lista[i], p_temp, &head);
    }
    
    free(p_temp);

}


void push(char elem, char *stack, short *head){

    *(stack + (++*head)) = elem;

}

void pop(char *elem, char *stack, short *head){

    *elem = *(stack + (*head)--);

}