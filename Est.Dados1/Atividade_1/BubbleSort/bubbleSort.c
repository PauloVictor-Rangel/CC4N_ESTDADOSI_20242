#include <stdio.h>
#define n 50
void imprimir(int *vetor){
  printf("\n-------------VETOR--------------\n");
  for(int i = 0; i < n; i++){
    printf("%d |", vetor[i]);
  }
}

int bubbleSort(int *vetor){
  int continua, troca;

  do{
    continua = 0;
for(int i = 0; i < n - 1; i++){
  if(vetor[i] > vetor[i + 1]){
        troca = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = troca;
        continua = 1;
      }
    }
    imprimir(vetor);
    
  }while(continua);
}

int main(void) {

  int vet[n] = {23, 1, 47, 5, 30, 8, 14, 26, 3, 43, 21, 9, 36, 12, 7, 18, 25, 39, 4, 11, 41, 35, 6, 13, 48, 29, 24, 10, 0, 19, 45, 37, 2, 32, 16, 22, 27, 38, 28, 42, 20, 34, 46, 15, 31, 17, 33, 44, 49, 40};


imprimir(vet);
bubbleSort(vet); imprimir(vet);
  return 0;
}