// Fun��o para exclu�r produtos
void deleteProduct(
        int *ptrCurrentProduct,
        productStruct *ptrProductsArray
) {
    int toDelete, index = -1, switchOption;
    char input[10], *endInput;

    int inputToDelete = 1;
    while (inputToDelete == 1) {
        // Input para escolher qual item do array ser� exclu�do
        printf(BBLK "\nDigite o c�digo do produto para excluir:\n" COLOR_RESET);
        fgets(input, sizeof(input), stdin); // L� uma linha de entrada como uma string

        toDelete = (int) strtol(input, &endInput, 10); // Converter a string em um n�mero inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de convers�o
            printf(BHRED "Entrada inv�lida. Digite um n�mero.\n" COLOR_RESET);
            continue; // Volta para o in�cio do menu
        } else {
            inputToDelete = 0;
        }
    }

    // Loop for para encontrar o endere�o do item a ser exclu�do
    for (int i = 0; i < *ptrCurrentProduct; ++i) {
        if (ptrProductsArray[i].idProduct == toDelete) {
            index = i; // Quando o mesmo � encontrado este � salvo na vari�vel index para uso posterior
            break;
        }
    }

    // Verifica se o input existe no array
    if (index == -1) {
        printf(BHRED "Produto n�o encontrado!\n" COLOR_RESET);
        sleep(2);
        return;
    }

    // Menu de confirma��o da exclus�o
    printf(BHRED "Tem certeza?\n" COLOR_RESET);
    printf("1 - Sim\n");
    printf("0 - N�o\n");
    int inputSwitchOption = 1;
    while (inputSwitchOption == 1) {
        fgets(input, sizeof(input), stdin); // L� uma linha de entrada como uma string

        switchOption = (int) strtol(input, &endInput, 10); // Converter a string em um n�mero inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de convers�o
            printf(BHRED "Entrada inv�lida. Digite um n�mero.\n" COLOR_RESET);
            continue; // Volta para o in�cio do menu
        } else {
            inputSwitchOption = 0;
        }
    }

    // Switch-case para excluir ou n�o o item
    switch (switchOption) {
        case 1:
            // Substitui os dados do item para excluir pelo �ltimo cadastrado
            sprintf(ptrProductsArray[index].name, "%s", ptrProductsArray[*ptrCurrentProduct - 1].name);
            ptrProductsArray[index].price = ptrProductsArray[*ptrCurrentProduct - 1].price;
            ptrProductsArray[index].amount = ptrProductsArray[*ptrCurrentProduct - 1].amount;
            *ptrCurrentProduct -= 1; //Diminui o �ndice corrente do array
            printf(BHGRN "Produto exclu�do com sucesso!\n" COLOR_RESET);
            sleep(2);
            break;

        case 0:
            printf(BBLK "Cancelando...\n" COLOR_RESET);
            sleep(2);
            break;

        default:
            printf(BHRED "Op��o inv�lida!\n" COLOR_RESET);
            sleep(2);
            break;
    }
}
