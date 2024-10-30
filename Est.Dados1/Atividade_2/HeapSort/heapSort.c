#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 50

// Função para trocar dois elementos
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para construir o heap
void heapify(int v[], int n, int i) {
    int maior = i; // Inicializa o maior como raiz
    int esquerda = 2 * i + 1; // filho à esquerda
    int direita = 2 * i + 2; // filho à direita

    // Se o filho da esquerda for maior que a raiz
    if (esquerda < n && v[esquerda] > v[maior])
        maior = esquerda;

    // Se o filho da direita for maior que o maior até agora
    if (direita < n && v[direita] > v[maior])
        maior = direita;

    // Se o maior não for a raiz
    if (maior != i) {
        trocar(&v[i], &v[maior]); // Troca

        // Recursivamente heapify a subárvore afetada
        heapify(v, n, maior);
    }
}

// Função principal para implementar o HeapSort
void heapSort(int v[]) {
    // Constrói o heap (reorganiza o vetor)
    for (int i = TAMANHO / 2 - 1; i >= 0; i--)
        heapify(v, TAMANHO, i);

    // Um a um extrai os elementos do heap
    for (int i = TAMANHO - 1; i >= 0; i--) {
        // Move a raiz atual para o final
        trocar(&v[0], &v[i]);

        // Chama heapify na árvore reduzida
        heapify(v, i, 0);

        // Exibe o estado atual do vetor
        printf("\nEstado atual do vetor: \n");
        for (int j = 0; j < TAMANHO; j++)
            printf("%d ", v[j]);
        printf("\n");
    }
}

// Função para preencher o vetor com números únicos
void preencherNumerosUnicos(int v[], int tamanho) {
    int usados[tamanho];
    for (int i = 0; i < tamanho; i++) {
        usados[i] = 0; // Marca todos os números como não usados
    }

    for (int i = 0; i < tamanho; i++) {
        int num;
        do {
            num = rand() % tamanho; // Gera um número aleatório de 0 a 49
        } while (usados[num]); // Continua até encontrar um número não usado
        v[i] = num; // Atribui o número ao vetor
        usados[num] = 1; // Marca o número como usado
    }
}

// Função para imprimir o vetor
void imprimirVetor(int v[]) {
    for (int i = 0; i < TAMANHO; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main() {
    int v[TAMANHO];

    // Preencher o vetor com números únicos
    preencherNumerosUnicos(v, TAMANHO);

    printf("\nVetor original: \n");
    imprimirVetor(v);

    // Ordenar o vetor
    heapSort(v);

    printf("\nVetor ordenado: \n");
    imprimirVetor(v);

    return 0;
}