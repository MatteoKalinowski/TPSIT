#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *codiceThread(void * arg){
    printf("io sono un Thread\n");
    return NULL;
}

int main(){


printf("io sono il main\n");
pthread_t ptid;
pthread_create(&ptid, NULL, codiceThread, NULL);
pthread_join(ptid, NULL);

    return 0;


}