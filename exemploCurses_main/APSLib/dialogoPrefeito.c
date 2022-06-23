#include "APSLib.h"

void Prefeito(int ultimaTecla, int *interagir, gameData * game){

    setColor(COLOR_GREEN, COLOR_BLACK, A_BOLD);

    switch(ultimaTecla){
        default:
            mvprintw(game->meioTela.y + 10, 0," - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            mvprintw(game->meioTela.y + 11, 0,"--------------------------------------------------\n");
            mvprintw(game->meioTela.y + 12, 0," > 1 - Assassinato da minha esposa \n > 2 - Como o Prefeito esta?  \n > 3 - Sair.");
            break;
        case '1':
            mvprintw(game->meioTela.y + 10, 0, " - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            mvprintw(game->meioTela.y + 11, 0," >> Sobre o assassinato da sua esposa.\n");
            mvprintw(game->meioTela.y + 12, 0," - Eu nao sei de nada!\n");
            mvprintw(game->meioTela.y + 13, 0," - Mas saiba que no que eu puder ajudar eu irei. \n");
            mvprintw(game->meioTela.y + 14, 0,"--------------------------------------------------\n");
            mvprintw(game->meioTela.y + 15, 0," > 2 - Como o Prefeito esta?  \n > 3 - Sair.");
            break;

        case '2':
            printw(" - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            printw(" >> Como o Prefeito esta? \n");
            printw(" - Estou bem, fora os acontecimentos dessa noite que me deixaram meio assustado, estou bem \n");
            printw("--------------------------------------------------\n");
            printw(" > 1 - Assassinato da minha esposa \n > 3 - Sair.");
            break;

        case '3':
            *interagir = 0;
            break;
    }


}
