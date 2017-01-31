/*
 * Ejercicio 2
 */

#include <sys/shm.h>
#include <stdlib.h>
#include <printf.h>
#include <errno.h>

int main(int argc, char* argv[]){
    int shmid, err;
    key_t key = 88888;
    int* dir_memCompartida;
    int stop;
    if ((shmid = shmget(key, NULL, 0)) == -1) {
        perror("Hubo un error al ejecutar shmget.");
        exit(1);
    } else {
        if ((dir_memCompartida = shmat(shmid, NULL, 0)) == -1) {
            perror("Shmat ha encontrado un error.");
            exit(1);
        } else {
            do{
                system("clear");
                printf("El dato en memoria compartida es %d \n", *dir_memCompartida);
                printf("Pulse 0 para salir u otro entero para continuar.\n");
                if(shmget(key, NULL, 0) == -1 ) {
                    err = errno;
                    break;
                }
                fscanf(stdin,"%d",&stop);
            }while(stop!=0);
            if(err == ENOENT) printf("No existe un segmento de memoria compartida con la clave dada.\n");
            printf("Saliendo.\n");
            shmdt((char *)dir_memCompartida);
        }
    }
    return 0;
}
