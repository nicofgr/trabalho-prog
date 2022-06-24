#include "APSLib.h"

/// Funções auxiliares para a biblioteca Curses
void initScreen(screenMode){
#ifdef XCURSES
    Xinitscr(argc, argv);
#else
    initscr();
#endif

    if (has_colors())
    {
        int bg = 0, fg = 0;

        start_color();

        for(bg = COLOR_BLACK; bg <= COLOR_WHITE; bg++)
            for(fg = COLOR_BLACK; fg <= COLOR_WHITE; fg++)
                init_pair(bg*PALLETE_SIZE + fg + 1, fg, bg); // color 0 is system default (reserved)
    }

    switch(screenMode){
        case MENU:
            echo();
            curs_set(1);
            nodelay(stdscr, FALSE);
            timeout(0);
            break;

        case GAME:
            // Trata a tecla Enter como \n
            //nl();
            // Teclas digitadas pelo usuário não aparecem na tela
            noecho();
            // 0 para cursor invisível
            curs_set(0);
            // Define getch como non-blocking de acordo com o timeout abaixo
            nodelay(stdscr, TRUE);
            // Timeout em 0 determina getch como non-blocking, não espera entrada do usuário
            timeout(0);
            break;
    }

    // Habilita teclas de function (F1, F2, ...), flechas, etc
    keypad(stdscr, TRUE);
}

void setColor(short int fg, short int bg, chtype attr){

    chtype color = COLOR_PAIR(bg*PALLETE_SIZE + fg + 1);
    color |= attr;
    attrset(color);
}


/// Funções da aplicação
void initGame(gameData * game){

    int mx, my;
    getmaxyx(stdscr, my, mx);
    game->meioTela.x = mx/2;
    game->meioTela.y = my/2;

    strcpy(game->nomePersonagem, "%s");
    game->posJogador.x = game->meioTela.x - game->posMapa.x;
    game->posJogador.y = game->meioTela.y - game->posMapa.y;

    ///Define pos inicial
    LeDados(game);

    game->posMapaAnterior.x = game->posMapa.x;
    game->posMapaAnterior.y = game->posMapa.y;

    game->ultimaTecla = -1;

    game->colisao = 0;
    game->interacaoDisponivel = 0;
    game->interagir = 0;

    game->menuInicial = TRUE; ///MUDAR AQUI PARA TESTE
    game->telaMenuInicial = 0;
    game->devMode = FALSE;
    LeMundo("Salas\\sala1.txt", game);
}

// Gerencia entradas do usuário e controla o estado interno em game
// Há diversas opções de teclas na Curses, como KEY_UP, KEY_DOWN, etc.
void handleInputs(gameData * game){

    int entrada = getch();
    int mx, my;

    if(entrada != -1)
        game->ultimaTecla = entrada;

    switch(entrada)
    {
        case 'w': //CIMA
            game->posMapaAnterior = game->posMapa;
            game->posMapa.y += 1;
            break;
        case 'a': //ESQUERDA
            game->posMapaAnterior = game->posMapa;
            game->posMapa.x += 1;
            break;
        case 's': //BAIXO
            game->posMapaAnterior = game->posMapa;
            game->posMapa.y -= 1;
            break;
        case 'd': //DIREITA
            game->posMapaAnterior = game->posMapa;
            game->posMapa.x -= 1;
            break;
        case 'e':
            if(game->interacaoDisponivel)
                game->interagir = 1;
            break;
        case 'f':
            if(game->interacaoDisponivel == 4)
                Dialogo(game->ultimaTecla, &game->interagir, 6, game);
            break;
        case 'q':
            SalvaDados(game);
            break;
        case 'Q':
            for (int i = 0; i < game->nMaxLin - 1; i++)
                free(game->gameMap[i]);
            free(game->gameMap);
            curs_set(1);
            endwin();
            exit(EXIT_SUCCESS);
            break;
        case KEY_F(1):
            game->devMode -= 1;
            break;
        case '\n':
            if(game->menuInicial)
                game->telaMenuInicial = 1;
            break;
        case KEY_RESIZE:
            // Finaliza a tela atual e cria uma nova
            getmaxyx(stdscr, my, mx);
            game->meioTela.x = mx/2;
            game->meioTela.y = my/2;

            game->posMapa.x = game->meioTela.x - game->posJogador.x;
            game->posMapa.y = game->meioTela.y - game->posJogador.y;

            game->posMapaAnterior.x = game->posMapa.x;
            game->posMapaAnterior.y = game->posMapa.y;
            endwin();
            initScreen(1);
            clear();
            refresh();
            break;
    }
}

void doUpdate(gameData * game){

    game->posJogador.x = game->meioTela.x - game->posMapa.x;
    game->posJogador.y = game->meioTela.y - game->posMapa.y;

    DetectaColisoes(game->mapa, game->posJogador.x, game->posJogador.y, &game->colisao);

    if(game->colisao == 1){
        game->posMapa.x = game->posMapaAnterior.x;
        game->posMapa.y = game->posMapaAnterior.y;
    }

    game->posJogador.x = game->meioTela.x - game->posMapa.x;
    game->posJogador.y = game->meioTela.y - game->posMapa.y;

    game->interacaoDisponivel = DetectaInteracoes(game->interactionMap, game->posJogador.x, game->posJogador.y);
}

void drawScreen(gameData * game, enum screenMode screenMode){

    clear();

    switch(screenMode){
        case MENU:
            MainMenu(game);
            break;
        case GAME:
            Overworld(game);
            break;
    }

    refresh();
}
