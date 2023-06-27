/*
Selectionsort: algoritmo de ordenação que encontra o menor elemento em uma lista e o troca com um elemento não classificado
Complexidade de tempo: O(n²)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void selectionsort(int array[], int n){
  int i, j, min; 

  //loop para percorrer cada elemento da lista
  for (i = 0; i < n - 1; i++){ //n-1 --> encontrar o menor elemento
    min = i; 
    for (j = i+ 1; j < n; j++){
      if (array[j] < array[min]){ //troca o elemento na posição i com outro elemento na posição min
        min = j; 
      } 
    }
    int temp = array[i]; 
    array[i] = array[min]; //troca menor elemento com o primeiro elemento não classificado
    array[min] = temp;
  }
}

int main(void) {
  int array[] = {5, 54, 10, 87, 4};
  int n = sizeof(array) / sizeof(array[0]); 

  int t_values[] = {5000, 10000, 15000, 20000};
  int t_values_tam = sizeof(t_values) / sizeof(t_values[0]);

  selectionsort(array, n); 

  printf("lista ordenada: \n");
  for (int i = 0; i < n; i++){
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
    selectionsort(array, t);
    end = clock();

    cpu_time_used = ((double) (end - start) * 1000 / CLOCKS_PER_SEC); 
    printf("\ntempo de execução para n = %d: %f milissegundos", t, cpu_time_used);
  }
  return 0;
}