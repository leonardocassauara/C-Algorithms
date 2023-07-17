# include <stdio.h>
# include <stdlib.h>

/*
    Problema: Usuário define numero de linha(tipo) e coluna(tamanho) da matriz do estoque. Além de definir os valores em cada índice e a quantidade de pedidos recebeida.
              Um pedido deve ser feito com a entrada do tipo e tamanho na matriz, se o valor na matriz for igual a 0, não é possível realizar o pedido. Retorne o número de pedidos
              feitos com sucesso.
    Abstração:
                1. Ler entradas do Usuário
                    1.1. Tamanho da matriz
                    1.2. Valores da matriz
                    1.3. Número de pedidos
                    1.4. Localização dos pedidos na matriz
                2. Criar Matriz
                    2.1. Usar parâmetros obtidos pelo usuário para criar a Matriz
                3. Lista condições de realização do pedido
                4. Imprimir número de pedidos realizados com sucesso
*/


void criarMatriz(int linha, int coluna, int matriz[][coluna]) {
	int i, j;
	for (i = 0; i < linha; i++)
	{
		for (j = 0; j < coluna; j++)
		{
			scanf("%d", &matriz[i][j]);
		}
	}
}


int lerPedido (int numPedidos, int coluna, int matriz[][coluna]) {
	int i, acessoLinha, acessoColuna, pedidosRealizados=0;
	for (i = 0; i < numPedidos; i++)
	{
		scanf("%d %d", &acessoLinha, &acessoColuna);
		if (matriz[acessoLinha-1][acessoColuna-1] > 0)
		{
			matriz[acessoLinha-1][acessoColuna-1]--;
			pedidosRealizados++;
		}
	}
	return pedidosRealizados;
}


int main () {
	int linha, coluna, i, j, numPedidos, pedidosRealizados;
	
	scanf("%d", &linha);
	scanf("%d", &coluna);
	
	int matriz[linha][coluna];
	criarMatriz(linha, coluna, matriz);
	
	scanf("%d", &numPedidos);
	pedidosRealizados = lerPedido(numPedidos, coluna, matriz);
	printf("%d", pedidosRealizados);
	
	return 0;
}
