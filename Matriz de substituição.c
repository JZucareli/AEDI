#include <stdio.h>

int main(void) {
  int X[10] = {48, -5, -63, 23, -10, -3, -8, 4, 4564, -10}; 
  int i; 
  
  for (i = 0; i < 10; i++){
    if (X[i] <= 0){
      X[i] = 1; 
    }
  }
  
  for (i = 0; i < 10; i++){
    printf("X[%d] = %d\n",i, X[i]);
  }
  
  return 0;
}