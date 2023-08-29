#include "global.h"

//Fun��o para editar produtos
void editProduct(const int *productsQty, productStruct *productsArray) {
    int numToEdit, switchOption;

    printf("Digite o c�digo do produto para editar: ");
    scanf("%d", &numToEdit); //NOLINT(cert-err34-c) <- remove o aviso do "scanf"

    //TODO encontrar no array o endere�o correto para altera��o

    //Menu para escolher o que deseja editar
    printf("1 - Nome do produto\n");
    printf("2 - Pre�o\n");
    printf("3 - Quantidade\n");
    printf("0 - Cancelar\n");
    printf("Digite o que deseja editar:\n");
    scanf("%d", &switchOption); //NOLINT(cert-err34-c)

    switch (switchOption) {
        case 1:
            printf("Digite o novo nome do produto:\n");
            scanf("%49s", productsArray[numToEdit].name); //NOLINT(cert-err34-c)
            break;

        case 2:
            printf("Digite o novo pre�o do produto:\n");
            scanf("%f", productsArray[numToEdit].price);
            break;

        case 3:
            printf("Digite o nova quantidade:\n");
            scanf("%d", productsArray[numToEdit].amount);
            break;

        case 0:
            printf("Voltando...\n");
            sleep(2);
            break;

        default:
            printf("Op��o inv�lida!");
            sleep(2);
            break;
    }
}
