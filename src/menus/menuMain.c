// Fun��o do menu principal
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
        printf(BBLK "Selecione a op��o desejada:\n" COLOR_RESET);
        fgets(input, sizeof(input), stdin); // L� uma linha de entrada como uma string

        selector = (int) strtol(input, &endInput, 10); // Converter a string em um n�mero inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de convers�o
            printf(BHRED "Entrada inv�lida. Digite um n�mero.\n" COLOR_RESET);
            sleep(2);
            continue; // Volta para o in�cio do menu
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

                //Case de op��o inv�lida
            default:
                printf(BHRED "Op��o inv�lida!" COLOR_RESET);
                sleep(2);
                break;
        } //End Switch
    }
}