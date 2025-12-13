#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    printf("sono il thread creato, il mio pid è: %d\n", getppid());
    printf("sono il pid del thread creato: %lu\n", pthread_self() );
    return NULL;
}
int main(){

printf("il pid del processo principale è: %d\n", getppid());
printf("sono il pid del processo phtread: %lu\n", pthread_self() );

pthread_t pthread;

pthread_create(&pthread, NULL, thread_function, NULL);

pthread_join(pthread, NULL);


    return 0;
}

