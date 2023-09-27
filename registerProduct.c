#include "global.h"

//Fun��o para registrar produtos
void registerProduct(int *currentIndex, productStruct *productsArray) {
    productStruct newProduct; // � criado uma nova struct de tipo productStruct
    newProduct.cod = *currentIndex + 1;

    printf("Insira o nome do produto:\n");
    scanf("%29s", newProduct.name);
    getchar(); // Consumir o caractere de nova linha restante no buffer de entrada

//    int nameInput = 1;
//    while (nameInput == 1) {
//        char input[30];
//        printf("Insira o nome do produto:\n");
//        fgets(newProduct.name, sizeof(input), stdin); // L� uma linha de entrada como uma string
//        nameInput = 0;
//    }

    int priceInput = 1;
    while (priceInput == 1) {
        char input[10], *endInput;
        printf("Insira o valor unit�rio do produto:\n");
        fgets(input, sizeof(input), stdin); // L� uma linha de entrada como uma string

        newProduct.price = (float) strtol(input, &endInput, 10); // Converter a string em um n�mero de ponto flutuante
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de convers�o
            printf("Entrada inv�lida. Digite um n�mero.\n");
            continue; // Volta para o in�cio do menu
        } else {
            priceInput = 0;
        }
    }

    int amountInput = 1;
    while (amountInput == 1) {
        char input[10], *endInput;
        printf("Insira a quantidade em estoque do produto:\n");
        fgets(input, sizeof(input), stdin); // L� uma linha de entrada como uma string

        newProduct.amount = (int) strtol(input, &endInput, 10); // Converter a string em um n�mero inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de convers�o
            printf("Entrada inv�lida. Digite um n�mero.\n");
        } else {
            amountInput = 0;
        }
    }

    // Ap�s inserir os dados da nova struct a mesma � atribu�da ao �ndice corrente do array
    productsArray[*currentIndex] = newProduct;
    (*currentIndex)++; // Pula para o pr�ximo �ndice
    printf("Produto cadastrado com sucesso!");
    sleep(2);
}
