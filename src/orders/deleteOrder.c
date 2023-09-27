// Função para excluír pedidos
void deleteOrder(
        int *ptrCurrentOrder,
        orderStruct *ptrOrdersArray
) {
    int toDelete, index = -1, switchOption;
    char input[10], *endInput;

    int inputToDelete = 1;
    while (inputToDelete == 1) {
        // Input para escolher qual item do array será excluído
        printf(BBLK "Digite o número do pedido para concluir:\n" COLOR_RESET);
        fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

        toDelete = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
            printf(BHRED "Entrada inválida. Digite um número.\n" COLOR_RESET);
            continue; // Volta para o início do menu
        } else {
            inputToDelete = 0;
        }
    }

    // Loop for para encontrar o endereço do pedido a ser excluído
    for (int i = 0; i < *ptrCurrentOrder; ++i) {
        if (ptrOrdersArray[i].idOrder == toDelete) {
            index = i; // Quando o mesmo é encontrado este é salvo na variável index para uso posterior
            break;
        }
    }

    // Verifica se o input existe no array
    if (index == -1) {
        printf(BHRED "Pedido não encontrado!\n" COLOR_RESET);
        sleep(2);
        return;
    }

    // Menu de confirmação da exclusão
    printf(BHRED "Tem certeza?\n" COLOR_RESET);
    printf("1 - Sim\n");
    printf("0 - Não\n");
    int inputSwitchOption = 1;
    while (inputSwitchOption == 1) {
        // Input para escolher qual item do array será excluído
        fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

        switchOption = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
            printf(BHRED "Entrada inválida. Digite um número.\n" COLOR_RESET);
            continue; // Volta para o início do menu
        } else {
            inputSwitchOption = 0;
        }
    }

    // Switch-case para excluir ou não o item
    switch (switchOption) {
        case 1:
            // Substitui os dados do item para excluir pelo último cadastrado
            sprintf(ptrOrdersArray[index].costumerName, "%s", ptrOrdersArray[*ptrCurrentOrder - 1].costumerName);
            ptrOrdersArray[index].qtyItem = ptrOrdersArray[*ptrCurrentOrder - 1].qtyItem;
            for (int i = 0; i < ptrOrdersArray[index].qtyItem; ++i) {
                ptrOrdersArray[index].products[i] = ptrOrdersArray[*ptrCurrentOrder - 1].products[i];
            }
            *ptrCurrentOrder -= 1; //Diminui o índice corrente do array
            printf(BHGRN "Pedido concluído com sucesso!\n" COLOR_RESET);
            sleep(2);
            break;

        case 0:
            printf(BBLK "Cancelando...\n" COLOR_RESET);
            sleep(2);
            break;

        default:
            printf(BHRED "Opção inválida!\n" COLOR_RESET);
            sleep(2);
            break;
    }
}
