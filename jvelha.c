#include <stdio.h>

int main(){

    char jogo[4][4];
    int l, c, linha, coluna, jogador, jogadas, ganhou, rejogar;

do{

    //colocando os valores das variáveis
    jogador=1;
    jogadas=0;
    ganhou=0;
    rejogar=1;

    //a criação do tabuleiro
    for(l=1; l<=3; l++){
        for(c=1; c<=3; c++){
            jogo[l][c] = '.';
        }
    }
    
    do{//repetição do jogo

        //a impressão do tabuleiro
        printf("\n     1   2   3 \n");
        for(l=1; l<=3; l++){
            for(c=1; c<=3; c++){

                if(c==1)
                    printf("\n%d   ", l);

                printf(" %c ", jogo[l][c]);

                if(c<3)
                printf("|");

            }

            if(l<3)
                printf("\n---------------");
        }

        //ler os dados das jogadas
        do{
            printf("\n\nJOGADOR %d: Digite em qual linha e coluna deseja jogar: ", jogador);
            scanf("%d %d", &linha, &coluna);
        }while(linha<1 || linha>3 || coluna<1 || coluna>3 || jogo[linha][coluna] != '.');


        //guardar os dados das jogadas dentro da matriz no lugar jogado
        if(jogador==1){
            jogo[linha][coluna] = 'O';
            jogador++;
        }

        else{
            jogo[linha][coluna] = 'X';
            jogador=1;
        }

        //subir a contagem de jogadas
        jogadas++;

        //ver se alguem ganhou, senão, ir pra proxima jogada

        //por linha
        if(
        jogo[1][1] == 'O' && jogo[1][2] == 'O' && jogo[1][3] == 'O' ||
        jogo[2][1] == 'O' && jogo[2][2] == 'O' && jogo[2][3] == 'O' ||
        jogo[3][1] == 'O' && jogo[3][2] == 'O' && jogo[3][3] == 'O'){
            printf("\nParabens! O jogador 1 ganhou por linha!");
            ganhou=1;
        }

        if(
        jogo[1][1] == 'X' && jogo[1][2] == 'X' && jogo[1][3] == 'X' ||
        jogo[2][1] == 'X' && jogo[2][2] == 'X' && jogo[2][3] == 'X' ||
        jogo[3][1] == 'X' && jogo[3][2] == 'X' && jogo[3][3] == 'X'){
            printf("\nParabens!  O jogador 2 ganhou por linha!");
            ganhou=1;
        }

        //por coluna

        if(
        jogo[1][1] == 'O' && jogo[2][1] == 'O' && jogo[3][1] == 'O' ||
        jogo[1][2] == 'O' && jogo[2][2] == 'O' && jogo[3][2] == 'O' ||
        jogo[1][3] == 'O' && jogo[2][3] == 'O' && jogo[3][3] == 'O'){
            printf("\nParabens! O jogador 1 ganhou por coluna!");
            ganhou=1;
        }

        if(
        jogo[1][1] == 'X' && jogo[2][1] == 'X' && jogo[3][1] == 'X' ||
        jogo[1][2] == 'X' && jogo[2][2] == 'X' && jogo[3][2] == 'X' ||
        jogo[1][3] == 'X' && jogo[2][3] == 'X' && jogo[3][3] == 'X'){
            printf("\nParabens! O jogador 2 ganhou por coluna!");
            ganhou=1;
        }

        //por diagonal principal

        if(
        jogo[1][1] == 'O' && jogo[2][2] == 'O' && jogo[3][3] == 'O'){
            printf("\nParabens! O jogador 1 ganhou pela diagonal principal!");
            ganhou=1;
        }

        if(
        jogo[1][1] == 'X' && jogo[2][2] == 'X' && jogo[3][3] == 'X'){
            printf("\nParabens! O jogador 2 ganhou pela diagonal principal!");
            ganhou=1;
        }

        //por diagonal secundaria

        if(
        jogo[1][3] == 'O' && jogo[2][2] == 'O' && jogo[3][1] == 'O'){
            printf("\nParabens! O jogador 1 ganhou pela diagonal secundaria!");
            ganhou=1;
        }

        if(
        jogo[1][3] == 'X' && jogo[2][2] == 'X' && jogo[3][1] == 'X'){
            printf("\nParabens! O jogador 2 ganhou pela diagonal secundaria!");
            ganhou=1;
        }
    }while(ganhou==0 && jogadas<9);

    printf("\n     1   2   3 \n");
        for(l=1; l<=3; l++){
            for(c=1; c<=3; c++){

                if(c==1)
                    printf("\n%d   ", l);

                printf(" %c ", jogo[l][c]);

                if(c<3)
                printf("|");

            }

            if(l<3)
                printf("\n---------------");
        }

    if(ganhou==0){
        printf("\nO jogo empatou!\n");
    }

    printf("\n\nDeseja jogar de novo?\n1-Sim\nQualquer outra coisa saira do programa.\n");
    scanf("%d", &rejogar);

}while(rejogar==1);

    return 0;
}