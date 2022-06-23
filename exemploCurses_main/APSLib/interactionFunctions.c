#include "APSLib.h"


int DetectaInteracoes(char mapa[100][100], int x, int y){

    char cima = mapa[y-1][x];
    char baixo = mapa[y+1][x];
    char esquerda =  mapa[y][x-1];
    char direita = mapa[y][x+1];

    printw("DetectaInteracoes\n");
    printw(" Cima: %c\n", cima);
    printw(" Baixo: %c\n", baixo);
    printw(" Esquerda: %c\n", esquerda);
    printw(" Direita: %c\n", direita);

    switch(cima){
        case '1':
            printw("Prefeito detectado\n");
            return 1;
            break;
        case '2':
            printw("Mordomo detectado\n");
            return 2;
            break;
        case '3':
            printw("Professor detectado\n");
            return 3;
            break;
        case '4':
            printw("Policial detectado\n");
            return 4;
            break;
        case '5':
            printw("Corpo detectado\n");
            return 5;
            break;
    }
    switch(baixo){
        case '1':
            printw("Prefeito detectado\n");
            return 1;
            break;
        case '2':
            printw("Mordomo detectado\n");
            return 2;
            break;
        case '3':
            printw("Professor detectado\n");
            return 3;
            break;
        case '4':
            printw("Policial detectado\n");
            return 4;
            break;
        case '5':
            printw("Corpo detectado\n");
            return 5;
            break;
    }
    switch(esquerda){
        case '1':
            printw("Prefeito detectado\n");
            return 1;
            break;
        case '2':
            printw("Mordomo detectado\n");
            return 2;
            break;
        case '3':
            printw("Professor detectado\n");
            return 3;
            break;
        case '4':
            printw("Policial detectado\n");
            return 4;
            break;
        case '5':
            printw("Corpo detectado\n");
            return 5;
            break;
    }
    switch(direita){
        case '1':
            printw("Prefeito detectado\n");
            return 1;
            break;
        case '2':
            printw("Mordomo detectado\n");
            return 2;
            break;
        case '3':
            printw("Professor detectado\n");
            return 3;
            break;
        case '4':
            printw("Policial detectado\n");
            return 4;
            break;
        case '5':
            printw("Corpo detectado\n");
            return 5;
            break;
    }

    return 0;
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
