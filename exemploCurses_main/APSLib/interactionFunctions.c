#include "APSLib.h"


int DetectaInteracoes(int interactionMap[100][100], int x, int y){

    int cima = interactionMap[y-1][x];
    int baixo = interactionMap[y+1][x];
    int esquerda =  interactionMap[y][x-1];
    int direita = interactionMap[y][x+1];

    /*printw("DetectaInteracoes\n");
    printw(" Cima: %d\n", cima);
    printw(" Baixo: %d\n", baixo);
    printw(" Esquerda: %d\n", esquerda);
    printw(" Direita: %d\n", direita);*/

    return cima + baixo + esquerda + direita;

}

void Dialogo(int ultimaTecla, int *interagir, int npcNum, gameData * game){

    switch(npcNum){
        case 1:
            Prefeito(ultimaTecla, interagir, game);
            break;
        case 2:
            //Empregado();
            break;
        case 3:
            //Professor();
            break;
        case 4:
            //Policial();
            break;
        case 5:
            //Corpo();
            break;
    }

}
