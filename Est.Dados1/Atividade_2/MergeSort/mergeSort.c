#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 50

// Função para imprimir o vetor em um intervalo específico
void imprimirVetorParcial(int vetor[], int inicio, int fim) {
    for (int i = inicio; i <= fim; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função para mesclar dois subarrays e mostrar o processo
void merge(int vetor[], int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Vetores temporários
    int esquerda[n1], direita[n2];

    // Copiando dados para os vetores temporários
    for (i = 0; i < n1; i++)
        esquerda[i] = vetor[inicio + i];
    for (j = 0; j < n2; j++)
        direita[j] = vetor[meio + 1 + j];

    // Mesclando os vetores temporários de volta no vetor principal
    i = 0; j = 0; k = inicio;
    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    // Copiando os elementos restantes de esquerda, se houver
    while (i < n1) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    // Copiando os elementos restantes de direita, se houver
    while (j < n2) {
        vetor[k] = direita[j];
        j++;
        k++;
    }

    // Mostrar o estado do vetor após cada mesclagem
    printf("\nApós mesclar de %d a %d: \n", inicio, fim);
    imprimirVetorParcial(vetor, inicio, fim);
}

// Função recursiva do MergeSort com exibição do processo
void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Dividir e ordenar a primeira metade
        mergeSort(vetor, inicio, meio);

        // Dividir e ordenar a segunda metade
        mergeSort(vetor, meio + 1, fim);

        // Mesclar as duas metades ordenadas e mostrar o passo
        merge(vetor, inicio, meio, fim);
    }
}

// Função para imprimir o vetor completo
void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[TAMANHO_VETOR];
    srand(time(NULL));

    // Preenchendo o vetor com valores aleatórios
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        vetor[i] = rand() % 100; // Valores de 0 a 99
    }

    printf("\nVetor original:\n");
    imprimirVetor(vetor, TAMANHO_VETOR);

    // Ordenando o vetor com MergeSort e mostrando o passo a passo
    printf("\nPasso a passo do MergeSort:\n");
    mergeSort(vetor, 0, TAMANHO_VETOR - 1);

    printf("\nVetor ordenado:\n");
    imprimirVetor(vetor, TAMANHO_VETOR);

    return 0;
}