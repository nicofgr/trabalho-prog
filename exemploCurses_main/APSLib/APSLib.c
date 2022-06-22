#include<stdio.h>
#include<curses.h>
#include "APSLib.h"

void DesenhaSala(){

    FILE* arquivo = fopen("Salas\\sala1.txt", "r");

    //fgets vai retornar null no final do arquivo
    char teste[100];
    int lin = 0;

    while(fgets(teste, 100, arquivo)){

        for(int col = 0; col < 20; col++){ //COLUNA
            if(teste[col] == 'x'){
                setColor(COLOR_BLACK, COLOR_WHITE, A_BOLD);
                mvaddch(lin, col, ACS_BLOCK);
            }
            if(teste[col] == '@'){
                setColor(COLOR_GREEN, COLOR_BLACK, 0);
                mvaddch(lin, col, ACS_DIAMOND);
            }
        }

        lin++;
    }

    fclose(arquivo);
}

void DetectaColisoes(int colisoes [100][100]){

    FILE* arquivo = fopen("Salas\\sala1.txt", "r");

    //fgets vai retornar null no final do arquivo
    char teste[100];
    int lin = 0;

    while(fgets(teste, 100, arquivo)){

        for(int col = 0; col < 20; col++){ //COLUNA
            if(teste[col] != ' '){
                colisoes[lin][col] = 1;
            }
        }

        lin++;
    }

    fclose(arquivo);
}

int DetectaInteracoes(int x, int y){

    int interacoes[100][100] = {0};
    FILE* arquivo = fopen("Salas\\sala1.txt", "r");

    //fgets vai retornar null no final do arquivo
    char teste[100];
    int lin = 0;

    while(fgets(teste, 100, arquivo)){

        for(int col = 0; col < 20; col++){ //COLUNA
            if(teste[col] == '@'){
                interacoes[lin][col] = 1;
            }
        }

        lin++;
    }

    fclose(arquivo);

    if(interacoes[y+1][x] || interacoes[y-1][x] || interacoes[y][x+1] || interacoes[y][x-1]){
        return 1;
    }else
        return 0;
}

void Dialogo(int a, int *interagir){

    setColor(COLOR_GREEN, COLOR_BLACK, A_BOLD);

    switch(a){
        case '1':
            printw("\n - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            printw(" >> ah, sobre o assassinato da sua mulher ?\n");
            printw(" - Eu nao sei de nada!\n");
            printw(" - Mas saiba que no que eu puder ajudar eu irei \n");
            printw("--------------------------------------------------\n");
            printw(" > 2 - Como o Prefeito esta  \n > 3 - sair.");
            break;

        case '2':
            printw("\n - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            printw(" >> Como o Prefeito esta? \n");
            printw(" - Estou bem, fora os acontecimentos dessa noite que me deixaram meio assustado, estou bem \n");
            printw("--------------------------------------------------\n");
            printw(" > 1 - Assassinato da sua mulher \n > 3 - sair.");
            break;

        case '3':
            *interagir = 0;
            break;

        default:
            printw("\n - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            printw("--------------------------------------------------\n");
            printw(" > 1 - Assassinato da sua mulher \n > 2 - Como o Prefeito esta  \n > 3 - sair.");
            break;
    }

}
