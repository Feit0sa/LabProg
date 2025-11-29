/* Escreva um programa que some todos os elementos de um vetor de float alocado dinamicamente. A quantidade de elementos devem ser fornecidas por linha de comando. Utilize a função rand() para alimentar o vetor com valores pseudo-aleatórios. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso incorreto: %s <tamanhoDoVetor>\n", *argv);
        exit(1);
    }

    float *p = (float *) malloc(atoi(argv[1]) * sizeof(float));

    srand(time(NULL));
    for (int i = 0; i < atoi(argv[1]); i++) {
        *(p+i) = (float) rand() / RAND_MAX;
    }

    float soma = 0;
    puts("Vetor:");
    for (int i = 0; i < atoi(argv[1]); i++) {
        printf("[%p] %f\n", p+i, *(p+i));
        soma += *(p+i);
    }
    printf("Soma de todos os valores: %f\n", soma);

    free(p);

    return 0;
}