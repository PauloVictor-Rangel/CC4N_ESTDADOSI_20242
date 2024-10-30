#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int v[], int n) {
    // Inicializa a variável de intervalo
    for (int intervalo = n / 2; intervalo > 0; intervalo /= 2) {
        for (int i = intervalo; i < n; i++) {
            // Armazena o valor atual que será inserido
            int valorAtual = v[i];
            int j;

            // Realiza a inserção de forma ordenada
            for (j = i; j >= intervalo && v[j - intervalo] > valorAtual; j -= intervalo) {
                v[j] = v[j - intervalo];
            }
            v[j] = valorAtual;
        }

        // Mostra o vetor após cada intervalo
        printf("\nApós intervalo %d: \n", intervalo);
        for (int k = 0; k < n; k++) {
            printf("%d ", v[k]);
        }
        printf("\n");
    }
}

// Função para embaralhar o vetor
void embaralharVetor(int v[], int n) {
    // Inicializa a semente para o gerador de números aleatórios
    srand(time(NULL));

    for (int i = n - 1; i > 0; i--) {
        // Gera um índice aleatório entre 0 e i
        int j = rand() % (i + 1);
        // Troca v[i] com o elemento em v[j]
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

int main() {
    int vetor[50];

    // Inicializa o vetor com valores de 0 a 49
    for (int i = 0; i < 50; i++) {
        vetor[i] = i;
    }

    // Embaralha o vetor
    embaralharVetor(vetor, 50);

    // Exibe o vetor original (desordenado)
    printf("\nVetor original (desordenado): \n");
    for (int i = 0; i < 50; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Chama a função de ordenação
    shellSort(vetor, 50);

    // Exibe o vetor ordenado
    printf("\nVetor ordenado: \n");
    for (int i = 0; i < 50; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}