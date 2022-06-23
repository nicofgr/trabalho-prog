///===========APSLib.h===========///

 ///Esse enum define dois modos que algumas funções podem operar:
 ///GAME para a maior parte do jogo
 ///MENU para alguns menus do jogo
enum screenMode{
    MENU,
    GAME
};



/// Para fácil troca de informações, essa struct contém a maioria das variáveis usadas pelas funções.
typedef struct gameData
{
    ///MENU INICIAL
    bool menuInicial; //Menu inicial ligado ou desligado
    int telaMenuInicial; //Pagina do menu inicial

    ///JOGO
    char nomePersonagem[50]; //Nome do personagem
    bool devMode; //Estado da opção de mostrar as informações do jogo na tela
    int ultimaTecla; //Ultima tecla pressionada
    int colisao; //Estado de colisão entre o jogador e outros elementos
    int interacaoDisponivel; //Armazena o valor da interação disponivel atualmente (varia de acordo com o npc que está próximo do jogador)
    int interagir; //Varia se o jogador estiver atualmente interagindo ou não 

    struct pos{  ///Struct criada para armazenar as duas coordenadas de diferentes elementos necessários para o jogo
        int x;
        int y;
    } posJogador; //Posição relativa do jogador com o mapa
    struct pos posMapa; //Posição do mapa no terminal
    struct pos posMapaAnterior; //Última posição do mapa no terminal antes de ser movido
    struct pos meioTela; //Posição do centro do terminal (pode mudar junto com o tamanho da tela)

    char mapa[100][100]; //Armazena uma cópia do mapa do jogo, que é originalmente um arquivo txt
    int interactionMap[100][100]; //Outro mapa do jogo contendo somente as interações possíveis

} gameData;

///GAME
void initScreen(screenMode); //Inicializa a tela de acordo com o modo escolhido (inicializa cores, liga/desliga cursor, teclas digitadas e tempo que getch pausa a tela) 
void setColor(short int fg, short int bg, chtype attr); // Namoral n faço a ideia doq isso faz

void initGame(gameData * game); //Inicializa os valores iniciais das variáveis (roda uma vez na inicialização do programa, não faz parte do loop)
void handleInputs(gameData * game); //Lê as teclas pressionadas e define o que elas fazem
void doUpdate(gameData * game); //Atualiza em cada iteração, para definir valores e coisas afim
void drawScreen(gameData * game, enum screenMode); //Atualiza a tela a cada iteração e mostra os componentes gráficos do jogo

///SCENES 
//Componentes gráficos do jogo, rodam no drawScreen
void MainMenu(gameData * game); //Menu Principal
void Overworld(gameData * game);  //Todo o resto

///WORLD
//Funções referentes ao mapa do jogo
void LeMundo(char* nomeArquivo, gameData * game); //Copia o mapa do txt e salva em um vetor
void DesenhaSala(int xMin, int yMin, int xMax, int yMax, char mapa[100][100], int telaOffsetX, int telaOffsetY); //Desenha alguma sala do jogo, usado várias vezes no DesenhaMundo
void DesenhaMundo(const int ,const int ,const int,const int, char mapa[100][100]); //Desenha o mapa do jogo
void DetectaColisoes(char mapa[100][100], int posJogadorX, int posJogadorY, int *colidindo); //Detecta se o jogador está colidindo com alguma coisa

///INTERACTIONS
void Dialogo(int a, int* interagir, int npcNum, gameData * game); //Gerencia que dialogo mostrar na tela
int DetectaInteracoes(int interactionMap[100][100], int x, int y); //Detecta se tem alguma interação disponível ao redor

///DIALOGOS DOS PERSONAGENS
//Todas as conversas dos personagens estão nas seguintes funções:
void prefeito(gameData * game); 
void policial(gameData * game);
void corpo(gameData * game);
void policial_2 (gameData * game);
void professor(gameData * game);
void filho(gameData * game);
void mordomo(gameData * game);
