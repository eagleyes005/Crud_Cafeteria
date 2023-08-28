#include "global.h"

//Fun��o para deleter produtos
void deleteProduct(int productType) {
    FILE *file;
    char filename[20];
    int lotToDelete;

    if (productType == 1) {
        strcpy(filename, "data1.bin");
    } else if (productType == 2) {
        strcpy(filename, "data2.bin");
    }

    file = fopen(filename, "rb"); //Abrir o arquivo data em modo de leitura

    printf("Digite o n�mero do lote para excluir: ");
    scanf("%d", &lotToDelete); //NOLINT(cert-err34-c) <- remove o aviso do "scanf"

    FILE* tempFile = fopen("temp.bin", "wb"); //Abrir o arquivo data em modo de escrita
    if (tempFile == NULL) {
        printf("Erro ao criar arquivo tempor�rio!\n");
        fclose(file);
        return;
    }

    //Loop para copiar os dados para o arquivo tempor�rio
    productStruct product;
    while (fread(&product, sizeof(product), 1, file) == 1) {
        if (product.lot != lotToDelete) {
            fwrite(&product, sizeof(product), 1, tempFile);
        }
    }

    //Fecha os arquivos
    fclose(file);
    fclose(tempFile);

    //Remove o arquivo original
    remove(filename);

    //Renomeia o arquivo tempor�rio para o nome do arquivo original
    rename("temp.bin", filename);

    printf("Produto exclu�do com sucesso!\n");
    sleep(2);
}