#include <stdio.h>

void bubble_sort(int [], int);
void swap(int *, int *);

int main ( ){

    int i, n=15, a[15]={4,2,5,7,1,91,1,1,1,1,10,3,6,8,100};

    printf("L'array e': \n");
    for ( i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");


    bubble_sort(a, n);


    printf("L'array ordinato per bubble sort e': \n");
    for ( i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}



void bubble_sort(int a[], int n){

    int i, j;

    for ( i = 0; i < n-1; i++)
    {
       for (j = 0; j < n-i-1; j++)
       {
        
            if (a[j]>a[j+1])
            {
                swap(&a[j], &a[j+1]);
            }

        }
     
    }
    
}


void swap(int *c1, int *c2){
    
    int temp;
    temp=*c1;
    *c1=*c2;
    *c2=temp;

}