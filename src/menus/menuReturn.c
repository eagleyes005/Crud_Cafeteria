// Função para retornar após consulta
void menuReturn() {
    char returnTrigger[10];
    printf("\n");
    printf(BBLK "Insira algo para voltar\n" COLOR_RESET);
    scanf("%s", returnTrigger);
    getchar(); // Consumir o caractere de nova linha restante no buffer de entrada

    system("cls");
    printf(BBLK "Voltando...\n" COLOR_RESET);
    sleep(2);
}