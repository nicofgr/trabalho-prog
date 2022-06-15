#include<stdio.h>
#include <stdlib.h>
#include <curses.h>


void MostraImagem (char *nomeArquivo){

    FILE *arquivo = fopen(nomeArquivo, "r");

    int tamArquivo;
    char atual;

    fseek(arquivo, 0, SEEK_END);
    tamArquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    for (int i = 0; i < 2260; i++){
        fscanf(arquivo, "%c", &atual);
        printw("%c", atual);
    }


}
