# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <locale.h>

void imprimirMenu() {
	printf("\n\n===========================\n[1] Sintaxe\n[2] Declaração de Variável\n[3] Lógica\n[4] Limpeza de Buffer\n[5] Chamada de Função\n===========================\n");
}

int lerRespostaDoMenuAlternativa() {
	int alternativa;
	do
	{
		printf("\nQual tipo de erro? > ");
		scanf(" %d", &alternativa);
	} while ((alternativa < 1) || (alternativa > 5));
	
	return alternativa;
}

char lerRespostaDoMenuSwitch(int n) {
	char resposta;
	switch (n) {
		case (1):
			printf("Qual caractere está errado? ");
			scanf(" %c", &resposta);
			return resposta;
		case (2):
			printf("Qual variável está com o nome errado? ");
			scanf(" %c", &resposta);
			return resposta;
		case (3):
			printf("Qual caractere ou número está errado? ");
			scanf(" %c", &resposta);
			return resposta;
		case (4):
			printf("Qual variável está sendo prejudicada pelo buffer? ");
			scanf(" %c", &resposta);
			return resposta;
		case(5):
			return resposta = '1';
		default:
			break;
	}
}

struct Erro {
	int menu;
	char erroCode;
};

struct Questao {
	char code[650];
	struct Erro erro;
	int feito;
	char explicacao[450];
} questoes[6];

int main()
{
	setlocale(LC_ALL, "portuguese");
	
	int hp = 4, palpite_int, i=0, acertos = 0, prosseguir;
	char palpite_char;
	
	strcpy(questoes[0].code, "# include <stdio.h>\n\ndouble calcularFatorial (int numero) {\n    if (numero == 1) {\n        return 0;\n    }\n    else {\n        return numero * calcularFatorial(numero - 1);\n    }\n}");
	questoes[0].erro.menu = 3;
	questoes[0].erro.erroCode ='0';
	questoes[0].feito = 0;
	strcpy(questoes[0].explicacao, "Ao definir o valor do fatorial de 1 e de 0 como 0, \na função sempre retornará o valor 0 independente do parâmetro passado,\npois todo número real multiplicado por 0 vale 0.\nIsso configura um erro de lógica na função de cálculo de fatorial,\ne para corrigi-lo basta garantir que o fatorial de 1 e de 0 retorne 1.");

	strcpy(questoes[1].code, "# include <stdio.h>\n\nint somarElementosDoVetor (int elementos, int vetor[]) {\n    int i, acumulador = 0;\n\n    for (i = 0, i < elementos, i++) {\n        acumulador = acumulador + vetor[i];\n    }\n\n    return acumulador;\n}");
	questoes[1].erro.menu = 1;
	questoes[1].erro.erroCode = ',';
	questoes[1].feito = 0;
	strcpy(questoes[1].explicacao, "A estrutura de repetição 'for' utiliza apenas ';'\npara dividir os seus parâmetros.\nAo usar ',' é identificado um erro de sintaxe\nencerrando o programa e retornando um código de erro.");

	strcpy(questoes[2].code, "# include <stdio.h>\n# include <string.h>\n\nstruct E {\n    int m;\n    char c;\n};\n\nstruct Q {\n    char s[20];\n    int f;\n    struct e d;\n} questoes[2];\n\nint main() {\n    strcpy(questoes[0].s, \"place_holder\");\n    questoes[0].f = 10;\n    questoes[0].d.m = 1;\n    questoes[0].d.c = '0';\n\n    strcpy(questoes[1], \"place_holder\");\n    questoes[1].f = 21;\n    questoes[1].d.m = 0;\n    questoes[1].d.c = '1';\n\n    return 0;\n}");                     
	questoes[2].erro.menu = 2;
	questoes[2].erro.erroCode = 'e';
	questoes[2].feito = 0;
	strcpy(questoes[2].explicacao, "Usar structs aninhadas é uma boa prática para organizar dados no código.\nEntretanto deve-se atentar ao nome da struct quando for chamá-la.\nAo chamar a struct 'E' indevidamente com o nome de 'e'\né identificado um erro de declaração de variável,\npois não há variável ou struct com o nome 'e'.");
	
	strcpy(questoes[3].code, "# include <stdio.h>\n# include <string.h>\n\nvoid inverterString(char str[]) {\n    int inicio = 1;\n    int fim = strlen(str) - 1;\n    char aux;\n\n    while (inicio < fim) {\n        aux = str[inicio];\n        str[inicio] = str[fim];\n        str[fim] = aux;\n        inicio++;\n        fim--;\n    }\n}");
	questoes[3].erro.menu = 3;
	questoes[3].erro.erroCode = '1';
	questoes[3].feito = 0;
	strcpy(questoes[3].explicacao, "O programa funciona trocando os caracteres da string representados\npelo índice início e fim por intermédio de uma variável auxiliar\nque armazena temporariamente um dos caracteres.\nAo declarar que a variável 'inicio' começa com valor 1\no primeiro digito da string é pulado e consequentemente não é trocado.\nIsso configura um erro de lógica.");
	
	strcpy(questoes[4].code, "# include <stdio.h>\n# include <string.h>\n\nint main() {\n    char a, b;\n\n    printf(\"Digite o seu primeiro nome: \");\n    scanf(\"\%c\", &a);\n    printf(\"Digite o seu segundo nome: \");\n    scanf(\"\%c\", &b);\n\n    return 0;\n}");
	questoes[4].erro.menu = 4;
	questoes[4].erro.erroCode = 'b';
	questoes[4].feito = 0;
	strcpy(questoes[4].explicacao, "Ao usar dois scanf's seguidos para ler caracteres do usuário\nsem limpar o buffer de teclado, a linguagem C entende\no 'enter' do teclado como qualquer outra tecla, no caso o '\\n'.\nQuando o usuário aperta enter para enviar o primeiro caractere,\no 'enter' é lido pelo segundo scanf como um caractere normal.\nIsso impede que o usuário digite o segundo caractere a sua preferência,\nconfigurando um problema de buffer de teclado.");
	
	strcpy(questoes[5].code, "# include <stdio.h>\n\nint concatenarUltimoDigitoDeCincoNumeros(int numeros[]) {\n    int i, potenciaDe10 = 10000, novoNumero = 0;\n    for (i = 0; i < 5; i++) {\n        numeros[i] = (numeros[i] % 10) * potenciaDe10;\n        potenciaDe10 = potenciaDe10 / 10;\n        novoNumero = novoNumero + numeros[i];\n    }\n\n    return novoNumero;\n}\n\nint main() {\n    int i, novoNumero, numeros[5];\n    for (i = 0; i < 5; i++) {\n        printf(\"Digite um número inteiro: \");\n        scanf(\"\%d\", &numeros[i]);\n    }\n\n    novoNumero = concatenarUltimoDigitoDCincoNumeros(numeros);\n    printf(\"Novo número: \%d\", novoNumero);\n\n    return 0;\n}");
	questoes[5].erro.menu = 5;
	questoes[5].erro.erroCode = '1';
	strcpy(questoes[5].explicacao, "O erro está no nome da função dentro do int main.\nAo chamar a função 'concatenarUltimoDigitoDeCincoNumeros' mas sem o 'e' após o 'D', \no programa encerra retornando um erro de referência indefinida.\nIsso configura um problema de chamada de função.");
	
	printf("===== Correção de Código =====");
	printf("\nResponda exatamente o que a questão pede");
	printf("\nNúmero de vidas: %d\n\n", hp);
	sleep(2);
	
	for (i = 0; i < 6; i++)
	{
		do 
		{
			printf("===== QUESTÃO %d =====\n", i+1);
			sleep(2);
			printf("%s", questoes[i].code);
			imprimirMenu();
			palpite_int = lerRespostaDoMenuAlternativa();
			palpite_char = lerRespostaDoMenuSwitch(palpite_int);
			if ((palpite_char == questoes[i].erro.erroCode) && (palpite_int == questoes[i].erro.menu))
			{
				sleep(1.5);
				printf("\n\n=========== Correto! ===========");
				questoes[i].feito = 1;
				acertos++;
				sleep(1.5);
				}
			else
			{
				sleep(1.5);
				printf("\n\n=========== Errado! ===========");;
				hp--;
				printf("\nNúmero de vidas: %d", hp);
				sleep(2);
				system("cls");
				fflush(stdin);
			}
			if (hp == 0)
			{
				printf("\n\n\n\tQue pena. Não foi dessa vez. Você acertou %d questôes.\n\tFica pra próxima blz?\n\n", acertos);
				return 0;	
			}
			printf("\n\n");
		} while ((palpite_char != questoes[i].erro.erroCode) || (palpite_int != questoes[i].erro.menu));
		
		printf("\n===== EXPLICAÇÃO =====\n%s\n======================", questoes[i].explicacao);
		printf("\n\nDigite qualquer número inteiro para prosseguir > ");
		scanf(" %d", &prosseguir);
		system("cls");
		printf("\n");
	}
			
	if ((questoes[0].feito == 1) && (questoes[1].feito == 1) && (questoes[2].feito == 1) && (questoes[3].feito == 1) && (questoes[4].feito == 1) && (questoes[5].feito == 1))
	{
		printf("\n\n\n\tParabéns! Voce acertou todas as questões e terminou o jogo com %d vidas\n\n\n", hp);
		return 0;
	}
}
