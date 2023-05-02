#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//função para mesclar os vetores ordenados
void mesclar(int array[], int left[], int tam_left, int right[], int tam_right){
  int i = 0, j = 0, k = 0; 

  //percorre os dois vetores os comparando e inserindo o menor elemento em um novo vetor
  while(i < tam_left && j < tam_right){
    if(left[i] <= right[j]){
      array[k] = left[i]; 
      i++;
    } else {
      array[k] = right[j];
      j++;
    }
    k++; //manter o indice da posição atual
  }
  while(i < tam_left){ //percorre os elementos restantes do vetor esquerdo
    array[k] = left[i];
    i++;
    k++;
  }
  while(j < tam_right){ //percorre os elementos restantes do vetor direito
    array[k] = right[j];
    j++;
    k++;
  }
}

//função para dividir o vetor em partes menores
void divide(int array[], int n){
  if(n < 2){
    return; 
  }
  int meio = n/2; 
  int left[meio]; 
  int right[n - meio]; 

  for(int i = 0; i < meio; i++){
    left[i] = array[i];
  }
  for(int i = meio; i < n; i++){
    right[i - meio] = array[i];
  }
  divide(left, meio); 
  divide(right, n-meio); 
  mesclar(array, left, meio, right, n-meio);
}


int main(void) {
  int array[] = {2, 66, 98, 4, 6, 9, 10}; 
  int n = sizeof(array) / sizeof(array[0]);
  
  int t_values[] = {5000, 10000, 15000, 20000};
  int t_values_tam = sizeof(t_values) / sizeof(t_values[0]);

  printf("antes da ordenação: \n");
  for (int i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n\n"); 
  divide(array, n); 
  
  printf("depois da ordenação: \n");
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
    divide(array, t);
    end = clock();

    cpu_time_used = ((double) (end - start) * 1000 / CLOCKS_PER_SEC); 
    printf("\ntempo de execução para n = %d: %f milissegundos", t, cpu_time_used);
  }
    return 0;
}