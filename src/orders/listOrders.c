// Função para listar pedidos
void listOrders(
        int *ptrCurrentOrder,
        orderStruct *ptrOrdersArray
) {

    // Impressão dos produtos utilizando um loop for onde será impresso até o índice corrente
    printf(BHCYN "======================================= PEDIDOS =======================================\n" COLOR_RESET);
    for (int i = 0; i < *ptrCurrentOrder; i++) {
        float totalPedido = 0;
        printf("------------------------------------- PEDIDO Nº %d -------------------------------------\n",
               (ptrOrdersArray[i].idOrder));
        printf("Nome do Cliente: %-30s\n", ptrOrdersArray[i].costumerName);
        printf("                   ----------------- ITENS DO PEDIDO -----------------\n");
        printf(BBLK "            %-10s%-30s%-14s%-20s\n", "Item:", "Nome do Produto:", "Preço un:", "Quantidade:" COLOR_RESET);
        for (int j = 0; j < ptrOrdersArray[i].qtyItem; ++j) {
            printf("            %-10d%-30sR$ %-11.2f%-20d\n",
                   ptrOrdersArray[i].products[j].idProduct,
                   ptrOrdersArray[i].products[j].name,
                   ptrOrdersArray[i].products[j].price,
                   ptrOrdersArray[i].products[j].amount);
            totalPedido += ptrOrdersArray[i].products[j].price * ptrOrdersArray[i].products[j].amount;
        }
        printf(BHYEL "\nTotal do pedido: R$ %.2f\n" COLOR_RESET, totalPedido);
    }
    printf("---------------------------------------------------------------------------------------\n");
}