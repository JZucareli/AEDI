#include <stdio.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

int verificar_mapa() {
  int width, height; // largura e altura
  char mapa[MAX_HEIGHT][MAX_WIDTH];

  scanf("%d", &width);
  scanf("%d", &height);
  //getchar(); // Descartar o caractere de nova linha

  // ler o mapa
  for (int i = 0; i < height; i++) {
    fgets(mapa[i], MAX_WIDTH, stdin);
    mapa[i][strcspn(mapa[i], "\n")] = '\0'; // remover o caractere de nova linha
  }

  // verificar se o mapa é válido
  int atual_x = 0;
  int atual_y = 0;
  int anterior_x = -1;
  int anterior_y = -1;

  while (1) {
    if (atual_x < 0 || atual_x >= width || atual_y < 0 || atual_y >= height) { // verificar se a posição atual está fora dos limites do mapa
      return 0; // mapa inválido
    }

    char symbol = mapa[atual_y][atual_x];

    if (symbol == '.') {
      int prox_x = atual_x; // próxima posição x
      int prox_y = atual_y; // próxima posição y

      // Verificar a próxima posição com base na direção
      if (atual_y + 1 < height && mapa[atual_y + 1][atual_x] == '^') {
        prox_y = atual_y + 1;
      } else if (atual_y - 1 >= 0 && mapa[atual_y - 1][atual_x] == 'v') {
        prox_y = atual_y - 1;
      } else if (atual_x + 1 < width && mapa[atual_y][atual_x + 1] == '<') {
        prox_x = atual_x + 1;
      } else if (atual_x - 1 >= 0 && mapa[atual_y][atual_x - 1] == '>') {
        prox_x = atual_x - 1;
      } else {
        return 0; // mapa inválido
      }

      // Verificar se a próxima posição é igual à posição anterior
      if (prox_x == anterior_x && prox_y == anterior_y) {
        return 0; // mapa inválido
      }

      anterior_x = atual_x; // atualizar a posição anterior
      anterior_y = atual_y;

      atual_x = prox_x; // atualizar a posição atual
      atual_y = prox_y;
    } else if (symbol == '*') {
      return 1; // encontrou baú
    } else {
      return 0; // mapa inválido
    }
  }
}

int main(void) {
  int resultado = verificar_mapa();

  if (resultado == 1) {
    printf("*\n");
  } else {
    printf("!\n");
  }

  return 0;
}
