/* Calcule o erro médio quadrático entre dois vetores A e B de dimensão N gerados aleatoriamente. Pesquise a equação. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define MAX 5

double emq(const int [], const int [], const unsigned);

int main() {
    int A[TAM], B[TAM];
    int *pa = A, *pb = B;

    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        A[i] = rand() % MAX;
        B[i] = rand() % MAX;
    }

    puts("Vetor A:");
    for (int i = 0; i < TAM; i++) {
        printf("[%p] %d\n", pa+i, *(pa+i));
    }

    puts("Vetor B:");
    for (int i = 0; i < TAM; i++) {
        printf("[%p] %d\n", pb+i, *(pb+i));
    }

    printf("EMQ: %lf\n", emq(pa, pb, TAM));

    return 0;

}

double emq(const int A[], const int B[], const unsigned tamanho) {
    int diferenca;
    double soma = 0;
    for (int i = 0; i < tamanho; i++) {
        diferenca = A[i]-B[i];
        soma += diferenca * diferenca;
    }

    return (double) soma/tamanho;
}