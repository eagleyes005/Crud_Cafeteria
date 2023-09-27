#include "global.h"

// Função para editar produtos
void editProduct(const int *currentIndex, productStruct *productsArray) {
    int toEdit, index = -1, switchOption;
    char input[10], *endInput;

    int inputToEdit = 1;
    while (inputToEdit == 1) {
        // Input para escolher qual item do array será editado
        printf("Digite o código do produto para editar:\n");
        fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

        toEdit = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
            printf("Entrada inválida. Digite um número.\n");
            continue; // Volta para o início do menu
        } else {
            inputToEdit = 0;
        }
    }

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

    int inputSwitchOption = 1;
    while (inputSwitchOption == 1) {
        // Input para escolher qual item do array será editado
        fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

        switchOption = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
            printf("Entrada inválida. Digite um número.\n");
            continue; // Volta para o início do menu
        } else {
            inputSwitchOption = 0;
        }
    }

    //scanf("%d", &switchOption);

    // Switch-case para editar o que foi escolhido
    switch (switchOption) {
        case 1:
            printf("Digite o novo nome do produto:\n");
            scanf("%29s", productsArray[index].name); // Atribui o novo nome
            getchar(); // Consumir o caractere de nova linha restante no buffer de entrada
            printf("Produto editado com sucesso!\n");
            sleep(2);
            break;

        case 2:
            printf("Digite o novo preço do produto:\n");
            int newPriceInput = 1;
            while (newPriceInput == 1) {
                fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

                productsArray[index].price = (float) strtol(input, &endInput, 10); // Converter a string em um número de ponto flutuante
                if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
                    printf("Entrada inválida. Digite um número.\n");
                    continue; // Volta para o início do menu
                } else {
                    newPriceInput = 0;
                }
            }
            printf("Produto editado com sucesso!\n");
            sleep(2);
            break;

        case 3:
            printf("Digite o nova quantidade:\n");
            int newAmountInput = 1;
            while (newAmountInput == 1) {
                fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

                productsArray[index].amount = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
                if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
                    printf("Entrada inválida. Digite um número.\n");
                    continue; // Volta para o início do menu
                } else {
                    newAmountInput = 0;
                }
            }
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
