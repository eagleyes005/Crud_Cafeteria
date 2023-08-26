#include "global.h"
#include "functions.c"

int main() {
    setlocale(LC_ALL, "Portuguese");
    int running = 1;
    while (running == 1) {
        int selector, *ptrSelector;
        ptrSelector = &selector;

        system("cls"); //Limpeza do terminal

        //Menu principal
        printf("Bem vindo ao sistema de cadastro de queijos e vinhos!\n\n");

        printf("-------------- MENU --------------\n");
        printf("1 - Consultar Produtos\n");
        printf("2 - Cadastrar Novo Produto\n");
        printf("3 - Editar Produto\n");
        printf("4 - Excluir Produto\n");
        printf("0 - Sair\n\n");
        printf("Selecione a opção desejada:\n");
        scanf("%d", ptrSelector); //NOLINT(cert-err34-c)
        system("cls");


        switch (*ptrSelector)
        {
                //Case para cadastrar produtos
            case 1:
                registerProduct();
                break;

                //Case para listar produtos
            case 2:
                listProduct();
                break;

                //Case para editar produtos
            case 3:
                editProduct();
                break;

                //Case para excluir produtos
            case 4:
                deleteProduct();
                break;

                //Case para encerrar o programa
            case 0:
                printf("Saindo... volte sempre! :)\n");
                sleep(2);
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
