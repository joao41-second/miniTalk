#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "../libft/libft/libft.h"

int main(int argc, char **argv) {
    if (argc != 3) {
    }else{
    pid_t server_pid = atoi(argv[1]);
    int signal = atoi(argv[2]);

    if (signal == 1) {
      kill(server_pid, SIGUSR1);
    } else if (signal == 2) {
      kill(server_pid, SIGUSR2);
    } else {
       // printf(stderr, "Sinal inválido. Use 1 para SIGUSR1, 2 para SIGUSR2.\n");
    }

    printf("Sinal %d enviado para o servidor com PID %d\n", signal, server_pid);

	}
}