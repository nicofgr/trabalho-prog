#ifndef APSLIB_H_INCLUDED
#define APSLIB_H_INCLUDED

void DesenhaMundo(const int ,const int ,const int,const int);
void DesenhaSala(int xMin, int yMin, int xMax, int yMax, char mapa[100][100], int telaOffsetX, int telaOffsetY);
void DetectaColisoes(int colisoes [100][100]);
int DetectaInteracoes(int x, int y);
void Dialogo(int a, int* interagir);

#endif // APSLIB_H_INCLUDED
