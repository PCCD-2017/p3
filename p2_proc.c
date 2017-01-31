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
    int stop;
    if ((shmid = shmget(key, NULL, 0)) == -1) {
        perror("Hubo un error al ejecutar shmget.");
        exit(1);
    } else {
        if ((dir_memCompartida = shmat(shmid, NULL, 0)) == -1) {
            perror("Shmat ha encontrado un error.");
            exit(1);
        } else {
            //TODO añadir bucle que persista leyendo mientras no se pulse una tecla.
            do{
                system("clear");
                printf("El dato en memoria compartida es %d \n", *dir_memCompartida);
                printf("Pulse 0 para salir u otro entero para continuar.\n");
                fscanf(stdin,"%d",&stop);
            }while(stop!=0);
            printf("Saliendo.\n");
            shmdt((char *)dir_memCompartida);
        }
    }
    return 0;
}
