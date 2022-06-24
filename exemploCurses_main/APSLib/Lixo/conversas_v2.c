#include "APSLib.h"

void prefeito(gameData * game){

    char nome[50];
    strcpy(nome, game->nomePersonagem);
    printf("\n\nPrefeito Jonny - Oh, Detetive %s, 1 segundo, deixe eu enxugar minhas lagrimas... Sniff... Pronto, posso ajudar em algo sobre a investigacao criminal?",nome);
    printf("\n1- Me fale sobre sua mulher. \n2- Onde voce estava quando as luzes se apagaram? \n3- Voce escutou algo quando a energia caiu?");
    int a=0;
    scanf("%d",&a);
    switch(a){
        case 1:{
            printf("Prefeito Jonny - Jessica era uma mulher complicada, mas eu a amava. Havia momentos em que nos brigavamos e eu acabava passando dos limites, mas tambem ela era muito controladora, mal deixava eu sair com meus amigos e tambem gastava dinheiro de mais, mas fora as partes ruins, ela era perfeita...");
            int c =0;
            printf("\n1- Alguem da festa possuia algo contra sua mulher?\n 2- Como voce esta?\n 3- Entendo, meus pesames...");
            scanf("%d",&c);
            switch(c){
                case 1 :{
                    printf("\n\nPrefeito Jonny – Mas e claro que nao! Jessica possuia defeitos, mas nao o suficiente para alguem assassinar ela!");
                    return;
                }
                case 2:{
                    printf("\n\nPrefeito Jonny – Estou superando ainda essa coisa toda, mas acho que vou ficar bem. Nada que uma segunda dama nao resolva, nao? he-he... (ele da uma risada sem graça)");
                    return;
                }
                case 3 :{
                    printf("\n\nPrefeito Jonny – Obrigado, Detetive...");
                    return;
                }
            }
        }
        case 2:{
            printf("\n\nPrefeito Jonny – Eu estava descendo as escadas do segundo andar junto com o mordomo procurando alguma lanterna ou qualquer outra fonte de luz.");
            int c =0;
            printf("\n 1- Alguem da festa possuía algo contra sua mulher?\n 2- Como voce esta?\n 3- Entendo, meus pesames...");
            scanf("%d",&c);
            switch(c){
                case 1 :{
                    printf("\n\nPrefeito Jonny – Mas e claro que nao! Jessica possuia defeitos, mas nao o suficiente para alguem assassinar ela!");
                    return;
                }
                case 2:{
                    printf("\n\nPrefeito Jonny – Estou superando ainda essa coisa toda, mas acho que vou ficar bem. Nada que uma segunda dama nao resolva, nao? he-he... (ele da uma risada sem graça)");
                    return;
                }
                case 3 :{
                    printf("\n\nPrefeito Jonny – Obrigado, Detetive...");
                    return;
                }
            }
        }
        case 3 :{
            printf("\n\nPrefeito Jonny - Estava trovejando tanto que eu so escutei o barulho dos raios.");
            printf("\n 1- Alguem da festa possuía algo contra sua mulher?\n 2- Como voce esta?\n 3- Entendo, meus pesames...");
            int c =0;
            scanf("%d",&c);
            switch(c){
                case 1 :{
                    printf("\n\nPrefeito Jonny – Mas e claro que nao! Jessica possuia defeitos, mas nao o suficiente para alguem assassinar ela!");
                    return;
                }
                case 2:{
                    printf("\n\nPrefeito Jonny – Estou superando ainda essa coisa toda, mas acho que vou ficar bem. Nada que uma segunda dama nao resolva, nao? he-he... (ele da uma risada sem graça)");
                    return;
                }
                case 3 :{
                    printf("\n\nPrefeito Jonny – Obrigado, Detetive...");
                    return;
                }
            }
        }
    }
}


void policial(gameData * game){

    char nome[50];
    strcpy(nome, game->nomePersonagem);

    printf("\n\n##########O policial James, um velho amigo de infancia abre a porta e lhe recebe.##########\n\n");
    printf("Policial James - Vamos entre, a chuva esta muito forte, afinal de contas, o que faz aqui? Nao sabia que tambem era amigo do prefeito. ");

    int a = 0, b=0;
        // primeira interação
        printf(" \n\n 1 - Ola James.\n 2 - Eu recebi uma ligacao falando sobre um assassinato.\n 3 - EU?! O QUE VOCE FAZ AQUI?");
        scanf("%d",&a);
    switch(a){
        case 1:{// termina em Caso 3-4 (3-3) (1-1)
            printf("\n\n Policial James - Ola de novo, mas me conta logo, o que voce faz aqui\n?");
            int seg =0;

            printf("\n\n 1- Ah, eu fui chamado para resolver algum assassinato ou algo assim. \n 2- Eu recebi uma ligacao falando sobre um assassinato.\n 3- Eu nao vou te falar nada seu otario.");
            scanf("%d",&seg);
            // segunda interação se a pessoa escolher 1 no inicio
            switch(seg){
                case 1:{//1-2 (1-1)
                    printf("\n\nPolicial James - Ah sim, entao tambem te chamaram, e o seguinte, o prefeito resolveu dar uma festa aqui hoje, mas nao acabou muito bem. Na verdade, a mulher dele esta morta la no banheiro, e pra piorar ninguem viu quem foi por causa das luzes terem se apagado.");
                    printf("\n\n1- Entendo, os convidados ainda estao ai dentro ai? \n2- Um assassinato as cegas, hmmm. O prefeito esta ai? \n3- Compreendo... Algum suspeito?");
                    int j = 0;
                    scanf("%d",&j);
                    switch(j){
                        case 1:{//Caso 1-3 (1-2)
                            printf("\n\nPolicial James - Claro! O prefeito esta no quarto aqui atras, os outros convidados estao ai pela mansão.");
                            return;
                        }
                        case 2 :{ // Caso 2-3 (1-2)
                            printf("\n\nPolicial James - Claro! O prefeito esta no quarto aqui atras, os outros convidados estao ai pela mansao.");
                            return;
                        }
                        case 3:{
                            printf("\n\nPolicial James – Algum? Sinceramente, boa sorte em descobrir quem foi o culpado, ela tinha muitos... Bem... “Inimigos” assim digamos.");
                            printf("\n\n1- Inimigos? \n 2- Entendi, vou entrar e procurar o prefeito para interroga-lo. \n 3- Inimigos e? Vou averiguar a cena do crime");
                            int s =0;
                            scanf("%d",&s);
                            switch(s){
                                case 1:{
                                    printf("\n\nPolicial James - E, inimigos, que Deus o tenha, mas para falar a verdade, ela era insuportavel, sempre se achando melhor que tudo e todos, digamos que era uma pessoa dificil de conviver...");
                                    return;
                                }
                                case 2: return;
                                case 3: return;

                            }
                        }
                    }
                }
            }
        }
        case 2:{ // caso responda 2 interação Caso 2-1
            printf("\n\nPolicial James - Ah sim, entao tambem te chamaram, e o seguinte, o prefeito resolveu dar uma festa aqui hoje, mas nao acabou muito bem. Na verdade, a mulher dele esta morta la no banheiro, e pra piorar ninguem viu quem foi por causa das luzes terem se apagado. ");
            printf("\n\n1- Entendo, os convidados ainda estao ai dentro ai? \n2- Um assassinato as cegas, hmmm. O prefeito esta ai? \n3- Compreendo... Algum suspeito?");
            int j = 0;
            scanf("%d",&j);
            switch(j){
                case 1:{
                    printf("\n\nPolicial James – Claro! O prefeito esta no quarto aqui atras, os outros convidados estao ai pela mansao. ");
                    return;
                }
                case 2:{
                    printf("\n\nPolicial James – Claro! O prefeito esta no quarto aqui atras, os outros convidados estao aí pela mansao. ");
                    return;
                }
                case 3:{
                    printf("\n\nPolicial James – Algum? Sinceramente, boa sorte em descobrir quem foi o culpado, ela tinha muitos... Bem... “Inimigos” assim digamos.  ");
                    printf("\n\n1- Inimigos? \n 2- Entendi, vou entrar e procurar o prefeito para interroga-lo. \n 3- Inimigos e? Vou averiguar a cena do crime");
                    int s =0;
                    scanf("%d",&s);
                    switch(s){
                        case 1:{
                            printf("\n\nPolicial James - E, inimigos, que Deus o tenha, mas para falar a verdade, ela era insuportavel, sempre se achando melhor que tudo e todos, digamos que era uma pessoa dificil de conviver...");
                            return;
                        }
                        case 2: return;
                        case 3: return;
                    }
                }
            }
        }
        case 3:{ // caso responda 3 na interação Caso 3-1
            printf("\n\nPolicial James – Ei! O que isso cara, se acalma um pouco... ");
            int j=0;
            printf("\n1 - ME ACALMAR?! COM VOCE SEMPRE ROUBANDO MEUS CASOS?! EU VOU TE QUEBRAR NA PORRADA! \n2 - Perdao pelo susto, e que faz muito tempo que nao te vejo... Mas me conta, o que que aconteceu aqui? \n 3 - **Ir embora** ");
            scanf("%d",&j);
            switch(j){
                case 1:{
                    printf("\n\nPolicial James – Olha o jeito que voce fala comigo! Vai para parede com as maos na cabeça! ");
                    printf("\n\n##########Nisso, James saca sua arma e aponta contra voce.##########");
                    printf("\n\nPolicial James - Ja chega %s, nao e a primeira vez que voce usa de desacato para me tirar do serio! Voce vai para cadeia. ",nome);
                    printf("\n\n##########Policial James algema suas maos e o leva para viatura.##########");
                    printf("##########VOCE VAI PARA CADEIA ##########");
                    return;
                }
                case 2:{
                    printf("Policial James – Ta ta, mas me conta logo, o que voce faz aqui? ");
                    int s =0;
                    printf("\n1- Ah, eu fui chamado para resolver algum assassinato ou algo assim.\n 2- Eu recebi uma ligacao falando sobre um assassinato.\n 3- Eu nao vou te falar nada seu otario.");
                    scanf("%d",&s);
                    switch(s){
                        case 1:{
                            printf("\n\nPolicial James - Ah sim, entao tambem te chamaram, e o seguinte, o prefeito resolveu dar uma festa aqui hoje, mas nao acabou muito bem. Na verdade, a mulher dele esta morta la no banheiro, e pra piorar ninguem viu quem foi por causa das luzes terem se apagado.");
                            printf("\n\n1- Entendo, os convidados ainda estao ai dentro ai? \n2- Um assassinato as cegas, hmmm. O prefeito esta ai? \n3- Compreendo... Algum suspeito?");
                            int j = 0;
                            scanf("%d",&j);
                            switch(j){
                                case 1:{
                                    printf("\n\nPolicial James - Claro! O prefeito esta no quarto aqui atras, os outros convidados estao ai pela mansão.");
                                    return;
                                }
                                case 2:{
                                    printf("\n\nPolicial James - Claro! O prefeito esta no quarto aqui atras, os outros convidados estao ai pela mansao.");
                                    return;
                                }
                                case 3:{
                                    printf("\n\nPolicial James – Algum? Sinceramente, boa sorte em descobrir quem foi o culpado, ela tinha muitos... Bem... “Inimigos” assim digamos.");
                                    printf("\n\n1- Inimigos? \n 2- Entendi, vou entrar e procurar o prefeito para interroga-lo. \n 3- Inimigos e? Vou averiguar a cena do crime");
                                    int ta =0;
                                    scanf("%d",&ta);
                                    switch(ta){
                                        case 1:{
                                            printf("\n\nPolicial James - E, inimigos, que Deus o tenha, mas para falar a verdade, ela era insuportavel, sempre se achando melhor que tudo e todos, digamos que era uma pessoa dificil de conviver...");
                                            return;
                                        }
                                        case 2: return;
                                        case 3: return;
                                    }
                                }
                            }
                        }
                        case 2:{
                            printf("\n\nPolicial James – A primeira dama foi assassinada aqui hoje durante a festa que o prefeito tava dando, mas sinceramente, boa sorte em descobrir quem foi o culpado, ela tinha muitos... Bem... “Inimigos” assim digamos.");
                            printf("\n\nPolicial James – Algum? Sinceramente, boa sorte em descobrir quem foi o culpado, ela tinha muitos... Bem... “Inimigos” assim digamos.");
                            printf("\n\n1- Inimigos? \n 2- Entendi, vou entrar e procurar o prefeito para interroga-lo. \n 3- Inimigos e? Vou averiguar a cena do crime");
                            int s =0;
                            scanf("%d",&s);
                            switch(s){
                                case 1:{
                                    printf("\n\nPolicial James - E, inimigos, que Deus o tenha, mas para falar a verdade, ela era insuportavel, sempre se achando melhor que tudo e todos, digamos que era uma pessoa dificil de conviver...");
                                    return;
                                }
                                case 2: return;
                                case 3: return;
                            }
                        }
                        case 3:{
                            printf("\n\nPolicial James – Olha o jeito que voce fala comigo! Vai para parede com as maos na cabeça! ");
                            printf("\n\n##########Nisso, James saca sua arma e aponta contra voce.##########");
                            printf("\n\nPolicial James - Ja chega %s, nao e a primeira vez que voce usa de desacato para me tirar do serio! Voce vai para cadeia. ",nome);
                            printf("\n\n##########Policial James algema suas maos e o leva para viatura.##########");
                            printf("##########VOCE VAI PARA CADEIA ##########");
                            return;
                        }
                    }
                }
                case 3:{
                    printf("Voce chocado em rever seu velho “conhecido” de infancia, se vira e vai em direção ao seu carro, ignorando a chuva, voce abre a porta do seu carro, entra, liga o motor e vai para casa descançar.");
                    return;
                }
            }
        }
    }
}


void corpo(gameData * game){

    char nome[50];
    strcpy(nome, game->nomePersonagem);
    printf("\n\nVoce para e observa o banheiro todo baguncado com remedios e produtos de beleza jogados no chao, e depois o corpo, com uma leitura fria da situacao, voce nao ve marcas de luta, do lado do corpo ha uma municao de 9mm (tipo de arma) no chao e ve que a o vestido esta intacto e levemente ensanguentado na regiao do abdomen e possuia sangue em seus dedos, provavelmente o ferimento esta na barriga dela e ela tentou tampar o machucado com as maos, mas para nao interferir nas provas ate a chegada do perito criminal voce nao abre o vestido para averiguar a lesao.\n\n");
    return;
}


void policial_2 (gameData * game){

    char nome[50];
    strcpy(nome, game->nomePersonagem);
    printf("\n\nPolicial James - AH, voce de novo, descobriu algo?");
    printf("\n\n 1- Voce estava aqui durante a festa? \n 2- Eu sei o que aconteceu! \n 3- Ainda nao");
    int a =0;
    scanf("%d",&a);
    switch(a){
        case 1 :{
            printf("\n\nPolicial James – Eu estava, mas eu vim aqui com meu uniforme porque eu havia acabado de sair do expediente quando o prefeito me convidou.");
            printf("\n 1- Voce esta com a sua arma? \n2- Ja que voce estava aqui, tem alguma suspeita? \n3- ...");
            int s =0;
            scanf("%d",&s);

            switch (s){
                case 1:{
                    printf("Policial James - Estou sim! E uma 9mm, tenho que carregar ela por causa do trabalho.");
                    return;
                }
            case 2:{
                    printf("Policial James – Talvez o prefeito, a primeira dama possuia um seguro de vida milionario, e do jeito que o prefeito vai nas eleiçoes, eu nao duvidaria nada se isso fosse um golpe... Fica so entre nos, mas o casamento deles tambem não ia bem.");
                    return;
                }
            case 3:
                return;
            }
        }
        case 2:{
            printf("\n\nPolicial James - Sabe?! Quem foi o assassino entao?");
            printf("\n\n 1- Foi o prefeito! \n 2- Foi o mordomo! \n 3- Foi o professor! \n 4- Foi o filho dela! \n 5- Foi voce! \n 6- Outros. \n 7- Eu ainda nao sei...");
            int j = 0;
            scanf("%d",&j);

            if (j==1){
                printf("\n\nVoce aponta o prefeito como culpado, e ele vai preso, porem semanas depois, foi descoberto que o prefeito nao era o real culpado! Voce prendeu um inocente!");
                printf("\n\n########## UM INOCENTE FOI PRESO ##########\n\n");
                return;
            }
            if (j==2){
                printf("\n\nVoce aponta o mordomo como culpado, e ele vai preso, porem semanas depois, foi descoberto que o mordomo nao era o real culpado! Voce prendeu um inocente!");
                printf("\n\n########## UM INOCENTE FOI PRESO ##########\n\n");
                return;
            }
            if (j==3){
                printf("\n\nVoce aponta o professor como culpado, e ele vai preso, porem semanas depois, foi descoberto que o professor nao era o real culpado! Voce prendeu um inocente!");
                printf("\n\n########## UM INOCENTE FOI PRESO ##########\n\n");
                return;
            }
            if (j==4){
                printf("\n\nVoce aponta o filho  como culpado, e ele vai preso, porem semanas depois, foi descoberto que o filho nao era o real culpado! Voce prendeu um inocente!");
                printf("\n\n########## UM INOCENTE FOI PRESO ##########\n\n");
                return;
            }
            if(j==5){
                printf("\n\nVoce aponta o mordomo como culpado, e ele vai preso, porem semanas depois, foi descoberto que o mordomo nao era o real culpado! Voce prendeu um inocente!");
                printf("\n\n########## UM INOCENTE FOI PRESO ##########\n\n");
                return;
            }
            if(j==6){
                printf("\n\nPolicial James - Como?");
                printf("\n\nO prefeito sai de seu quarto, vai em sua direcao e comeca a falar.");
                printf("\n\nPrefeito – Outros? Como assim outros?");
                printf("\n\nDetetive %s - Na verdade, nos temos aqui uma cena de ...\n",nome);
                char k[100];
                scanf("%s",k);

                if (!strcmp(k,"suicidio")){//caso correto
                    printf("\n\nDetetive %s – Prefeito, sua mulher infelizmente se suicidou, apesar de todo o luxo em que vivia, ela era infeliz com seu casamento e alem de nao receber amor de seu filho, ela estava insegura se seu padrao de vida mudasse apos a provavel perca das eleicoes, e se for julgar pela quantidade de remedios no banheiro acho que a situacao dela nao estava legal. Por isso eu creio que a causa da morte tenha sido suicidio! Possivelmente ela se dopou de remedios e apos isso fez um ferimento com as proprias unhas em sua barriga, mas ainda assim creio que o motivo da morte foi uma overdose de remedios.",nome);
                    printf("\n\nApos determinar o caso, voce se retira da mansao, aproveitando que a chuva ja passou, voce anda tranquilamente ate seu carro. Um mes depois do ocorrido, voce le nos jornais uma noticia sobre o incidente com a primeira dama, onde os medicos legistas e peritos confirmaram a causa da morte, parabens Detetive %s, sua acusacao estava correta!",nome);
                    printf("\n\n############PARABENS############");
                    return;
                }
                if (!strcmp(k,"Suicidio")){//caso correto
                    printf("\n\nDetetive %s - Prefeito, sua mulher infelizmente se suicidou, apesar de todo o luxo em que vivia, ela era infeliz com seu casamento e alem de nao receber amor de seu filho, ela estava insegura se seu padrao de vida mudasse apos a provavel perca das eleicoes, e se for julgar pela quantidade de remedios no banheiro acho que a situacao dela nao estava legal. Por isso eu creio que a causa da morte tenha sido suicidio! Possivelmente ela se dopou de remedios e apos isso fez um ferimento com as proprias unhas em sua barriga, mas ainda assim creio que o motivo da morte foi uma overdose de remedios.",nome);
                    printf("\n\nApos determinar o caso, voce se retira da mansao, aproveitando que a chuva ja passou, voce anda tranquilamente ate seu carro. Um mes depois do ocorrido, voce le nos jornais uma noticia sobre o incidente com a primeira dama, onde os medicos legistas e peritos confirmaram a causa da morte, parabens Detetive %s, sua acusacao estava correta!",nome);
                    printf("\n\n############\tPARABENS\t############");
                    return;
                }
                if (strcmp(k,"suicidio")){
                    printf("\n\nApos essa afirmacao, o perito criminal entra pela porta da mansao e vai fazer a analise da cena do crime, e depois de 2 a 3 horas de espera ele sai do banheiro com o veredito.");
                    printf("\n\nLegista – A causa da morte foi suicidio.");
                    printf("\n\nDesacreditado e desmoralizado com sua capacidade de resolucao de crimes, voce vai para casa comer sorvete e pensar na vida.");
                    printf("\n\n \t\t\t # FINAL SEM MORAL # ");
                    return;
                }
            }
        }
        case 3:{
            printf("%s sai do dialogo",nome);
            return;
        }
    }
}

void professor(gameData * game){

    char nome[50];
    strcpy(nome, game->nomePersonagem);
    printf("\n\nProfessor Samuel ? Pelas suas vestimentas presumo que seja o detetive, prazer, sou Samuel, professor particular do filho do prefeito.");
    printf("\n 1- Poderia me dizer como e sua relacao com a familia do prefeito?\n 2- Onde voce estava quando a luz voltou?\n 3- O que e essa macha cor de vinho em sua gravata?");
    int a =0;
    scanf("%d",&a);
    switch(a){
        case 1:{
            printf("\n\nProfessor Samuel ? E boa, o filho deles e um pouco estranho e quieto de mais, mas e um garoto bom, ja o casal, eu tinha minhas intrigas com eles, principalmente depois que diminuiram meu salario pela metade, mas nada demais. Quer dizer exceto pela ultima vez onde houveram ameacas, mas nada alem disso, somos amigos... Colegas... Conhecidos... E, conhecidos se encaixa mais...");
            int k =0;
            printf("\n\n 1 - Como sao as aulas com o filho do casal?\n 2 - Caso voce tenha visto a cena do crime, com que arma acha que foi feito o assassinato?\n 3 - Como voce descreveria o casamento do prefeito?");
            scanf("%d",&k);
            switch(k){
                case 1:{
                    printf("\n\nProfessor Samuel ? Sao normais, so que o menino nao tem muita educacao e e um pouco estressante, mas fora isso sao tranquilas.");
                    return;
                }
                case 2:{
                    printf("\n\nProfessor Samuel ? Eu nao olhei muito, mas pelo que eu vi a coisa foi feia, ela tava toda rasgada com cortes profundos, acho que algum maniaco desesperado tenha feito isso com uma faca.");
                    return;
                }
                case 3:{
                    printf("\n\nProfessor Samuel ? Sinceramente, era complicado, na maioria das vezes eu via o prefeito com sua secretaria em casa enquanto a primeira dama nao estava, nao quero tirar conclusoes precipitadas, mas acho que nao era tao estavel nao.");
                    return;
                }
            }
        }
        case 2:{
            printf("\n\nProfessor Samuel ? Eu estava aqui no saguao, nao conseguia ver nada quando a luz apagou, entao eu resolvi sentar no chao e esperar voltar.");
            int k =0;
            printf("\n\n 1 - Como sao as aulas com o filho do casal?\n 2 - Caso voce tenha visto a cena do crime, com que arma acha que foi feito o assassinato?\n 3 - Como voce descreveria o casamento do prefeito?");
            scanf("%d",&k);
            switch(k){
                case 1:{
                    printf("\n\nProfessor Samuel ? Sao normais, so que o menino nao tem muita educacao e e um pouco estressante, mas fora isso sao tranquilas.");
                    return;
                }
                case 2:{
                    printf("\n\nProfessor Samuel ? Eu nao olhei muito, mas pelo que eu vi a coisa foi feia, ela tava toda rasgada com cortes profundos, acho que algum maniaco desesperado tenha feito isso com uma faca.");
                    return;
                }
                case 3:{
                    printf("\n\nProfessor Samuel ? Sinceramente, era complicado, na maioria das vezes eu via o prefeito com sua secretaria em casa enquanto a primeira dama nao estava, nao quero tirar conclusoes precipitadas, mas acho que nao era tao estavel nao.");
                    return;
                }
            }
        }
        case 3:{
            printf("\n\nProfessor Samuel ? E vinho apenas...");
            int k =0;
            printf("\n\n 1 - Como sao as aulas com o filho do casal?\n 2 - Caso voce tenha visto a cena do crime, com que arma acha que foi feito o assassinato?\n 3 - Como voce descreveria o casamento do prefeito?");
            scanf("%d",&k);
            switch(k){
                case 1:{
                    printf("\n\nProfessor Samuel ? Sao normais, so que o menino nao tem muita educacao e e um pouco estressante, mas fora isso sao tranquilas.");
                    return;
                }
                case 2:{
                    printf("\n\nProfessor Samuel ? Eu nao olhei muito, mas pelo que eu vi a coisa foi feia, ela tava toda rasgada com cortes profundos, acho que algum maniaco desesperado tenha feito isso com uma faca.");
                    return;
                }
                case 3:{
                    printf("\n\nProfessor Samuel ? Sinceramente, era complicado, na maioria das vezes eu via o prefeito com sua secretaria em casa enquanto a primeira dama nao estava, nao quero tirar conclusoes precipitadas, mas acho que nao era tao estavel nao.");
                    return;
                }
            }
        }
    }
}


void filho (gameData * game){

    char nome[50];
    strcpy(nome, game->nomePersonagem);
    printf("\n\nFilho Arnold – Quem e voce e que roupa de idiota e essa? Voce por acaso foi convidado? Isso nao e festa fantasia nao! ");
    printf("\n\n 1- Oh moleque, me diz logo, fala um pouco sobre a sua mae.  \n 2- O garoto, voce escutou algo quando a luz apagou? \n 3- So me responde, o que seu professor achava da sua mae?");
    int a =0;
    scanf("%d",&a);
    switch(a){
        case 1 :{
            printf("\n\nFilho Arnold – A velha foi tarde, ela me proibia de sair com os amigos, parou de me dar mesada e ainda me obrigava a\nestudar com o idiota do professor particular, pelo menos agora acho que vou poder jogar videogame em paz!");
            printf("\n 1- Onde o mordomo estava? \n2- Seu pai fica muito em casa? \n3- Qual a profissao dos seus sonhos? ");
            int s =0;
            scanf("%d",&s);

            switch (s){
                case 1:{
                    printf("Filho Arnold – Eu acho que ele tava na porta do banheiro, talvez ele seja o assassino, quem sabe...");
                    return;
                }
                case 2:{
                    printf("Filho Arnold – Ate que fica na parte da manha, mas quando ele sai ele costuma chegar so na madrugada.");
                    return;
                }
                case 3:{
                    printf("Filho Arnold – Eu quero ser herdeiro, acho que e isso.");
                    return;
                }
            }
        }
        case 2:{
            printf("\n\nFilho Arnold – Eu nao me lembro nao, talvez trovejando muito.");
            printf("\n 1- Onde o mordomo estava? \n2- Seu pai fica muito em casa? \n3- Qual a profissao dos seus sonhos? ");
            int s =0;
            scanf("%d",&s);
            switch (s){
                case 1:{
                    printf("\nFilho Arnold - Eu acho que ele tava na porta do banheiro, talvez ele seja o assassino, quem sabe...");
                    return;
                }
                case 2:{
                    printf("\nFilho Arnold - Ate que fica na parte da manha, mas quando ele sai ele costuma chegar so na madrugada.");
                    return;
                }
                case 3:{
                    printf("\nFilho Arnold - Eu quero ser herdeiro, acho que e isso.");
                    return;
                }
            }
        }
        case 3:{
            printf("\n\nFilho Arnold - Ele nao gostava muito dela nao, ainda mais depois que\nela diminuiu o dinheiro que ele ganhava, acho que ele tem inveja da nossa família, eu tento nem falar muito com ele... ");
            printf("\n 1- Onde o mordomo estava? \n2- Seu pai fica muito em casa? \n3- Qual a profissao dos seus sonhos? ");
            int s =0;
            scanf("%d",&s);
            switch (s){
                case 1:{
                    printf("\nFilho Arnold - Eu acho que ele tava na porta do banheiro, talvez ele seja o assassino, quem sabe...");
                    return;
                }
                case 2:{
                    printf("\nFilho Arnold - Ate que fica na parte da manha, mas quando ele sai ele costuma chegar so na madrugada.");
                    return;
                }
                case 3:{
                    printf("\nFilho Arnold - Eu quero ser herdeiro, acho que e isso.");
                    return;
                }
            }
        }
    }
}

void mordomo (gameData * game){

    char nome[50];
    strcpy(nome, game->nomePersonagem);
    printf("\n\nMordomo Donald - Senhor detetive, que noite tragica nao? Posso ajudar sua investigacao respondendo algumas perguntas?");
    printf("\n\n 1- Quais tipos de bebidas voce serviu hoje na festa?  \n 2- Quem foi a pessoa que estava mais proxima da primeira dama quando a luz se apagou? \n 3- Onde voce estava quando acabou a energia?");
    int a =0;
    scanf("%d",&a);
    switch(a){
        case 1 :{
            printf("\n\nMordomo Donald - Hoje foi servido apenas champagne e refrigerante.");
            printf("\n 1- Voce escutou alguma coisa? \n2- Voce viu alguem saindo do banheiro? \n3- Como voce descreveria a primeira dama? ");
            int s =0;
            scanf("%d",&s);
            switch (s){
                case 1:{
                    printf("\nMordomo Donald - Talvez eu esteja enganado, mas me recordo de escutar um barulho muito alto, como um tiro ou algo do tipo.");
                    return;
                }
                case 2:{
                    printf("\nMordomo Donald - A ultima pessoa que saiu do banheiro foi o professor Samuel, quando a luz voltou, ele saiu de la anunciando que havia encontrado um corpo.");
                    return;
                }
                case 3:{
                    printf("\nMordomo Donald - Era uma mulher complicada de se lidar, mas de umas semanas pra ca ela havia começado a agir estranho, estava\nsempre um pouco cansada, comia pouco e sempre estava acordada, raramente eu a via dormindo.");
                    return;
                }
            }
        }
        case 2:{
            printf("\n\nMordomo Donald - Creio que alguns minutos antes da luz se apagar o policial James estava conversando com a primeira dama.");
            printf("\n 1- Voce escutou alguma coisa? \n2- Voce viu alguem saindo do banheiro? \n3- Como voce descreveria a primeira dama? ");
            int s =0;
            scanf("%d",&s);
            switch (s){
                case 1:{
                    printf("\nMordomo Donald - Talvez eu esteja enganado, mas me recordo de escutar um barulho muito alto, como um tiro ou algo do tipo.");
                    return;
                }
                case 2:{
                    printf("\nMordomo Donald - A ultima pessoa que saiu do banheiro foi o professor Samuel, quando a luz voltou, ele saiu de la anunciando que havia encontrado um corpo.");
                    return;
                }
                case 3:{
                    printf("\nMordomo Donald - Era uma mulher complicada de se lidar, mas de umas semanas pra ca ela havia começado a agir estranho, estava\nsempre um pouco cansada, comia pouco e sempre estava acordada, raramente eu a via dormindo.");
                    return;
                }
            }
        }
        case 3:{
            printf("\n\nMordomo Donald - Eu estava no corredor entre o quarto e o salao, mas lembro que alguem estava nas escadas atras de mim.");
            printf("\n 1- Voce escutou alguma coisa? \n2- Voce viu alguem saindo do banheiro? \n3- Como voce descreveria a primeira dama? ");
            int s =0;
            scanf("%d",&s);
            switch (s){
                case 1:{
                    printf("\nMordomo Donald - Talvez eu esteja enganado, mas me recordo de escutar um barulho muito alto, como um tiro ou algo do tipo.");
                    return;
                }
                case 2:{
                    printf("\nMordomo Donald – A ultima pessoa que saiu do banheiro foi o professor Samuel, quando a luz voltou, ele saiu de la anunciando que havia encontrado um corpo.");
                    return;
                }
                case 3:{
                    printf("\nMordomo Donald – Era uma mulher complicada de se lidar, mas de umas semanas pra ca ela havia começado a agir estranho, estava\nsempre um pouco cansada, comia pouco e sempre estava acordada, raramente eu a via dormindo.");
                    return;
                }
            }
        }
    }
}
