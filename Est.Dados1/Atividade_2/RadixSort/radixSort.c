#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50

// Função para obter o dígito em uma determinada posição
int getDigit(int number, int position) {
    return (number / position) % 10;
}

// Função para fazer a contagem dos elementos
void contagemSort(int vet[], int Tam, int position) {
    int saida[TAM]; // Vetor de saída
    int contagem[10] = {0}; // Contador para cada dígito (0-9)

    // Armazenar a contagem de ocorrências de cada dígito
    for (int i = 0; i < Tam; i++) {
        contagem[getDigit(vet[i], position)]++;
    }

    // Alterar contagem[i] para conter a posição real de cada dígito
    for (int i = 1; i < 10; i++) {
        contagem[i] += contagem[i - 1];
    }

    // Construir o vetor de saída
    for (int i = Tam - 1; i >= 0; i--) {
        saida[contagem[getDigit(vet[i], position)] - 1] = vet[i];
        contagem[getDigit(vet[i], position)]--;
    }

    // Copiar o vetor de saída para o vetor original
    for (int i = 0; i < Tam; i++) {
        vet[i] = saida[i];
    }

    // Mostrar o vetor após a contagem
    printf("\nVetor após ordenação na posição %d: \n", position);
    for (int i = 0; i < Tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

// Função principal do Radix Sort
void radixSort(int vet[], int Tam) {
    // Encontrar o maior número para determinar o número de dígitos
    int max = vet[0];
    for (int i = 1; i < Tam; i++) {
        if (vet[i] > max) {
            max = vet[i];
        }
    }

    // Aplicar counting sort para cada dígito
    for (int position = 1; max / position > 0; position *= 10) {
        contagemSort(vet, Tam, position);
    }
}

// Função para embaralhar o vetor
void embaralharVetor(int vet[], int Tam) {
    for (int i = Tam - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Gera um índice aleatório
        // Trocar vet[i] com o elemento em um índice aleatório
        int temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
    }
}

int main() {
    // Inicializar gerador de números aleatórios
    srand(time(NULL));

    // Criar um vetor de 50 elementos únicos de 0 a 49
    int vet[TAM];
    for (int i = 0; i < TAM; i++) {
        vet[i] = i;
    }

    // Embaralhar o vetor
    embaralharVetor(vet, TAM);

    // Exibir o vetor original (desordenado)
    printf("\nVetor original (desordenado): \n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    // Ordenar o vetor usando Radix Sort
    radixSort(vet, TAM);

    // Exibir o vetor ordenado
    printf("\nVetor ordenado: \n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}