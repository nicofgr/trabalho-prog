// https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html
#include <stdlib.h>
#include <time.h>
#include "APSLib/APSLib.h"

int main(int argc, char *argv[]){

    gameData game;  // estrutura com dados internos da aplicação

    initScreen(GAME); // inicializa a tela pelo Curses e o estado inicial da aplicação
    initGame(&game);

	while(1){ // Laço principal sem retorno, pode ser removido para exibição direta de informação na tela

        handleInputs(&game);  // Gerencia entradas do usuário pelo teclado

        doUpdate(&game); // Gerencia lógica da aplicação

        if(game.menuInicial){
            drawScreen(&game, MENU); // Atualiza a tela
        }else{
            drawScreen(&game, GAME);
        }

        napms(10); // Controla o FPS da aplicação
    }

    endwin(); // Encerra a tela inicializada em initScreen

	return 0;
}
