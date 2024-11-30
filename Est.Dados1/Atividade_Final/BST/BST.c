#include <stdio.h>
#include <stdlib.h>

// Definição do nó da árvore
typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

// Função para criar um novo nó
No* criarNo(int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->esquerdo = NULL;
    novoNo->direito = NULL;
    return novoNo;
}

// Função para inserir um valor na Árvore Binária de Busca
No* inserir(No* raiz, int dado) {
    if (raiz == NULL) {
        return criarNo(dado); // Se a raiz for nula, cria um novo nó
    }
    if (dado < raiz->dado) {
        raiz->esquerdo = inserir(raiz->esquerdo, dado); // Insere na subárvore esquerda
    } else if (dado > raiz->dado) {
        raiz->direito = inserir(raiz->direito, dado); // Insere na subárvore direita
    }
    return raiz;
}

// Função para buscar um valor na Árvore Binária de Busca
No* buscar(No* raiz, int dado) {
    if (raiz == NULL || raiz->dado == dado) {
        return raiz; // Retorna o nó encontrado ou NULL se não encontrado
    }
    if (dado < raiz->dado) {
        return buscar(raiz->esquerdo, dado); // Busca na subárvore esquerda
    }
    return buscar(raiz->direito, dado); // Busca na subárvore direita
}

// Função para exibir os valores da árvore em ordem crescente (In-Ordem)
void percursoEmOrdem(No* raiz) {
    if (raiz != NULL) {
        percursoEmOrdem(raiz->esquerdo); // Percorre a subárvore esquerda
        printf("%d ", raiz->dado); // Exibe o dado do nó atual
        percursoEmOrdem(raiz->direito); // Percorre a subárvore direita
    }
}

// Função para exibir os valores da árvore em Pré-Ordem
void percursoPreOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado); // Exibe o dado do nó atual
        percursoPreOrdem(raiz->esquerdo); // Percorre a subárvore esquerda
        percursoPreOrdem(raiz->direito); // Percorre a subárvore direita
    }
}

// Função para exibir os valores da árvore em Pós-Ordem
void percursoPosOrdem(No* raiz) {
    if (raiz != NULL) {
        percursoPosOrdem(raiz->esquerdo); // Percorre a subárvore esquerda
        percursoPosOrdem(raiz->direito); // Percorre a subárvore direita
        printf("%d ", raiz->dado); // Exibe o dado do nó atual
    }
}

// Função principal
int main() {
    No* raiz = NULL; // Inicializa a árvore vazia
    int opcao, valor;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir\n");
        printf("2. Buscar\n");
        printf("3. Exibir Pré-Ordem\n");
        printf("4. Exibir Em Ordem\n");
        printf("5. Exibir Pós-Ordem\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Digite o valor para inserir: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            break;

        case 2:
            printf("Digite o valor para buscar: ");
            scanf("%d", &valor);
            if (buscar(raiz, valor)) {
                printf("Valor %d encontrado na árvore.\n", valor);
            } else {
                printf("Valor %d não encontrado na árvore.\n", valor);
            }
            break;

        case 3:
            printf("Árvore em Pré-Ordem: ");
            percursoPreOrdem(raiz);
            printf("\n");
            break;

        case 4:
            printf("Árvore em ordem crescente (Em Ordem): ");
            percursoEmOrdem(raiz);
            printf("\n");
            break;

        case 5:
            printf("Árvore em Pós-Ordem: ");
            percursoPosOrdem(raiz);
            printf("\n");
            break;

        case 6:
            printf("Encerrando o programa.\n");
            exit(0);

        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
