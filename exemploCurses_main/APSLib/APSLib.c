#include<stdio.h>
#include<curses.h>
#include "APSLib.h"

void DesenhaSala(const int telaOffsetX, const int telaOffsetY, const int posJogX, const int posJogY){

    FILE* arquivo = fopen("Salas\\sala1.txt", "r");

    char mapa[100][100] = {0}; //LINHA X COLUNA

    ///COPIA O MAPA DO ARQUIVO NO VETOR
    for(int lin = 0; fgets(mapa[lin], 100, arquivo); lin++){ //fgets vai retornar null no final do arquivo

        for(int col = 0; col < 50; col++){ //COLUNA
            if(mapa[lin][col] == 'x'){
                //setColor(COLOR_BLACK, COLOR_WHITE, A_BOLD);
                //mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_BLOCK);
            }
            if(mapa[lin][col] == '@'){
                //setColor(COLOR_GREEN, COLOR_BLACK, 0);
                //mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_DIAMOND);
            }
        }
    }

    ///VERIFICA EM QUE QUARTO O JOGADOR ESTA
    enum quartos{
        QUARTO,
        SALAO,
        BANHEIRO,
        CORREDOR,
        ENTRADA
    } quartoAtual;

    if(0 < posJogX && posJogX < 10 && 0 < posJogY && posJogY < 4){
        quartoAtual = ENTRADA;
        printw("Esta na entrada\n");
    }else if(10 < posJogX && posJogX < 14 && 0 < posJogY && posJogY < 9){
        quartoAtual = CORREDOR;
        printw("Esta no corredor\n");
    }else if(14 < posJogX && posJogX < 26 && 0 < posJogY && posJogY < 3){
        quartoAtual = BANHEIRO;
        printw("Esta no banheiro\n");
    }else if(14 < posJogX && posJogX < 26 && 3 < posJogY && posJogY < 9){
        quartoAtual = SALAO;
        printw("Esta no salao de festas\n");
    }else if(0 < posJogX && posJogX < 10 && 4 < posJogY && posJogY < 9){
        quartoAtual = QUARTO;
        printw("Esta no quarto\n");
    }


    ///LE O VETOR E DESENHA NA TELA
    for(int lin = 0; lin < 10; lin++){
        for(int col = 0; col < 50; col++){ //COLUNA

            if(mapa[lin][col] == 'x'){
                setColor(COLOR_BLACK, COLOR_WHITE, A_BOLD);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_BLOCK);
            }
            if(mapa[lin][col] == '@'){
                setColor(COLOR_GREEN, COLOR_BLACK, 0);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_DIAMOND);
            }
        }
    }

    fclose(arquivo);
}

void DetectaColisoes(int colisoes [100][100]){

    FILE* arquivo = fopen("Salas\\sala1.txt", "r");

    //fgets vai retornar null no final do arquivo
    char teste[100];
    int lin = 0;

    while(fgets(teste, 100, arquivo)){

        for(int col = 0; col < 50; col++){ //COLUNA
            if(teste[col] != ' '){
                colisoes[lin][col] = 1;
            }
        }

        lin++;
    }

    fclose(arquivo);
}

int DetectaInteracoes(int x, int y){

    int interacoes[100][100] = {0};
    FILE* arquivo = fopen("Salas\\sala1.txt", "r");

    //fgets vai retornar null no final do arquivo
    char teste[100];
    int lin = 0;

    while(fgets(teste, 100, arquivo)){

        for(int col = 0; col < 50; col++){ //COLUNA
            if(teste[col] == '@'){
                interacoes[lin][col] = 1;
            }
        }

        lin++;
    }

    fclose(arquivo);

    if(interacoes[y+1][x] || interacoes[y-1][x] || interacoes[y][x+1] || interacoes[y][x-1]){
        return 1;
    }else
        return 0;
}

void Dialogo(int a, int *interagir){

    setColor(COLOR_GREEN, COLOR_BLACK, A_BOLD);

    switch(a){
        case '1':
            printw("\n - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            printw(" >> ah, sobre o assassinato da sua mulher ?\n");
            printw(" - Eu nao sei de nada!\n");
            printw(" - Mas saiba que no que eu puder ajudar eu irei \n");
            printw("--------------------------------------------------\n");
            printw(" > 2 - Como o Prefeito esta  \n > 3 - sair.");
            break;

        case '2':
            printw("\n - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            printw(" >> Como o Prefeito esta? \n");
            printw(" - Estou bem, fora os acontecimentos dessa noite que me deixaram meio assustado, estou bem \n");
            printw("--------------------------------------------------\n");
            printw(" > 1 - Assassinato da sua mulher \n > 3 - sair.");
            break;

        case '3':
            *interagir = 0;
            break;

        default:
            printw("\n - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            printw("--------------------------------------------------\n");
            printw(" > 1 - Assassinato da sua mulher \n > 2 - Como o Prefeito esta  \n > 3 - sair.");
            break;
    }

}
