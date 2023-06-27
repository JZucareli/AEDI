/*
Selectionsort: algoritmo de ordenação que divide repetidamente uma lista em duas partes menores com base em um pivo escolhido e, então, ordena as partes menores recursivamente 
Complexidade de tempo: O(n log n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int array[], int left, int right){
  int i = left; 
  int j = right; 
  int temp;
  int pivo = array[(left + right) / 2]; //escolha do pivô central (metade)

  while(i <= j){
    while(array[i] < pivo)
      i++;
    while(array[j] > pivo)
      j--;

    if(i <= j){
      temp = array[i];
      array[i] = array[j];
      array[j] = temp; 
      i++;
      j--;
    }
  }
  if(left < j)
    quicksort(array, left, j);
  if(i < right)
    quicksort(array, i, right);
}

int main(void) {
  int array[] = {1, 9, 5, 2, 8, 7, 10, 4, 3, 6};
  int n = sizeof(array) / sizeof(array[0]);

  int t_values[] = {5000, 10000, 15000, 20000,}; 
  int t_values_tam = sizeof(t_values) / sizeof(t_values[0]);
  
  quicksort(array, 0, n-1);

  printf("array: \n");
  for(int i = 0; i < n; i++)
    printf("%d ", array[i]);

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
    quicksort(array, 0, t - 1);
    end = clock();

    cpu_time_used = ((double) (end - start) * 1000 / CLOCKS_PER_SEC); 
    printf("\ntempo de execução para n = %d: %f milissegundos", t, cpu_time_used);
  }
  

    
  
  return 0;
}