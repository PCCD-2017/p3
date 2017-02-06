/*
 * Ejercicio 5
 */

#include <stdio.h>
#include <sys/shm.h>
#include <stdlib.h>

int turno = 0;

int main(int argc, char *argv[]) {
    int shmid;
    key_t key = 88888;
    int *dir_memCompartida;
    char input[32];

    shmget(key, sizeof(int), IPC_CREAT);

    if ((shmid = shmget(key, NULL, 0)) == -1) {
        perror("Hubo un error al ejecutar shmget.");
        exit(1);
    } else {
        if ((dir_memCompartida = shmat(shmid, NULL, 0)) == -1) {
            perror("Shmat ha encontrado un error.");
            exit(1);
        } else {
            while (1) {
                turno = *dir_memCompartida;
                printf("Caminando por mi habitación.\n");
                fgets(input, sizeof(input), stdin);
                printf("Intentando entrar en mi sección crítica.\n");
                while (turno == 1) {
                    printf("La puerta está cerrada.\n");
                    turno = *dir_memCompartida;
                    fgets(input, sizeof(input), stdin);
                }
                printf("Dentro de mi sección crítica.\n");
                fgets(input, sizeof(input), stdin);
                printf("Saliendo de mi sección crítica.\n");
                fgets(input, sizeof(input), stdin);
                printf("He accionado mi pulsador.\n");
                *dir_memCompartida = 1;
            }
        }
    }
}