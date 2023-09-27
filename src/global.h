// Arquivo Header com todas as bibliotecas utilizadas globalmente
// Início da biblioteca GLOBAL.H
#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <time.h>

#define MAX_LENGTH 30
#include "colorCodes.c"

// Define um tipo de struct para produtos
typedef struct {
    int idProduct;
    char name[MAX_LENGTH];
    float price;
    int amount;
} productStruct;

// Define um tipo de struct para pedidos
typedef struct {
    int idOrder;
    char costumerName[MAX_LENGTH];
    productStruct products[10]; // Array de productStruct
    int qtyItem; // Número atual de produtos na lista
} orderStruct;

// Sub-bibliotecas
#include "products/products.h"
#include "orders/orders.h"
#include "menus/menus.h"

#endif
// Fim da biblioteca GLOBAL.H