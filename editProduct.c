#include "global.h"

// Função para editar produtos
void editProduct(const int *currentIndex, productStruct *productsArray) {
    int toEdit, index = -1, switchOption;

    // Input para escolher qual item do array será editado
    printf("Digite o código do produto para editar:\n");
    scanf("%d", &toEdit);

    // Loop for para encontrar o endereço do item a ser editado
    for (int i = 0; i < *currentIndex; ++i) {
        if (productsArray[i].cod == toEdit) {
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

    // Menu para escolher o que deseja editar
    printf("1 - Nome do produto\n");
    printf("2 - Preço\n");
    printf("3 - Quantidade\n");
    printf("0 - Cancelar\n");
    printf("Digite o que deseja editar:\n");
    scanf("%d", &switchOption);

    // Switch-case para editar o que foi escolhido
    switch (switchOption) {
        case 1:
            printf("Digite o novo nome do produto:\n");
            scanf("%49s", productsArray[index].name); // Atribui o novo nome
            printf("Produto editado com sucesso!\n");
            sleep(2);
            break;

        case 2:
            printf("Digite o novo preço do produto:\n");
            scanf("%f", &productsArray[index].price); // Atribui o novo preço
            printf("Produto editado com sucesso!\n");
            sleep(2);
            break;

        case 3:
            printf("Digite o nova quantidade:\n");
            scanf("%d", &productsArray[index].amount); // Atribui a nova quantidade
            printf("Produto editado com sucesso!\n");
            sleep(2);
            break;

        case 0:
            printf("Voltando...\n");
            sleep(2);
            break;

        default:
            printf("Opção inválida!\n");
            sleep(2);
            break;
    }
}
