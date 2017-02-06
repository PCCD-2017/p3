/*
 * Ejercicio 4
 */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    char input[32];
    while(1){
        printf("Caminando por mi habitación.\n");
        fgets(input, sizeof(input), stdin);
        printf("Intentando entrar en mi sección crítica.\n");
        printf("Dentro de mi sección crítica.\n");
        fgets(input, sizeof(input), stdin);
        printf("He salido de mi sección crítica.\n");
    }

    return 0;
}