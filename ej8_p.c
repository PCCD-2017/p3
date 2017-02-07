/*
 * Ejercicio 8
 */

#include <stdio.h>
#include <sys/shm.h>
#include <stdlib.h>

int turno = 0;
int quiere_p = 0;
int quiere_q = 0;

int main(int argc, char *argv[]) {
    int shmid_p, shmid_q, segmentop;
    key_t key_p = 88888;
    key_t key_q = 99999;
    int *dir_memCompartida_p;
    int *dir_memCompartida_q;
    char input[32];
    segmentop = shmget(key_p, NULL, 0);
    shmctl(segmentop, IPC_RMID, (struct shmid_ds *) NULL);
    shmget(key_p, sizeof(int), IPC_CREAT);
    if ((shmid_p = shmget(key_p, NULL, 0)) == -1) {
        perror("Hubo un error al ejecutar shmget.");
        exit(1);
    }
    if ((dir_memCompartida_p = shmat(shmid_p, NULL, 0)) == -1) {
        perror("Shmat ha encontrado un error.");
        exit(1);
    }
    shmid_q = shmget(key_q, NULL, 0);
    dir_memCompartida_q = shmat(shmid_q, NULL, 0);
    while (1) {
        printf("Caminando por mi habitación.\n");
        fgets(input, sizeof(input), stdin);
        printf("Dentro del pasillo.\n");
        fgets(input, sizeof(input), stdin);
        *dir_memCompartida_p = 1;
        quiere_p = *dir_memCompartida_p;
        printf("He accionado el pulsador.\n");
        fgets(input, sizeof(input), stdin);
        quiere_q = *dir_memCompartida_q;
        printf("Intentando acceder a la sección crítica...\n");
        fgets(input, sizeof(input), stdin);
        if (quiere_q == 0) {
            printf("Dentro de mi sección crítica.\n");
            fgets(input, sizeof(input), stdin);
            printf("He salido de mi sección crítica.\n");
            fgets(input, sizeof(input), stdin);
            quiere_p = 0;
            *dir_memCompartida_p = 0;
            printf("He accionado el pulsador.");
        } else {
            printf("Puerta cerrada, saliendo al pasillo.\n");
            fgets(input, sizeof(input), stdin);
            quiere_p = 0;
            *dir_memCompartida_p = 0;
            printf("He accionado el pulsador.\n");
            printf("He salido al pasillo.\n");
        }
    }
}
