#include "global.h"

// Função para listar produtos
void listProduct (int *currentIndex, productStruct *productsArray) {

    // Impressão dos produtos utilizando um loop for onde será impresso até o índice corrente
    printf("%-10s%-30s%-10s%-20s%-10s\n", "Código:", "Nome do Produto:", "Preço:", "Quantidade:", "Total:");
    for (int i = 0; i < *currentIndex; i++) {
        float total = productsArray[i].price * productsArray[i].amount;
        printf("%-10d%-30s%-10.2f%-20d%-10.2f\n",
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