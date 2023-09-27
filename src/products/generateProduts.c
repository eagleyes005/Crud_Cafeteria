// Função para gerar alguns produtos para teste
void generateProducts(
        int *ptrCurrentProduct,
        productStruct *ptrProductsArray
) {
    strcpy(ptrProductsArray[0].name, "Espresso");
    ptrProductsArray[0].amount = 20;
    ptrProductsArray[0].idProduct = 1;
    ptrProductsArray[0].price = (float) 3.50;

    strcpy(ptrProductsArray[1].name, "Cappuccino");
    ptrProductsArray[1].amount = 12;
    ptrProductsArray[1].idProduct = 2;
    ptrProductsArray[1].price = (float) 5.00;

    strcpy(ptrProductsArray[2].name, "Muffin de Chocolate");
    ptrProductsArray[2].amount = 23;
    ptrProductsArray[2].idProduct = 3;
    ptrProductsArray[2].price = (float) 4.50;

    strcpy(ptrProductsArray[3].name, "Chá de Camomila");
    ptrProductsArray[3].amount = 5;
    ptrProductsArray[3].idProduct = 4;
    ptrProductsArray[3].price = (float) 3.00;

    strcpy(ptrProductsArray[4].name, "Sanduíche de Frango");
    ptrProductsArray[4].amount = 8;
    ptrProductsArray[4].idProduct = 5;
    ptrProductsArray[4].price = (float) 7.50;

    strcpy(ptrProductsArray[5].name, "Latte");
    ptrProductsArray[5].amount = 12;
    ptrProductsArray[5].idProduct = 6;
    ptrProductsArray[5].price = (float) 4.50;

    strcpy(ptrProductsArray[6].name, "Croissant de Chocolate");
    ptrProductsArray[6].amount = 10;
    ptrProductsArray[6].idProduct = 7;
    ptrProductsArray[6].price = (float) 3.75;

    strcpy(ptrProductsArray[7].name, "Bolo de Cenoura");
    ptrProductsArray[7].amount = 15;
    ptrProductsArray[7].idProduct = 8;
    ptrProductsArray[7].price = (float) 4.00;

    strcpy(ptrProductsArray[8].name, "Mocha");
    ptrProductsArray[8].amount = 7;
    ptrProductsArray[8].idProduct = 9;
    ptrProductsArray[8].price = (float) 5.25;

    strcpy(ptrProductsArray[9].name, "Chai Latte");
    ptrProductsArray[9].amount = 9;
    ptrProductsArray[9].idProduct = 10;
    ptrProductsArray[9].price = (float) 5.00;

    *ptrCurrentProduct = 10;
}
