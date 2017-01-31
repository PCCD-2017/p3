/*
 * Ejercicio 3
 */

#include <sys/shm.h>
#include <stdlib.h>
#include <printf.h>

int main(int argc, char* argv[]){
    //TODO escribir proceso que libere zona de memoria compartida
    key_t key = 88888;
    int segmento;
    system("clear");
    if((segmento=shmget(key, NULL, 0))==-1){
        perror("Ha habido un error con shmget.");
        exit(1);
    }else{
        printf("Liberando zona de memoria compartida.\n");
        shmctl(segmento,IPC_RMID,(struct shmid_ds *)NULL);
        /*
         * From https://linux.die.net/man/2/shmctl :
         * IPC_RMID :
         * Mark the segment to be destroyed. The segment will only actually be destroyed after
         * the last process detaches it (i.e., when the shm_nattch member of the associated structure
         * shmid_ds is zero). The caller must be the owner or creator, or be privileged. If a segment
         * has been marked for destruction, then the (nonstandard) SHM_DEST flag of the shm_perm.mode
         * field in the associated data structure retrieved by IPC_STAT will be set.
         */
    }

    return 0;
}