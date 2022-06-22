#include <curses.h>
#include <stdlib.h>
#include <time.h>
#define PALLETE_SIZE (COLOR_WHITE - COLOR_BLACK + 1)

typedef struct gameData  ///NESSA STRUCT FICAM AS VARIAVEIS (SEM VALOR ATRIBUIDO, VER FUNCAO initGame PARA ATRIBUIR VALORES)
{
    int numero; //Numero inteiro

    unsigned int pointPos; //Posicao do cursor na tela
    unsigned int pointLine; //Linha do ponteiro na tela

    int ultimaTecla;

} gameData;

void initGame(gameData * game)  ///ESSA FUNCAO DEFINE O VALOR >>INICIAL<< DAS VARIAVEIS (SO EH CHAMADA UMA VEZ, NO INICIO DO PROGRAMA)
{
    game->ultimaTecla = -1;

    game->numero = 0; //Valor inicial do numero inteiro
    game->pointLine = 0; //Posicao (coluna) inicial do ponteiro
}

void handleInputs(gameData * game)  ///ESSA FUNCAO DEFINE O QUE AS TECLAS VAO FAZER
{
    int entrada = getch();

    if(entrada != -1)
        game->ultimaTecla = entrada;

    switch(entrada)
    {
        case KEY_LEFT: //Seta para esquerda
            break;
        case KEY_RIGHT: //Seta para esquerda
            break;
        case KEY_UP: //Seta para cima
            if(game->pointLine > 0)
                game->pointLine--;
            break;

        case KEY_DOWN: //Seta para baixo
            if(game->pointLine < 2)
                game->pointLine++;
            break;

        case 't': //Tecla t
            break;

        case '1': //Tecla 1
            break;

        case '0': //Tecla 0
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

void doUpdate(gameData * game)  ///ESSA FUNCAO DEFINE O VALOR DAS VARIAVEIS >>EM CADA INSTANTE<< (essa funcao eh chamada a todo momento)
{
    game->pointPos = 26 + game->pointLine;
}

void drawScreen(gameData * game)  ///ESSA FUNCAO EH PARA AS COISAS QUE VAO APARECER NA TELA
{
    clear();
    /** FUNCOES IMPORTANTES PARA SEREM USADAS AQUI:

        //DEFINE A COR que sera usada ate a cor ser mudada novamente:

        setColor( <cor principal>, <cor de fundo>, <parametros>);

        -Cores: COLOR_BLACK
                COLOR_RED
                COLOR_GREEN
                COLOR_YELLOW
                COLOR_BLUE
                COLOR_MAGENTA
                COLOR_CYAN
                COLOR_WHITE

        -Parametros: Nao sei oq isso faz direito, mas se vc colocar A_BOLD as cores ficam mais claras


        //DESENHA UM CARACTERE OU SIMBOLO:

        mvaddch(<linha>, <coluna>, <caractere>);

        -Simbolos:  ACS_ULCORNER
                    ACS_LLCORNER
                    ACS_URCORNER
                    ACS_LRCORNER
                    ACS_RTEE
                    ACS_LTEE
                    ACS_BTEE
                    ACS_TTEE
                    ACS_HLINE
                    ACS_VLINE
                    ACS_PLUS
                    ACS_S1
                    ACS_S9
                    ACS_DIAMOND
                    ACS_CKBOARD
                    ACS_DEGREE
                    ACS_PLMINUS
                    ACS_BULLET
                    ACS_LARROW
                    ACS_RARROW
                    ACS_DARROW
                    ACS_UARROW
                    ACS_BOARD
                    ACS_LANTERN
                    ACS_BLOCK


        //IMPRIME TEXTO:

        printw("<texto>");

        -Funciona igual printf

    */

    ///IMAGEM (max. 117x24)
    setColor(COLOR_GREEN, COLOR_BLACK, 0);
    MostraImagem(".\\jogoAPS\\Imagens\\teste.txt");



    ///TEXTO
    printw("\n\n");
    setColor(COLOR_GREEN, COLOR_BLACK, 0);
    printw("  > Opcao 1: \n");
    printw("  > Opcao 2: \n");
    printw("  > Opcao 3: \n");

    /// BORDAS
    //Borda superior e inferiores
    for(int i = 0; i <= 119; i++){
        mvaddch(0, i, ACS_BLOCK); //Borda superior
        mvaddch(25, i, ACS_BLOCK);
        mvaddch(29, i, ACS_BLOCK); //Borda inferior
    }

    //Bordas laterais
    for(int i = 0; i <= 29; i++){
        mvaddch(i, 0, ACS_BLOCK); //Borda esquerda
        mvaddch(i, 119, ACS_BLOCK); //Borda direita
    }


    ///CURSOR
    setColor(COLOR_BLACK, COLOR_GREEN, 0);  //Define a cor das linhas seguintes (preto com fundo verde)
    mvaddch(game->pointPos, 2, ACS_DIAMOND);    //Adiciona um caractere (nesse caso diamante) na linha 3, coluna pointPos


    // Exibe o conteúdo na tela (stdscr), getch() também ativa um refresh
    refresh();
}

///
///
///   NAO EH NECESSARIO MEXER EM MAIS NADA DAQUI PRA BAIXO
///
///


void initScreen();
void setColor(short int fg, short int bg, chtype attr);

int main(int argc, char *argv[]) ///AQUI N COLOCA NADA SE NAO PRECISAR
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

void initScreen()  ///IGNORA ESSA FUNCAO
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

void setColor(short int fg, short int bg, chtype attr) ///IGNORA ESSA FUNCAO
{
    chtype color = COLOR_PAIR(bg*PALLETE_SIZE + fg + 1);
    color |= attr;
    attrset(color);
}
