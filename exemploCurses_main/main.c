// https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html
#include <stdlib.h>
#include <time.h>
#include "APSLib/APSLib.h"

int main(int argc, char *argv[])
{
    // estrutura com dados internos da aplicação
    gameData game;

    // inicializa a tela pelo Curses e o estado inicial da aplicação
    initScreen(GAME);
    initGame(&game);

    // Laço principal sem retorno, pode ser removido para exibição direta de informação na tela
	while(1)
    {
        // Gerencia entradas do usuário pelo teclado
        handleInputs(&game);

        // Gerencia lógica da aplicação
        doUpdate(&game);

        // Atualiza a tela
        if(game.menuInicial){
            drawScreen(&game, MENU);
        }else{
            drawScreen(&game, GAME);
        }

        // Controla o FPS da aplicação
        napms(10);
    }

    // Encerra a tela inicializada em initScreen
    endwin();

	return 0;
}
