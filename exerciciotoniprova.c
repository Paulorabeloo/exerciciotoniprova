#include <stdio.h>
#include <string.h>

int main()
{
    // a) Vetor para armazenar os nomes dos produtos
    char produtos[10][50]; // Cada produto pode ter at� 50 caracteres

    // b) Matriz para armazenar a quantidade de cada produto em 5 armaz�ns
    int qtdprodutos[5][10]; // 5 armaz�ns para 10 produtos

    // Vari�veis auxiliares
    int totalArmazens[5] = {0}; // Total de itens em cada armaz�m
    int totalProdutos[10] = {0}; // Total de itens de cada produto
    int i, j;
    int menorEstoque, maiorEstoque;
    char produtoMenorEstoque[50], produtoMaiorEstoque[50];

    // Entrada
    for(i = 0; i < 10; i++)
    {
        printf("Digite o nome do produto %d:\n", i + 1);
        scanf("%s", produtos[i]);
        for(j = 0; j < 5; j++)
        {
            printf("Digite a quantidade do produto %s no armaz�m %d:\n", produtos[i], j + 1);
            scanf("%d", &qtdprodutos[j][i]);
        }
    }

    // Processamento
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 5; j++)
        {
            totalArmazens[j] += qtdprodutos[j][i]; // Total de itens em cada armaz�m
            totalProdutos[i] += qtdprodutos[j][i]; // Total de itens de cada produto
        }
    }

    // Inicializando valores de menor e maior estoque
    menorEstoque = totalProdutos[0];
    maiorEstoque = totalProdutos[0];
    strcpy(produtoMenorEstoque, produtos[0]);
    strcpy(produtoMaiorEstoque, produtos[0]);

    for(i = 1; i < 10; i++)
    {
        if(totalProdutos[i] < menorEstoque)
        {
            menorEstoque = totalProdutos[i];
            strcpy(produtoMenorEstoque, produtos[i]);
        }
        if(totalProdutos[i] > maiorEstoque)
        {
            maiorEstoque = totalProdutos[i];
            strcpy(produtoMaiorEstoque, produtos[i]);
        }
    }

    // Sa�da
    printf("\nTotal de itens armazenados em cada armaz�m:\n");
    for(j = 0; j < 5; j++)
    {
        printf("Armaz�m %d: %d itens\n", j + 1, totalArmazens[j]);
    }

    printf("\nTotal de itens armazenados de cada produto:\n");
    for(i = 0; i < 10; i++)
    {
        printf("Produto %s: %d itens\n", produtos[i], totalProdutos[i]);
    }

    printf("\nProduto com menor n�mero de itens em estoque: %s (%d itens)\n", produtoMenorEstoque, menorEstoque);
    printf("Produto com maior n�mero de itens em estoque: %s (%d itens)\n", produtoMaiorEstoque, maiorEstoque);

    return 0;
}

