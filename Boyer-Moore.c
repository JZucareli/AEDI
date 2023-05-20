#include <stdio.h>
#include <string.h>
#include <ctype.h>

int boyer_moore(char* haystack, char* needle){ //haystack (palheiro): string onde será realizada a busca; needle (agulha): padrão a ser procurado
  int m = strlen(haystack); //recebe o tamanho da string haystack
  int n = strlen(needle); //recebe o tamanho da string needle

  //CONSTRUIR TABELA DE SALTOS
  int table[256];
  
  for (int i = 0; i < 256; i++){ //inicialização com tamanho da string 'haystack'
    table[i] = m;
  }
  
  //REALIZAR BUSCAS
  int i = m-1; //m-1 --> posição inicial da última letra no haystack
  int ocorrs = 0; 

  while (i <= n){
    int j = 0; 
    while (m - j >= 1 && haystack[m - 1] == needle[j]){ //compara caracteres de needle e haystack de trás para frente (continua enquanto houver caracteres ou enquanto os caracteres forem iguais)
      j += 1;
    }
    if (m - j < 1){ //se todos os caracteres foram verificados
      ocorrs += 1; //incrementado sempre que encontra um ocorrencia padrão
      break;
    }
    if (j == n)
      j += 1;
    else j += table[needle[j + 1]] + 1;
  }
  return ocorrs;
}


int main(void) {
  char S[100005]; 
  
  fgets(S, sizeof(S), stdin);

  if (S[strlen(S) - 1] == '\n'){
     S[strlen(S) - 1 ] = '\0';
  }

  for (int i = 0; i < strlen(S); i++){
    S[i] = tolower(S[i]);
  }

  int m = strlen(S); 
  char needle[] = "needle";
  int n = strlen(needle);

  if (strstr(S, "zelda") != NULL){
    printf ("Link Bolado\n");
  } else {
    printf ("Link Tranquilo\n");
  }

  return 0;
}