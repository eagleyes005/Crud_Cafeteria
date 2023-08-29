#include "global.h"

// Função para listar produtos
void listProduct (int *currentIndex, productStruct *productsArray) {

    // Impressão dos produtos utilizando um loop for onde será impresso até o índice corrente
    printf("Código:\t\tNome do Produto:\tPreço:\t\tQuantidade:\t\tTotal:\n");
    for (int i = 0; i < *currentIndex; i++) {
        float total = productsArray[i].price * productsArray[i].amount;
        printf("%d\t\t"
               "%s\t\t"
               "R$ %.2f\t\t"
               "%d\t\t"
               "R$ %.2f\t\t\n",
               productsArray[i].cod,
               productsArray[i].name,
               productsArray[i].price,
               productsArray[i].amount,
               total);
    }
}
// Função para retornar após consulta
void returnOption () {
    int returnTrigger;

    printf("Insira algo para voltar\n");
    scanf("%d", &returnTrigger);

    if (returnTrigger) {
        printf("Voltando...\n");
        sleep(2);
        return;
    }
}