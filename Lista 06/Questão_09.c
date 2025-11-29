/* Escreva um programa em C que binarize os elementos da matriz M gerada aleatoriamente e com dimensões obtidas em tempo de execução. A partir de um limiar t dado, crie a matriz S da seguinte forma: 
                        Sij = | 1 se Mij > t
                              | 0 caso contrário
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void binarizarMatriz(int **, const unsigned, const unsigned, const unsigned);

int main(int argc, char *argv[]) {

      if (argc != 5) {
            printf("Uso incorreto: %s <linhas> <colunas> <valorMAX> <limiar t>\n", *argv);
            exit(1);
      }

      int **matriz;
      int linhas = atoi(argv[1]);
      int colunas = atoi(argv[2]);
      int max = atoi(argv[3]);
      int t = atoi(argv[4]);
      
      matriz = (int **) malloc(linhas * sizeof(int *));
      if (matriz ==  NULL) {
            puts("Erro de memória!");
            exit(2);
      }


      for (int i = 0; i < linhas; i++) {
            matriz[i] = (int *) malloc(colunas * sizeof(int));
            if (matriz[i] == NULL) {
                  puts("Erro de memória!");
                  exit(3);
            }
      }

      srand(time(NULL));
      for (int i = 0; i < linhas; i++) {
            for (int j = 0; j< colunas; j++) {
                  *(*(matriz+i)+j) = rand() % max;
            }
      }

      puts("Matriz antes da binarização:");
      for (int i = 0; i < linhas; i++) {
            printf("[ ");
            for (int j = 0; j < colunas; j++) {
                  printf("%d ", *(*(matriz+i)+j));
            }
            puts("]");
      }

      puts("");
      puts("Matriz depois da binarização");
      binarizarMatriz(matriz, linhas, colunas, t);
      for (int i = 0; i < linhas; i++) {
            printf("[ ");
            for (int j = 0; j < colunas; j++) {
                  printf("%d ", *(*(matriz+i)+j));
            }
            puts("]");
      }

      for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
      }
      free(matriz);

      return 0;
}

void binarizarMatriz(int **matriz, const unsigned linhas, const unsigned colunas, const unsigned t) {
      for (int i = 0; i < linhas; i++) {
            for (int j = 0; j< colunas; j++) {
                  if (*(*(matriz+i)+j) > t) {
                        *(*(matriz+i)+j) = 1;
                  } else{
                        *(*(matriz+i)+j) = 0;
                  }
            }
      }
}