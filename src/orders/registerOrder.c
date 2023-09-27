//Função para registrar pedidos
void registerOrder(
        int *ptrCurrentProduct,
        int *ptrCurrentOrder,
        productStruct *ptrProductsArray,
        orderStruct *ptrOrdersArray
) {
    orderStruct newOrder; // É criado uma nova struct de tipo productStruct
    productStruct newOrderProduct;
    newOrder.idOrder = *ptrCurrentOrder + 1;
    newOrder.qtyItem = 0;

    printf("Insira o nome do cliente:\n");
    scanf("%29s", newOrder.costumerName);
    getchar(); // Consumir o caractere de nova linha restante no buffer de entrada

    int productsInput = 1;
    while (productsInput == 1) {
        int idProduto, qtyProduct, indexProduct = -1;
        char input[10], *endInput;

        system("cls");
        printf(BHGRN "Cliente: %s\n" COLOR_RESET, newOrder.costumerName);
        listProduct(ptrCurrentProduct, ptrProductsArray);
        printf("Insira o código do produto:\n");
        fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

        idProduto = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
            printf(BHRED "Entrada inválida. Digite um número.\n" COLOR_RESET);
            continue; // Volta para o início do menu
        }

        // Loop for para encontrar o endereço do item a ser incluído
        for (int i = 0; i < *ptrCurrentProduct; ++i) {
            if (ptrProductsArray[i].idProduct == idProduto) {
                indexProduct = i; // Quando o mesmo é encontrado este é salvo na variável indexProduct para uso posterior
                break;
            }
        }

        // Verifica se o input existe no array
        if (indexProduct == -1) {
            printf(BHRED "Produto não encontrado!\n" COLOR_RESET);
            sleep(2);
            continue;
        } else {
            newOrderProduct = ptrProductsArray[indexProduct];
        }


        int qtyInput = 1;
        while (qtyInput == 1) {
            printf("Insira a quantidade do item do pedido:\n");
            fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

            qtyProduct = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
            if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
                printf(BHRED "Entrada inválida. Digite um número.\n" COLOR_RESET);
                continue; // Volta para o início do menu
            } else {
                qtyInput = 0;
            }
        }

        newOrder.products[newOrder.qtyItem] = newOrderProduct;
        newOrder.products[newOrder.qtyItem].amount = qtyProduct;
        newOrder.products[newOrder.qtyItem].idProduct = (newOrder.qtyItem + 1);
        newOrder.qtyItem++;

        // Menu para incluir mais um item no pedido
        printf(BHRED "Deseja incluir mais um item no pedido?\n" COLOR_RESET);
        printf("1 - Sim\n");
        printf("0 - Não\n");
        int inputSwitchOption = 1, switchOption;
        while (inputSwitchOption == 1) {
            fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

            switchOption = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
            if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
                printf(BHRED "Entrada inválida. Digite um número.\n" COLOR_RESET);
                continue; // Volta para o início da opção
            } else {
                inputSwitchOption = 0;
            }
        }

        // Switch-case para excluir ou não o item
        switch (switchOption) {
            case 1:
                continue;

            case 0:
                printf(BHGRN "Pedido incluso com sucesso!\n" COLOR_RESET);
                productsInput = 0;
                sleep(2);
                break;

            default:
                printf(BHRED "Opção inválida!\n" COLOR_RESET);
                productsInput = 0;
                sleep(2);
                break;
        }
    }

    // Após inserir os dados da nova struct a mesma é atribuída ao índice corrente do array
    ptrOrdersArray[*ptrCurrentOrder] = newOrder;
    (*ptrCurrentOrder)++; // Pula para o próximo índice
}
