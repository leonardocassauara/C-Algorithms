# include <stdio.h>
# include <math.h>

/*
	Problema: Usando fun��es, verifique se um inteiro � uma pot�ncia perfeita (x = z^y), com x, z e y pertencentes ao conjunto dos inteiros
	Abstra��o:	1. Ler n�mero inteiro 
				2. Verificar se o n�mero � uma pot�ncia perfeita
					2.1. Utilizar while com incremento para verificar qual o m�ltiplo desse n�mero (fun��o)
					2.2. Com o m�ltiplo em m�os, basta incrementar ou decrementar o expoente do m�ltiplo 
					2.3. Fazer isso at� ultrapassar o valor do n�mero
					2.4. Se o valor for igual, temos uma pot�ncia perfeita
					2.5. Se n�o, n�o temos uma pot�ncia perfeita
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
