# include <stdio.h>
# include <math.h>

/*
	Problema: Usando funções, verifique se um inteiro é uma potência perfeita (x = z^y), com x, z e y pertencentes ao conjunto dos inteiros
	Abstração:	1. Ler número inteiro 
				2. Verificar se o número é uma potência perfeita
					2.1. Utilizar while com incremento para verificar qual o múltiplo desse número (função)
					2.2. Com o múltiplo em mãos, basta incrementar ou decrementar o expoente do múltiplo 
					2.3. Fazer isso até ultrapassar o valor do número
					2.4. Se o valor for igual, temos uma potência perfeita
					2.5. Se não, não temos uma potência perfeita
				3. Imprimir resultados
*/

int verificarPotenciaPerfeita(int numero) {
	int multiploZ = 2, expoenteY = 1;
	
	if (numero < 0)
	{
		numero = numero * -1;
	}
	
	while (1)
	{
		if (numero % multiploZ == 0)
		{
			break;
		}
		else
		{
			multiploZ++;
		}
	}
	
	while (1)
	{
		double potencia = pow(multiploZ, expoenteY);
		if ((numero > 0) && (numero < 1))
		{
			if (potencia > numero)
			{
				expoenteY--;
			}
			else if (potencia < numero)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			if (potencia < numero)
			{
				expoenteY++;
			}
			else if (potencia > numero)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}

	}
}

int main() {
	int numero, estado;
	
	printf("Digite um numero inteiro qualquer: ");
	scanf(" %d", &numero);
	
	estado = verificarPotenciaPerfeita(numero);
	
	if (estado)
	{
		printf("\n%d eh uma potencia perfeita", numero);
	}
	else
	{
		printf("\n%d nao eh uma potencia perfeita", numero);
	}
	
	return 0;
}
