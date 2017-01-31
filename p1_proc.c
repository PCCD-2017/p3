/*
 * Ejercicio 1
 *
 * Breve apunte: Ejecutar con privilegios de superusuario.
 */

#include <sys/shm.h>
#include <stdlib.h>
#include <printf.h>

int main(int argc, char *argv[]) {
    int param = atoi(argv[1]);
    int shmid;
    key_t key = 88888;
    int* dir_memCompartida;
    int size = sizeof(param);

    /*
     * shmget recibe tres parámetros:
     * -key (key_t) : clave identificativa para el segmento de memoria
     * -size (size_t) : tamaño de la zona de memoria a crear
     * -shmflg (int) : valor que indica la acción a utilizar, en este caso crear.
     *
     * devuelve un entero, que es el identificador de la zona de memoria asociada con la clave key_t
     */

    if ((shmid = shmget(key, size, IPC_CREAT)) == -1) {
        perror("Hubo un error al ejecutar shmget.");
        exit(1);
    } else {
        printf("Shmget devolvió %d .\n", shmid);

        /*
         * shmat recibe tres parámetros:
         * -shmid (int) : identificador de la zona de memoria a apuntar
         * -shmaddr (const void *) : dirección, si se conoce
         * -shmflg (int) : como en shmget, en este caso no es especifica nada
         *
         * devuelve un entero, que es un puntero a la zona de memoria en cuestión.
         */
        if((dir_memCompartida = shmat(shmid, NULL, 0)) == -1){
            perror("Hubo un error al ejecutar shmat.");
            exit(1);
        }else{
            //TODO añadir bucle que persista escribiendo mientras no se pulse una tecla
            *dir_memCompartida = param;
            printf("Se ha escrito en memoria compartida el valor %d .\n", *dir_memCompartida);
        }
        exit(0);
    }
    return 0;
}
