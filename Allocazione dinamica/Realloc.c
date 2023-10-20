#include <stdio.h>
#include <stdlib.h>


int main(){

    int n, npn;
    float *b;
    float a[] = {0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 7.f, 9.f};
    n = 10;

    b = (float *) calloc(n, sizeof(float));

    for (int i = 0; i < n; i++)
    {
        *(b+i) = a[i];
    }
    
    puts("Array prima del realloc:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\tb[%2d] = %f\n", i, b[i]);
    }
    
    npn= 2*n;


    b = (float *)realloc(b, npn*sizeof(float)); 
 
    for (int i = 0; i < n; i++)
    {
        b[n+i] = a[n-1-i];
    }
    puts("Array dopo la realloc:\n");

    for (int i = 0; i < npn; i++)
    {
        printf("\tb[%2d] = %f\n", i, b[i]);
    }


}  