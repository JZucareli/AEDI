#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort(int array[], int n){
  int i, j, key; 

  //loop externo: esquerda para direitra
  for (i = 1; i < n; i++){ //começa a percorrer a partir do segundo elemento
    key = array[i]; //para cada interação, o elemento atual armazena a variável key
    j = i - 1; //desloca para esquerda;

    //loop interno: direita para esquerda
    while (j >= 0 && array[j] > key){
      array[j+1] = array[j]; // compara cada elemento o valor da variável key
      j = j - 1; // se for menor que key, o elemento desloca para direita para abrir espaço para inserção de key
    } 
    array[j+1] = key; 
  }
}

int main(void) {
  int array[] = {6, 8, 9, 5, 1, 3}; 
  int n = sizeof(array) / sizeof(array[0]); 
  int i; 

  int t_values[] = {5000, 10000, 15000, 20000};
  int t_values_tam = sizeof(t_values) / sizeof(t_values[0]);

  printf("antes da ordenação: \n");
  for (i = 0; i < n; i++){ //percorre de 0 até n-1
    printf("%d ", array[i]); 
  }
  
  printf("\n\n");
  insertionsort(array, n); //ordena sem retornar valor

  printf("\n\ndepois da ordenação: \n"); 
  for(i = 0; i < n; i++){  //percorre de 0 até n-1
    printf("%d ", array[i]);
  }
  printf("\n\n");

  srand(time(NULL)); 
  
  for (int i = 0; i < t_values_tam; i++){
    int t = t_values[i]; 
    int array[t]; 
    
    for(int j = 0; j < t; j++){
      array[j] = rand() % 1000 + 1; 
    }
    
    clock_t start, end;  
    double cpu_time_used;

    start = clock(); 
    insertionsort(array, t);
    end = clock(); 
    cpu_time_used = ((double) (end - start) * 1000 / CLOCKS_PER_SEC); 
    printf("\ntempo de execução para n = %d: %f milissegundos", t, cpu_time_used);
  }
  
  return 0;
}