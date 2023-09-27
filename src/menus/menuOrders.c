// Fun��o do menu de pedidos
void menuOrders(
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

        printf(BHCYN "================================== GERENCIAR PEDIDOS ==================================\n" COLOR_RESET);
        printf("1 - Consultar Pedidos\n");
        printf("2 - Cadastrar Pedido\n");
        printf("3 - Concluir Pedido\n");
        printf("0 - Voltar\n\n");
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
                // Case para consultar pedidos
            case 1:
                system("cls");
                if (*ptrCurrentOrder == 0) {
                    printf(BHRED "N�o h� pedidos para serem listados!\n" COLOR_RESET);
                    sleep(2);
                    break;
                }
                listOrders(ptrCurrentOrder, ptrOrdersArray);
                menuReturn();
                system("cls");
                break;

                // Case para cadastrar pedidos
            case 2:
                system("cls");
                if (*ptrCurrentProduct == 0) {
                    printf(BHRED "N�o h� produtos para criar pedidos!\n" COLOR_RESET);
                    sleep(2);
                    break;
                }
                registerOrder(ptrCurrentProduct, ptrCurrentOrder, ptrProductsArray, ptrOrdersArray);
                system("cls");
                break;

                // Case para editar produtos
            case 3:
                system("cls");
                // Verifica se existe algum produto no array
                if (*ptrCurrentOrder == 0) {
                    printf(BHRED "N�o h� pedidos para serem finalizados!\n" COLOR_RESET);
                    sleep(2);
                    break;
                }
                listOrders(ptrCurrentOrder, ptrOrdersArray);
                deleteOrder(ptrCurrentOrder, ptrOrdersArray);
                system("cls");
                break;

                //Case para voltar
            case 0:
                printf(BBLK "Voltando...\n" COLOR_RESET);
                sleep(1);
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