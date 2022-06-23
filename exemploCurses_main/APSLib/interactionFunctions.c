#include "APSLib.h"


int DetectaInteracoes(int interactionMap[100][100], int x, int y){

    int cima = interactionMap[y-1][x];
    int baixo = interactionMap[y+1][x];
    int esquerda =  interactionMap[y][x-1];
    int direita = interactionMap[y][x+1];

    printw("DetectaInteracoes\n");
    printw(" Cima: %d\n", cima);
    printw(" Baixo: %d\n", baixo);
    printw(" Esquerda: %d\n", esquerda);
    printw(" Direita: %d\n", direita);

    return cima + baixo + esquerda + direita;

}

void Dialogo(int a, int *interagir){

    setColor(COLOR_GREEN, COLOR_BLACK, A_BOLD);
    printw("\n");

    switch(a){
        case '1':
            printw("\n - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            printw(" >> Sobre o assassinato da minha esposa.\n");
            printw(" - Eu nao sei de nada!\n");
            printw(" - Mas saiba que no que eu puder ajudar eu irei. \n");
            printw("--------------------------------------------------\n");
            printw(" > 2 - Como o Prefeito esta?  \n > 3 - Sair.");
            break;

        case '2':
            printw("\n - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            printw(" >> Como o Prefeito esta? \n");
            printw(" - Estou bem, fora os acontecimentos dessa noite que me deixaram meio assustado, estou bem \n");
            printw("--------------------------------------------------\n");
            printw(" > 1 - Assassinato da minha esposa \n > 3 - Sair.");
            break;

        case '3':
            *interagir = 0;
            break;

        default:
            printw("\n - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            printw("--------------------------------------------------\n");
            printw(" > 1 - Assassinato da minha esposa \n > 2 - Como o Prefeito esta?  \n > 3 - Sair.");
            break;
    }

}
