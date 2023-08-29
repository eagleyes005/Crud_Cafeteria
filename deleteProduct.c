#include "global.h"

// Função para excluír produtos
void deleteProduct(const int *productsQty, productStruct *productsArray) {
    int toDelete, index = -1, switchOption;

    // Input para escolher qual item do array será excluído
    printf("Digite o código do produto para excluir:\n");
    scanf("%d", &toDelete);

    // Loop for para encontrar o endereço do item a ser excluído
    for (int i = 0; i < *productsQty; ++i) {
        if (productsArray[i].cod == toDelete) {
            index = i; // Quando o mesmo é encontrado este é salvo na variável index para uso posterior
            break;
        }
    }

    // Verifica se o input existe no array
    if (index == -1) {
        printf("Produto não encontrado!\n");
        sleep(2);
        return;
    }

    // Menu de confirmação da exclusão
    printf("Tem certeza?\n");
    printf("1 - Sim\n");
    printf("0 - Não\n");
    scanf("%d", &switchOption);

    // Switch-case para excluir ou não o item
    switch (switchOption) {
        case 1:
            // A exclusão é somente a transformação do título para "EXCLUÍDO" e a mudança do preço
            // Em arrays é difícil de se eliminar um dado, pois estes são armazenados de forma contígua na memória.
            sprintf(productsArray[index].name, "EXCLUÍDO");
            productsArray[index].price = -1,00;
            productsArray[index].amount = -1;
            printf("Produto excluído com sucesso!\n");
            sleep(2);
            break;

        case 0:
            printf("Cancelando...\n");
            sleep(2);
            break;

        default:
            printf("Opção inválida!\n");
            sleep(2);
            break;
    }
}
