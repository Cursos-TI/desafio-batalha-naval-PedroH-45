#include <stdio.h>
int main () {

int tabuleiro[10][10];
int navioH[3] = {3, 3, 3};
int navioV[3] = {3, 3, 3};
int linhaH = 3, colunaH = 4;
int linhaV = 6, colunaV = 8;


for (int linha = 0; linha < 10; linha++) {//Codigo do tabuleiro 10x10, apenas com 0 para simulara a agua
    for (int coluna = 0; coluna < 10; coluna++) {
        tabuleiro[linha][coluna] = 0;
    }
}

for (int i = 0; i < 3; i++) {//Codigo do Navio 3x3 na Horizontal sendo simbolizado com 3 
    tabuleiro[linhaH][colunaH + i] = navioH[i];
}

for (int j = 0; j < 3; j++) {//Codigo do Navio 3x3 na Verdical sendo simbolizado com 3 
    tabuleiro[linhaV + j][colunaV] = navioV[j];
}

printf ("       ###  Batalha Naval  ###   \n");//cabeçalho do titulo

printf ("   ");

for (int coluna = 1; coluna <= 10; coluna++) {//Codigo da tabela Horizontal do cabeçalho de 1 a 10
    printf ("%2d ", coluna);
}

printf ("\n");

for (int linha = 0; linha <  10; linha++) {//Codigo da tabela Verdical de A a J
    printf ("%c  ", 'A' + linha);

    for (int coluna = 0; coluna < 10; coluna++) {
        printf ("%2d ", tabuleiro[linha][coluna]);

    }

    printf ("\n");
}


    return 0;

}