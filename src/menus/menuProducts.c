// Fun��o do menu de produtos
void menuProducts(
        int *ptrCurrentProduct,
        productStruct *ptrProductsArray
) {
    int running = 1;
    while (running == 1) {
        char input[10], *endInput;
        int selector;

        system("cls"); //Limpeza do terminal

        printf(BHCYN "================================== GERENCIAR PRODUTOS =================================\n" COLOR_RESET);
        printf("1 - Consultar Produtos\n");
        printf("2 - Cadastrar Novo Produto\n");
        printf("3 - Editar Produto\n");
        printf("4 - Excluir Produto\n");
        printf("5 - Gerar Produtos para Teste\n");
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
                // Case para listar produtos
            case 1:
                system("cls");
                if (*ptrCurrentProduct == 0) {
                    printf(BHRED "N�o h� produtos para serem listados!\n" COLOR_RESET);
                    sleep(2);
                    break;
                }
                listProduct(ptrCurrentProduct, ptrProductsArray);
                menuReturn();
                system("cls");
                break;

                // Case para cadastrar produtos
            case 2:
                system("cls");
                registerProduct(ptrCurrentProduct, ptrProductsArray);
                system("cls");
                break;

                // Case para editar produtos
            case 3:
                system("cls");
                // Verifica se existe algum produto no array
                if (*ptrCurrentProduct == 0) {
                    printf(BHRED "N�o h� produtos para serem editados!\n" COLOR_RESET);
                    sleep(2);
                    break;
                }
                listProduct(ptrCurrentProduct, ptrProductsArray);
                editProduct(ptrCurrentProduct, ptrProductsArray);
                system("cls");
                break;

                //Case para excluir produtos
            case 4:
                system("cls");
                // Verifica se existe algum produto no array
                if (*ptrCurrentProduct == 0) {
                    printf(BHRED "N�o h� produtos para serem exclu�dos!\n" COLOR_RESET);
                    sleep(2);
                    break;
                }
                listProduct(ptrCurrentProduct, ptrProductsArray);
                deleteProduct(ptrCurrentProduct, ptrProductsArray);
                system("cls");
                break;

                //Case para gerar produtos
            case 5:
                system("cls");
                // Verifica se existe algum produto no array
                generateProducts(ptrCurrentProduct, ptrProductsArray);
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