#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 

void *codice_thread(void * arg){
    while(1){
        printf("thread in esecuzione...\n");
        sleep(1);
    }
    return NULL;
}

int main(){

    int n;
    pthread_t ptid;

    pthread_create(&ptid, NULL, codice_thread, NULL);
    scanf("%d", &n);
    pthread_cancel(ptid);
    pthread_join(ptid, NULL);
}
    
