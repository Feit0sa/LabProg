#include <stdio.h>

int main() {

    int R = 0, Q, n;

    puts("Digite o número de processos:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Digite o número máximo de recursos que o processo %d pode solicitar:\n", i+1);
        scanf("%d", &Q);
        R += Q-1;
    }
    
    R++;

    printf("A quantidade de recursos mínima de recursos necessários para evitar deadlock é %d\n", R);
    
    return 0;
}