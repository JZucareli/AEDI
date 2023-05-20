#include <stdio.h>
#include <string.h>
#include <ctype.h>

int boyer_moore(char* haystack, char* needle){ //haystack (palheiro): string onde será realizada a busca; needle (agulha): padrão a ser procurado
  int n = strlen(haystack); //recebe o tamanho da string haystack
  int m = strlen(needle); //recebe o tamanho da string needle

  //CONSTRUIR TABELA DE SALTOS
  int table[256];
  
  for (int i = 0; i < 256; i++){ //inicialização 
    table[i] = m;
  }
  for (int i = 0; i < m-1; i++){ //percorre 'needle' até penúltimo caractere
    table[(unsigned char) needle[i]] = m-1-i; //armazena/preenche a tabela com a distância entre a posição atual e a última na tabela
  }

  //REALIZAR BUSCAS
  int i = m-1; //m-1 --> posição inicial da última letra no haystack

  while (i < n){
    int j = m-1; 
    while (j >= 0 && haystack[i] == needle[j]){ //compara caracteres de needle e haystack de trás para frente (continua enquanto houver caracteres ou enquanto os caracteres forem iguais)
      i--;
      j--;
    }
    if (j < 0){ //se todos os caracteres foram verificados
      return i+1; //volta ao inicio
    }
    i += table[(unsigned char) haystack[i]]; //se não encontrar nenhuma correspondência, utiliza 'i' para avançar retornando a quantidade de posições que 'i' deve avançar
  }
  return -1;
  
}


int main(void) {
  char S[105]; 
  
  fgets(S, sizeof(S), stdin);

  if (S[strlen(S) - 1] == '\n'){
     S[strlen(S) - 1 ] = '\0';
  }

  for (int i = 0; i < strlen(S); i++){
    S[i] = tolower(S[i]);
  }

  if (boyer_moore(S, "zelda") != -1){
    printf("Link Bolado\n");
  } else {
    printf("Link Tranquilo\n");
  }
  return 0;
}