#include "global.h"

//Função para editar produtos
void editProduct(int productType) {
    FILE *file;
    char filename[20];
    int lotToEdit, dataToEdit;

    if (productType == 1) {
        strcpy(filename, "data1.bin");
    } else if (productType == 2) {
        strcpy(filename, "data2.bin");
    }

    file = fopen(filename, "r+b"); //Abrir o arquivo data em modo de leitura

    printf("Digite o número do lote para editar: ");
    scanf("%d", &lotToEdit); //NOLINT(cert-err34-c) <- remove o aviso do "scanf"

    //Encontrar o lote do produto para editar
    productStruct product; // Declaração da variável product

    // Loop para procurar o produto com o número do lote a ser editado
    int found = 0; // Variável para verificar se o produto foi encontrado
    while (fread(&product, sizeof(product), 1, file) == 1) {
        if (product.lot == lotToEdit) {
            found = 1; // O produto foi encontrado
            break;
        }
    }

    //Menu para escolher o que deseja editar

    if (found) {
        printf("\n1 - Lote\n");
        printf("2 - Data de produção\n");
        printf("3 - Tipo\n");
        printf("4 - Quantidade\n");
        printf("0 - Cancelar\n");
        printf("Digite o que deseja editar: ");
        scanf("%d", &dataToEdit); //NOLINT(cert-err34-c) <- remove o aviso do "scanf"

        switch (dataToEdit) {
            case 1:
                printf("Digite o novo número do lote: ");
                scanf("%d", &product.lot); //NOLINT(cert-err34-c) <- remove o aviso do "scanf"
                break;

            case 2:
                printf("Digite a nova data de produção: ");
                scanf("%s", product.production);
                break;

            case 3:
                printf("Digite o novo tipo do produto: ");
                scanf("%s", product.type);
                break;

            case 4:
                printf("Digite a nova quantidade: ");
                scanf("%d", &product.amount); //NOLINT(cert-err34-c) <- remove o aviso do "scanf"
                break;

            case 0:
                printf("Voltando...\n");
                sleep(2);
                fclose(file);
                break;

            default:
                printf("Opção inválida!");
                sleep(2);
                break;
        }

        // Posicione o ponteiro do arquivo na posição correta para atualizar o produto
        fseek(file, -sizeof(product), SEEK_CUR);
        fwrite(&product, sizeof(product), 1, file);
        fclose(file);

        printf("Produto editado com sucesso!\n");
        sleep(2);
    } else {
        printf("Número do lote não encontrado!\n");
        sleep(2);
        fclose(file);
    }
}
