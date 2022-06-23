#include "APSLib.h"
#include <string.h>


void policial(gameData * game)
{
    char nome[50];

    strcpy(nome, game->nomePersonagem);

    printf("\n\n##########O policial James, um velho amigo de infancia abre a porta e lhe recebe.##########\n\n");
    printf("Policial James - Vamos entre, a chuva esta muito forte, afinal de contas, o que faz aqui? Nao sabia que tambem era amigo do prefeito. ");

    int a = 0, b=0;
    {    // primeira interação
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
                            case 1://Caso 1-3 (1-2)
                                printf("\n\nPolicial James - Claro! O prefeito esta no quarto aqui atras, os outros convidados estao ai pela mansão.");
                                return;

                            case 2 : // Caso 2-3 (1-2)
                                printf("\n\nPolicial James - Claro! O prefeito esta no quarto aqui atras, os outros convidados estao ai pela mansao.");
                                return;

                            case 3:
                            {
                                printf("\n\nPolicial James – Algum? Sinceramente, boa sorte em descobrir quem foi o culpado, ela tinha muitos... Bem... “Inimigos” assim digamos.");
                                printf("\n\n1- Inimigos? \n 2- Entendi, vou entrar e procurar o prefeito para interroga-lo. \n 3- Inimigos e? Vou averiguar a cena do crime");
                                int s =0;
                                scanf("%d",&s);
                                switch(s)
                                {
                                    case 1:
                                        printf("\n\nPolicial James - E, inimigos, que Deus o tenha, mas para falar a verdade, ela era insuportavel, sempre se achando melhor que tudo e todos, digamos que era uma pessoa dificil de conviver...");
                                        return;
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
                    case 1:
                        printf("\n\nPolicial James – Claro! O prefeito esta no quarto aqui atras, os outros convidados estao ai pela mansao. ");
                        return;
                    case 2:
                        printf("\n\nPolicial James – Claro! O prefeito esta no quarto aqui atras, os outros convidados estao aí pela mansao. ");
                        return;
                    case 3:
                        printf("\n\nPolicial James – Algum? Sinceramente, boa sorte em descobrir quem foi o culpado, ela tinha muitos... Bem... “Inimigos” assim digamos.  ");
                        printf("\n\n1- Inimigos? \n 2- Entendi, vou entrar e procurar o prefeito para interroga-lo. \n 3- Inimigos e? Vou averiguar a cena do crime");
                        int s =0;
                        scanf("%d",&s);
                        switch(s){
                            case 1:
                                printf("\n\nPolicial James - E, inimigos, que Deus o tenha, mas para falar a verdade, ela era insuportavel, sempre se achando melhor que tudo e todos, digamos que era uma pessoa dificil de conviver...");
                                return;
                            case 2: return;
                            case 3: return;
                        }
                }
            }


    case 3: // caso responda 3 na interação Caso 3-1
    {
        printf("\n\nPolicial James – Ei! O que isso cara, se acalma um pouco... ");
        int j=0;
        printf("\n1 - ME ACALMAR?! COM VOCE SEMPRE ROUBANDO MEUS CASOS?! EU VOU TE QUEBRAR NA PORRADA! \n2 - Perdao pelo susto, e que faz muito tempo que nao te vejo... Mas me conta, o que que aconteceu aqui? \n 3 - **Ir embora** ");
        scanf("%d",&j);
        switch(j)
        {
        case 1:
            {
                printf("\n\nPolicial James – Olha o jeito que voce fala comigo! Vai para parede com as maos na cabeça! ");
                printf("\n\n##########Nisso, James saca sua arma e aponta contra voce.##########");
                printf("\n\nPolicial James - Ja chega %s, nao e a primeira vez que voce usa de desacato para me tirar do serio! Voce vai para cadeia. ",nome);
                printf("\n\n##########Policial James algema suas maos e o leva para viatura.##########");
                printf("##########VOCE VAI PARA CADEIA ##########");
                return;
            }
        case 2:
            {
                printf("Policial James – Ta ta, mas me conta logo, o que voce faz aqui? ");
                int s =0;
                printf("\n1- Ah, eu fui chamado para resolver algum assassinato ou algo assim.\n 2- Eu recebi uma ligacao falando sobre um assassinato.\n 3- Eu nao vou te falar nada seu otario.");
                scanf("%d",&s);
                switch(s)
                {
                case 1:
                    {
                        printf("\n\nPolicial James - Ah sim, entao tambem te chamaram, e o seguinte, o prefeito resolveu dar uma festa aqui hoje, mas nao acabou muito bem. Na verdade, a mulher dele esta morta la no banheiro, e pra piorar ninguem viu quem foi por causa das luzes terem se apagado.");
                         printf("\n\n1- Entendo, os convidados ainda estao ai dentro ai? \n2- Um assassinato as cegas, hmmm. O prefeito esta ai? \n3- Compreendo... Algum suspeito?");
               int j = 0;
               scanf("%d",&j);
               switch(j)
               {
               case 1:
                {
                    printf("\n\nPolicial James - Claro! O prefeito esta no quarto aqui atras, os outros convidados estao ai pela mansão.");
                    return;
                }

               case 2:
                {
                    printf("\n\nPolicial James - Claro! O prefeito esta no quarto aqui atras, os outros convidados estao ai pela mansao.");
                    return;
                }

               case 3:
                {
                    printf("\n\nPolicial James – Algum? Sinceramente, boa sorte em descobrir quem foi o culpado, ela tinha muitos... Bem... “Inimigos” assim digamos.");
                    printf("\n\n1- Inimigos? \n 2- Entendi, vou entrar e procurar o prefeito para interroga-lo. \n 3- Inimigos e? Vou averiguar a cena do crime");
                int ta =0;
                scanf("%d",&ta);

                switch(ta)
                {
                case 1:
                    {
                        printf("\n\nPolicial James - E, inimigos, que Deus o tenha, mas para falar a verdade, ela era insuportavel, sempre se achando melhor que tudo e todos, digamos que era uma pessoa dificil de conviver...");
                        return;
                    }
                case 2: return;
                case 3: return;

                    }
                }
            }
        }
                case 2:
                    {
                      printf("\n\nPolicial James – A primeira dama foi assassinada aqui hoje durante a festa que o prefeito tava dando, mas sinceramente, boa sorte em descobrir quem foi o culpado, ela tinha muitos... Bem... “Inimigos” assim digamos.");

                    printf("\n\nPolicial James – Algum? Sinceramente, boa sorte em descobrir quem foi o culpado, ela tinha muitos... Bem... “Inimigos” assim digamos.");
                    printf("\n\n1- Inimigos? \n 2- Entendi, vou entrar e procurar o prefeito para interroga-lo. \n 3- Inimigos e? Vou averiguar a cena do crime");
                int s =0;
                scanf("%d",&s);

                switch(s)
                {
                case 1:
                    {
                        printf("\n\nPolicial James - E, inimigos, que Deus o tenha, mas para falar a verdade, ela era insuportavel, sempre se achando melhor que tudo e todos, digamos que era uma pessoa dificil de conviver...");
                        return;
                    }
                case 2: return;
                case 3: return;

                    }
    }
                case 3:
                    {
                      printf("\n\nPolicial James – Olha o jeito que voce fala comigo! Vai para parede com as maos na cabeça! ");
                printf("\n\n##########Nisso, James saca sua arma e aponta contra voce.##########");
                printf("\n\nPolicial James - Ja chega %s, nao e a primeira vez que voce usa de desacato para me tirar do serio! Voce vai para cadeia. ",nome);
                printf("\n\n##########Policial James algema suas maos e o leva para viatura.##########");
                printf("##########VOCE VAI PARA CADEIA ##########");
                return;
                    }

                }}
        case 3:
            {
                printf("Voce chocado em rever seu velho “conhecido” de infancia, se vira e vai em direção ao seu carro, ignorando a chuva, voce abre a porta do seu carro, entra, liga o motor e vai para casa descançar.");
                return;
            }







}
}
   }}}


void corpo(char *nome[])
{
    printf("\n\nVoce para e observa o corpo, com uma leitura fria da situacao, voce nao ve marcas de luta, do lado do corpo ha uma munição de 9mm (tipo de arma) no chao e ve que a o vestido esta cheio de sangue, provavelmente o ferimento provavelmente esta na barriga dela, mas para nao interferir nas provas ate a chegada do perito criminal voce nao abre o vestido.\n\n");
    return;
}


void policial_2 (char *nome[])
{
    printf("\n\nPolicial James - AH, voce de novo, descobriu algo?");
    printf("\n\n 1- Voce estava aqui durante a festa? \n 2- Eu sei o que aconteceu! \n 3- Ainda nao");
    int a =0;
    scanf("%d",&a);
    switch(a)
    {
    case 1 :
        {
            printf("\n\nPolicial James – Eu estava, mas eu vim aqui com meu uniforme porque eu havia acabado de sair do expediente quando o prefeito me convidou.");
            printf("\n 1- Voce esta com a sua arma? \n2- Ja que voce estava aqui, tem alguma suspeita? \n3- ...");
            int s =0;
            scanf("%d",&s);

            switch (s)
            {
            case 1:
                {
                    printf("Policial James - Estou sim! E uma 9mm, tenho que carregar ela por causa do trabalho.");
                    return;
                }
            case 2:
                {
                    printf("Policial James – Talvez o prefeito, a primeira dama possuia um seguro de vida milionario, e do jeito que o prefeito vai nas eleiçoes, eu nao duvidaria nada se isso fosse um golpe... Fica so entre nos, mas o casamento deles tambem não ia bem.");
                    return;
                }
            case 3:
                return;
            }

        }
    case 2:
     {
         printf("\n\nPolicial James - Sabe?! Quem foi o assassino entao?");
         printf("\n\n 1- Foi o prefeito! \n 2- Foi o mordomo! \n 3- Foi o professor! \n 4- Foi o filho dela! \n 5- Foi voce! \n 6- Outros. \n 7- Eu ainda nao sei...");
         int j = 0;
         scanf("%d",&j);

         if (j==1)
            {
            printf("\n\nVoce aponta o prefeito como culpado, e ele vai preso, porem semanas depois, foi descoberto que o prefeito nao era o real culpado! Voce prendeu um inocente!");
            printf("\n\n########## UM INOCENTE FOI PRESO ##########\n\n");
            return;
            }
            if (j==2)
            {
            printf("\n\nVoce aponta o mordomo como culpado, e ele vai preso, porem semanas depois, foi descoberto que o mordomo nao era o real culpado! Voce prendeu um inocente!");
            printf("\n\n########## UM INOCENTE FOI PRESO ##########\n\n");
            return;
            }
            if (j==3)
            {
            printf("\n\nVoce aponta o professor como culpado, e ele vai preso, porem semanas depois, foi descoberto que o professor nao era o real culpado! Voce prendeu um inocente!");
            printf("\n\n########## UM INOCENTE FOI PRESO ##########\n\n");
            return;
            }
            if (j==4)
            {
            printf("\n\nVoce aponta o filho  como culpado, e ele vai preso, porem semanas depois, foi descoberto que o filho nao era o real culpado! Voce prendeu um inocente!");
            printf("\n\n########## UM INOCENTE FOI PRESO ##########\n\n");
            return;
            }
            if(j==5)
            {
            printf("\n\nVoce aponta o mordomo como culpado, e ele vai preso, porem semanas depois, foi descoberto que o mordomo nao era o real culpado! Voce prendeu um inocente!");
            printf("\n\n########## UM INOCENTE FOI PRESO ##########\n\n");
            return;
            }
            if(j==6)
            {
                printf("\n\nPolicial James - Como?");
                printf("\n\nO prefeito sai de seu quarto em sua direcao e comeca a falar.");
                printf("\n\nDetetive %s - Na verdade, nos temos aqui uma cena de ...\n",nome);
                char k[100];
                scanf("%s",k);

                if (!strcmp(k,"suicidio"))//caso correto
                {
                 printf("\n\nDetetive %s – Prefeito, sua mulher infelizmente se suicidou, apesar de todo o luxo em que vivia, ela era infeliz com seu casamento e alem de nao receber amor de seu filho, ela estava insegura se seu padrao de vida mudasse apos a provavel perca das eleicoes, e se for julgar pela quantidade de remedios no banheiro acho que a situacao dela nao estava legal. Por isso eu creio que a causa da morte tenha sido suicidio! Possivelmente ela se dopou de remedios e apos isso fez um ferimento com as proprias unhas em sua barriga, mas ainda assim creio que o motivo da morte foi uma overdose de remedios.",nome);
                 printf("\n\nApos determinar o caso, voce se retira da mansao, aproveitando que a chuva ja passou, voce anda tranquilamente ate seu carro. Um mes depois do ocorrido, voce le nos jornais uma noticia sobre o incidente com a primeira dama, onde os medicos legistas e peritos confirmaram a causa da morte, parabens Detetive %s, sua acusacao estava correta!",nome);
                 printf("\n\n############PARABENS############");
                 return;
                }
                 if (!strcmp(k,"Suicidio"))//caso correto
                {
                 printf("\n\nDetetive %s - Prefeito, sua mulher infelizmente se suicidou, apesar de todo o luxo em que vivia, ela era infeliz com seu casamento e alem de nao receber amor de seu filho, ela estava insegura se seu padrao de vida mudasse apos a provavel perca das eleicoes, e se for julgar pela quantidade de remedios no banheiro acho que a situacao dela nao estava legal. Por isso eu creio que a causa da morte tenha sido suicidio! Possivelmente ela se dopou de remedios e apos isso fez um ferimento com as proprias unhas em sua barriga, mas ainda assim creio que o motivo da morte foi uma overdose de remedios.",nome);
                 printf("\n\nApos determinar o caso, voce se retira da mansao, aproveitando que a chuva ja passou, voce anda tranquilamente ate seu carro. Um mes depois do ocorrido, voce le nos jornais uma noticia sobre o incidente com a primeira dama, onde os medicos legistas e peritos confirmaram a causa da morte, parabens Detetive %s, sua acusacao estava correta!",nome);
                 printf("\n\n############\tPARABENS\t############");
                 return;
                }
                if (strcmp(k,"suicidio"))
                {
                    printf("\n\nApos essa afirmacao, o perito criminal entra pela porta da mansao e vai fazer a analise da cena do crime, e depois de 2 a 3 horas de espera ele sai do banheiro com o veredito.");
                    printf("\n\nLegista – A causa da morte foi suicidio.");
                    printf("\n\nDesacreditado e desmoralizado com sua capacidade de resolucao de crimes, voce vai para casa comer sorvete e pensar na vida.");
                    printf("\n\n \t\t\t # FINAL SEM MORAL # ");
                    return;
                }

            }

         }
    case 3:
        {
            printf("%s sai do dialogo",nome);
            return;
        }
     }
    }

