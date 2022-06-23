#include"APSLib.h"


void SalvaDados(gameData * game){

    FILE* arquivo = fopen("datasave.txt", "w");

    ///SALVA POSICAO DO MAPA
    int posX = game->posMapa.x;
    int posY = game->posMapa.y;

    fprintf(arquivo, "%d\n",posX);
    fprintf(arquivo, "%d\n",posY);

    fclose(arquivo);

}

void LeDados(gameData * game){

    FILE* arquivo = fopen("datasave.txt", "r");

    int posX = 0;
    int posY = 0;

    fscanf(arquivo, "%d", &posX);
    fscanf(arquivo, "%d", &posY);

    fclose(arquivo);

    game->posMapa.x = posX;
    game->posMapa.y = posY;

    //game->posMapa.x = (game->meioTela.x) - 4;
    //game->posMapa.y = (game->meioTela.y) - 1;
}
