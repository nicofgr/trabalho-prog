// https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html

#include <curses.h>
#include <stdlib.h>
#include <time.h>

// 8 colors for standard Curses
#define PALLETE_SIZE (COLOR_WHITE - COLOR_BLACK + 1)

// Estrutura com estado interno da aplicação
typedef struct gameData
{
    ///MENU INICIAL
    bool menuInicial;
    int telaMenuInicial;

    ///JOGO
    char nomePersonagem[50];
    bool devMode;
    int ultimaTecla;
    int colisao;
    int interacaoDisponivel;
    int interagir;

    struct pos{
        int x;
        int y;
    } posJogador;
    struct pos posMapa;
    struct pos posMapaAnterior;
    struct pos meioTela;

    char mapa[100][100];

} gameData;

//////////////////////////////////////////////////////////////////////
// Funções auxiliares para a biblioteca Curses
//////////////////////////////////////////////////////////////////////
void initScreen(int modo)
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

    if(modo){
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

    }else{
        echo();
        curs_set(1);
        nodelay(stdscr, FALSE);
        timeout(0);
    }
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
    int mx, my;
    getmaxyx(stdscr, my, mx);
    game->meioTela.x = mx/2;
    game->meioTela.y = my/2;

    game->posJogador.x = game->meioTela.x - game->posMapa.x;
    game->posJogador.y = game->meioTela.y - game->posMapa.y;

    game->posMapa.x = (game->meioTela.x) - 4;
    game->posMapa.y = (game->meioTela.y) - 1;

    game->posMapaAnterior.x = game->posMapa.x;
    game->posMapaAnterior.y = game->posMapa.y;

    game->ultimaTecla = -1;

    game->colisao = 0;
    game->interacaoDisponivel = 0;
    game->interagir = 0;

    game->menuInicial = FALSE; ///MUDAR AQUI PARA TESTE
    game->telaMenuInicial = 0;
    game->devMode = FALSE;
    LeMundo("Salas\\sala1.txt", game->mapa);
}

// Gerencia entradas do usuário e controla o estado interno em game
// Há diversas opções de teclas na Curses, como KEY_UP, KEY_DOWN, etc.
void handleInputs(gameData * game)
{
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
        case 'q':
            break;
        case 'Q':
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
            game->posJogador.x = game->meioTela.x - game->posMapa.x;
            game->posJogador.y = game->meioTela.y - game->posMapa.y;
            game->posMapa.x = (game->posJogador.x) - 12;
            game->posMapa.y = (game->posJogador.y) - 1;
            game->posMapaAnterior.x = game->posMapa.x;
            game->posMapaAnterior.y = game->posMapa.y;

            endwin();
            initScreen(1);
            clear();
            refresh();
            break;
    }
}

void doUpdate(gameData * game)
{
    game->posJogador.x = game->meioTela.x - game->posMapa.x;
    game->posJogador.y = game->meioTela.y - game->posMapa.y;

    DetectaColisoes(game->mapa, game->posJogador.x, game->posJogador.y, &game->colisao);

    if(game->colisao == 1){
        game->posMapa.x = game->posMapaAnterior.x;
        game->posMapa.y = game->posMapaAnterior.y;
    }

    game->posJogador.x = game->meioTela.x - game->posMapa.x;
    game->posJogador.y = game->meioTela.y - game->posMapa.y;

    //DetectaInteracoes(&game);
}

void drawScreen(gameData * game){

    clear();

    //TESTE
    game->interacaoDisponivel = DetectaInteracoes(game->mapa, game->posJogador.x, game->posJogador.y);

        setColor(COLOR_RED, COLOR_BLACK, A_BOLD);
    if(game->devMode){

        printw("Nome do personagem: %s\n", game->nomePersonagem);
        printw("Posicao jogador: (%d, %d)\n", game->posJogador.x, game->posJogador.y);
        printw("Posicao tela: (%d, %d)\n", game->posMapa.x, game->posMapa.y);
        printw("Posicao tela anterior: (%d, %d)\n", game->posMapaAnterior.x, game->posMapaAnterior.y);
        printw("Centro do terminal: (%d, %d)\n", game->meioTela.x, game->meioTela.y);
        printw("Colisao: %d\n", game->colisao);
        printw("Ultima tecla: %c\n", game->ultimaTecla);
    }else
        printw("Pressione F1 para mostrar informacoes do jogo.");

    //DESENHA JOGADOR
    setColor(COLOR_WHITE, COLOR_BLACK, A_BOLD);
    mvaddch(game->meioTela.y, game->meioTela.x, ACS_DIAMOND);

    //DESENHA MUNDO
    DesenhaMundo(game->posMapa.x, game->posMapa.y, game->posJogador.x, game->posJogador.y, game->mapa);
    //INTERACAO
    if(game->interagir && game->interacaoDisponivel){
        Dialogo(game->ultimaTecla, &game->interagir);
    }else{
        game->interagir = 0;
    }

    setColor(COLOR_WHITE, COLOR_BLACK, A_BOLD);
    if(game->interacaoDisponivel && !(game->interagir))
        printw("\n\nInteracao disponivel, pressione 'e' para interagir");


    /*
    // Exemplos de print na tela
    setColor(COLOR_BLACK, COLOR_WHITE, A_BOLD);
    printw("\nEngenharia de Computacao!\n");
    */
    // Exibe o conteúdo na tela (stdscr), getch() também ativa um refresh
    refresh();
}

int main(int argc, char *argv[])
{
    // estrutura com dados internos da aplicação
    gameData game;

    // inicializa a tela pelo Curses e o estado inicial da aplicação
    initScreen(1);
    initGame(&game);

    // Laço principal sem retorno, pode ser removido para exibição direta de informação na tela
	while(1)
    {
        // Gerencia entradas do usuário pelo teclado
        handleInputs(&game);

        // Gerencia lógica da aplicação
        doUpdate(&game);

        // Atualiza a tela
        if(game.menuInicial)
            MenuInicial(&game);
        else
            drawScreen(&game);

        // Controla o FPS da aplicação
        napms(10);
    }

    // Encerra a tela inicializada em initScreen
    endwin();

	return 0;
}
