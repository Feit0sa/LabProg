/* Reescreva a questão anterior para que o erro seja calculado de forma genérica, permitindo o uso de diferentes métricas de erro. Para isso, implemente uma função genérica que receba um ponteiro para uma função que calcula o erro. A função de erro pode ser o Erro Médio Quadrático (MSE) ou o Erro Absoluto Médio (MAE), e deve ser passada por referência para a função genérica. Pesquise a equação para calcular o Erro Absoluto Médio (MAE) e implemente ambas as funções de erro para serem utilizadas na função genérica. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM 10
#define MAX 5

double emq(const int [], const int [], const unsigned);
double eam(const int [], const int [], const unsigned);
double calcularErro(const int [], const int [], const unsigned, double (*funcErro)(const int [], const int [], const unsigned));

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

    printf("EMQ: %lf\n", calcularErro(A, B, TAM, emq));
    printf("EAM: %lf\n", calcularErro(A, B, TAM, eam));

    return 0;

}

double emq(const int A[], const int B[], const unsigned tamanho) {
    double diferenca;
    double soma = 0;
    for (int i = 0; i < tamanho; i++) {
        diferenca = A[i]-B[i];
        soma += diferenca * diferenca;
    }
    return soma/tamanho;
}

double eam(const int A[], const int B[], const unsigned tamanho) {
    double soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += fabs(A[i]-B[i]);
    }
    return (double) soma/tamanho;
}

double calcularErro(const int A[], const int B[], const unsigned tamanho, double (*funcErro)(const int [], const int [], const unsigned)) {
    return funcErro(A, B, tamanho);
}