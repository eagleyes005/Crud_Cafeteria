#include "global.h"

// Função para listar produtos
void listProduct (int *currentIndex, productStruct *productsArray) {

    // Impressão dos produtos utilizando um loop for onde será impresso até o índice corrente
    printf("--------------------------------- ESTOQUE DE PRODUTOS ---------------------------------\n");
    printf("%-10s%-30s%-14s%-20s%-20s\n", "Código:", "Nome do Produto:", "Preço:", "Quantidade:", "Total:");
    for (int i = 0; i < *currentIndex; i++) {
        float total = productsArray[i].price * productsArray[i].amount;
        printf("%-10d%-30sR$ %-11.2f%-20dR$ %-17.2f\n",
               productsArray[i].cod,
               productsArray[i].name,
               productsArray[i].price,
               productsArray[i].amount,
               total);
    }
    printf("---------------------------------------------------------------------------------------\n");
}
// Função para retornar após consulta
void returnOption () {
    char returnTrigger[10];
    printf("\n");
    printf("Insira algo para voltar\n");
    scanf("%s", returnTrigger);
    getchar(); // Consumir o caractere de nova linha restante no buffer de entrada

    system("cls");
    printf("Voltando...\n");
    sleep(2);
    return;
}