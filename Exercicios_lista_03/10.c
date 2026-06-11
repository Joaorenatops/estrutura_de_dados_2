//Etapa 1 — Cada nó da árvore precisa armazenar:
//um valor;
//ponteiro para filho da esquerda; 
//ponteiro para filho da direita.

//Em linguagem C:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

//Etapa 2 — Criando um novo nó
//Agora criamos uma função para alocar memória para um nó.
No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

//Etapa 3 — Inserção na ABB
//A inserção é o coração da árvore.
//Regras:
//se o valor for menor → vai para esquerda;
//se o valor for maior → vai para direita.
//Implementação
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

No* buscar(No *raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }
    if (valor < raiz->valor) {
        return buscar(raiz->esq, valor);
    }
    return buscar(raiz->dir, valor);
}

//Remoção
//Remoção
No* remover(No *raiz, int valor) {
    No *temp = NULL;
    // árvore vazia
    if (raiz == NULL) {
        return NULL;
    }

    // busca do nó
    if (valor < raiz->valor) {
        raiz->esq = remover(raiz->esq, valor);
    }

    else if (valor > raiz->valor) {
        raiz->dir = remover(raiz->dir, valor);
    }

    // encontrou o nó
    else {
        
        // CASO 1 - sem filhos
        if (raiz->esq == NULL && raiz->dir == NULL) {

            free(raiz);

            return NULL;
        }

        // CASO 2 - um filho à direita
        else if (raiz->esq == NULL) {

            temp = raiz->dir;

            free(raiz);

            return temp;
        }

        // CASO 2 - um filho à esquerda
        else if (raiz->dir == NULL) {

            temp = raiz->esq;

            free(raiz);

            return temp;
        }
    raiz->dir = temp;
    //raiz->valor = temp->valor;
    return raiz;
}
}

// 41. Contar o número de nós
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


int main() {

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

    printf("\n\nInformacoes da Arvore:\n");
    printf("Quantidade de nos: %d\n", contarNos(raiz));
    printf("Altura da arvore: %d\n", calcularAltura(raiz));
    printf("Quantidade de folhas: %d\n", contarFolhas(raiz));

    raiz = remover(raiz, 80);

    printf("\nDepois de remover o elemento 80:\n");
    emOrdem(raiz);

    printf("\n\nEspelhando a arvore (Exibindo Em-Ordem):\n");
    espelhar(raiz);
    emOrdem(raiz);
    printf("\n");

    return 0;
}