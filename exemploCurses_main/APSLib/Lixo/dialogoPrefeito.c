#include "APSLib.h"

void Prefeito(gameData * game){

    setColor(COLOR_GREEN, COLOR_BLACK, A_BOLD);

    switch(game->ultimaTecla){
        default:
            mvprintw(game->meioTela.y + 5, 0," - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?");
            mvprintw(game->meioTela.y + 6, 0,"--------------------------------------------------");
            mvprintw(game->meioTela.y + 7, 0," > 1 - Assassinato da sua esposa \n > 2 - Como o Prefeito esta?  \n > 3 - Sair.");
            break;
        case '1':
            mvprintw(game->meioTela.y + 5, 0, " - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?");
            mvprintw(game->meioTela.y + 6, 0," >> Sobre o assassinato da sua esposa.");
            mvprintw(game->meioTela.y + 7, 0," - Eu nao sei de nada!");
            mvprintw(game->meioTela.y + 8, 0," - Mas saiba que no que eu puder ajudar eu irei. ");
            mvprintw(game->meioTela.y + 9, 0,"--------------------------------------------------");
            mvprintw(game->meioTela.y + 10, 0," > 2 - Como o Prefeito esta?  \n > 3 - Sair.");
            break;

        case '2':
            mvprintw(game->meioTela.y + 5, 0," - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            mvprintw(game->meioTela.y + 6, 0," >> Como o Prefeito esta? \n");
            mvprintw(game->meioTela.y + 7, 0," - Estou bem, fora os acontecimentos dessa noite que me deixaram meio assustado, estou bem \n");
            mvprintw(game->meioTela.y + 8, 0,"--------------------------------------------------\n");
            mvprintw(game->meioTela.y + 9, 0," > 1 - Assassinato da sua esposa \n > 3 - Sair.");
            break;

        case '3':
            game->interagir = 0;
            break;
    }

    ///BORDA SUPERIOR
    for(int col = 0; col <= (game->meioTela.x * 2); col++)
        mvaddch(game->meioTela.y + 4, col, ACS_BOARD);


}
