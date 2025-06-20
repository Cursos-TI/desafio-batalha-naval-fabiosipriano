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
            printf("%d ", tabuleiro[i][j]);
        }
    }
}

//funções de ataques especiais
void especialCone (int tabuleiro[10][10], int ataqueL, int ataqueC){

}

void especialCruz (int tabuleiro[10][10], int ataqueL, int ataqueC){
    //marca o centro da cruz
    if (tabuleiro[ataqueL][ataqueC] == 0){
            tabuleiro[ataqueL][ataqueC] = 5;
        } else if (tabuleiro[ataqueL][ataqueC] == 3){
            tabuleiro[ataqueL][ataqueC] = 7;
        } else{
            tabuleiro[ataqueL][ataqueC] = 5;
        }
    //marca a parte de cima
    int contador = 1;
    for (int i=1; i<=2; i++){
        if (ataqueL-contador>=0){
            if (tabuleiro[ataqueL-contador][ataqueC] == 0){
                tabuleiro[ataqueL-contador][ataqueC] = 5;
                contador++;
            } else if (tabuleiro[ataqueL-contador][ataqueC] == 3){
                tabuleiro[ataqueL-contador][ataqueC] = 7;
                contador++;
            } else {
                contador++;
            }
        }
    }
    //marca parte de baixo
    contador = 1;
    for (int i=1; i<=2; i++){
        if (ataqueL+contador<=9){
            if (tabuleiro[ataqueL+contador][ataqueC] == 0){
                tabuleiro[ataqueL+contador][ataqueC] = 5;
                contador++;
            } else if (tabuleiro[ataqueL+contador][ataqueC] == 3){
                tabuleiro[ataqueL+contador][ataqueC] = 7;
                contador++;
            } else {
                contador++;
            }
        }
    }
    //marca parte da esquerda
    contador = 1;
    for (int i=1; i<=2; i++){
        if (ataqueC-contador>=0){
            if (tabuleiro[ataqueL][ataqueC-contador] == 0){
                tabuleiro[ataqueL][ataqueC-contador] = 5;
                contador++;
            } else if (tabuleiro[ataqueL][ataqueC-contador] == 3){
                tabuleiro[ataqueL][ataqueC-contador] = 7;
                contador++;
            } else {
                contador++;
            }
        }
    }
    //marca parte da direita
    contador = 1;
    for (int i=1; i<=2; i++){
        if (ataqueC+contador<=9){
            if (tabuleiro[ataqueL][ataqueC+contador] == 0){
                tabuleiro[ataqueL][ataqueC+contador] = 5;
                contador++;
            } else if (tabuleiro[ataqueL][ataqueC+contador] == 3) {
                tabuleiro[ataqueL][ataqueC+contador] = 7;
                contador++;
            } else {
                contador++;
            }
        }
    }
}

void especialOctaedro (int tabuleiro[10][10], int ataqueL, int ataqueC){

}

int main(){
    //declaração de variaveis
    int tabuleiro [10][10], navios[4][4], ataques[3][3];
    int teste, numeronavio, testesobreposicao, contadordeataques;
    //preencher o tabuleiro
    criarTabuleiro(tabuleiro);
    
    //cadastrando dados dos navios, com máximo de 4 navios.
    
    numeronavio = 0;

    while (numeronavio<4){

        printf("Colocando navio no tabuleiro: \n");
        //repetições para validar se os valores estão de acordo com o solicitado
        do{
            printf("Escolha um numero de 1 a 10 para a linha da posição inicial do navio: \n");
            scanf("%d", &navios[numeronavio][0]);
            navios[numeronavio][0]--;
            if((navios[numeronavio][0]<0) || (navios[numeronavio][0]>9)){
                printf("O valor escolhido é inválido!\n");
            }
        }while ((navios[numeronavio][0]<0) || (navios[numeronavio][0]>9));
        do{
            printf("Escolha um numero de 1 a 10 para a coluna da posição inicial do navio: \n");
            scanf("%d", &navios[numeronavio][1]);
            navios[numeronavio][1]--;
            if((navios[numeronavio][1]<0) || (navios[numeronavio][1]>9)){
                printf("O valor escolhido é inválido!\n");
            }
        }while ((navios[numeronavio][1]<0) || (navios[numeronavio][1]>9));
        do{
            printf("Escolha um numero de 1 a 4 para o tamanho do navio: \n");
            scanf("%d", &navios[numeronavio][2]);
            if((navios[numeronavio][2]<1) || (navios[numeronavio][2]>4)){
                printf("O valor escolhido é inválido!\n");
            }
        }while ((navios[numeronavio][2]<1) || (navios[numeronavio][2]>4));
        do{
            printf("Escolha se o navio será posicionado na vertical, horizontal ou nas diagonais: \n1. Para vertical\n2. Para horizontal\n3. Para vertical baixo\n4. Para vertical cima\n");
            scanf("%d", &navios[numeronavio][3]);
            if((navios[numeronavio][3]<1) || (navios[numeronavio][3]>4)){
                printf("O valor escolhido é inválido!\n");
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
    contadordeataques = 0;
    while (contadordeataques<3){
        do{
        printf("Selecione o tipo do ataque. Pressione: \n1. Ataque Cone.\n2. Ataque Cruz.\n3. Ataque Octaedro.\n");
        scanf("%d", &ataques[contadordeataques][0]);
        if ((ataques[contadordeataques][0]<1) || (ataques[contadordeataques][0]>4)){
            printf("Valores inválidos!\n");
        }
        }while((ataques[contadordeataques][0]<1) || (ataques[contadordeataques][0]>4));
        do{
        printf("Selecione a coordenada do ataque.\nDigite um numero de 1 a 10 para a linha: \n");
        scanf("%d", &ataques[contadordeataques][1]);
        if ((ataques[contadordeataques][1]<1) || (ataques[contadordeataques][1]>10)){
            printf("Valores inválidos!\n");
        }
        }while((ataques[contadordeataques][1]<1) || (ataques[contadordeataques][1]>10));
        ataques[contadordeataques][1]--;
        do{
        printf("Selecione a proxima coordenada do ataque.\nDigite um numero de 1 a 10 para a coluna: \n");
        scanf("%d", &ataques[contadordeataques][2]);
        if ((ataques[contadordeataques][2]<1) || (ataques[contadordeataques][2]>10)){
            printf("Valores inválidos!\n");
        }
        }while((ataques[contadordeataques][2]<1) || (ataques[contadordeataques][2]>10));
        ataques[contadordeataques][2]--;
        switch (ataques[contadordeataques][0]){
            case 1:
                especialCone(tabuleiro, ataques[contadordeataques][1], ataques[contadordeataques][2]);
            break;
            case 2:
                especialCruz(tabuleiro, ataques[contadordeataques][1], ataques[contadordeataques][2]);
            break;
            case 3:
                especialOctaedro(tabuleiro, ataques[contadordeataques][1], ataques[contadordeataques][2]);
            break;        
        }
        contadordeataques++;
    }
    //mostrando na tela
    mostrarTabuleiro(tabuleiro);
    printf("\n\nLegenda: 0.Água - 3.Navio - 5.Ataque - 7.Campo com navio atigido por ataque\n\n");    
    return 0;
}