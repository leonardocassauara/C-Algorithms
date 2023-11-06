# include <stdio.h>

int main() {

    // Declarar uma variável do tipo Arquivo
    FILE* quePeriodoMerda;
    
    // Abrir um arquivo de extensão txt no modo de leitura("r" inicial de read, ler em inglês)
    quePeriodoMerda = fopen("nomeDoArquivo.txt", "r");

    // Contador e String
    int contador = 0;
    char string[100];

    // Enquanto ele conseguir ler strings do arquivo, faça:
    while(fscanf(quePeriodoMerda, "%s", string) == 1) {

        // Operações com os dados do arquivo
        printf("%d : %s\n", contador, string);
        contador++;
    }

    fclose(quePeriodoMerda);

    return 0;
}
