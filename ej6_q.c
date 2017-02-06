/*
 * Ejercicio 6
 */

#include <stdio.h>
#include <sys/shm.h>
#include <stdlib.h>

int turno = 0;
int quiere_p = 0;
int quiere_q = 0;

int main(int argc, char *argv[]) {
    int shmid_p, shmid_q;
    key_t key_p = 88888;
    key_t key_q = 99999;
    int *dir_memCompartida_p;
    int *dir_memCompartida_q;
    char input[32];
    shmget(key_q, sizeof(int), IPC_CREAT);
    if ((shmid_q = shmget(key_q, NULL, 0)) == -1) {
        perror("Hubo un error al ejecutar shmget.");
        exit(1);
    }
    if ((dir_memCompartida_q = shmat(shmid_q, NULL, 0)) == -1) {
        perror("Shmat ha encontrado un error.");
        exit(1);
    }
    while (1) {
        quiere_q = *dir_memCompartida_q;
        printf("Caminando por mi habitación.\n");
        fgets(input, sizeof(input), stdin);
        printf("Intentando acceder al pasillo de entrada de mi sección crítica.\n");

        shmid_p = shmget(key_p, NULL, 0);
        dir_memCompartida_p = shmat(shmid_p, NULL, 0);
        quiere_p = *dir_memCompartida_p;

        while (quiere_p == 1) {
            printf("Puerta cerrada.\n");
            fgets(input, sizeof(input), stdin);
            quiere_p = *dir_memCompartida_p;
        }
        printf("Dentro del pasillo.\n");
        fgets(input, sizeof(input), stdin);
        *dir_memCompartida_q = 1;
        printf("He accionado el pulsador.\n");
        printf("Dentro de mi sección crítica.\n");
        fgets(input, sizeof(input), stdin);
        printf("He salido de mi sección crítica.\n");
        fgets(input, sizeof(input), stdin);
        *dir_memCompartida_q = 0;
        printf("He accionado el pulsador.\n");
    }


}