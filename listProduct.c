#include "global.h"

// Fun��o para listar produtos
void listProduct (int *currentIndex, productStruct *productsArray) {

    // Impress�o dos produtos utilizando um loop for onde ser� impresso at� o �ndice corrente
    printf("%-10s%-30s%-10s%-20s%-10s\n", "C�digo:", "Nome do Produto:", "Pre�o:", "Quantidade:", "Total:");
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
// Fun��o para retornar ap�s consulta
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