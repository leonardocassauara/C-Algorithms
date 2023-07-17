# include <stdio.h>
# include <stdlib.h>

/*
    Problema: Usu�rio define numero de linha(tipo) e coluna(tamanho) da matriz do estoque. Al�m de definir os valores em cada �ndice e a quantidade de pedidos recebeida.
              Um pedido deve ser feito com a entrada do tipo e tamanho na matriz, se o valor na matriz for igual a 0, n�o � poss�vel realizar o pedido. Retorne o n�mero de pedidos
              feitos com sucesso.
    Abstra��o:
                1. Ler entradas do Usu�rio
                    1.1. Tamanho da matriz
                    1.2. Valores da matriz
                    1.3. N�mero de pedidos
                    1.4. Localiza��o dos pedidos na matriz
                2. Criar Matriz
                    2.1. Usar par�metros obtidos pelo usu�rio para criar a Matriz
                3. Lista condi��es de realiza��o do pedido
                4. Imprimir n�mero de pedidos realizados com sucesso
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
