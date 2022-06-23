#include<stdio.h>
#include<curses.h>
#include "APSLib.h"

void LeMundo(char* nomeArquivo, char mapa[100][100]){

    FILE* arquivo = fopen("Salas\\sala1.txt", "r");

    ///INICIALIZA O VETOR
    for(int i = 0; i < 100; i++){
       for(int j = 0; j < 100; j++){
            mapa[i][j] = ' ';
        }
    }

    ///COPIA O MAPA DO ARQUIVO NO VETOR
    for(int lin = 0; fgets(mapa[lin], 100, arquivo); lin++){}; //fgets vai retornar null no final do arquivo

    fclose(arquivo);
}

void DesenhaMundo(const int telaOffsetX, const int telaOffsetY, const int posJogX, const int posJogY, char mapa[100][100]){

    ///VERIFICA EM QUE QUARTO O JOGADOR ESTA
    enum quartos{
        QUARTO,
        SALAO,
        BANHEIRO,
        CORREDOR,
        ENTRADA,
        FORA
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
    }else
        quartoAtual = FORA;


    ///DESENHA O COMODO ATUAL NA TELA
    switch(quartoAtual){
        case CORREDOR:
            //printw("Corredor\n");
            DesenhaSala(10, 0, 14, 10, mapa, telaOffsetX, telaOffsetY);
            break;
        case ENTRADA:
            //printw("Entrada\n");
            DesenhaSala(0, 0, 10, 4, mapa, telaOffsetX, telaOffsetY);
            break;
        case BANHEIRO:
            //printw("Banheiro\n");
            DesenhaSala(14, 0, 26, 3, mapa, telaOffsetX, telaOffsetY);
            break;
        case SALAO:
            //printw("Salao de festas\n");
            DesenhaSala(14, 3, 26, 9, mapa, telaOffsetX, telaOffsetY);
            break;
        case QUARTO:
            //printw("Quarto\n");
            DesenhaSala(0, 4, 10, 9, mapa, telaOffsetX, telaOffsetY);
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

void DesenhaSala(int xMin, int yMin, int xMax, int yMax, char mapa[100][100], int telaOffsetX, int telaOffsetY){

    ///SALAS NO FUNDO
    for(int lin = 0; lin <= 50; lin++){     //LINHA
        for(int col = 0; col <= 50; col++){ //COLUNA

            if(mapa[lin][col] == 'x'){
                setColor(COLOR_WHITE, COLOR_BLACK, A_DIM);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_BOARD);
            }
        }
     }

    ///SALA ATUAL
    for(int lin = yMin; lin <= yMax; lin++){     //LINHA
        for(int col = xMin; col <= xMax; col++){ //COLUNA

            if(mapa[lin][col] == 'x'){
                setColor(COLOR_WHITE, COLOR_BLACK, A_DIM);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_BLOCK);
            }

            if(mapa[lin][col] == '1'){ //PREFEITO
                setColor(COLOR_GREEN, COLOR_BLACK, 0);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_DIAMOND);
            }
            if(mapa[lin][col] == '2'){ //EMPREGADO
                setColor(COLOR_YELLOW, COLOR_BLACK, 0);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_DIAMOND);
            }
            if(mapa[lin][col] == '3'){ //PROFESSOR
                setColor(COLOR_RED, COLOR_BLACK, A_BOLD);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_DIAMOND);
            }
            if(mapa[lin][col] == '4'){ //POLICIAL
                setColor(COLOR_BLUE, COLOR_BLACK, A_BOLD);
                mvaddch(lin + telaOffsetY, col + telaOffsetX, ACS_DIAMOND);
            }
            if(mapa[lin][col] == '5'){ //CORPO
                setColor(COLOR_WHITE, COLOR_RED, 0);
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

void MenuInicial(gameData * game){

    clear();

    ///TITULO GRANDE
    setColor(COLOR_GREEN, COLOR_BLACK, 0);
    printw("\n\n\n\n\n\n\n\n\n");
    printw("                                  _____ _ _         _          ___              _          \n");
    printw("                                 |_   _(_) |       | |        / _ \\            (_)        \n");
    printw("                                   | |  _| |_ _   _| | ___   / /_\\ \\ __ _ _   _ _        \n");
    printw("                                   | | | | __| | | | |/ _ \\  |  _  |/ _` | | | | |        \n");
    printw("                                   | | | | |_| |_| | | (_) | | | | | (_| | |_| | |         \n");
    printw("                                   \\_/ |_|\\__|\\__,_|_|\\___/  \\_| |_/\\__, |\\__,_|_|  \n");
    printw("                                                                       | |                 \n");
    printw("                                                                       |_|                 \n");

    switch(game->telaMenuInicial){
        case 0:
            ///OPCOES
            printw("                                             Pressione ENTER para continuar.");

            break;
        case 1:
            initScreen(0);
            printw("\n                                      Digite o nome do seu personagem: ");
            getstr(game->nomePersonagem);
            game->telaMenuInicial = 3;
            break;
        case 3:
            clear();
            initScreen(0);
            printw("\n");
            mvprintw(4,game->meioTela.x - 30, "Era uma noite escura e chuvosa, relampejava sem parar,");
            mvprintw(5,game->meioTela.x - 32, "estava tudo tao quieto, que qualquer barulho lhe chamava atencao");
            mvprintw(6,game->meioTela.x - 30, "Olhando ao seu redor, as unicas coisas que voce ve sao");
            mvprintw(7,game->meioTela.x - 32, "a sua mesa com o telefone e alguns papeis em cima.");
            mvprintw(8,game->meioTela.x - 30, "Voce esta quase pegando no sono...");
            mvprintw(10,game->meioTela.x - 8, "TRIN TRIN TRIN\n");
            mvprintw(12,game->meioTela.x - 30, "O telefone toca, uma voz misteriosa comeca a fala do outro lado da linha.");
            mvprintw(14,game->meioTela.x - 34, ">>> Detetive %s, certo? O prefeito estava fazendo uma festa em sua mansao hoje,", game->nomePersonagem);
            mvprintw(15,game->meioTela.x - 32, " mas durante uma queda de energia, sua esposa sumiu,");
            mvprintw(16,game->meioTela.x - 32, " quando a luz voltou a mulher estava morta!");
            mvprintw(17,game->meioTela.x - 34, ">>> Preciso que voce va ate la urgente!");
            mvprintw(19,game->meioTela.x - 30, "A ligacao cai, voce sai correndo para a garagem,");
            mvprintw(20,game->meioTela.x - 32, " entra no carro e parte em direcao a mansao do prefeito.");
            mvprintw(21,game->meioTela.x - 30, "Ao chegar no local, voce sobe as escadas e bate na porta.");
            mvprintw(22,game->meioTela.x - 30, "Quando a porta se abre voce eh surpreendido.");
            char str[5];
            getstr(str);
            game->menuInicial = FALSE;
            initScreen(1);
            break;

    }

    ///BORDAS
            for(int lin = 0; lin < (game->meioTela.y*2); lin++){
                for(int col = 0; col < (game->meioTela.x*2); col++){
                    if(lin == 0 || col == 0 || lin == (game->meioTela.y*2)-1 || col == (game->meioTela.x*2)-1){
                        setColor(COLOR_BLACK, COLOR_GREEN, 0);
                        mvaddch(lin, col, ACS_BOARD);
                    }
                }
            }

    ///Meio da tela
    //mvaddch(game->meioTela.y, game->meioTela.x, 'x');

    refresh();
}

int DetectaInteracoes(char mapa[100][100], int x, int y){

    char cima = mapa[y-1][x];
    char baixo = mapa[y+1][x];
    char esquerda =  mapa[y][x-1];
    char direita = mapa[y][x+1];

    printw("DetectaInteracoes\n");
    printw(" Cima: %c\n", cima);
    printw(" Baixo: %c\n", baixo);
    printw(" Esquerda: %c\n", esquerda);
    printw(" Direita: %c\n", direita);

    switch(cima){
        case '1':
            printw("Prefeito detectado\n");
            return 1;
            break;
        case '2':
            printw("Mordomo detectado\n");
            return 2;
            break;
        case '3':
            printw("Professor detectado\n");
            return 3;
            break;
        case '4':
            printw("Policial detectado\n");
            return 4;
            break;
        case '5':
            printw("Corpo detectado\n");
            return 5;
            break;
    }
    switch(baixo){
        case '1':
            printw("Prefeito detectado\n");
            return 1;
            break;
        case '2':
            printw("Mordomo detectado\n");
            return 2;
            break;
        case '3':
            printw("Professor detectado\n");
            return 3;
            break;
        case '4':
            printw("Policial detectado\n");
            return 4;
            break;
        case '5':
            printw("Corpo detectado\n");
            return 5;
            break;
    }
    switch(esquerda){
        case '1':
            printw("Prefeito detectado\n");
            return 1;
            break;
        case '2':
            printw("Mordomo detectado\n");
            return 2;
            break;
        case '3':
            printw("Professor detectado\n");
            return 3;
            break;
        case '4':
            printw("Policial detectado\n");
            return 4;
            break;
        case '5':
            printw("Corpo detectado\n");
            return 5;
            break;
    }
    switch(direita){
        case '1':
            printw("Prefeito detectado\n");
            return 1;
            break;
        case '2':
            printw("Mordomo detectado\n");
            return 2;
            break;
        case '3':
            printw("Professor detectado\n");
            return 3;
            break;
        case '4':
            printw("Policial detectado\n");
            return 4;
            break;
        case '5':
            printw("Corpo detectado\n");
            return 5;
            break;
    }

    return 0;
}

void Dialogo(int a, int *interagir){

    setColor(COLOR_GREEN, COLOR_BLACK, A_BOLD);
    printw("\n");

    switch(a){
        case '1':
            printw("\n - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            printw(" >> Sobre o assassinato da minha esposa.\n");
            printw(" - Eu nao sei de nada!\n");
            printw(" - Mas saiba que no que eu puder ajudar eu irei. \n");
            printw("--------------------------------------------------\n");
            printw(" > 2 - Como o Prefeito esta?  \n > 3 - Sair.");
            break;

        case '2':
            printw("\n - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            printw(" >> Como o Prefeito esta? \n");
            printw(" - Estou bem, fora os acontecimentos dessa noite que me deixaram meio assustado, estou bem \n");
            printw("--------------------------------------------------\n");
            printw(" > 1 - Assassinato da minha esposa \n > 3 - Sair.");
            break;

        case '3':
            *interagir = 0;
            break;

        default:
            printw("\n - Ola, sou o prefeito dessa cidade, sobre o que gostaria de falar?\n");
            printw("--------------------------------------------------\n");
            printw(" > 1 - Assassinato da minha esposa \n > 2 - Como o Prefeito esta?  \n > 3 - Sair.");
            break;
    }

}
