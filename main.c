#include "global.h"

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Criação do array para receber os produtos antes do sistema entrar em loop
    int productsQty = 100, *ptrProductsQty, currentIndex = 0, *ptrCurrentIndex;
    ptrProductsQty = &productsQty;
    ptrCurrentIndex = &currentIndex;

    // Aloca memória dinamicamente para o array de estruturas
    productStruct *ptrProductsArray = (productStruct *)malloc(*ptrProductsQty * sizeof(productStruct));

    // Se não conseguir alocar dará erro antes de iniciar o sistema
    if (ptrProductsArray == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1; // Saída do programa com erro
    }

    int running = 1;
    while (running == 1) {
        int selector, *ptrSelector;
        ptrSelector = &selector;

        system("cls"); //Limpeza do terminal

        //Menu principal
        printf("Bem vindo ao sistema de cadastro de produtos!\n\n");

        printf("-------------- MENU --------------\n");
        printf("1 - Consultar Produtos\n");
        printf("2 - Cadastrar Novo Produto\n");
        printf("3 - Editar Produto\n");
        printf("4 - Excluir Produto\n");
        printf("0 - Sair\n\n");
        printf("Selecione a opção desejada:\n");
        scanf("%d", ptrSelector);
        system("cls");


        switch (*ptrSelector)
        {
                // Case para listar produtos
            case 1:
                system("cls");
                listProduct(ptrCurrentIndex, ptrProductsArray);
                returnOption();
                system("cls");
                break;

                // Case para cadastrar produtos
            case 2:
                system("cls");
                registerProduct(ptrCurrentIndex, ptrProductsArray);
                system("cls");
                break;

                // Case para editar produtos
            case 3:
                system("cls");
                // Verifica se existe algum produto no array
                if (*ptrCurrentIndex == 0) {
                    printf("Não há produtos para serem editados!\n");
                    sleep(2);
                    break;
                }
                listProduct(ptrCurrentIndex, ptrProductsArray);
                editProduct(ptrCurrentIndex, ptrProductsArray);
                system("cls");
                break;

                //Case para excluir produtos
            case 4:
                system("cls");
                // Verifica se existe algum produto no array
                if (*ptrCurrentIndex == 0) {
                    printf("Não há produtos para serem excluídos!\n");
                    sleep(2);
                    break;
                }
                listProduct(ptrCurrentIndex, ptrProductsArray);
                deleteProduct(ptrCurrentIndex, ptrProductsArray);
                system("cls");
                break;

                //Case para encerrar o programa
            case 0:
                printf("Saindo... volte sempre! :)\n");
                sleep(2);
                free(ptrProductsArray);
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
