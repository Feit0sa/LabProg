/* Escreva um programa em C que utilize uma Estrutura aluno para conter duas notas, lidas do usuário, e sua média. */

#include <stdio.h>
#include <stdlib.h>

struct aluno {
    float *pNotas;
    float media;
};

void calculaMedia(struct aluno *const);
float *alocarMemoria(unsigned);

int main(int argc, char **argv) {

    struct aluno a1;
    struct aluno *pa = &a1;

    if (argc != 3) {
        printf("Uso incorreto: %s <nota1> <nota2>\n", *argv);
        exit(1);
    }

    if (!(a1.pNotas = alocarMemoria(2))) {
        puts("Memória indisponível!");
        exit(2);
    }

    pa->pNotas = alocarMemoria(2);

    for (int i = 0; i < argc-1; i++) {
        *(pa->pNotas+i) = atoi(*(argv+i+1));
    }

    calculaMedia(pa);
    printf("Média do aluno: %.2f\n", pa->media);

    return 0;
}

void calculaMedia(struct aluno *const px) {
    px->media = ((2 * *(px->pNotas))+(3 * *(px->pNotas+1)))/5.0;
}

float *alocarMemoria(unsigned tam) {
    return malloc(2 * sizeof(int));
}