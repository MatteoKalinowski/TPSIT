#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    printf("il processo principale ha PID: %d\n", getpid());

   int pid = fork();

    if(pid < 0){
        printf("errore PID non valido\n");
        exit(1);
    }

    if(pid == 0){
        printf("[FIGLIO]: sono il proceso figlio!\n");
        printf("[FIGLIO]: il mio PID e': %i\n", getpid());
        printf("[FIGLIO]: il pid di mio padre e': %d\n", getppid());

        printf("...il figlio simula il lavoro...\n");
        sleep(2);
        
        int risultato = 10 * 5;
        printf("[FIGLO]: calcolo 10*5...= %d\n", risultato);
        printf("il figlio termina con codice di corretto svolgimento\n");
        exit(0);

    } else{

        printf("[PADRE]: sono il processo padre con PID = %i\n", getpid);
        printf("[PADRE]: il PID di mio figlio e': %d\n", pid);

        int stato;
        printf("[PADRE]: attendo la terminazione del figlio...\n"); 
        wait(&stato);
        printf("[PADRE]: il figlio e' terminato\n");

        if(WIFEXITED(stato)){
            int codice = WEXITSTATUS(stato);
            printf("[PADRE]: il figlio è terminato correttamente con exit: %d\n", codice); 
        } else if(WIFSIGNALED(stato)){
            int segnale = WTERMSIG(stato);
            printf("[PADRE]: il figlio è stato terminato da un segnale: %d\n", segnale); 
        }
        return 0;
    }
}