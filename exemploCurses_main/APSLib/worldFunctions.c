#include "APSLib.h"

void LeMundo(char* nomeArquivo, gameData * game){

    FILE* arquivo = fopen("Salas\\sala1.txt", "r");

    ///INICIALIZA O VETOR
    for(int i = 0; i < 100; i++){
       for(int j = 0; j < 100; j++){
            game->mapa[i][j] = ' ';
        }
    }

    //Mede quantas linhas o arquivo tem:
    int qtdLin;
    for(qtdLin = 0; fgets(game->mapa[qtdLin], 100, arquivo); qtdLin++){};
    //printf("Quantidade de linhas: %d\n", qtdLin);

    //Aloca o numero de linhas (ponteiros de char) necessario
    char** arr = (char**)malloc(qtdLin * sizeof(char*));

    fseek(arquivo, 0, SEEK_SET);

    //Mede quantos caracteres cada linha tem
    for(int lin = 0; fgets(game->mapa[lin], 100, arquivo); lin++){
        int nChar = strlen(game->mapa[lin]) + 1;
        //printf("A linha %d tem %d caracteres\n", lin + 1, nChar);
        //Alocar o numero de caracterers da linha i necessarios (ponteiro i)
        arr[lin] = (char*)malloc(nChar * sizeof(char));
        //Copiar os valores no vetor
        strcpy(arr[lin], game->mapa[lin]);
    };

    game->nMaxLin = qtdLin;

    game->gameMap = arr;

    fseek(arquivo, 0, SEEK_SET);

    ///COPIA O MAPA DO ARQUIVO NO VETOR
    for(int lin = 0; fgets(game->mapa[lin], 100, arquivo); lin++){}; //fgets vai retornar null no final do arquivo

    fclose(arquivo);

    ///DESENHA O MAPA DE INTERAÇÕES
    for(int lin = 0; lin < 100; lin++){
       for(int col = 0; col < 100; col++){
            switch(game->mapa[lin][col]){
                case '1':
                    game->interactionMap[lin][col] = 1;
                    break;
                case '2':
                    game->interactionMap[lin][col] = 2;
                    break;
                case '3':
                    game->interactionMap[lin][col] = 3;
                    break;
                case '4':
                    game->interactionMap[lin][col] = 4;
                    break;
                case '5':
                    game->interactionMap[lin][col] = 5;
                    break;
                case '7':
                    game->interactionMap[lin][col] = 7;
                    break;
                default:
                    game->interactionMap[lin][col] = 0;
                    break;
            }
        }
    }
}

void DesenhaMundo(const int telaOffsetX, const int telaOffsetY, const int posJogX, const int posJogY, char mapa[100][100], gameData * game){

    ///VERIFICA EM QUE QUARTO O JOGADOR ESTA
    enum quartos{
        QUARTO,
        SALAO,
        BANHEIRO,
        CORREDOR,
        ENTRADA,
        FORA,
        QUARTOFILHO
    } quartoAtual;

    if(10 <= posJogX && posJogX <= 14 && 0 < posJogY && posJogY < 9){
        quartoAtual = CORREDOR;
    }else if(0 < posJogX && posJogX < 10 && 0 <= posJogY && posJogY < 4){
        quartoAtual = ENTRADA;
    }else if(14 < posJogX && posJogX < 26 && 0 < posJogY && posJogY < 3){
        quartoAtual = BANHEIRO;
    }else if(14 < posJogX && posJogX < 26 && 3 <= posJogY && posJogY < 9){
        quartoAtual = SALAO;
    }else if(0 < posJogX && posJogX < 10 && 4 < posJogY && posJogY < 9){
        quartoAtual = QUARTO;
    }else if(8 < posJogX && posJogX < 16 && 9 < posJogY && posJogY < 14){
        quartoAtual = QUARTOFILHO;
    }else
        quartoAtual = FORA;


    ///DESENHA O COMODO ATUAL NA TELA
    switch(quartoAtual){
        case CORREDOR:
            //printw("Corredor\n");
            DesenhaSala(10, 0, 14, 9, telaOffsetX, telaOffsetY, game);
            break;
        case ENTRADA:
            //printw("Entrada\n");
            DesenhaSala(0, 0, 10, 4, telaOffsetX, telaOffsetY, game);
            break;
        case BANHEIRO:
            //printw("Banheiro\n");
            DesenhaSala(14, 0, 26, 3, telaOffsetX, telaOffsetY, game);
            break;
        case SALAO:
            //printw("Salao de festas\n");
            DesenhaSala(14, 3, 26, 9, telaOffsetX, telaOffsetY, game);
            break;
        case QUARTO:
            //printw("Quarto\n");
            DesenhaSala(0, 4, 10, 9, telaOffsetX, telaOffsetY, game);
            break;
        case QUARTOFILHO:
            //printw("QuartoFilho\n");
            DesenhaSala(8, 10, 16, 14, telaOffsetX, telaOffsetY, game);
            break;
        case FORA:
            //printw("Fora\n");
            for(int lin = 0; lin < 10; lin++){
                for(int col = 0; col < 50; col++){ //COLUNA
                    if(mapa[lin][col] == 'x' && (lin == 0 || col == 0 || lin == 9 || col == 26)){
                        setColor(COLOR_BLACK, COLOR_WHITE, A_BOLD);
                        mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_BLOCK);
                    }
                }
            }
            break;
    }
}

void DesenhaSala(int xMin, int yMin, int xMax, int yMax, int telaOffsetX, int telaOffsetY, gameData * game){

    ///SALAS NO FUNDO
    for(int lin = 0; lin < game->nMaxLin; lin++){     //LINHA
        for(int col = 0; game->gameMap[lin][col] != '\0'; col++){ //COLUNA

            if(game->gameMap[lin][col] == 'x'){
                setColor(COLOR_WHITE, COLOR_BLACK, A_DIM);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_BOARD);
            }
        }
     }

    ///SALA ATUAL
    for(int lin = yMin; lin <= yMax; lin++){     //LINHA
        for(int col = xMin; col <= xMax; col++){ //COLUNA

            if(game->mapa[lin][col] == 'x'){
                setColor(COLOR_WHITE, COLOR_BLACK, A_DIM);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_BLOCK);
            }

            if(game->mapa[lin][col] == 'o'){
                setColor(COLOR_WHITE, COLOR_BLACK, A_DIM);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_BLOCK);
            }

            if(game->mapa[lin][col] == '1'){ //PREFEITO
                setColor(COLOR_GREEN, COLOR_BLACK, 0);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_DIAMOND);
            }
            if(game->mapa[lin][col] == '2'){ //EMPREGADO
                setColor(COLOR_YELLOW, COLOR_BLACK, 0);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_DIAMOND);
            }
            if(game->mapa[lin][col] == '3'){ //PROFESSOR
                setColor(COLOR_RED, COLOR_BLACK, A_BOLD);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_DIAMOND);
            }
            if(game->mapa[lin][col] == '4'){ //POLICIAL
                setColor(COLOR_BLUE, COLOR_BLACK, A_BOLD);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_DIAMOND);
            }
            if(game->mapa[lin][col] == '5'){ //CORPO
                setColor(COLOR_WHITE, COLOR_RED, 0);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_DIAMOND);
            }
            if(game->mapa[lin][col] == '7'){ //FILHO PREFEITO
                setColor(COLOR_MAGENTA, COLOR_BLACK, A_BOLD);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_DIAMOND);
            }
        }
    }
}

void DetectaColisoes(char mapa[100][100], int posJogadorX, int posJogadorY, int* colidindo){

    if(mapa[posJogadorY][posJogadorX] != ' '){
        *colidindo = 1;
    }else{
        *colidindo = 0;
    }
}
