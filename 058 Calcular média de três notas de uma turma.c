# include <stdio.h>
# include <string.h>

/*
	Problema: Usando funções, ler um conjunto de 3 notas e calcular a média de cada aluno informando estado, calcular média geral da turma, informar extremos
	Abstração:	1. Função para ler número de alunos
				2. Função para ler nome do aluno
				3. Função para ler 3 notas de um aluno
				4. Função para calcular média do aluno
				5. Função para calcular a média da turma
				6. Função para acumular valores
				7. Função para ordenar as médias
				8. Armazenar esses dados numa struct
				9. Imprimir resultados
*/

struct Aluno {
	char nome[40];
	float nota[3];
	float media;
	float somaNotas;
};

int lerNumeroDeAlunos() {
	int alunos;
	
	printf("Quantos alunos compoem a turma? ");
	scanf(" %d", &alunos);
	
	return alunos;
}

void lerNomeDoAluno(char nome[]) {
	char str[40];
	printf("\nNome: ");
	scanf(" %s", &str);
	strcpy(nome, str);
}

float lerNotaDoAluno() {
	float nota;
	printf("Nota: ");
	scanf(" %f", &nota);
	return nota;
}

float somarNotas(int numeroDeNotas, float notas[]) {
	int i;
	float soma=0;
	for (i = 0; i < numeroDeNotas; i++)
	{
		soma = soma + notas[i];
	}
	
	return soma;
}

float somarValores(float a, float b) {
	return a + b;
}

float calcularMedia(float somaDasNotas, float numeroDeAlunos) {
	float media;
	media = somaDasNotas / numeroDeAlunos;
	return media;
}

void ordenarMedias(float medias[], int numeroDeMedias) {
	float buffer;
	int i, cinza = 0;
	while (cinza <= numeroDeMedias - 1)
	{
		for (i = 0; i < numeroDeMedias - 1; i++) 
		{
			if (medias[i] < medias[i+1]) 
			{
				buffer = medias[i];
				medias[i] = medias[i+1];
				medias[i+1] = buffer;
				cinza = 0;
			}
			else
			{
				cinza++;
			}
		}
	}
}

int main () {
	int numAlunos, i, j;
	float acumuladorMedias=0, mediaTurma;
	numAlunos = lerNumeroDeAlunos();
	float medias[numAlunos];
	
	struct Aluno alunos[numAlunos];
	
	for (i = 0; i < numAlunos; i++)
	{
		lerNomeDoAluno(alunos[i].nome);
		for (j = 0; j < 3; j++)
		{
			alunos[i].nota[j] = lerNotaDoAluno();
		}
		alunos[i].somaNotas = somarNotas(3, alunos[i].nota);
		alunos[i].media = calcularMedia(alunos[i].somaNotas, 3);
		acumuladorMedias = somarValores(acumuladorMedias, alunos[i].media);
		medias[i] = alunos[i].media;
	}
	
	mediaTurma = calcularMedia(acumuladorMedias, numAlunos);
	ordenarMedias(medias, numAlunos);
	
	printf("Media da Turma: %.2f\nMaior Media: %.2f\nMenor Media: %.2f", mediaTurma, medias[0], medias[numAlunos - 1]);
	
	return 0;
}

