#include "global.h"
//TODO adicionar verificar de duplicidade
//TODO adicionar aloca��o din�mica de mem�ria

//Fun��o para registrar produtos
void registerProduct (int *currentIndex, productStruct *productsArray) {
    productStruct newProduct; // � criado uma nova struct de tipo productStruct
    newProduct.cod = *currentIndex + 1;
    printf("Insira o nome do produto:\n");
    scanf("%49s", newProduct.name);
    printf("Insira o valor unit�rio do produto:\n");
    scanf("%f", &newProduct.price);
    printf("Insira a quantidade em estoque do produto:\n");
    scanf("%d", &newProduct.amount);

    // Ap�s inserir os dados da nova struct a mesma � atribu�da ao �ndice corrente do array
    productsArray[*currentIndex] = newProduct;
    (*currentIndex)++; // Pula para o pr�ximo �ndice
    printf("Produto cadastrado com sucesso!");
    sleep(2);
}
