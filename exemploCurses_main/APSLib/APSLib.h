#ifndef APSLIB_H_INCLUDED
#define APSLIB_H_INCLUDED
#include <curses.h>
#include <stdlib.h>
#include <time.h>
// 8 colors for standard Curses
#define PALLETE_SIZE (COLOR_WHITE - COLOR_BLACK + 1)

enum screenMode{
    MENU,
    GAME
};

// Estrutura com estado interno da aplicação
typedef struct gameData
{
    ///MENU INICIAL
    bool menuInicial; //Menu inicial ligado ou desligado
    int telaMenuInicial; //Pagina do menu inicial

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
    int interactionMap[100][100];

} gameData;

///GAME
void initScreen(screenMode);
void setColor(short int fg, short int bg, chtype attr);
void initGame(gameData * game);
void handleInputs(gameData * game);
void doUpdate(gameData * game);
void drawScreen(gameData * game, enum screenMode);

///SCENES
void MainMenu(gameData * game);
void Overworld(gameData * game);

///WORLD
void LeMundo(char* nomeArquivo, char mapa[100][100], int interactionMap[100][100]);
void DesenhaSala(int xMin, int yMin, int xMax, int yMax, char mapa[100][100], int telaOffsetX, int telaOffsetY);
void DesenhaMundo(const int ,const int ,const int,const int, char mapa[100][100]);
void DetectaColisoes(char mapa[100][100], int posJogadorX, int posJogadorY, int *colidindo);

///INTERACTIONS
void Dialogo(int a, int* interagir, int npcNum, gameData * game);
int DetectaInteracoes(int interactionMap[100][100], int x, int y);

///DIALOGOS
void Prefeito(int ultimaTecla, int *interagir, gameData * game);
void Empregado(int ultimaTecla,int *interagir);
void Professor(int ultimaTecla, int *interagir);
void Policial(int ultimaTecla, int *interagir);
void Corpo(int ultimaTecla, int *interagir);

#endif // APSLIB_H_INCLUDED
