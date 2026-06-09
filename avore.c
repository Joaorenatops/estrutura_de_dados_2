void menuInsercao() {
    int op;
    do {
        
        printf("\n--- Metodo de Insercao ---\n");
        printf("1. Inserir no Inicio\n");
        printf("2. Inserir no Fim\n");
        printf("3. Inserir no Meio\n");
        printf("4. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);

        

    } while (op != 4);
}
int main(){

    printf("Menu da aplicação Árvore");
    menuInsercao();


    return 0;
}