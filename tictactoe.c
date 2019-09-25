// Desenvolvido por Josué Barros da Silva (Joshua)
// Em 21/09/2019
// GitHub: JoshuaWebDev
// site: http://www.joshuawebdev.wordpress.com

#include <stdio.h>
#define TAMANHO 3 // constante com o tamanho da matriz

int vez(int num)
{
    if ( num % 2 == 0 )
        return 1;
    else
        return -1;
}

void limparTela()
{
    int count = 0;
    while( count != 50 )
    {
        putchar('\n');
        count++;
    }
}

void inicializar(int matriz[][TAMANHO], int tam)
{
    int i, j;
    for(i = 0; i < tam; i++)
        for(j = 0; j < tam; j++)
            matriz[i][j] = 0;
}

void mostrar(int matriz[][TAMANHO], int tam)
{
    int i, j;
    printf("\n::: JOGO DA VELHA 1.0 :::\n");
    printf(" _ _ _ \n");
    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {
            if(matriz[i][j] == 0) {
                printf("|_");
            } else {
                if(matriz[i][j] == 1) {
                    printf("|X");
                } else {
                    printf("|O");
                }
            }
        }
        printf("|\n");
    }
    printf("\n");
}

int diagonalPrincipal(int matriz[][TAMANHO], int tam)
{
    int i, j, somaX = 0, somaO = 0;
    for( i = 0; i < tam; i++ )
    {
        for( j = 0; j < tam; j++)
        {
            if ( i == j )
            {
                if ( matriz[i][j] == 1 )
                    somaX++;
                if ( matriz[i][j] == -1 )
                    somaO += -1;
            }
        }
        if (somaX == 3)
            return 1;
        if (somaO == -3)
            return -1;
    }
    return 0;
}

int main()
{
    int tabuleiro[TAMANHO][TAMANHO];
    int linha, coluna;
    int jogadas = 0;

    // inicializa a matriz com zeros
    inicializar(tabuleiro, TAMANHO);

    limparTela();

    // exibe a matriz, neste momento ela ainda não foi
    // preenchida por nenhum jogador, ou seja, esta zerada
    mostrar(tabuleiro, TAMANHO);

    do {
        printf("Escolha uma posição na matriz 3x3\n");
        printf("Linha (1 a 3): ");
        scanf("%d", &linha);
        printf("Coluna (1 a 3): ");
        scanf("%d", &coluna);

        if(tabuleiro[linha-1][coluna-1] == 0)
        {
            // alterna entre os jogadores (1 e -1)
            tabuleiro[linha-1][coluna-1] = vez(jogadas);

            limparTela();

            // exibe a matriz
            mostrar(tabuleiro, TAMANHO);

            if( diagonalPrincipal(tabuleiro, TAMANHO) == 1 )
            {
                printf("\nO jogador X ganhou!\n");
                break;
            }
            
            if( diagonalPrincipal(tabuleiro, TAMANHO) == -1 )
            {
                printf("\nO jogador O ganhou!\n");
                break;
            }

            // contabiliza a quantidade de jogadas válidas
            jogadas++;

        } else {
            limparTela();
            printf("\nA posição %d,%d já foi preenchida!", linha, coluna);
            printf("\nEscolha outra posição!\n");
            mostrar(tabuleiro, TAMANHO);
        }
  
    } while ( jogadas != 9 );

return 0;
}
