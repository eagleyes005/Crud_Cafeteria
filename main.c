#include "global.h"

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Cria��o do array para receber os produtos antes do sistema entrar em loop
    int productsQty = 100, *ptrProductsQty, currentIndex = 0, *ptrCurrentIndex;
    ptrProductsQty = &productsQty;
    ptrCurrentIndex = &currentIndex;

    // Aloca mem�ria dinamicamente para o array de estruturas
    productStruct *ptrProductsArray = (productStruct *)malloc(*ptrProductsQty * sizeof(productStruct));

    // Se n�o conseguir alocar dar� erro antes de iniciar o sistema
    if (ptrProductsArray == NULL) {
        printf("Falha na aloca��o de mem�ria.\n");
        return 1; // Sa�da do programa com erro
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
        printf("Selecione a op��o desejada:\n");
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
                    printf("N�o h� produtos para serem editados!\n");
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
                    printf("N�o h� produtos para serem exclu�dos!\n");
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

                //Case de op��o inv�lida
            default:
                printf("Op��o inv�lida!");
                sleep(2);
                break;
        } //End Switch
    }
}
