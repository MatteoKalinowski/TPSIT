#include <stdio.h>
#include <stdlib.h>


int main(){

    int n, m;
    printf("quanti float?:\n ");
    scanf("%d", &n);

    float *a = malloc(sizeof(float));

        for(int i = 0; i < n; i++){
           printf("inserisci il %d float \n", i + 1);
           scanf("%f", &a[i]);

           
        }

        for(int i = 0; i < n; i++){
            printf("%f", a[i]);
        }

        printf("la media dei numeri inseriti e': \n");
        float somma = 0;
        for(int i = 0; i < n; i++){
            somma += a[i];
        }
        float media = somma / n;
        printf("%f\n", media);

        free(a);

    return 0;
}