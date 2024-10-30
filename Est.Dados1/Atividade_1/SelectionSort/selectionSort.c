#include <stdio.h>
#define n 50

void imprimir(int *v){
  printf("\n-------------   Vetor   --------------\n");
  for(int i = 0; i < n; i++){
    printf("%d |", v[i]);
  }
}

int selectionSort(int *v){
  int menor, troca;
for(int i = 0; i < n - 1; i++){
  menor = i;
  for(int k = i + 1; k < n; k++){
    if(v[k] < v[menor]){
      menor = k;
    }
  }
  imprimir(v);
  if(i != menor){
    troca = v[i];
    v[i] = v[menor];
    v[menor] = troca;
   }
 }  
}

int main(void) {
 int vetor[n] = {23, 1, 47, 5, 30, 8, 14, 26, 3, 43, 21, 9, 36, 12, 7, 18, 25, 39, 4, 11, 41, 35, 6, 13, 48, 29, 24, 10, 0, 19, 45, 37, 2, 32, 16, 22, 27, 38, 28, 42, 20, 34, 46, 15, 31, 17, 33, 44, 49, 40};

imprimir(vetor);
selectionSort(vetor);
  imprimir(vetor);
  
  return 0;
}