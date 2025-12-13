#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main(){

    pthread_t td;

    pthread_create(&td, NULL, NULL, NULL);
    
    printf("%lu\n", td);



    return 0;
}



