#include "global.h"

// Função para excluír produtos
void deleteProduct(int *currentIndex, productStruct *productsArray) {
    int toDelete, index = -1, switchOption;
    char input[10], *endInput;

    int inputToDelete = 1;
    while (inputToDelete == 1) {
        // Input para escolher qual item do array será excluído
        printf("Digite o código do produto para excluir:\n");
        fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

        toDelete = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
            printf("Entrada inválida. Digite um número.\n");
            continue; // Volta para o início do menu
        } else {
            inputToDelete = 0;
        }
    }

    // Loop for para encontrar o endereço do item a ser excluído
    for (int i = 0; i < *currentIndex; ++i) {
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
    int inputSwitchOption = 1;
    while (inputSwitchOption == 1) {
        // Input para escolher qual item do array será excluído
        fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

        switchOption = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
            printf("Entrada inválida. Digite um número.\n");
            continue; // Volta para o início do menu
        } else {
            inputSwitchOption = 0;
        }
    }

    // Switch-case para excluir ou não o item
    switch (switchOption) {
        case 1:
            // Substitui os dados do item para excluir pelo último cadastrado
            sprintf(productsArray[index].name, "%s", productsArray[*currentIndex - 1].name);
            productsArray[index].price = productsArray[*currentIndex - 1].price;
            productsArray[index].amount = productsArray[*currentIndex - 1].amount;
            *currentIndex -= 1; //Diminui o índice corrente do array
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
