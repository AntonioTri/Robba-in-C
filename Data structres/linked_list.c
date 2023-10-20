#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int data;
    void *next;

}Node;

Node *head = NULL;

void printMenu();
Node *addNode(int );
int removeNode(int );
Node *insertNode(int , int );
void printlist();


int main(){

    int options = -1;

    do
    {
        options = -1;
        int arg1 = 0;
        int arg2 = 0;

        printMenu();
        scanf("%d", &options);

        if ( options > 0 && options <= 5)
        {
            switch (options)
            {
            case 1:
                
                // add operation
                printf("What data do you want to insert at the beginning?\n");
                scanf("%d", &arg1);
                Node *new = addNode(arg1);

                break;

            case 2:

                //remove operation
                printf("What data do you want to remove?\n");
                scanf("%d", &arg1);
                int success = removeNode(arg1);

                if (!success)
                {
                    printf("Element not found\n");
                }
                
                break;

            case 3: 
                // Insert operation
                printf("What data do you want to insert?\n");
                scanf("%d", &arg1);
                printf("What position?\n");
                scanf("%d", &arg2);
                Node *new2 = insertNode(arg1, arg2);
                if (new2 == NULL)
                {
                    printf("Failed to insert...\n");
                }
                
                break;

            case 4:

                // Print list
                printlist();

                break;

            case 5:

                break;
         
            }

        } else {

            printf("Invalid option, try again.\n");

        }

    } while (options != 5);


}
    

//print menu
void printMenu(){

    printf("You have the following options:\n");
    printf("\t1 Add a node to the list\n");
    printf("\t2 Remove a node to the list\n");
    printf("\t3 Insert a node to the list\n");
    printf("\t4 Print your list\n");
    printf("\t5 Exit\n");
}

//add a node
Node *addNode(int data){

    // two cases

    Node *new = NULL;

    //If the list is empty, head pointing to NULL
    if (head == NULL)
    {
        new = malloc(sizeof(Node));
        //check to see if there is enough memory
        if (new == NULL)
            return NULL;

        // assigning values
        new->data = data;
        head = new;
        new->next = NULL;

    } else {
        
        new = malloc(sizeof(Node));
        //check to see if there is enough memory
        if (new == NULL)
            return NULL;

        // assigning values
        new->data = data;
        new->next = head;
        head = new;

    }
    
    
    return new;

}

//remove a node
int removeNode(int data){

    Node *current = head;
    Node *prev = head;

    while (current != NULL)
    {
        if (current->data == data)
        {
            
            if (current == head)
            {
                head = current->next;
            } else {

                prev->next = current->next;
                free(current);
                current = NULL; 

            }

            return 1;
            
        }
        
        prev = current;
        current = current->next;
        
    }
    

}

//insert a node in the middle
Node *insertNode(int data, int position){

    Node *current = head;
    while (current != NULL && position != 0)
    {
        position--;
    }

    if (position != 0)
    {
        printf("The position is too far from the list\n");
        return NULL;
    }

    Node *new = malloc(sizeof(Node));
        if (new == NULL)
            return NULL;  
        
        new->data = data;
        new->next = current->next;
        current->next = new;
    
    return new;

}

//print operation
void printlist(){

    Node *current = head;

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    
    
    printf("\n");

}
