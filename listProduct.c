#include "global.h"

//Fun��o para listar produtos
void listProduct (const int *productsQty, productStruct *productsArray) {

    system("cls"); //Limpeza do terminal

    //Impress�o dos produtos

    printf("C�digo:\t\tNome do Produto:\tPre�o:\t\tQuantidade:\n");
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
}

void returnOption () {
    int returnTrigger;

    printf("Insira algo para voltar\n");
    scanf("%d", &returnTrigger); //NOLINT(cert-err34-c)

    if (returnTrigger) {
        printf("Voltando...\n");
        sleep(2);
        return;
    }
}