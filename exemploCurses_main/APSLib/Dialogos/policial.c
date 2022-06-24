#include "../APSLib.h"

void policialTeste(gameData * game){

    setlocale(LC_ALL, "Portuguese");
    printf("AQUI");
    p0();

    return 0;

}

///ARVORE
void p0(){
    int opt = 0;
    ///DIALOGO
    printf("\n\n##########O policial James, um velho amigo de infancia abre a porta e lhe recebe.##########\n\n");
    printf("Policial James - Vamos entre, a chuva esta muito forte, afinal de contas, o que faz aqui? Não sabia que também era amigo do prefeito.\n");
    ///OPCOES
    printf(" 1 - Olá James.\n");
    printf(" 2 - Eu recebi uma ligação falando sobre um assassinato.\n");
    printf(" 3 - EU?! O QUE VOCE FAZ AQUI?\n");

    fflush(stdin);
    switch(getch()){
        case '1':
            p1();
        case '2':
            p2();
        case '3':
            p3();
        default:
            p0();
    }
}

void p1(){
    int opt = 0;
    ///DIALOGO
    printf("\n\n Policial James - Olá de novo, mas me conte logo, o que você faz aqui?\n");

    ///OPCOES
    printf(" 1 - Ah, eu fui chamado para resolver algum assassinato ou algo assim.\n");
    printf(" 2 - Eu recebi uma ligação falando sobre um assassinato.\n");
    printf(" 3 - Eu não vou te falar nada seu otário.\n");


    fflush(stdin);
    switch(getch()){
        case '1':
            p2();
        case '2':
            p2();
        case '3':
            p3();
        default:
            p1();
    }
}

void p2(){
    int opt = 0;
    ///DIALOGO
    printf("\n\nPolicial James - Ah sim, entao tambem te chamaram, e o seguinte, o prefeito resolveu dar uma festa aqui hoje, mas nao acabou muito bem. Na verdade, a mulher dele esta morta la no banheiro, e pra piorar ninguem viu quem foi por causa das luzes terem se apagado.\n");

    ///OPCOES
    printf(" 1 - Entendo, os convidados ainda estão aí dentro? \n");
    printf(" 2 - Um assassinato as cegas, hmmm. O prefeito esta aí? \n");
    printf(" 3 - Compreendo... Algum suspeito?\n");

    fflush(stdin);
    switch(getch()){
        case '1':
            p21();
        case '2':
            p21();
        case '3':
            p113();
        default:
            p2();
    }
}

void p21(){
    int opt = 0;
    ///DIALOGO
     printf("\n\nPolicial James - Claro! O prefeito esta no quarto aqui atrás, os outros convidados estão ai pela mansão.\n");
    ///OPCOES

    fflush(stdin);
    switch(getch()){
        default:
            main();
    }
}

void p113(){
    int opt = 0;
    ///DIALOGO
    printf("\n\nPolicial James – Algum? Sinceramente, boa sorte em descobrir quem foi o culpado, ela tinha muitos... Bem... “Inimigos” assim digamos.\n");

    ///OPCOES
    printf(" 1- Inimigos? \n");
    printf(" 2- Entendi, vou entrar e procurar o prefeito para interroga-lo. \n");
    printf(" 3- Inimigos é? Vou averiguar a cena do crime\n");

    fflush(stdin);
    switch(getch()){
        case '1':
            p1131();
        default:
            main();
    }
}

void p1131(){
    int opt = 0;
    ///DIALOGO
    printf("\n\nPolicial James - É, inimigos, que Deus o tenha, mas para falar a verdade, ela era insuportavel, sempre se achando melhor que tudo e todos, digamos que era uma pessoa dificil de conviver...\n");

    ///OPCOES

    fflush(stdin);
    switch(getch()){
        default:
            main();
    }
}

void p3(){
    int opt = 0;
    ///DIALOGO
    printf("\n\nPolicial James – Ei! O que é isso cara, se acalma um pouco... \n");

    printf(" 1 - ME ACALMAR?! COM VOCÊ SEMPRE ROUBANDO MEUS CASOS?! EU VOU É TE QUEBRAR NA PORRADA! \n");
    printf(" 2 - Perdão pelo susto, é que faz muito tempo que não te vejo... Mas me conta, o que aconteceu aqui? \n");
    printf(" 3 - **Ir embora** \n");

    ///OPCOES

    fflush(stdin);
    switch(getch()){
        case '1':
            p31();
        case '2':
            p32();
        case '3':
            p33();
        default:
            p3();
    }
}

void p31(){
    int opt = 0;
    ///DIALOGO
    printf("\n\nPolicial James – Olha o jeito que você fala comigo! Vai para parede com as mãos na cabeça!!! ");
    printf("\n\n##########Nisso, James saca sua arma e aponta contra você.##########");
    printf("\n\nPolicial James - Ja chega %s, não é a primeira vez que você usa de desacato para me tirar do sério! Você vai para cadeia. ","nome");
    printf("\n\n##########Policial James algema suas mãos e leva você para a viatura.##########");
    printf("##########VOCÊ VAI PARA CADEIA ##########");

    ///OPCOES

    fflush(stdin);
    switch(getch()){
        default:
            main();
    }
}

void p32(){
    int opt = 0;
    ///DIALOGO
    printf("Policial James – Tá tá, mas me conta logo, o que você faz aqui? \n");
    printf("1- Ah, eu fui chamado para resolver algum assassinato ou algo assim.\n");
    printf(" 2- Eu recebi uma ligacao falando sobre um assassinato.\n");
    printf(" 3- Eu não vou te falar nada seu otário.\n");

    ///OPCOES

    fflush(stdin);
    switch(getch()){
        case '1':
            p2();
        case '2':
            p2();
        case '3':
            p31();
        default:
            p32();
    }
}

void p322(){
    int opt = 0;
    ///DIALOGO
    printf("\n\nPolicial James – A primeira dama foi assassinada aqui hoje durante a festa que o prefeito estava dando, mas sinceramente, boa sorte em descobrir quem foi o culpado, ela tinha muitos... Bem... “Inimigos” assim digamos.\n");
    ///OPCOES
    printf(" 1- Inimigos? \n");
    printf(" 2- Entendi, vou entrar e procurar o prefeito para interroga-lo. \n");
    printf(" 3- Inimigos é? Vou averiguar a cena do crime\n");

    fflush(stdin);
    switch(getch()){
        case '1':
            p1131();
        default:
            main();
    }
}

void p33(){
    int opt = 0;
    ///DIALOGO
    printf("Você chocado em rever seu velho “conhecido” de infância, se vira e vai em direção ao seu carro, ignorando a chuva, você abre a porta do seu carro, entra, liga o motor e vai para casa descansar.\n");

    ///OPCOES

    fflush(stdin);
    switch(getch()){
        default:
            main();
    }
}




