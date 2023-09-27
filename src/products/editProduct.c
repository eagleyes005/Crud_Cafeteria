// Função para editar produtos
void editProduct(
        const int *ptrCurrentProduct,
        productStruct *ptrProductsArray
) {
    int toEdit, index = -1, switchOption;
    char input[10], *endInput;

    int inputToEdit = 1;
    while (inputToEdit == 1) {
        // Input para escolher qual item do array será editado
        printf(BBLK "\nDigite o código do produto para editar:\n" COLOR_RESET);
        fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

        toEdit = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
            printf(BHRED "Entrada inválida. Digite um número.\n" COLOR_RESET);
            continue; // Volta para o início do menu
        } else {
            inputToEdit = 0;
        }
    }

    // Loop for para encontrar o endereço do item a ser editado
    for (int i = 0; i < *ptrCurrentProduct; ++i) {
        if (ptrProductsArray[i].idProduct == toEdit) {
            index = i; // Quando o mesmo é encontrado este é salvo na variável index para uso posterior
            break;
        }
    }

    // Verifica se o input existe no array
    if (index == -1) {
        printf(BHRED "Produto não encontrado!\n" COLOR_RESET);
        sleep(2);
        return;
    }

    // Menu para escolher o que deseja editar
    printf("1 - Nome do produto\n");
    printf("2 - Preço\n");
    printf("3 - Quantidade\n");
    printf("0 - Cancelar\n");
    printf(BBLK "Digite o que deseja editar:\n" COLOR_RESET);

    int inputSwitchOption = 1;
    while (inputSwitchOption == 1) {
        // Input para escolher qual item do array será editado
        fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

        switchOption = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
            printf(BHRED "Entrada inválida. Digite um número.\n" COLOR_RESET);
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
            scanf("%29s", ptrProductsArray[index].name); // Atribui o novo nome
            getchar(); // Consumir o caractere de nova linha restante no buffer de entrada
            printf(BHGRN "Produto editado com sucesso!\n" COLOR_RESET);
            sleep(2);
            break;

        case 2:
            printf("Digite o novo preço do produto:\n");
            int newPriceInput = 1;
            while (newPriceInput == 1) {
                fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

                ptrProductsArray[index].price = (float) strtol(input, &endInput,
                                                               10); // Converter a string em um número de ponto flutuante
                if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
                    printf(BHRED "Entrada inválida. Digite um número.\n" COLOR_RESET);
                    continue; // Volta para o início do menu
                } else {
                    newPriceInput = 0;
                }
            }
            printf(BHGRN "Produto editado com sucesso!\n" COLOR_RESET);
            sleep(2);
            break;

        case 3:
            printf("Digite o nova quantidade:\n");
            int newAmountInput = 1;
            while (newAmountInput == 1) {
                fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

                ptrProductsArray[index].amount = (int) strtol(input, &endInput,
                                                              10); // Converter a string em um número inteiro
                if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
                    printf(BHRED "Entrada inválida. Digite um número.\n" COLOR_RESET);
                    continue; // Volta para o início do menu
                } else {
                    newAmountInput = 0;
                }
            }
            printf(BHGRN "Produto editado com sucesso!\n" COLOR_RESET);
            sleep(2);
            break;

        case 0:
            printf(BBLK "Voltando...\n" COLOR_RESET);
            sleep(2);
            break;

        default:
            printf(BBLK "Opção inválida!\n" COLOR_RESET);
            sleep(2);
            break;
    }
}
