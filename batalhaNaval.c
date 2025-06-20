#include <stdio.h>
#include <stdlib.h>

void criarTabuleiro(int tabuleiro[10][10]){
    for (int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            tabuleiro[i][j] = 0;
        }
    }
}

void testarSobreposicao(int ){

}

void posicionarNavioVertical(int ){

}

void posicionarNavioHorizontal(int ){

}

void posicionarNavioVerticalCima(int ){

}

void posicionarNavioVerticalBaixo(int ){
    
}

int main(){
    //declaração de variaveis
    int tabuleiro [10][10];
    int navios[4][4], navio_2[4], teste;
    int i, j, condicao = 0, numeronavio;
    int aux, soma, testesobreposicao = 0;
    //preencher o tabuleiro
    criartabuleiro(tabuleiro);
    
    //cadastrando dados dos navios, com máximo de 4 navios.
    
    condicao = 0;
    numeronavio = 0;

    while(condicao == 0){

        printf("Colocando o primeiro navio no tabuleiro: \n");
        do{
            printf("Escolha um numero de 1 a 10 para a linha da posição inicial do primeiro navio: \n");
            scanf("%d", &navios[numeronavio][0]);
            navios[numeronavio][0]--;
            if((navios[numeronavio][0]<0) || (navios[numeronavio][0]>9)){
                printf("\nO valor escolhido é inválido!");
            }
        }while ((navios[numeronavio][0]<0) || (navios[numeronavio][0]>9));
        do{
            printf("Escolha um numero de 1 a 10 para a coluna da posição inicial do primeiro navio: \n");
            scanf("%d", &navios[numeronavio][1]);
            navios[numeronavio][1]--;
            if((navios[numeronavio][1]<0) || (navios[numeronavio][1]>9)){
                printf("\nO valor escolhido é inválido!");
            }
        }while ((navios[numeronavio][1]<0) || (navios[numeronavio][1]>9));
        do{
            printf("Escolha um numero de 1 a 4 para o tamanho do primeiro navio: \n");
            scanf("%d", &navios[numeronavio][2]);
            if((navios[numeronavio][2]<1) || (navios[numeronavio][2]>4)){
                printf("\nO valor escolhido é inválido!");
            }
        }while ((navios[numeronavio][2]<1) || (navios[numeronavio][2]>4));
        do{
            printf("Escolha se o primeiro navio será posicionado na vertical, horizontal ou nas diagonais: \n1. Para vertical\n2. Para horizontal\n3. Para vertical baixo\n4. Para vertical cima\n");
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
                if (navios[numeronavio][0]+navios[numeronavio][2]>10 || (navios[numeronavio][1]+navios[numeronavio][2])){
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
        default:
            break;
        }
        if (navio_1[2] == 1){
            if (navio_1[0]+navio_1[1]>10){
                printf("As condições selecionadas para o navio deixam ele fora do tabuleiro (10x10). Por favor escolha opções válidas!");
                teste = 0;
            }else{
                teste = 1;
            } 
        }else{
            if (navio_1[3]+navio_1[1]>10){
                printf("As condições selecionadas para o navio deixam ele fora do tabuleiro (10x10). Por favor escolha opções válidas!");
                teste = 0;
            }else{
                teste = 1;
            }
        }
        if (teste == 1){
            condicao = 1;
        }
    }
    //colocando o primeiro navio no tabuleiro
    if (navio_1[2] == 1){
        soma = 0;
        for (i=1; i<=navio_1[1];i++){
            aux = navio_1[0] + soma;
            tabuleiro[aux][navio_1[3]] = 3;
            soma++;
        }
    }else{
        soma = 0;
        for (i=1; i<=navio_1[1];i++){
            aux = navio_1[3] + soma;
            tabuleiro[navio_1[0]][aux] = 3;
            soma++;
        }
    }
    //cadastrando dados do segundo navio
    condicao = 0;
    while(condicao == 0){
        printf("\nColocando o segundo navio no tabuleiro: \n");
        do{
            printf("Escolha um numero de 1 a 10 para a linha posição inicial do segundo navio: \n");
            scanf("%d", &navio_2[0]);
            navio_2[0]--;
        }while ((navio_2[0]<0) || (navio_2[0]>9));
        do{
            printf("Escolha um numero de 1 a 10 para a coluna da posição  inicial do segundo navio: \n");
            scanf("%d", &navio_2[3]);
            navio_2[3]--;
        }while ((navio_2[3]<0) || (navio_2[3]>9));
        do{
            printf("Escolha um numero de 1 a 4 para o tamanho do segundo navio: \n");
            scanf("%d", &navio_2[1]);
        }while ((navio_2[1]<1) || (navio_2[1]>4));
        do{
            printf("Escolha se o segundo navio será posicionado na vertical ou horizontal: \n1. Para vertical\n2. Para horizontal\n");
            scanf("%d", &navio_2[2]);
        }while((navio_2[2]<1) || (navio_2[2]>2));
            if (navio_2[2] == 1){
                if (navio_2[0]+navio_2[1]>10){
                    printf("As condições selecionadas para o navio deixam ele fora do tabuleiro (10x10). Por favor escolha opções válidas!");
                    teste = 0;
                }else{
                    teste = 1;
                } 

            }else{
                if (navio_2[3]+navio_2[1]>10){
                    printf("As condições selecionadas para o navio deixam ele fora do tabuleiro (10x10). Por favor escolha opções válidas!");
                    teste = 0;
                }else{
                    teste = 1;
                }
            }
                
        //testando se os navios não se sobrepoem
        if (navio_2[2] == 1){
            soma = 0;
            for (i=1; i<=navio_2[1];i++){
                aux = navio_2[0] + soma;
                if(tabuleiro[aux][navio_2[3]] == 3){
                    testesobreposicao = 1;
                }
                soma++;
            }
        }else{
            soma = 0;
            for (i=1; i<=navio_2[1];i++){
                aux = navio_2[3] + soma;
                if(tabuleiro[navio_2[0]][aux] == 3){
                    testesobreposicao = 1;
                }
                soma++;
            }

        }
        if (testesobreposicao == 1){
            printf("O segundo navio não pode ser sobreposto em outro navio já posicionado! Escolha outra posição.");
        }
        if ((teste == 1) && testesobreposicao == 0){
            condicao = 1;
        }
    }
    //colocando o segundo navio no tabuleiro
    if (navio_2[2] == 1){
        soma = 0;
        for (i=1; i<=navio_2[1];i++){
            aux = navio_2[0] + soma;
            tabuleiro[aux][navio_2[3]] = 3;
            soma++;
        }
    }else{
        soma = 0;
        for (i=1; i<=navio_2[1];i++){
            aux = navio_2[3] + soma;
            tabuleiro[navio_2[0]][aux] = 3;
            soma++;
        }
    }
    //mostrando na tela
    for (i=0; i<10; i++){
        printf("\n");
        for(j=0; j<10; j++){
            printf("%d, ", tabuleiro[i][j]);
        }
        
    }    

    return 0;

}