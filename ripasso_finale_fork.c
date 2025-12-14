#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid1 = fork();
    if(pid1 < 0){
        perror("errore nella fork");
        exit(1);
    }

    if(pid1 == 0){  // primo figlio
        printf("[FIGLIO1]: sono il primo figlio con PID: %d\n", getpid());
        printf("[FIGLIO1]: il PID di mio padre e': %d\n", getppid());
        sleep(3);
        int risultato = 5 * 5;
        printf("[FIGLIO1]: calcolo 5*5...= %d\n", risultato);
        exit(1);
    }

    // solo il padre crea il secondo figlio
    int pid2 = fork();
    if(pid2 < 0){
        perror("errore nella fork");
        exit(1);
    }

    if(pid2 == 0){  // secondo figlio
        printf("[FIGLIO2]: sono il secondo figlio con PID: %d\n", getpid());
        printf("[FIGLIO2]: il PID di mio padre e': %d\n", getppid());
        sleep(3);
        int risultato = 10 + 7;
        printf("[FIGLIO2]: calcolo 10+7...= %d\n", risultato);
        exit(2);
    }

    // solo il padre arriva qui
    if(pid1 > 0 && pid2 > 0){
        printf("[PADRE]: sono il padre e attendo la terminazione dei figli\n");
        int status;
        for(int i = 0; i < 2; i++){
            int pid = wait(&status);
            printf("[PADRE]: il processo con PID %d è terminato, codice %d\n", pid, WEXITSTATUS(status));
        }
    }

    return 0;
}
