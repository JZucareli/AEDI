/*
ESQUERDA = chaves menores que a chave nó
DIREITA = chaves maiores que a chave nó
ENTRADA = 8 3 10 14 6 4 13 7 1

PRÉ ORDEM: esquerda, raíz, direita
EM ORDEM: raiz, esquerda, direita
PÓS ORDEM: direita, esquerda, raiz
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int info; 
  struct Node* left; 
  struct Node* right; 
}; 

int tam; 


//BUSCAR NA ÁRVORE
struct Node* search (struct Node* root, int k){	
    if(root == NULL)
        return NULL;
    else 
        if(k <= root -> info){
            if (root -> left == NULL);
            return root;
    else
       return search(root -> left, k);
    else
        if(root -> right == NULL){
            return root;
    else
        return search(root -> right, k);
    }
}

//IMPRIMIR ÁRVORE
int imprimir(struct Node* root){
	if(root != NULL){
		if(tipo == 1){ 
			printf(" %d", root -> info);
			imprimir(root -> left);
			imprimir(root -> right);
		}
		if(tipo == 2){
			imprimir(root -> left);
			printf(" %d", root -> info);
			imprimir(root -> right);
		}
		if(tipo == 3){
			imprimir(root -> left);
			ImprimeArvore(root -> right);
			printf(" %d", root -> info);
		}
	}

	return 0;
}

/*
//PÓS ORDEM: raiz, esquerda, direita
void pre_order(struct Node* root){
  if (root != NULL){
    printf("%d ", root -> info);
    order(root -> left);
    order(root -> right);
  }
}

//ORDEM: esquerda, raiz, direita
void order(struct Node* root){
  if (root != NULL){
    order(root -> left);
    printf("%d ", root -> info);
    order(root -> right);
  }
}

//PÓS ORDEM: direita, esquerda, raiz
void pos_order(struct Node* root){
  if (root != NULL){
    ordem(root -> right);
    ordem(root -> left); 
    printf("%d ", root -> info);
}
*/

int main() {
    Node *raiz, *aux, *pai;
	int tam, cases, node;
	

	root = NULL;
	scanf("%d", &cases);

	for(int c = 1; c <= cases; c++){
		root = NULL;

		scanf("%d", &tam);
		for(int d = 0; d < tam; d++){
			scanf("%d", &node);

			aux = (Node *) malloc(sizeof(Node));
			aux -> info = node;
			aux -> left = NULL;
			aux -> right = NULL;

			pai = search(root, node);
			if(pai == NULL)
				root = aux;
			else
				if(node <= pai -> info)
					pai -> left = aux;
				else
					pai -> right = aux;
		}

		printf("Case %d:", c);

		printf("\nPre.:");
		tipo = 1;
		imprimir(root);

		printf("\nIn..:");
		tipo = 2;
		imprimir(root);

		printf("\nPost:");
		tipo = 3;
		imprimir(root);

		printf("\n\n");

	}

	return 0;
}
