/* Faça um programa em C que leia duas strings do usuário e informe se elas são iguais. Faça uma
versão com o uso da função strcmp() e outra sem. */

#include <stdio.h>
#include <string.h>

#define TAM 20

int main() {
    
    // Declarações
    char str1[TAM], str2[TAM];
    unsigned i, diferente = 0;

    // Entrada das strings
    puts("Digite a primeira string:");
    fgets(str1, TAM, stdin);
    puts("Digite a segunda string:");
    fgets(str2, TAM, stdin);

    // Conferindo se são iguais com laço de repetição
    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            diferente = 1;
            break;
        }
    }

    // Conferição extra
    if (str1[i] != str2[i]) {
        diferente = 1;
    }

    // if sem strcmp
    if (diferente) {
        puts("As strings são diferentes (sem strcmp).");
    } else {
        puts("As strings são iguais (sem strcmp).");
    }

    // if com strcmp
    if (strcmp(str1, str2)) {
        puts("As strings são diferentes (com strcmp).");
    } else {
        puts("As strings são iguais (com strcmp).");
    }


    /* A ideia era fazer um 'ou' usando o diferente e o strcmp, mas provavelmente você vai querer eles separados */
    return 0;
}