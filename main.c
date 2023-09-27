#include "global.h"

void menuProducts(int *currentIndex, productStruct *productsArray) {
    int running = 1;
    while (running == 1) {
        char input[10], *endInput;
        int selector;

        system("cls"); //Limpeza do terminal

        printf("-------------- GERENCIAR PRODUTOS --------------\n");
        printf("1 - Consultar Produtos\n");
        printf("2 - Cadastrar Novo Produto\n");
        printf("3 - Editar Produto\n");
        printf("4 - Excluir Produto\n");
        printf("0 - Voltar\n\n");
        printf("Selecione a opção desejada:\n");
        fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

        selector = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
            printf("Entrada inválida. Digite um número.\n");
            sleep(2);
            continue; // Volta para o início do menu
        }

        system("cls");

        switch (selector) {
            // Case para listar produtos
            case 1:
                system("cls");
                listProduct(currentIndex, productsArray);
                returnOption();
                system("cls");
                break;

                // Case para cadastrar produtos
            case 2:
                system("cls");
                registerProduct(currentIndex, productsArray);
                system("cls");
                break;

                // Case para editar produtos
            case 3:
                system("cls");
                // Verifica se existe algum produto no array
                if (*currentIndex == 0) {
                    printf("Não há produtos para serem editados!\n");
                    sleep(2);
                    break;
                }
                listProduct(currentIndex, productsArray);
                editProduct(currentIndex, productsArray);
                system("cls");
                break;

                //Case para excluir produtos
            case 4:
                system("cls");
                // Verifica se existe algum produto no array
                if (*currentIndex == 0) {
                    printf("Não há produtos para serem excluídos!\n");
                    sleep(2);
                    break;
                }
                listProduct(currentIndex, productsArray);
                deleteProduct(currentIndex, productsArray);
                system("cls");
                break;

                //Case para voltar
            case 0:
                printf("Voltando...\n");
                sleep(1);
                running = 0;
                break;

                //Case de opção inválida
            default:
                printf("Opção inválida!");
                sleep(2);
                break;
        } //End Switch
    }
}

void menuMain(int *currentIndex, productStruct *productsArray) {
    int running = 1;
    while (running == 1) {
        char input[10], *endInput;
        int selector;

        system("cls"); //Limpeza do terminal

        //Menu principal
        printf("---------------- MENU PRINCIPAL ----------------\n");
        printf("1 - Gerenciar Produtos\n");
        printf("2 - Gerenciar Pedidos\n");
        printf("0 - Sair\n\n");
        printf("Selecione a opção desejada:\n");
        fgets(input, sizeof(input), stdin); // Lê uma linha de entrada como uma string

        selector = (int) strtol(input, &endInput, 10); // Converter a string em um número inteiro
        if (*endInput != '\0' && *endInput != '\n') { // Verificar por erros de conversão
            printf("Entrada inválida. Digite um número.\n");
            sleep(2);
            continue; // Volta para o início do menu
        }

        system("cls");

        switch (selector) {
            // Case para gerenciar produtos
            case 1:
                system("cls");
                menuProducts(currentIndex, productsArray);
                system("cls");
                break;

                // Case para gerenciar pedidos
            case 2:
                system("cls");

                system("cls");
                break;

                //Case para encerrar o programa
            case 0:
                printf("Saindo... volte sempre! :)\n");
                sleep(2);
                free(productsArray);
                running = 0;
                break;

                //Case de opção inválida
            default:
                printf("Opção inválida!");
                sleep(2);
                break;
        } //End Switch
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Criação do array para receber os produtos antes do sistema entrar em loop
    int productsQty = 100, *ptrProductsQty, currentIndex = 0, *ptrCurrentIndex;
    ptrProductsQty = &productsQty;
    ptrCurrentIndex = &currentIndex;

    // Aloca memória com a quantidade de definida
    productStruct *ptrProductsArray = (productStruct *) malloc(*ptrProductsQty * sizeof(productStruct));

    // Se não conseguir alocar dará erro antes de iniciar o sistema
    if (ptrProductsArray == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1; // Saída do programa com erro
    }

    printf("Bem vindo ao sistema de gerenciamento de produtos e pedidos!\n\n");
    sleep(4);
    system("cls");

    menuMain(ptrCurrentIndex, ptrProductsArray);
}
