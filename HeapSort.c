#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//a função verifica se o elemento na posição 'i' é maior que seus filhos, se não for troca o elemento com o filho que é maior
void heapify(int array[], int n, int i){
  int largest = i; //inicializa maior como raiz
  int left = 2*i + 1; //filho da esquerda
  int right = 2*i + 2; //filho da direita

  if(left < n && array[left] > array[largest]) //se o filho da esquerda for maior que largest
    largest = left;
  
  if(right < n && array[right] > array[largest]) //se o filho da direita for maior que largest
    largest = right; 

  if(largest != i){
    int temp = array[i];
    array[i] = array[largest];
    array[largest] = temp;

    heapify(array, n, largest);
  }
}

void heapsort(int array[], int n){
  
  for(int i = n/2 - 1; i >= 0; i--){ //construir uma heap máxima percorrendo o array de trás para frente (n/2 - 1)
    heapify(array, n, i);
  }
  for(int i = n - 1; i >= 0; i--){ //extrair um por um cada elemento da heap movendo a raiz atual para o final e passando indice '0' como raíz
    int temp = array[0]; 
    array[0] = array[i]; 
    array[i] = temp;

    heapify(array, n, 0);
  }
}

int main(void) {
  int array[] = {1, 5, 9, 8, 22, 12};
  int n = sizeof(array) / sizeof(array[0]);

  int t_values[] = {5000, 10000, 15000, 20000};
  int t_values_tam = sizeof(t_values) / sizeof(t_values[0]);

  heapsort(array, n);

  printf("array ordenado (decrescente): \n");
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
    heapsort(array, t);
    end = clock();

    cpu_time_used = ((double) (end - start) * 1000 / CLOCKS_PER_SEC); 
    printf("\ntempo de execução para n = %d: %f milissegundos", t, cpu_time_used);
  }
  
  return 0;
}