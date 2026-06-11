//Implemente a estrutura de um nó de árvore binária em C.
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// 17. Função que inicializa uma árvore vazia
No* inicializarArvore() {
    return NULL;
}

// 18. Inserir filho usando esq (filho) e dir (irmão)
void inserirFilho(No *pai, int valor) {
    if (pai == NULL) return;
    
    No *novo = criarNo(valor);
    
    // Se não tem nenhum filho, vira o filho da esquerda (esq)
    if (pai->esq == NULL) {
        pai->esq = novo;
    } else {
        // Se já tem filhos, navega pelos irmãos da direita (dir) até o último
        No *atual = pai->esq;
        while (atual->dir != NULL) {
            atual = atual->dir;
        }
        atual->dir = novo; // Encaixa o novo irmão na direita
    }
}

// 19. Contar quantos nós existem
int contarNos(No *raiz) {
    if (raiz == NULL) return 0;
    // Conta ele mesmo (1) + filhos (esq) + irmãos (dir)
    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}

// 20. Calcular a altura da árvore
int calcularAltura(No *raiz) {
    if (raiz == NULL) return -1;
    
    int altMaxima = -1;
    No *atual = raiz->esq; // Vai para o primeiro filho
    
    // Passa por todos os filhos (que estão encadeados por 'dir')
    while (atual != NULL) {
        int altFilho = calcularAltura(atual);
        if (altFilho > altMaxima) {
            altMaxima = altFilho;
        }
        atual = atual->dir; // Avança para o próximo irmão/filho
    }
    return altMaxima + 1;
}

// 21. Contar quantas folhas existem
int contarFolhas(No *raiz) {
    if (raiz == NULL) return 0;
    
    // Se não tem filhos (esq == NULL), ele é uma folha!
    // Mas precisamos continuar contando as folhas dos irmãos (dir)
    if (raiz->esq == NULL) {
        return 1 + contarFolhas(raiz->dir);
    }
    
    // Se tem filhos, procura folhas nos filhos e nos irmãos
    return contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
}

// 22. Verificar se um valor existe na árvore
int buscarValor(No *raiz, int x) {
    if (raiz == NULL) return 0;
    if (raiz->valor == x) return 1; // Achou!
    
    // Procura nos filhos (esq) ou nos irmãos (dir)
    return buscarValor(raiz->esq, x) || buscarValor(raiz->dir, x);
}

int main(){
//inicializando a variável raiz
   No *raiz = inicializarArvore();
    raiz = criarNo(10); 

    // 18. Insere filhos no 10
    inserirFilho(raiz, 20);
    inserirFilho(raiz, 30);
    inserirFilho(raiz, 40);

    // Insere filhos no 20 (filho da esquerda do 10)
    inserirFilho(raiz->esq, 50);
    inserirFilho(raiz->esq, 60);

    // 19. Quantidade de nós
    printf("Total de nos: %d\n", contarNos(raiz));

    // 20. Altura
    printf("Altura: %d\n", calcularAltura(raiz));

    // 21. Folhas
    printf("Folhas: %d\n", contarFolhas(raiz));

    // 22. Busca
    printf("O valor 30 existe? %s\n\n", buscarValor(raiz, 30) ? "Sim" : "Nao");
};