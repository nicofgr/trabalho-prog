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

    endwin();
    system("cls");
    fflush(stdin);
    setlocale(LC_ALL, "Portuguese");

    switch(npcNum){
        case 1:
            prefeito(game);
            break;
        case 2:
            mordomo(game);
            break;
        case 3:
            professor(game);
            break;
        case 4:
            policial(game);
            break;
        case 5:
            corpo(game);
            break;
        case 6:
            policial_2(game);
            break;
        case 7:
            filho(game);
            break;
    }


    printf("\n\n");
    system("pause");
    system("cls");
    game->interagir = 0;

}




