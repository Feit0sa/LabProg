/* Escreva um programa em C que gere um vetor com números aleatórios e calcule sua média. Orga-
nize uma Estrutura com as seguintes informações: ponteiro para a matriz, quantidade de elementos
e a média. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct dados {
    int *vetor;
    int qtd;
    float media;
};

int *alocaVetor(struct dados const *);
void geraVetor(struct dados const *, unsigned);
float calculaMedia(struct dados *);
void imprimeVetor(struct dados const *);

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Uso incorreto: %s <quantidadeElementos> <valorMax>\n", *argv);
        exit(1);
    }

    struct dados d1;
    struct dados *pd = &d1;

    pd->qtd = atoi(*(argv+1));
    int max= atoi(*(argv+2));
    pd->vetor = alocaVetor(pd);

    geraVetor(pd, max);
    imprimeVetor(pd);
    printf("A média é %.2f\n", calculaMedia(pd));

    return 0;

}

int *alocaVetor(struct dados const *px) {
    return malloc(px->qtd * sizeof(int));
}

void geraVetor(struct dados const *px, unsigned max) {
    for (int i = 0; i < px->qtd; i++) {
        *(px->vetor+i) = rand() % max;
    }
}

float calculaMedia(struct dados *px) {
    px->media = 0;
    for (int i = 0; i < px->qtd; i++) {
        px->media += *(px->vetor+i);
    }
    return px->media/(float) px->qtd;
}

void imprimeVetor(struct dados const *px) {
    printf("Vetor: [ ");
    for (int i = 0; i < px->qtd; i++) {
        printf("%d ", *(px->vetor+i));
    }
    puts("]");
}