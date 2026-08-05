#include <stdio.h>
int main () {

int tabuleiro[10][10];

int navioH[3] = {3, 3, 3};
int navioV[3] = {3, 3, 3};
int navioD1[3] = {3, 3, 3};
int navioD2[3] = {3, 3, 3};

int linhaH = 3, colunaH = 4;
int linhaV = 6, colunaV = 8;
int linhaD1 = 1, colunaD1 = 6;
int linhaD2 = 7, colunaD2 = 5;

int cone[5][5];
int cruz[5][5];
int octaedro[5][5];

int Lcruz = 4, Ccruz = 4;
int Lcone = 2, Ccone = 7;
int lOct = 7, COct =2;




for (int linha = 0; linha < 10; linha++) {//Codigo do tabuleiro 10x10, apenas com 0 para simulara a agua
    for (int coluna = 0; coluna < 10; coluna++) {
        tabuleiro[linha][coluna] = 0;
    }
}

for (int linha = 0; linha < 5; linha++) {//Codigo da Cruz 
    for (int coluna = 0; coluna < 5; coluna++) {

        if (linha == 2 || coluna == 2) {
            cruz[linha][coluna] = 1;
        } else {
            cruz[linha][coluna] = 0;
        }
    }
}

for (int linha = 0; linha < 5; linha++) {// Codigo do Cone
    for (int coluna = 0; coluna < 5; coluna++){

        if ((linha == 0 && coluna == 2) ||
            (linha == 1 && coluna >= 1 && coluna <= 3) ||
            (linha == 2)) {

            cone[linha][coluna] = 1;


         } else {
            cone[linha][coluna] = 0;
         }
    }
}

for (int linha = 0; linha < 5; linha++) {
    for (int coluna = 0; coluna < 5; coluna++) {

        if ((linha == 0 && coluna == 2) || (linha == 4 && coluna == 2) ||
            (linha == 1 && coluna >= 1 && coluna <= 3) ||
            (linha == 3 && coluna >= 1 && coluna <= 3) ||
            (linha == 2)) {

                octaedro[linha][coluna] = 1;
    } else {

                octaedro[linha][coluna] = 0;
    }
}
}

for (int i = 0; i < 3; i++) {//Codigo do Navio 3x3 na Horizontal sendo simbolizado com 3 
    tabuleiro[linhaH][colunaH + i] = navioH[i];
}

for (int j = 0; j < 3; j++) {//Codigo do Navio 3x3 na Verdical sendo simbolizado com 3 
    tabuleiro[linhaV + j][colunaV] = navioV[j];
}

for (int l = 0; l < 3; l++) {//Codigo do primeiro navio 3x3 na Diagonal
    tabuleiro[linhaD1 + l][colunaD1 + l] = navioD1[l];
}

for (int t = 0; t < 3; t++) {//Codigo do segundo navio 3x3 na Diagonal 
    tabuleiro[linhaD2 + t][colunaD2 - t] = navioD2[t];
}
for (int linha = 0; linha < 5; linha++) {
    for (int coluna = 0; coluna < 5; coluna++) {

        int novaLinha = Lcruz + (linha - 2);
        int novaColuna = Ccruz + (coluna - 2);

        if (novaLinha >= 0 && novaLinha < 10 &&
            novaColuna >= 0 && novaColuna < 10) {

            if (cruz[linha][coluna] == 1 &&
                tabuleiro[novaLinha][novaColuna] == 0) {

                tabuleiro[novaLinha][novaColuna] = 5;
            }
        }
    }
}

for (int linha = 0; linha < 5; linha++) {
    for (int coluna = 0; coluna < 5; coluna++) {

        int novaLinha = Lcone + (linha - 2);
        int novaColuna = Ccone + (coluna - 2);

        if (novaLinha >= 0 && novaLinha < 10 &&
            novaColuna >= 0 && novaColuna < 10) {

            if (cone[linha][coluna] == 1 &&
                tabuleiro[novaLinha][novaColuna] == 0) {

                tabuleiro[novaLinha][novaColuna] = 5;
            }
        }
    }
}

for (int linha = 0; linha < 5; linha++) {
    for (int coluna = 0; coluna < 5; coluna++) {

        int novaLinha = lOct + (linha - 2);
        int novaColuna = COct + (coluna - 2);

        if (novaLinha >= 0 && novaLinha < 10 &&
            novaColuna >= 0 && novaColuna < 10) {

            if (octaedro[linha][coluna] == 1 &&
                tabuleiro[novaLinha][novaColuna] == 0) {

                tabuleiro[novaLinha][novaColuna] = 5;
            }
        }
    }
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


printf ("\n Matriz de Cruz \n\n");

for (int linha = 0; linha < 5; linha++) {
    for (int coluna = 0; coluna < 5; coluna++) {

        printf ("%d ", cruz[linha][coluna]);
    }

    printf("\n");
}


    return 0;

}