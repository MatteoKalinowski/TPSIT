#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 

void *codice_thread(void *n){
    int b = *(int *)n;
    for(int i = 0; i < b; i++){
        printf("thread in esecuzione...\n");
        sleep(1);
    }
    return NULL;
}
int main(){

    int n;
    pthread_t ptid;

    printf("inserire il numero di passi che il thread deve compiere: ");
    scanf("%d", &n);

    pthread_create(&ptid, NULL, codice_thread, &n);
    pthread_join(ptid, NULL);
}