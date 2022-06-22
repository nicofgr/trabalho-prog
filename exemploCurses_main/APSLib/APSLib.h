#ifndef APSLIB_H_INCLUDED
#define APSLIB_H_INCLUDED

void LeMundo(char* nomeArquivo, char mapa[100][100]);
void DesenhaMundo(const int ,const int ,const int,const int, char mapa[100][100]);
void DesenhaSala(int xMin, int yMin, int xMax, int yMax, char mapa[100][100], int telaOffsetX, int telaOffsetY);
void DetectaColisoes(char mapa[100][100], int posJogadorX, int posJogadorY, int *colidindo);
int DetectaInteracoes(int x, int y);
void Dialogo(int a, int* interagir);

#endif // APSLIB_H_INCLUDED
