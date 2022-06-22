/*NOME: Nicolas Ferreira Gruenwaldt Ribeiro
  RA: 2036339

  ATIVIDADE:
  Escreva um programa utilizando a biblioteca Curses para realizar a conversão de valores binários para decimais.

  O programa deverá apresentar um campo gráfico para preenchimento de valores binários e outro campo para apresentação
  do valor convertido para decimal. A cada valor binário preenchido, o campo decimal deverá ser atualizado.

*/
// https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html

#include <curses.h>
#include <stdlib.h>
#include <time.h>

// 8 colors for standard Curses
#define PALLETE_SIZE (COLOR_WHITE - COLOR_BLACK + 1)


typedef struct operacaoBinaria{

    bool sinal;
    unsigned long int numero;
    char operacao;
    int posicao;

} operacaoBinaria;


// Estrutura com estado interno da aplicação
typedef struct gameData
{
    operacaoBinaria dados;
    unsigned int pointPos;
    unsigned int pointBit;
    unsigned int bitNaPos;

    int ultimaTecla;

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
    game->dados.sinal = FALSE;
    game->dados.numero = 2;
    game->pointPos = 64;
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
        case KEY_LEFT:
            if(game->pointPos > 2)
                game->pointPos -= 2;
            break;
        case KEY_RIGHT:
            if(game->pointPos < 64)
                game->pointPos += 2;
            break;
        case KEY_UP:
            if(game->dados.numero < 4294967295)
                if(!(game->bitNaPos == -1))
                    game->dados.numero += (1<<game->pointBit);
            break;
        case KEY_DOWN:
            if((game->dados.numero > 0) && ((game->dados.numero>>(32-(game->pointPos/2))) > 0))
                game->dados.numero -= (1<<game->pointBit);
            break;
        case 's':
            game->dados.sinal = 1 - game->dados.sinal;
            break;
        case 'q':
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
    game->pointBit = (32-(game->pointPos/2));
    game->bitNaPos = game->dados.numero>>game->pointBit;

}

void drawScreen(gameData * game)
{
    clear();

    // Exemplos de print na tela
    setColor(COLOR_GREEN, COLOR_BLACK, A_BOLD);
    printw("CONVERSOR BINARIO -> DECIMAL\n");

    printw("\t\t\t\t\t\t\t\t     NUMERO DECIMAL: ");


    //Bits do numero
    printw("\n  ");
    for(int i = 0; i <= 31; i++){
        int bitAtual = (game->dados.numero)>>(31-i);
        if((bitAtual %2) == 0 ) //Se o bit for 0
            printw("0 ");
        else
            printw("1 ");
    }


    if(game->dados.sinal == TRUE){
        printw("         %ld", game->dados.numero);
        printw("\n\n\nUsando: Signed Long Int (32 bits)(Bit mais significativo representa sinal)\n");
        printw("Pressione 's' para trocar\n");
    }else{
        printw("         %lu", game->dados.numero);
        printw("\n\n\nUsando: Unsigned Long Int (32 bits)\n");
        printw("Pressione 's' para trocar\n");
    }
    printw("Posicao do cursor: %d\n", game->pointBit);
    printw("Valor a partir dessa posicao: %ld\n", game->bitNaPos);


    // Bordas
    for(int i = 0; i < 67; i++){
        setColor(COLOR_GREEN, COLOR_BLACK, 0);
        mvaddch(1, i, ACS_BOARD);
        mvaddch(3, i, ACS_BOARD);
    }
    mvaddch(2, 0, ACS_BOARD);
    mvaddch(2, 66, ACS_BOARD);
    for(int i = 0; i < 66; i+=2){
        setColor(COLOR_GREEN, COLOR_BLACK, 0);
        mvaddch(2, i+1, ACS_BOARD);
        mvaddch(2, i+1, ACS_BOARD);
    }


    //CURSOR
    setColor(COLOR_GREEN, COLOR_BLACK, 0);
    mvaddch(3, game->pointPos, ACS_UARROW);



    /*if(game->ultimaTecla != -1)
        printw("\n\nUltima tecla: %d", game->ultimaTecla);*/

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
