/* Escreva um programa em C que utilize uma Estrutura estoque que contém uma string com o
nomePeca, um número inteiro para identificar o número da peça, o preço em ponto flutuante e um
elemento inteiro para identificar o número do pedido. */

#include <stdio.h>

struct estoque {
    char nomePeca[80];
    int idPeca;
    float preco;
    int idPedido;
};

int main() {
    struct estoque e1;
    struct estoque *pe = &e1;

    puts("Digite o nome da peça requerida:");
    fgets(pe->nomePeca, 80, stdin);
    pe->idPeca = 17;
    pe->preco = 27.99;
    pe->idPedido = 10;

    int pos;
    for (int i = 0; pe->nomePeca[i] != '\n'; i++) {
        pos = i;
    }

    pe->nomePeca[pos+1] = '\0';


    puts("Informações do pedido:");
    printf("Nome da peça: %s\n", pe->nomePeca);
    printf("Id da peça: %d\n", pe->idPeca);
    printf("Preço: %.2f\n", pe->preco);
    printf("Id do pedido: %d\n", pe->idPedido);

    return 0;
}