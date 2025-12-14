#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){ 
int pid1 = fork();

if(pid1 < 0){
    perror("erorre nel fork");
    exit(1);
}
if(pid1 == 0){
    printf("[FIGLIO] sono il processo figlio numero 1 con pid %d\n", getpid());
    printf("[FIGLIO] il mio processo padre ha pid %d\n", getppid());
    printf("[FIGLIO] simulo del lavoro con sleep di 3 secondi\n");
    sleep(3);
    int risultato = 5 + 5;
    printf("[FIGLIO] il risultato del calcolo e' %d\n", risultato);
    exit(0);
}

int pid2 = fork();
if(pid2 < 0){
    perror("erorre nel fork");
    exit(1);
}
if(pid2 == 0){
    printf("[FIGLIO] sono il processo figlio numero 2 con pid %d\n", getpid());
    printf("[FIGLIO] il mio processo padre ha pid %d\n", getppid());
    printf("[FIGLIO] simulo del lavoro con sleep di 5 secondi\n");
    sleep(5);
    int risultato = 10 * 10;
    printf("[FIGLIO] il risultato del calcolo e' %d\n", risultato);
    exit(0);
}
if(pid1 > 0 && pid2 > 0){
    printf("[PADRE] sono il processo padre con PID %d\n", getpid());
    printf("[PADRE] il mio processo figlio 1 ha PID %d\n", pid1);
    printf("[PADRE] il mio processo figlio 2 ha PID %d\n", pid2);
    int status1, status2;
    printf("[PADRE] attendo la terminazione dei miei due figli...\n");
    int terminated_pid1 = wait(&status1);
    int terminated_pid2 = wait(&status2);
    printf("[PADRE] i due processi figli sono terminati con PID %d e %d\n", terminated_pid1, terminated_pid2);
    printf("[PADRE] i loro stati di terminazione sono %d, %d\n", WEXITSTATUS(status1), WEXITSTATUS(status2));
    }
return 0;
}
