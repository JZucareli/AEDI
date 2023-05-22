#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
  int info; 
  struct NO* left;
  struct NO* right;
} NO; 

//arvore* raiz;

//CRIAR NOVO NÓ
NO* criar_no(int info){
  NO* newnode = (NO*) malloc(sizeof(NO));

  newnode -> info = info; 
  newnode -> left = NULL;
  newnode -> right = NULL;

  return newnode;
}

//INSERIR
NO* inserir(NO* raiz, char info){
  if (raiz == NULL){
    return criar_no(info);
  } else if (info < raiz -> info){
    raiz -> left = inserir(raiz -> left, info);
  } else if (info > raiz -> info){
    raiz -> right = inserir(raiz -> right, info);
  }
  return raiz; 
}

//PRÉ ORDEM: raiz, esquerda e direita
void pre_ordem(NO* raiz){
  if (raiz != NULL){
    printf ("%d ", raiz -> info);
    pre_ordem(raiz -> left);
    pre_ordem(raiz -> right);
  }
}

//ORDEM: esquerda, raiz, direita
void ordem(NO* raiz){
  if (raiz != NULL){
    ordem(raiz -> left);
    printf ("%d ",  raiz -> info);
    ordem(raiz -> right);
  }
}

//POS ORDEM: esquerda, direita, raiz
void pos_ordem(NO* raiz){
  if (raiz != NULL){
    pos_ordem(raiz -> left);
    pos_ordem(raiz -> right);
    printf ("%d ", raiz -> info);
  }
}

//BUSCA
int buscar(NO* raiz, char info){
  if (raiz == NULL){
    return 0;
  } else if (raiz -> info == info){
    return 1;
  } else if (info < raiz -> info){
    return buscar(raiz -> left, info);
  } else {
    return buscar(raiz -> right, info);
  }
}


int main(void) {
  NO* raiz = NULL;
  char comando; 
  int info; 

  scanf("%c %d", &comando, &info);
  raiz = inserir(raiz, info);

  while (scanf(" %c ", &comando) != EOF){
    if (comando == 'I'){
    //inserir novo elemento
      scanf("%d ", &info);
      raiz = inserir(raiz, info);
    } else if (comando == 'P'){
    //pesquisar elemento
      scanf("%d ", &info); 
      if (buscar(raiz, info)){
        printf("%d existe\n", info);
      } else {
        printf("%d nao existe\n", info);
      }
    } else if (comando == 'P'){
      //pesquisar elemento
      scanf ("%d ", &info);
      if (buscar(raiz, info)){
        printf("%d existe\n", info);
      } else {
        printf("%d nao existe\n", info);
      }
    } else if (comando == 'P'){
      //pesquisar elemento
      scanf("%d ", &info);
      if (buscar(raiz, info)){
        printf("%d existe\n", info);
      } else {
        printf("%d não existe\n", info);
      }
    } 
  }
  free(raiz);
  return 0;
}