#ifndef APSLIB_H_INCLUDED
#define APSLIB_H_INCLUDED

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
    int interacao;
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

void LeMundo(char* nomeArquivo, char mapa[100][100]);
void DesenhaMundo(const int ,const int ,const int,const int, char mapa[100][100]);
void DesenhaSala(int xMin, int yMin, int xMax, int yMax, char mapa[100][100], int telaOffsetX, int telaOffsetY);
void DetectaColisoes(char mapa[100][100], int posJogadorX, int posJogadorY, int *colidindo);
int DetectaInteracoes(int x, int y);
void Dialogo(int a, int* interagir);

#endif // APSLIB_H_INCLUDED
