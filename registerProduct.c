#include "global.h"
//TODO adicionar verificar de duplicidade
//TODO adicionar alocação dinâmica de memória

//Função para registrar produtos
void registerProduct (int *currentIndex, productStruct *productsArray) {
    productStruct newProduct; // É criado uma nova struct de tipo productStruct
    newProduct.cod = *currentIndex + 1;
    printf("Insira o nome do produto:\n");
    scanf("%49s", newProduct.name);
    printf("Insira o valor unitário do produto:\n");
    scanf("%f", &newProduct.price);
    printf("Insira a quantidade em estoque do produto:\n");
    scanf("%d", &newProduct.amount);

    // Após inserir os dados da nova struct a mesma é atribuída ao índice corrente do array
    productsArray[*currentIndex] = newProduct;
    (*currentIndex)++; // Pula para o próximo índice
    printf("Produto cadastrado com sucesso!");
    sleep(2);
}
