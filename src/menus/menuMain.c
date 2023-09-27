// Função do menu principal
void menuMain(
        int *ptrCurrentProduct,
        int *ptrCurrentOrder,
        productStruct *ptrProductsArray,
        orderStruct *ptrOrdersArray
) {
    int running = 1;
    while (running == 1) {
        char input[10], *endInput;
        int selector;

        system("cls"); //Limpeza do terminal

        //Menu principal
        printf(BHCYN "==================================== MENU PRINCIPAL ===================================\n" COLOR_RESET);
        printf("1 - Gerenciar Produtos\n");
        printf("2 - Gerenciar Pedidos\n");
        printf("0 - Sair\n\n");
        printf(BBLK "Selecione a opção desejada:\n" COLOR_RESET);
        fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

        selector = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
            printf(BHRED "Entrada inválida. Digite um número.\n" COLOR_RESET);
            sleep(2);
            continue; // Volta para o início do menu
        }

        system("cls");

        switch (selector) {
                // Case para gerenciar produtos
            case 1:
                system("cls");
                menuProducts(ptrCurrentProduct, ptrProductsArray);
                system("cls");
                break;

                // Case para gerenciar pedidos
            case 2:
                system("cls");
                menuOrders(ptrCurrentProduct, ptrCurrentOrder, ptrProductsArray, ptrOrdersArray);
                system("cls");
                break;

                //Case para encerrar o programa
            case 0:
                printf("Saindo... volte sempre!");
                printf(BHGRN " :)\n" COLOR_RESET);
                sleep(2);
                free(ptrProductsArray);
                running = 0;
                break;

                //Case de opção inválida
            default:
                printf(BHRED "Opção inválida!" COLOR_RESET);
                sleep(2);
                break;
        } //End Switch
    }
}