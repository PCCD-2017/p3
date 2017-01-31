/*
 * Ejercicio 2
 */

#include <sys/shm.h>
#include <stdlib.h>
#include <printf.h>

int main(int argc, char* argv[]){
    int shmid;
    key_t key = 88888;
    int* dir_memCompartida;


    if ((shmid = shmget(key, NULL, 0)) == -1) {
        perror("Hubo un error al ejecutar shmget.");
        exit(1);
    } else {
        if ((dir_memCompartida = shmat(shmid, NULL, 0)) == -1) {
            perror("Shmat ha encontrado un error.");
            exit(1);
        } else {
            printf("El valor encontrado en la dirección de memoria es %d \n.", *dir_memCompartida);
        }
    }
    return 0;
}
