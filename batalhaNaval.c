#include <stdio.h>
#include <stdlib.h>

void criarTabuleiro(int tabuleiro[10][10]){
    for (int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            tabuleiro[i][j] = 0;
        }
    }
}

void testarSobreposicao(int tabuleiro[10][10], int posicaoL, int posicaoC, int tamanho, int lado, int *validacao){
    switch(lado){
        case 1:
            for (int i=1; i<=tamanho; i++){
                if (tabuleiro[posicaoL][posicaoC] == 0){
                    posicaoL++;
                } else {
                    printf("A posição selecionada está ocupada por outro navio!\n");
                    posicaoL++;
                    *validacao = 0;
                }
            }
        break;
        case 2:
            for (int i=1; i<=tamanho; i++){
                if (tabuleiro[posicaoL][posicaoC] == 0){
                    posicaoC++;
                } else {
                    printf("A posição selecionada está ocupada por outro navio!\n");
                    posicaoC++;
                    *validacao = 0;
                }
            }
        break;
        case 3:
            for (int i=1; i<=tamanho; i++){
                if (tabuleiro[posicaoL][posicaoC] == 0){
                    posicaoL++;
                    posicaoC++;
                } else {
                    printf("A posição selecionada está ocupada por outro navio!\n");
                    posicaoL++;
                    posicaoC++;
                    *validacao = 0;
                }
            }
        break;
        case 4:
            for (int i=1; i<=tamanho; i++){
                if (tabuleiro[posicaoL][posicaoC] == 0){
                    posicaoL--;
                    posicaoC++;
                } else {
                    printf("A posição selecionada está ocupada por outro navio!\n");
                    posicaoL--;
                    posicaoC++;
                    *validacao = 0;
                }
            }
        break;
    }
}

void posicionarNavio(int tabuleiro[10][10], int posicaoL, int posicaoC, int tamanho, int lado){
    switch(lado){
        case 1:
            for (int i=1; i<=tamanho; i++){
                tabuleiro[posicaoL][posicaoC] = 3;
                posicaoL++;
            }
        break;
        case 2:
            for (int i=1; i<=tamanho; i++){
                tabuleiro[posicaoL][posicaoC] = 3;
                posicaoC++;
            }
        break;
        case 3:
            for (int i=1; i<=tamanho; i++){
                tabuleiro[posicaoL][posicaoC] = 3;
                posicaoL++;
                posicaoC++;
            }
        break;
        case 4:
            for (int i=1; i<=tamanho; i++){
                tabuleiro[posicaoL][posicaoC] = 3;
                posicaoL--;
                posicaoC++;
            }
        break;
    }
}


void mostrarTabuleiro(int tabuleiro[10][10]){
    for (int i=0; i<10; i++){
        printf("\n");
        for(int j=0; j<10; j++){
            printf("%d, ", tabuleiro[i][j]);
        }
    }
}

int main(){
    //declaração de variaveis
    int tabuleiro [10][10];
    int navios[4][4], teste;
    int i, j, numeronavio;
    int aux, soma, testesobreposicao;
    //preencher o tabuleiro
    criarTabuleiro(tabuleiro);
    
    //cadastrando dados dos navios, com máximo de 4 navios.
    
    numeronavio = 0;

    while (numeronavio<4){

        printf("Colocando navio no tabuleiro: \n");
        do{
            printf("Escolha um numero de 1 a 10 para a linha da posição inicial do navio: \n");
            scanf("%d", &navios[numeronavio][0]);
            navios[numeronavio][0]--;
            if((navios[numeronavio][0]<0) || (navios[numeronavio][0]>9)){
                printf("\nO valor escolhido é inválido!");
            }
        }while ((navios[numeronavio][0]<0) || (navios[numeronavio][0]>9));
        do{
            printf("Escolha um numero de 1 a 10 para a coluna da posição inicial do navio: \n");
            scanf("%d", &navios[numeronavio][1]);
            navios[numeronavio][1]--;
            if((navios[numeronavio][1]<0) || (navios[numeronavio][1]>9)){
                printf("\nO valor escolhido é inválido!");
            }
        }while ((navios[numeronavio][1]<0) || (navios[numeronavio][1]>9));
        do{
            printf("Escolha um numero de 1 a 4 para o tamanho do navio: \n");
            scanf("%d", &navios[numeronavio][2]);
            if((navios[numeronavio][2]<1) || (navios[numeronavio][2]>4)){
                printf("\nO valor escolhido é inválido!");
            }
        }while ((navios[numeronavio][2]<1) || (navios[numeronavio][2]>4));
        do{
            printf("Escolha se o navio será posicionado na vertical, horizontal ou nas diagonais: \n1. Para vertical\n2. Para horizontal\n3. Para vertical baixo\n4. Para vertical cima\n");
            scanf("%d", &navios[numeronavio][3]);
            if((navios[numeronavio][3]<1) || (navios[numeronavio][3]>4)){
                printf("\nO valor escolhido é inválido!");
            }
        }while((navios[numeronavio][3]<1) || (navios[numeronavio][3]>4));

        //testando se o navio cabe dentro do tabuleiro
        switch (navios[numeronavio][3]){
            case 1:
                if (navios[numeronavio][0]+navios[numeronavio][2]>10){
                    teste = 0;
                } else {
                    teste = 1;
                }
            break;
            case 2:
                if (navios[numeronavio][1]+navios[numeronavio][2]>10){
                    teste = 0;
                } else {
                    teste = 1;
                }
            break;
            case 3:
                if (navios[numeronavio][0]+navios[numeronavio][2]>10 || (navios[numeronavio][1]+navios[numeronavio][2]>10)){
                    teste = 0;
                } else {
                    teste = 1;
                }
            break;
            case 4:
                if ((navios[numeronavio][0]-navios[numeronavio][2]<0) || (navios[numeronavio][1]+navios[numeronavio][2]>10)){
                    teste = 0;
                } else {
                    teste = 1;
                }
            break;
        }
        if (teste == 0){
            printf("As condições selecionadas deixam esse navio fora do tabuleiro\n");
        } else {
            //chamar função de teste de sobreposição de navios
            testesobreposicao = 1;
            testarSobreposicao(tabuleiro, navios[numeronavio][0], navios[numeronavio][1], navios[numeronavio][2], navios[numeronavio][3], &testesobreposicao);
            if (testesobreposicao == 1){
                posicionarNavio(tabuleiro, navios[numeronavio][0], navios[numeronavio][1], navios[numeronavio][2], navios[numeronavio][3]);
                numeronavio++;
                if (numeronavio<4){
                    printf("O navio foi adicionado com sucesso, insira mais um navio.\n");
                } else {
                    printf("Parabens, você adicionou 4 navios no tabuleiro com sucesso.\n");
                }
            } else {
                printf("O navio não foi posicionado devido a problema de sobreposição. Insira os dados novamente\n");
            }
        }
    }
    //mostrando na tela
    mostrarTabuleiro(tabuleiro);
    printf("\n\nLegenda: 0. Água 3.Navio\n\n");    
    return 0;
}