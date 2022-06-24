#ifndef APSLIB_H_INCLUDED
#define APSLIB_H_INCLUDED
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
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

    char** gameMap;
    int nMaxLin;
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

///DATA
void SalvaDados(gameData * game);
void LeDados(gameData * game);

///SCENES
void MainMenu(gameData * game);
void Overworld(gameData * game);

///WORLD
void LeMundo(char* nomeArquivo, gameData * game);
void DesenhaSala(int xMin, int yMin, int xMax, int yMax, int telaOffsetX, int telaOffsetY, gameData * game);
void DesenhaMundo(const int ,const int ,const int,const int, char mapa[100][100], gameData * game);
void DetectaColisoes(char mapa[100][100], int posJogadorX, int posJogadorY, int *colidindo);

///INTERACTIONS
void Dialogo(int a, int* interagir, int npcNum, gameData * game);
int DetectaInteracoes(int interactionMap[100][100], int x, int y);

///DIALOGOS DOS PERSONAGENS
void prefeito(gameData * game);
void policial(gameData * game);
void corpo(gameData * game);
void policial_2 (gameData * game);
void professor(gameData * game);
void filho(gameData * game);
void mordomo(gameData * game);

#endif // APSLIB_H_INCLUDED
