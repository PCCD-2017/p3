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
    int shmid_p, shmid_q, segmentoq;
    key_t key_p = 88888;
    key_t key_q = 99999;
    int *dir_memCompartida_p;
    int *dir_memCompartida_q;
    char input[32];
    segmentoq = shmget(key_q, NULL, 0);
    shmctl(segmentoq, IPC_RMID, (struct shmid_ds *) NULL);
    shmget(key_q, sizeof(int), IPC_CREAT);
    if ((shmid_q = shmget(key_q, NULL, 0)) == -1) {
        perror("Hubo un error al ejecutar shmget.");
        exit(1);
    }
    if ((dir_memCompartida_q = shmat(shmid_q, NULL, 0)) == -1) {
        perror("Shmat ha encontrado un error.");
        exit(1);
    }
    shmid_p = shmget(key_p, NULL, 0);
    dir_memCompartida_p = shmat(shmid_p, NULL, 0);
    while (1) {
        printf("Caminando por mi habitación.\n");
        fgets(input, sizeof(input), stdin);
        printf("Dentro del pasillo.\n");
        fgets(input, sizeof(input), stdin);
        *dir_memCompartida_q = 1;
        quiere_q = *dir_memCompartida_q;
        printf("He accionado el pulsador.\n");
        fgets(input, sizeof(input), stdin);
        quiere_p = *dir_memCompartida_p;
        printf("Intentando acceder a la sección crítica...\n");
        fgets(input, sizeof(input), stdin);
        if (quiere_p == 0) {
            printf("Dentro de mi sección crítica.\n");
            fgets(input, sizeof(input), stdin);
            printf("He salido de mi sección crítica.\n");
            fgets(input, sizeof(input), stdin);
            quiere_q = 0;
            *dir_memCompartida_q = 0;
            printf("He accionado el pulsador.\n");
        } else {
            printf("Puerta cerrada, saliendo al pasillo.\n");
            fgets(input, sizeof(input), stdin);
            quiere_q = 0;
            *dir_memCompartida_q = 0;
            printf("He accionado el pulsador.\n");
            printf("He salido al pasillo.\n");
        }
    }
}
