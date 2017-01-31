/*
 * Ejercicio 1
 *
 * Breve apunte: Ejecutar con privilegios de superusuario.
 */

#include <sys/shm.h>
#include <stdlib.h>
#include <printf.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int shmid, err;
    key_t key = 88888;
    int *dir_memCompartida;
    int stop;
    if ((shmid = shmget(key, sizeof(int), IPC_CREAT)) == -1) {
        perror("Hubo un error al ejecutar shmget.");
        exit(1);
    } else {
        printf("Shmget devolvió %d .\n", shmid);
        if ((dir_memCompartida = shmat(shmid, NULL, 0)) == -1) {
            perror("Hubo un error al ejecutar shmat.");
            exit(1);
        } else {
            do {
                system("clear");
                printf("Se ha escrito en memoria compartida el valor %d .\n", *dir_memCompartida);
                printf("Pulse 0 para salir u otro entero para continuar.\n");
                fscanf(stdin, "%d", &stop);
                if(shmget(key, NULL, 0) == -1 ) {
                    err = errno;
                    break;
                }
                if (stop != 0) {
                    *dir_memCompartida = stop;
                }
            } while (stop != 0);
            printf("Deteniendo escritura.\n");
            if(err == ENOENT) printf("No existe un segmento de memoria compartida con la clave dada.\n");
            shmdt((char *) dir_memCompartida);
        }
        exit(0);
    }
    return 0;
}
