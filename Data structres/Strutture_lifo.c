#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

void invertire_array(char [], short);
void push(char, char [], short *);
void pop(char *, char [], short *);


void main (){

    char a[]={'A','B','C','D','E','F','G','H','I','J',};
    short lun_a = 10, i;

    puts("Array prima:\n");
    for (int i = 0; i < lun_a; i++)
    {
        printf("a[%d] = %c\n", i, a[i]);
    }
    
    invertire_array(a, lun_a);

    puts("Array dopo l'inversione:\n");

    for (int i = 0; i < lun_a; i++)
    {
         printf("a[%d] = %c\n", i, a[i]);
    }
    

}



void invertire_array(char a[], short lun_a){

    char temp[MAX_STACK_SIZE];
    short i, head;

    head = -1;
    for (int i = 0; i < lun_a; i++)
    {
        push(a[i], temp, &head);
    }

    for (int i = 0; i < lun_a; i++)
    {
        pop(a+i, temp, &head);
    }

}

void push (char elem, char p_stack[], short *head){

    *(p_stack + (++(*head))) = elem;

    //p_stack[++(*head)] = elem; 

}

void pop (char *elem, char p_stack[], short *head){

    *elem = *(p_stack + (*head)--);

}
