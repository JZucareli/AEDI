
#include <stdio.h>
#include <stdlib.h>

typedef struct Alunos{
    char nome[21];
    // int numero;
} Alunos;

void Merge(Alunos *alunos, int inicio, int meio, int fim){
    int i, j, k,l;
    int parteUM = meio - inicio + 1;
    int parteDOIS = fim - meio;

    Alunos *esquerdo, *direito;

    esquerdo = (Alunos*) malloc(parteUM * sizeof(Alunos));
    direito = (Alunos*) malloc(parteDOIS * sizeof(Alunos));

    for(i = 0; i < parteUM; i++){
        esquerdo[i] = alunos[inicio + i];
    }
    for(j = 0; j < parteDOIS; j++){
        direito[j] = alunos[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;
    
    int flag = 0;

    while(i < parteUM && j < parteDOIS){
        if(strcmp(esquerdo[i].nome, direito[j].nome) <= 0){
            alunos[k] = esquerdo[i];
            i++;
        }else{
            alunos[k] = direito[j];
            j++;
        }
        
        k++;
    }

    for(int m = i; m < parteUM; m++){
        alunos[k] = esquerdo[m];
        k++;
    }

    for(int n = j ; n < parteDOIS - 1; n++){
        alunos[k] = direito[n];
        k++;
    }
}

void MergeSortAlunos(Alunos *alunos, int inicio, int fim){
    if(inicio < fim){
        int meio = inicio + (fim - inicio) / 2;

        MergeSortAlunos(alunos, inicio, meio);
        MergeSortAlunos(alunos, meio + 1, fim);

        Merge(alunos, inicio, meio, fim);
    }
}

int main(){
    int n, k;

    Alunos *alunos;
    char lixo[1];
    
    scanf("%d %d", &n, &k);

    alunos = (Alunos*) malloc(n * sizeof(Alunos));
    gets(lixo);

    for(int i = 0; i < n; i++){
        gets(alunos[i].nome);
        // alunos[i].numero = i + 1;
    }

    MergeSortAlunos(alunos, 0, n - 1);
    
    //for(int i = 0; i < n; i++){
    //   printf("%s\n", alunos[i].nome);
    //     // alunos[i].numero = i + 1;
    //}

    printf("%s\n", alunos[k-1].nome);
}
