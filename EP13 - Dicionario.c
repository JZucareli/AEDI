#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINHAS 10000
#define MAX_COMPRIMENTO 201
#define MAX_PALAVRAS 5000

int comparar_strings(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
}

int main(void) {
  char input[MAX_LINHAS][MAX_COMPRIMENTO];
  char *palavras[MAX_PALAVRAS];
  int num_palavras = 0;

  // ler linhas de entrada
  int linhas = 0;
  while (fgets(input[linhas], MAX_COMPRIMENTO, stdin) != NULL) {
    linhas++;

    if (linhas == MAX_LINHAS) {
      break;
    }
  }

  // tirar palavras das linhas
  for (int i = 0; i < linhas; i++) {
    char linha[MAX_COMPRIMENTO];
    strcpy(linha, input[i]);

    // substituir caracteres especiais por espaços
    int len = strlen(linha);
    for (int j = 0; j < len; j++) {
      if (!isalpha(linha[j])) {
        linha[j] = ' ';
      }
    }

    char *simbol = strtok(linha, " \t\n");

    while (simbol != NULL) {
      char *palavra = strdup(simbol);

      // remover espaços em branco
      int len = strlen(palavra);
      int index = 0;
      for (int j = 0; j < len; j++) {
        if (palavra[j] != ' ') {
          palavra[index] = palavra[j];
          index++;
        }
      }
      palavra[index] = '\0';

      // mudar para minúsculas
      for (int j = 0; palavra[j]; j++) {
        palavra[j] = tolower(palavra[j]);
      }

      int duplicado = 0;

      for (int j = 0; j < num_palavras; j++) {
        if (strcmp(palavras[j], palavra) == 0) {
          duplicado = 1;
          break;
        }
      }

      if (!duplicado) {
        if (num_palavras == MAX_PALAVRAS) {
          break;
        }
        palavras[num_palavras] = strdup(palavra);
        num_palavras++;
      }
      simbol = strtok(NULL, " \t\n");
    }
    if (num_palavras == MAX_PALAVRAS || linhas == MAX_LINHAS) {
      break;
    }
  }

  // ordenar em ordem alfabética
  qsort(palavras, num_palavras, sizeof(char *), comparar_strings);

  for (int i = 0; i < num_palavras; i++) {
    printf("%s\n", palavras[i]);
    free(palavras[i]);
  }

  return 0;
}