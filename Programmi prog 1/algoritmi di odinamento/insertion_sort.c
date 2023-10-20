#include <stdio.h>

void insertion_sort(int [], int );


int main ( ){

    int i, n=15, a[15]={4,2,5,7,1,91,1,1,1,1,10,3,6,8,100};

        printf("L'array e': \n");

    for ( i = 0; i < n; i++)
    {
        printf("%d ", a[i]);

    }

    printf("\n");
    
    insertion_sort(a, n);

    printf("L'array ordinato per inserimento e': \n");

    for ( i = 0; i < n; i++)
    {
        printf("%d ", a[i]);

    }
}



void insertion_sort(int a[], int n){

int i, j, temp;

    for ( i = 1; i < n; i++)
    {
        temp=a[i];
        j=i-1;

        while (j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        } 

        a[j+1]=temp;

    }

}