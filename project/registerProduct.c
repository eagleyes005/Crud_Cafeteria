#include "global.h"
//TODO adicionar verificar de duplicidade
//TODO adicionar alocação dinâmica de memória

//Função para registrar produtos
void registerProduct (int *productsQty, productStruct *productsArray) {

    system("cls"); //Limpeza do terminal

    int keepRegistering = 1, *ptrKeepRegistering;
    ptrKeepRegistering = &keepRegistering;

    do {
        productStruct newProduct;
        newProduct.cod = *productsQty + 1;
        printf("Insira o nome do produto:\n");
        scanf("%49s", newProduct.name);
        printf("Insira o valor unitário do produto:\n");
        scanf("%f", &newProduct.price);
        printf("Insira a quantidade em estoque do produto:\n");
        scanf("%d", &newProduct.amount);

        productsArray[*productsQty] = newProduct;
        (*productsQty)++;

        // Menu para continuar cadastrando
        printf("\n");
        printf("Deseja cadastrar mais produtos?\n");
        printf("1 - Sim\n");
        printf("0 - Não\n");
        scanf("%d", ptrKeepRegistering);
    } while (*ptrKeepRegistering == 1);

}
