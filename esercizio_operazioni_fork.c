#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

    int f1(){
        return 5 * 3;
    }

    int f2(){
        return 9 * 4;
    }

    int f3(){
        return 4 * 7;
    }

int main(){

    pid_t pid1 = fork();

    if(pid1 == 0){
        exit(f1());
    }
    else {
        pid_t pid2 = fork();

        if(pid2 == 0){
            exit(f2());
        }
        else{
            int temp = f3();
            int r1;
            int r2;
            wait(&r1);
            wait(&r2);
            printf("il risultato e': %d\n ", WEXITSTATUS(r1) + WEXITSTATUS(r2) + temp);
        }
    }
}

