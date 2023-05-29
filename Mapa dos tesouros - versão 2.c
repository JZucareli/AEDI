#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Grafo {
	int width; //largura l
	int height;	//altura h
	char **adj; //matriz adjacente
}Grafo;

//inicializar
Grafo* init(int largura, int altura) {  

	Grafo *G ;
	G = (Grafo*) malloc(sizeof(Grafo));
  
	G -> width = largura;
	G -> height = altura;
	
	G->adj = (char**) malloc(sizeof(char*) * altura); s
  
	for (int i = 0; i < altura; i++) {
		G->adj[i] = (char *) malloc(sizeof(char) * (largura + 1));
	}
	
	return G;
}

void liberar_grafo(Grafo *G) {
	
	Grafo *aux = G;
	
	if (G == NULL)
		return;
	
	for (int i = 0; i < aux->height; i++) {
		free(aux -> adj[i]);
	}
	free(aux -> adj);
	free(aux);
}


int main () {
  
	Grafo *G;
	int x, y;            // x = largura, y = altura 
  //int i, j;
	int a = 0, b = 0;           // a = largura, b = altura
	int pos[MAX][MAX];
	char aux;
	
	scanf("%d", &x);
	scanf("%d", &y);
		
	G = init(x, y);
	
	for (int i = 0; i < y; i++) {
		scanf("%s", G -> adj[i]);
	}
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++)
			pos[i][j] = 0;
	}
	
	while (1) {
		
		if (pos[b][a]) 
			break;
		
		if (a >= x || b >= y || a < 0 || b < 0) 
			break;
	
		pos[b][a] = 1; 
		aux = G -> adj[b][a]; 

		if (aux == '>') {
			a++;
		}
		else if (aux == '<') {
			a--;
		}
		else if (aux == 'v') {
			b++;
		}
		else if (aux == '^') {
			b--;
		}
		else if (aux == '*') {
			printf("*\n");
			return 0;
		}
		else if (aux == '.') {
			if (a < G -> width - 1) {
				a++;
			}
			else if (b < G-> height - 1) {
				a = 0;
				b++;
			}
		}	
	}
	printf("!\n");
	liberar_grafo(G);
	
	return 0;
}
