//Arquivo Header com todas as bibliotecas utilizadas globalmente
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <time.h>

//Início da biblioteca GLOBAL.H
#ifndef GLOBAL_H
#define GLOBAL_H

#define MAX_LENGTH 30

//Define um tipo de struct denominado productStruct
typedef struct {
    int cod;
    char name[MAX_LENGTH];
    float price;
    int amount;
} productStruct;

#include "listProduct.c"
#include "registerProduct.c"
#include "editProduct.c"
#include "deleteProduct.c"
#endif
//Fim da biblioteca GLOBAL.H