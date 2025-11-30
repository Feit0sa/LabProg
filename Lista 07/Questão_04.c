/* Escreva um programa em C que modifique a Questão 1 para conter um array com 3 alunos. Escreva
uma função para calcular a média dos alunos. */

#include <stdio.h>
#include <stdlib.h>

struct aluno {
    float *pNotas;
    float media;
};

void calculaMedias(struct aluno *const);
float *alocarMemoria(unsigned);

int main() {
    
    struct aluno alunos[3];
    struct aluno *pa = alunos;
    
    for (int i = 0; i < 3; i++) {
        if (!((pa+i)->pNotas = alocarMemoria(2))) {
        puts("Memória indisponível!");
        exit(1);
    }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Digite a %d° nota do %d° aluno: ", j+1, i+1);
            scanf("%f", (pa+i)->pNotas+j);
        }
    }

    calculaMedias(pa);

    for (int i = 0; i < 3; i++) {
        printf("Média do %d° aluno: %.2f\n", i, (pa+i)->media);
    }

    return 0;
}

void calculaMedias(struct aluno *const px) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            (px+i)->media = ((2 * *((px+i)->pNotas))+(3 * *((px+i)->pNotas+1)))/5.0;        
        }
    }
}

float *alocarMemoria(unsigned tam) {
    return malloc(2 * sizeof(int));
}