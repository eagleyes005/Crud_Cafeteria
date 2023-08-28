#include "global.h"

//Função para listar produtos
void listProduct (const int *productsQty, productStruct *productsArray) {

    system("cls"); //Limpeza do terminal

    //Impressão dos produtos

    printf("Código:\t\tNome do Produto:\tPreço:\t\tQuantidade:\n");
    for (int i = 0; i < *productsQty; i++) {
        printf("%d\t\t"
               "%s\t\t"
               "R$ %.2f\t\t"
               "%d\t\t\n",
               productsArray[i].cod,
               productsArray[i].name,
               productsArray[i].price,
               productsArray[i].amount);
    }


    //TODO abstrair para função genérica
    int subSelector;

    printf("0 - Voltar\n\n");
    scanf("%d", &subSelector); //NOLINT(cert-err34-c)

    if (subSelector == 0) {
        printf("Voltando...\n");
        sleep(2);
        return;
    } else {
        printf("Opção inválida!");
        sleep(2);
        return;
    }
}