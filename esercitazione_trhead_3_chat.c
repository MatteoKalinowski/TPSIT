#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *codiceThread(void *arg) {

    printf("THREAD:\n");
    printf("  PID processo = %d\n", getpid());
    printf("  TID thread   = %lu\n", (unsigned long)pthread_self());

    return NULL;
}

int main() {

    pthread_t tid;

    printf("MAIN:\n");
    printf("  PID processo = %d\n", getpid());
    printf("  TID thread   = %lu\n", (unsigned long)pthread_self());

    pthread_create(&tid, NULL, codiceThread, NULL);

    printf("MAIN:\n");
    printf("  TID nuovo thread = %lu\n", (unsigned long)tid);

    pthread_join(tid, NULL);

    return 0;
}
