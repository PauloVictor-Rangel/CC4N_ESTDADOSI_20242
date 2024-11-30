#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da Árvore AVL
typedef struct No {
    int chave;           // Valor armazenado no nó
    struct No* esquerda; // Ponteiro para o filho esquerdo
    struct No* direita;  // Ponteiro para o filho direito
    int altura;          // Altura do nó
} No;

// Função para obter a altura de um nó
int altura(No* n) {
    if (n == NULL)
        return 0;
    return n->altura;
}

// Função para calcular o maior entre dois valores
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função para criar um novo nó
No* novoNo(int chave) {
    No* no = (No*)malloc(sizeof(No));
    no->chave = chave;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 1; // Nó recém-criado tem altura 1
    return no;
}

// Função para realizar uma rotação à direita
No* rotacaoDireita(No* y) {
    No* x = y->esquerda;
    No* T2 = x->direita;

    // Realiza a rotação
    x->direita = y;
    y->esquerda = T2;

    // Atualiza as alturas
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x; // Novo nó raiz
}

// Função para realizar uma rotação à esquerda
No* rotacaoEsquerda(No* x) {
    No* y = x->direita;
    No* T2 = y->esquerda;

    // Realiza a rotação
    y->esquerda = x;
    x->direita = T2;

    // Atualiza as alturas
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y; // Novo nó raiz
}

// Função para obter o fator de balanceamento de um nó
int obterFatorBalanceamento(No* n) {
    if (n == NULL)
        return 0;
    return altura(n->esquerda) - altura(n->direita);
}

// Função para inserir um nó na Árvore AVL
No* inserir(No* raiz, int chave) {
    if (raiz == NULL)
        return novoNo(chave);

    if (chave < raiz->chave)
        raiz->esquerda = inserir(raiz->esquerda, chave);
    else if (chave > raiz->chave)
        raiz->direita = inserir(raiz->direita, chave);
    else
        return raiz; // Chaves duplicadas não são permitidas

    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));
    int balanceamento = obterFatorBalanceamento(raiz);

    if (balanceamento > 1 && chave < raiz->esquerda->chave)
        return rotacaoDireita(raiz);

    if (balanceamento < -1 && chave > raiz->direita->chave)
        return rotacaoEsquerda(raiz);

    if (balanceamento > 1 && chave > raiz->esquerda->chave) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    if (balanceamento < -1 && chave < raiz->direita->chave) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

// Função para encontrar o menor valor em uma árvore
No* menorValor(No* no) {
    No* atual = no;

    while (atual->esquerda != NULL)
        atual = atual->esquerda;

    return atual;
}

// Função para remover um nó da Árvore AVL
No* remover(No* raiz, int chave) {
    if (raiz == NULL)
        return raiz;

    if (chave < raiz->chave)
        raiz->esquerda = remover(raiz->esquerda, chave);
    else if (chave > raiz->chave)
        raiz->direita = remover(raiz->direita, chave);
    else {
        if ((raiz->esquerda == NULL) || (raiz->direita == NULL)) {
            No* temp = raiz->esquerda ? raiz->esquerda : raiz->direita;

            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else
                *raiz = *temp;

            free(temp);
        } else {
            No* temp = menorValor(raiz->direita);
            raiz->chave = temp->chave;
            raiz->direita = remover(raiz->direita, temp->chave);
        }
    }

    if (raiz == NULL)
        return raiz;

    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));
    int balanceamento = obterFatorBalanceamento(raiz);

    if (balanceamento > 1 && obterFatorBalanceamento(raiz->esquerda) >= 0)
        return rotacaoDireita(raiz);

    if (balanceamento > 1 && obterFatorBalanceamento(raiz->esquerda) < 0) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    if (balanceamento < -1 && obterFatorBalanceamento(raiz->direita) <= 0)
        return rotacaoEsquerda(raiz);

    if (balanceamento < -1 && obterFatorBalanceamento(raiz->direita) > 0) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

// Função para imprimir a Árvore AVL (em ordem)
void imprimirEmOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        imprimirEmOrdem(raiz->direita);
    }
}


// Função principal
int main() {
    No* raiz = NULL;
    int opcao, valor;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir nó\n");
        printf("2. Remover nó\n");
        printf("3. Exibir árvore em ordem\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                break;
            case 3:
                printf("Árvore em ordem: ");
                imprimirEmOrdem(raiz);
                printf("\n");
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}
