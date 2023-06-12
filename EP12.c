/*
Ler cada caso de teste, calculando o hash para cada linha e acumular a soma total dos hashes
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calcular_valor_caractere(char caractere, int pos_elemento, int pos_caractere){
  int valor_abc = caractere - 'A';
  return valor_abc + pos_elemento + pos_caractere;
}

int calcular_hash(char** linhas, int qntd_linhas){
  int hash = 0; 

  for (int i = 0; i < qntd_linhas; i++){
    char* linha = linhas[i];
    int tam_linha = strlen(linha);

    for (int j = 0; j < tam_linha; j++){
      hash += calcular_valor_caractere(linha[j], i, j);
    }
  }
  return hash;
}

int main(void) {
  int num_testes; 
  scanf("%d", &num_testes);

  for (int t = 0; t < num_testes; t++){
    int qntd_linhas; 
    scanf("%d", &qntd_linhas);

    char** linhas = (char**) malloc(qntd_linhas * sizeof(char*));

    for (int i = 0; i < qntd_linhas; i++){
      linhas[i] = (char*) malloc(51 * sizeof(char));
      scanf("%s", linhas[i]);
    }

    int hash = calcular_hash(linhas, qntd_linhas);
    printf("%d\n", hash);

    for (int i = 0; i < qntd_linhas; i++){
      free(linhas[i]);
    }
    free(linhas);
  }
  return 0;
}
