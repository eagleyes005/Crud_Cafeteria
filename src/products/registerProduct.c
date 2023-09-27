// Função para registrar produtos
void registerProduct(
        int *ptrCurrentProduct,
        productStruct *ptrProductsArray
) {
    productStruct newProduct; // É criado uma nova struct de tipo productStruct
    newProduct.idProduct = *ptrCurrentProduct + 1;

    printf("Insira o nome do produto:\n");
    scanf("%29s", newProduct.name);
    getchar(); // Consumir o caractere de nova linha restante no buffer de entrada

    int priceInput = 1;
    while (priceInput == 1) {
        char input[10], *endInput;
        printf("Insira o valor unitário do produto:\n");
        fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

        newProduct.price = (float) strtol(input, &endInput, 10); // Converter a string em um número de ponto flutuante
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
            printf(BHRED "Entrada inválida. Digite um número.\n" COLOR_RESET);
            continue; // Volta para o início do menu
        } else {
            priceInput = 0;
        }
    }

    int amountInput = 1;
    while (amountInput == 1) {
        char input[10], *endInput;
        printf("Insira a quantidade em estoque do produto:\n");
        fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

        newProduct.amount = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
            printf(BHRED "Entrada inválida. Digite um número.\n" COLOR_RESET);
        } else {
            amountInput = 0;
        }
    }

    // Após inserir os dados da nova struct a mesma é atribuída ao índice corrente do array
    ptrProductsArray[*ptrCurrentProduct] = newProduct;
    (*ptrCurrentProduct)++; // Pula para o próximo índice
    system("cls");
    printf(BHGRN "Produto cadastrado com sucesso!" COLOR_RESET);
    sleep(2);
}
