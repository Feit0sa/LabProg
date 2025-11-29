/* Escreva um programa em C que apresente a média, a mediana e a moda de um vetor de inteiros gerados aleatoriamente em tempo de execução. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float media(const int *, const unsigned);
float mediana(const int *, const unsigned);
int moda(const int *, const unsigned, const unsigned);
int maximo(const int *, const unsigned);

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Uso incorreto: %s <tamanhoDoVetor> <valorMáximo>\n", *argv);
    }

    int *p = (int *) malloc(atoi(argv[1]) * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < atoi(argv[1]); i++) {
        *(p+i) = rand() % atoi(argv[2]);
    }

    for (int i = 0; i < atoi(argv[1]); i++) {
        printf("[%p] %d\n", p+i, *(p+i));
    }
    printf("Média: %.2f\n", media(p, atoi(argv[1])));
    printf("Mediana: %.2f\n", mediana(p, atoi(argv[1])));
    printf("Moda: %d\n", moda(p, atoi(argv[1]), atoi(argv[2])));

    free(p);

    return 0;
}

float media(const int *p, const unsigned tam) {
    float soma = 0;
    for (int i = 0; i < tam; i++) {
        soma += *(p+i);
    }
    return (float) soma/tam;
}

float mediana(const int *p, const unsigned tam) {
    float mediana;
    if (tam % 2 == 0) {
        mediana = (float) (*(p+(tam/2))+*(p+(tam/2)+1))/2;
        return mediana;
    } else {
        mediana = *(p+(tam/2));
        return (int) mediana;
    }
}

int moda(const int *p, const unsigned tam, const unsigned max) {
    int *q = (int *) calloc(max, sizeof(int));
    for (int i = 0; i < tam; i++) {
        (*(q+*(p+i)))++;
    }
    
    for (int i = 0; i < max; i++) {
        if (*(q+i) == maximo(q, max)) {
            return i;
        }
    }

}

int maximo(const int *pv, const unsigned tam) {
    int maior, menor;
    maior = *pv;
    menor = *pv;

    for (int i = 0; i < tam; i++) {
        if (*(pv+i) > maior) {
            maior = *(pv+i);
        }
        else if (*(pv+i) < menor) {
            menor = *(pv+i);
        }
    }

    return maior;
}