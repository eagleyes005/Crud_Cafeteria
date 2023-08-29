#include "global.h"

// Fun��o para exclu�r produtos
void deleteProduct(const int *productsQty, productStruct *productsArray) {
    int toDelete, index = -1, switchOption;

    // Input para escolher qual item do array ser� exclu�do
    printf("Digite o c�digo do produto para excluir:\n");
    scanf("%d", &toDelete);

    // Loop for para encontrar o endere�o do item a ser exclu�do
    for (int i = 0; i < *productsQty; ++i) {
        if (productsArray[i].cod == toDelete) {
            index = i; // Quando o mesmo � encontrado este � salvo na vari�vel index para uso posterior
            break;
        }
    }

    // Verifica se o input existe no array
    if (index == -1) {
        printf("Produto n�o encontrado!\n");
        sleep(2);
        return;
    }

    // Menu de confirma��o da exclus�o
    printf("Tem certeza?\n");
    printf("1 - Sim\n");
    printf("0 - N�o\n");
    scanf("%d", &switchOption);

    // Switch-case para excluir ou n�o o item
    switch (switchOption) {
        case 1:
            // A exclus�o � somente a transforma��o do t�tulo para "EXCLU�DO" e a mudan�a do pre�o
            // Em arrays � dif�cil de se eliminar um dado, pois estes s�o armazenados de forma cont�gua na mem�ria.
            sprintf(productsArray[index].name, "EXCLU�DO");
            productsArray[index].price = -1,00;
            productsArray[index].amount = -1;
            printf("Produto exclu�do com sucesso!\n");
            sleep(2);
            break;

        case 0:
            printf("Cancelando...\n");
            sleep(2);
            break;

        default:
            printf("Op��o inv�lida!\n");
            sleep(2);
            break;
    }
}
