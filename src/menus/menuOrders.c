// Função do menu de pedidos
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
                // Case para consultar pedidos
            case 1:
                system("cls");
                if (*ptrCurrentOrder == 0) {
                    printf(BHRED "Não há pedidos para serem listados!\n" COLOR_RESET);
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
                    printf(BHRED "Não há produtos para criar pedidos!\n" COLOR_RESET);
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
                    printf(BHRED "Não há pedidos para serem finalizados!\n" COLOR_RESET);
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

                //Case de opção inválida
            default:
                printf(BHRED "Opção inválida!" COLOR_RESET);
                sleep(2);
                break;
        } //End Switch
    }
}