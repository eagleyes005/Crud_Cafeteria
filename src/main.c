#include "global.h"

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Criação do array para receber os produtos antes do sistema entrar em loop
    int qty = 100, currentProduct = 0, *ptrCurrentProduct, currentOrder = 0, *ptrCurrentOrder;
    ptrCurrentProduct = &currentProduct;
    ptrCurrentOrder = &currentOrder;

    // Aloca um array para produtos com a quantidade definida
    productStruct *ptrProductsArray = (productStruct *) malloc(qty * sizeof(productStruct));

    // Aloca um array para pedidos com a quantidade definida
    orderStruct *ptrOrdersArray = (orderStruct *) malloc(qty * sizeof(orderStruct));

    // Se não conseguir alocar dará erro antes de iniciar o sistema
    if (ptrProductsArray == NULL || ptrOrdersArray == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1; // Saída do programa com erro
    }

    printf("Bem vindo ao sistema de gerenciamento de produtos e pedidos!\n\n\n");
    printf("                     ;)( ;\n");
    printf("                    :----:     o8Oo./\n");
    printf("                   C|====| ._o8o8o8Oo_.\n");
    printf("                    |    |  \\========/\n");
    printf("                    `----'   `------'\n");
    sleep(4);
    system("cls");

    menuMain(ptrCurrentProduct, ptrCurrentOrder, ptrProductsArray, ptrOrdersArray);
}
