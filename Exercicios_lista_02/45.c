//Implemente a estrutura de um nó de árvore binária em C.
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    
    int valor;
    struct No *esq;
    struct No *dir;

} No;

// Função auxiliar para criar o nó
No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No *raiz, int valor) {
    // árvore vazia
    if (raiz == NULL) {
        return criarNo(valor);
    }
    // inserção à esquerda
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    }
    // inserção à direita
    else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void emOrdem(No *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void posOrdem(No *raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}


int contarNos(No *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}

// 42. Calcular a altura da árvore binária
int calcularAltura(No *raiz) {
    if (raiz == NULL) {
        return -1;
    }
    int e = calcularAltura(raiz->esq);
    int d = calcularAltura(raiz->dir);
    if (e > d) {
        return e + 1;
    } else {
        return d + 1;
    }
}

// 43. Contar quantos nós folhas existem
int contarFolhas(No *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->esq == NULL && raiz->dir == NULL) {
        return 1;
    }
    return contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
}

// 44. Espelhar uma árvore binária
void espelhar(No *raiz) {
    if (raiz == NULL) {
        return;
    }
    No *temp = raiz->esq;
    raiz->esq = raiz->dir;
    raiz->dir = temp;
    espelhar(raiz->esq);
    espelhar(raiz->dir);
}

// 45. Verificar se duas árvores binárias são iguais
int saoIguais(No *a, No *b) {
    if (a == NULL && b == NULL) {
        return 1;
    }
    if (a == NULL || b == NULL) {
        return 0;
    }
    if (a->valor == b->valor && saoIguais(a->esq, b->esq) && saoIguais(a->dir, b->dir)) {
        return 1;
    }
    return 0;
}

int main(){
    No *raiz = NULL;

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);
    raiz = inserir(raiz, 90);
    raiz = inserir(raiz, 35);
    raiz = inserir(raiz, 25);

    printf("Antes de remover elementos (Em-Ordem):\n");
    emOrdem(raiz);

    printf("\n\nPercurso em Pre-Ordem:\n");
    preOrdem(raiz);

    printf("\n\nPercurso em Pos-Ordem:\n");
    posOrdem(raiz);

    printf("Quantidade de nos: %d\n", contarNos(raiz));

    printf("Altura da arvore: %d\n", calcularAltura(raiz));

    printf("Quantidade de folhas: %d\n", contarFolhas(raiz));

    printf("\n\nEspelhando a arvore (Exibindo Em-Ordem):\n");
    espelhar(raiz);
    emOrdem(raiz);
    printf("\n");
    
    printf("\n\nVerificando igualdade de arvores:\n");
    
    // Criando uma segunda árvore (árvore B) rápida para comparar
    No *raiz2 = NULL;
    raiz2 = inserir(raiz2, 50);
    raiz2 = inserir(raiz2, 30);
    raiz2 = inserir(raiz2, 70);

    if (saoIguais(raiz, raiz2)) {
        printf("As arvores sao IGUAIS!\n");
    } else {
        printf("As arvores sao DIFERENTES!\n");
    }

    printf("\n");
    return 0;
}
