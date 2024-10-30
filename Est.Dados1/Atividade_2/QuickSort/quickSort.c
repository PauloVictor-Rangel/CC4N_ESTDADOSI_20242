#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 50

// Função para trocar dois elementos no vetor
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição do QuickSort
int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[fim]);
    return i + 1;
}

// Função principal do QuickSort
void quicksort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = particionar(vetor, inicio, fim);

        // Imprime o vetor após cada chamada de partição
        printf("\nVetor após partição (pivô: %d): \n", vetor[indicePivo]);
        for (int k = 0; k < TAMANHO_VETOR; k++) {
            printf("%d ", vetor[k]);
        }
        printf("\n");

        quicksort(vetor, inicio, indicePivo - 1);
        quicksort(vetor, indicePivo + 1, fim);
    }
}

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função para verificar se um número já está no vetor
int existe(int vetor[], int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == numero) {
            return 1; // O número já existe
        }
    }
    return 0; // O número não existe
}

int main() {
    int vetor[TAMANHO_VETOR];
    srand(time(NULL));

    // Preenche o vetor com números aleatórios não repetidos
    for (int i = 0; i < TAMANHO_VETOR;) {
        int num = rand() % 100; // Números de 0 a 99
        if (!existe(vetor, i, num)) {
            vetor[i] = num;
            i++;
        }
    }

    printf("\nVetor original:\n");
    imprimirVetor(vetor, TAMANHO_VETOR);

    quicksort(vetor, 0, TAMANHO_VETOR - 1);

    printf("\nVetor ordenado:\n");
    imprimirVetor(vetor, TAMANHO_VETOR);

    return 0;
}