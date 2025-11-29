/* Dado dos vetores A e B de dimensão N gerados aleatoriamente, calcule o erro permitindo o uso de diferentes métricas. Para isso, implemente uma função genérica que receba um ponteiro para uma função que calcula o erro. A função de erro pode ser o Erro Médio Quadrático (MSE) ou o Erro Absoluto Médio (MAE), e deve ser passada por referência para a função genérica. Pesquise a equação para calcular o Erro Absoluto Médio (MAE) e implemente ambas as funções de erro para serem utilizadas na função genérica. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double emq(const int [], const int [], const unsigned);
double eam(const int [], const int [], const unsigned);
double calcularErro(const int [], const int [], const unsigned, double (*funcErro)(const int [], const int [], const unsigned));
int *alocaVetor(const unsigned);
void geraVetor(int *, const unsigned, const unsigned);
void imprimeVetor(const int *, const unsigned);

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Uso incorreto: %s <tamanhoVetor> <valorMax>\n", *argv);
    }

    int TAM = atoi(*(argv+1));
    int MAX = atoi(*(argv+2));

    int *A = alocaVetor(TAM);
    int *B = alocaVetor(TAM);

    srand(time(NULL));
    geraVetor(A, TAM, MAX);
    geraVetor(B, TAM, MAX);

    imprimeVetor(A, TAM);
    imprimeVetor(B, TAM);

    printf("\nEMQ: %lf\n", calcularErro(A, B, TAM, emq));
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

int *alocaVetor(const unsigned tamanho) {
    return malloc(tamanho * sizeof(int));
}

void geraVetor(int *v, const unsigned tamanho, const unsigned max) {
    for (int i = 0; i < tamanho; i++) {
        *(v+i) = rand() % max;
    }
}

void imprimeVetor(const int *v, const unsigned tamanho) {
    printf("Vetor: [ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(v + i));
    }
    puts("]");
}