// Função para listar produtos
void listProduct(
        const int *ptrCurrentProduct,
        productStruct *ptrProductsArray
) {

    // Impressão dos produtos utilizando um loop for onde será impresso até o índice corrente
    printf(BHCYN "================================= ESTOQUE DE PRODUTOS =================================\n" COLOR_RESET);
    printf(BBLK "%-10s%-30s%-14s%-20s%-20s\n", "Código:", "Nome do Produto:", "Preço un:", "Quantidade:",
           "Total:" COLOR_RESET);
    printf("---------------------------------------------------------------------------------------\n");
    for (int i = 0; i < *ptrCurrentProduct; i++) {
        float total = ptrProductsArray[i].price * ptrProductsArray[i].amount;
        printf("%-10d%-30sR$ %-11.2f%-20dR$ %-17.2f\n",
               ptrProductsArray[i].idProduct,
               ptrProductsArray[i].name,
               ptrProductsArray[i].price,
               ptrProductsArray[i].amount,
               total);
    }
    printf("---------------------------------------------------------------------------------------\n");
}