// https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html

#include <curses.h>
#include <stdlib.h>
#include <time.h>

// 8 colors for standard Curses
#define PALLETE_SIZE (COLOR_WHITE - COLOR_BLACK + 1)

// Estrutura com estado interno da aplicação
typedef struct gameData
{
    int ultimaTecla;
    int colisao;
    int interacao;
    int interagir;

    struct pos{
        int x;
        int y;
    } posAtual;

    struct pos posAnterior;

} gameData;

//////////////////////////////////////////////////////////////////////
// Funções auxiliares para a biblioteca Curses
//////////////////////////////////////////////////////////////////////
void initScreen()
{
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
    // Habilita teclas de function (F1, F2, ...), flechas, etc
    keypad(stdscr, TRUE);
}

void setColor(short int fg, short int bg, chtype attr)
{
    chtype color = COLOR_PAIR(bg*PALLETE_SIZE + fg + 1);
    color |= attr;
    attrset(color);
}


//////////////////////////////////////////////////////////////////////
// Funções da aplicação
//////////////////////////////////////////////////////////////////////
void initGame(gameData * game)
{
    game->ultimaTecla = -1;
    game->posAtual.x = 5;
    game->posAtual.y = 5;
    game->posAnterior.x = 5;
    game->posAnterior.y = 5;
    game->colisao = 0;
    game->interacao = 0;
    game->interagir = 0;
}

// Gerencia entradas do usuário e controla o estado interno em game
// Há diversas opções de teclas na Curses, como KEY_UP, KEY_DOWN, etc.
void handleInputs(gameData * game)
{
    int entrada = getch();

    if(entrada != -1)
        game->ultimaTecla = entrada;


    switch(entrada)
    {
        case 'w': //CIMA
            game->posAnterior = game->posAtual;
            game->posAtual.y -= 1;
            break;
        case 'a': //ESQUERDA
            game->posAnterior = game->posAtual;
            game->posAtual.x -= 1;
            break;
        case 's': //BAIXO
            game->posAnterior = game->posAtual;
            game->posAtual.y += 1;
            break;
        case 'd': //DIREITA
            game->posAnterior = game->posAtual;
            game->posAtual.x += 1;
            break;
        case 'e':
            if(game->interacao)
                game->interagir = 1;
            break;
        case 'q':
            break;
        case 'Q':
            curs_set(1);
            endwin();
            exit(EXIT_SUCCESS);
            break;
        case KEY_RESIZE:
            // Finaliza a tela atual e cria uma nova
            endwin();
            initScreen();
            clear();
            refresh();
            break;
    }
}

void doUpdate(gameData * game)
{
    int colisoes[100][100];

    game->interacao = DetectaInteracoes(game->posAtual.x, game->posAtual.y);

    DetectaColisoes(colisoes);

    if(colisoes[game->posAtual.y][game->posAtual.x] == 1)
        game->colisao = 1;
    else
        game->colisao = 0;

    if(game->colisao == 1)
        game->posAtual = game->posAnterior;

}

void drawScreen(gameData * game)
{

    clear();

    //DESENHA JOGADOR
    setColor(COLOR_WHITE, COLOR_BLACK, 0);
    mvaddch(game->posAtual.y, game->posAtual.x, ACS_DIAMOND);

    DesenhaSala();

    if(game->colisao == 1){
        setColor(COLOR_WHITE, COLOR_RED, A_BOLD);
        printw("COLISAO");
    }

    if(game->interacao)
        printw("Interacao disponivel, pressione 'e' para interagir");

    if(game->interagir && game->interacao){
        Dialogo(game->ultimaTecla, &game->interagir);
    }

    setColor(COLOR_WHITE, COLOR_BLACK, 0);
    printw("\n\n\n\n\n\n\n\n\n\n");
    printw("Posicao: x:%d y:%d\n", game->posAtual.x, game->posAtual.y);
    printw("PosicaoAnterior: x:%d y:%d\n", game->posAnterior.x, game->posAnterior.y);

    /*
    // Exemplos de print na tela
    setColor(COLOR_BLACK, COLOR_WHITE, A_BOLD);
    printw("\nEngenharia de Computacao!\n");
    */

    if(game->ultimaTecla != -1)
        printw("Ultima tecla: %c", game->ultimaTecla);


    // Exibe o conteúdo na tela (stdscr), getch() também ativa um refresh
    refresh();
}

int main(int argc, char *argv[])
{
    // estrutura com dados internos da aplicação
    gameData game;

    // inicializa a tela pelo Curses e o estado inicial da aplicação
    initScreen();
    initGame(&game);

    // Laço principal sem retorno, pode ser removido para exibição direta de informação na tela
	while(1)
    {
        // Gerencia entradas do usuário pelo teclado
        handleInputs(&game);

        // Gerencia lógica da aplicação
        doUpdate(&game);

        // Atualiza a tela
        drawScreen(&game);

        // Controla o FPS da aplicação
        napms(10);
    }

    // Encerra a tela inicializada em initScreen
    endwin();

	return 0;
}
