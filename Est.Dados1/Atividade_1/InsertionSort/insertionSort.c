#include <stdio.h>
#include <math.h>

void insertionSort(int v[], int n){
int i, key, j;
  for(i = 1; i < n; i++){
    key = v[i];
    j = i - 1;

    while(j >= 0 && v[j] > key){
      v[j + 1] = v[j];
      j = j - 1;
    }
    v[j + 1] = key;
  }
}
void mostraVetor(int v[], int n){
  int i;
  for(i = 0; i < n; i++)
     printf("%d |", v[i]);
     printf("\n");
  
}

int main(void){
 int v[] = {23, 1, 47, 5, 30, 8, 14, 26, 3, 43, 21, 9, 36, 12, 7, 18, 25, 39, 4, 11, 41, 35, 6, 13, 48, 29, 24, 10, 0, 19, 45, 37, 2, 32, 16, 22, 27, 38, 28, 42, 20, 34, 46, 15, 31, 17, 33, 44, 49, 40};
 int n = sizeof(v) / sizeof(v[0]);

    printf("\nBefore sorting vetor elements are - \n");
  
  mostraVetor(v, n);
  insertionSort(v, n);
  
  printf("\nAfter sorting vetor elements are - \n");
  
  mostraVetor(v, n);
  
  return 0;
}