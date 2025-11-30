/* Crie uma Estrutura disciplina em que um dos campos corresponde também a uma estrutura professor. */

#include <stdio.h>

struct professor {
    char nome[30];
    int idade;
};

struct disciplina {
    char nome[30];
    int qtdAlunos;
    struct professor prof;
};

int main() {

    struct disciplina d1;
    struct disciplina *pd = &d1;
    struct professor prof1;
    pd->prof = prof1;

    puts("Digite o nome da disciplina:");
    fgets(pd->nome, 30, stdin);
    puts("Digite o nome do professor:");
    fgets(pd->prof.nome, 30, stdin);
    pd->prof.idade = 40;
    pd->qtdAlunos = 45;

    int posD;
    for (int i = 0; pd->nome[i] != '\n'; i++) {
        posD = i;
    }
    pd->nome[posD+1] = '\0';

    int posP;
    for (int i = 0; pd->prof.nome[i] != '\n'; i++) {
        posP = i;
    }
    pd->prof.nome[posP+1] = '\0';

    printf("\nInformações da disciplina:\n");
    printf("Nome da disciplina: %s\n", pd->nome);
    printf("Quantidade de alunos: %d\n", pd->qtdAlunos);
    printf("Professor responsável: %s\n", pd->prof.nome);
    printf("Idade do professor: %d\n", pd->prof.idade);

    return 0;
}