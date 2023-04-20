#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct amigo {
  char nome[50]; 
  struct amigo* prox;
} Amigo; 

//função criar novo amigo
Amigo* criar(char* nome, int tamanho) {
  Amigo* novo = (Amigo*) malloc(sizeof(Amigo)); //alocar dinamicamente
  for (int i = 0; i < tamanho; i++){
    novo -> nome[i] = nome[i]; //copia nome do amigo para novo amigo
  }
  novo -> nome[tamanho] = '\0';
  novo -> prox = NULL; //ultimo nome da lista
  return novo; 
}

//função imprimir
void imprimir(Amigo* inicio) {
  Amigo* atual = inicio; //ponteiro auxiliar
  
  while (atual != NULL){ //inicio ter algum elemento, ou seja, não for vazio
    printf("%s ", atual -> nome); //imprime cada elemento
    atual = atual -> prox;
  }
  printf("\n");
}

//função inserir inicio
void inserir_inicio(Amigo** inicio, char* nome, int tamanho) {
  Amigo* novo = criar(nome, tamanho); 
  novo -> prox = *inicio; 
  *inicio = novo;
}

//função oinserir fim
void inserir_fim(Amigo** inicio, char* nome, int tamanho) {
  Amigo* novo = criar(nome, tamanho); 

  if (*inicio == NULL) { //lista não estiver vazia
    *inicio = novo; //vai para inicio
  } else {
    Amigo* atual = *inicio; //ponteiro auxiliar
    while (atual -> prox != NULL){ //qualquer posição 
      atual = atual -> prox; //recebe novo nome da proxima posição
    }
    atual -> prox = novo;
  }
}

//função inserir no meio
void inserir_meio(Amigo** inicio, Amigo* novo, char* nome_indicado, int tamanho_indicado) {
  if (strcmp((*inicio) -> nome, nome_indicado) == 0){
    novo -> prox = *inicio; 
    *inicio = novo;
  } else {
    Amigo* atual = *inicio;
    while (atual -> prox != NULL && strcmp(atual -> prox -> nome, nome_indicado) != 0){
      atual = atual -> prox; 
    }
    if (atual -> prox != NULL){
      novo -> prox = atual -> prox; 
      atual -> prox = novo; 
    } else {
      atual -> prox = novo;
    }
  }
}

int main(){

Amigo* amigos_luiggy = NULL;
char nome[50];
int tamanho;

//ler lista atual de amigos
while (scanf ("%s", nome) != EOF){
  tamanho = strlen(nome);
  inserir_fim(&amigos_luiggy, nome, tamanho);
}

//ler amigo indicado para nova lista
char nome_indicado[50];
scanf("%s", nome_indicado);
int tamanho_indicado = strlen(nome_indicado);

//verificar se houve indicação de amigo na nova lista
if(strcmp(nome_indicado, "não") != 0){
  Amigo* novo_amigo = criar(nome_indicado, tamanho_indicado);
  inserir_meio(&amigos_luiggy, novo_amigo, nome_indicado, tamanho_indicado);
}

//ler lista nova de amigos
Amigo* novos_amigos = NULL;
while (scanf("%s", nome) != EOF){
  tamanho = strlen(nome);
  inserir_fim(&novos_amigos, nome, tamanho);
}

//atualizar lista de amigos com novos amigos
if (amigos_luiggy == NULL){ //caso a lista atual esteja vazia, recebe a lista de novos amigos
  amigos_luiggy = novos_amigos;  
} else {
Amigo* atual = amigos_luiggy; //ponteiro auxiliar para percorrer a lista atual de amigos
while (atual -> prox != NULL){ //encontra o último amigo da lista atual de amigos
  atual = atual -> prox;
}
atual -> prox = novos_amigos; //último amigo aponta para o início da lista de novos amigos
}

//imprimir lista atualizada
imprimir(amigos_luiggy);

return 0;
}