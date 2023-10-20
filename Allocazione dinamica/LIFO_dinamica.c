#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

void invertire_array(char [], short);
void push(char, char [], short *);
void pop(char *, char [], short *);


int main (){

    char a[]={'A','B','C','D','E','F','G','H','I','J',};
    short lun_a = 10, i;

    puts("Array prima:\n");
    for ( i = 0; i < lun_a; i++)
    {
        printf("a[%d] = %c\n", i, a[i]);
    }
    
    invertire_array(a, lun_a);

    puts("Array dopo l'inversione:\n");

    for ( i = 0; i < lun_a; i++)
    {
         printf("a[%d] = %c\n", i, a[i]);
    }
    
    

}



void invertire_array(char a[], short lun_a){

    char *p_temp;
    short i, head;

    p_temp = (char *)calloc(lun_a, sizeof(a[0]));

    head = -1;
    for ( i = 0; i < lun_a; i++)
    {
        push(a[i], p_temp, &head);
    }

    for ( i = 0; i < lun_a; i++)
    {
        pop(a+i, p_temp, &head);
    }

}

void push (char elem, char *p_stack, short *head){

    *(p_stack + (++(*head))) = elem;

    //p_stack[++(*head)] = elem; 

}

void pop (char *elem, char *p_stack, short *head){

    *elem = *(p_stack + (*head)--);

}