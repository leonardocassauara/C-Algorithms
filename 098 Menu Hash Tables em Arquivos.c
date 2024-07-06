#include <stdio.h>
#include <stdlib.h>

// * Setup
char nomeArquivo[] = "hash.bin";
int tamanhoHashTable = 13;

typedef struct aluno {
    int matricula;
    char nome[100];
    char curso[100];
} aluno;

typedef struct registro {
    aluno info;
    int disponibilidade;
} registro;

// * Hash Functions 
void inicializarArquivoBinario() {
    FILE* f = fopen(nomeArquivo, "wb");
    registro molde;
    int i;

    molde.disponibilidade = 1;

    for (i = 0; i < tamanhoHashTable; i++) {
        fwrite(&molde, sizeof(registro), 1, f);
    }
    fclose(f);
}

void limparArquivoBinario() {
    // ? Isso seria gambiarra?
    FILE* f = fopen(nomeArquivo, "wb");
    fclose(f);
}

int hashProximaDisponivel(int matricula) {
    return matricula % tamanhoHashTable;
}

int acharPosicao(int matricula) {
    int pos = hashProximaDisponivel(matricula);
    registro busca;
    FILE* f = fopen(nomeArquivo, "rb");

    fseek(f, pos*sizeof(registro), SEEK_SET);
    fread(&busca, sizeof(registro), 1, f);

    while(busca.disponibilidade == 0) {
        pos = (pos + 1) % tamanhoHashTable;
        fseek(f, pos*sizeof(registro), SEEK_SET);
        fread(&busca, sizeof(registro), 1, f);
    }

    fclose(f);
    return pos;
}

void inserir(registro elemento) {
    int pos = acharPosicao(elemento.info.matricula);
    FILE* f = fopen(nomeArquivo, "r+b");

    registro novoRegistro;
    novoRegistro.info = elemento.info;
    novoRegistro.disponibilidade = 0;

    fseek(f, pos*sizeof(registro), SEEK_SET);
    fwrite(&novoRegistro, sizeof(registro), 1, f);
    fclose(f);
}

void recuperarHash(registro (*registros)[]) {
    FILE* f = fopen(nomeArquivo, "rb");
    int i;

    for (i = 0; i < tamanhoHashTable; i++) {
        fread(&((*registros)[i]), sizeof(registro), 1, f);
    }

    fclose(f);
}

int buscarAluno(int matricula, registro* aluno) {
    int pos = hashProximaDisponivel(matricula);
    FILE* f = fopen(nomeArquivo, "rb");
    int encontrou = 0;

    fseek(f, pos*sizeof(registro), SEEK_SET);
    fread(&(*aluno), sizeof(registro), 1, f);
    
    if ((*aluno).info.matricula == matricula) {
            encontrou = 1;
            fclose(f);
            return pos;
        }

    while((*aluno).disponibilidade == 0) {
        pos = (pos + 1) % tamanhoHashTable;
        fseek(f, pos*sizeof(registro), SEEK_SET);
        fread(&(*aluno), sizeof(registro), 1, f);

        printf("\nAlvo: %d | Atual: %d\n", matricula, (*aluno).info.matricula);

        if ((*aluno).info.matricula == matricula) {
            encontrou = 1;
            break;
        }
    }

    if (encontrou == 0) pos = -1;

    fclose(f);
    return pos;
}

void imprimirHash() {
    
    registro registros[tamanhoHashTable];
    recuperarHash(&registros);
    int i;

    for (i = 0; i < tamanhoHashTable; i++) {
        printf("Posicao %d: ", i);
        if (registros[i].disponibilidade == 1) {
            printf("livre.\n");
        }
        else {
            printf("\n\tNome: \t\t%s\n", registros[i].info.nome);
            printf("\tCurso: \t\t%s\n", registros[i].info.curso);
            printf("\tMatricula: \t%d\n", registros[i].info.matricula);
        }
        printf("---------------------------\n");
    }
}

// * Menu
void imprimirMenu() {
    puts("==================================");
    printf("[1] Inserir um novo aluno\n");
    printf("[2] Buscar um aluno\n");
    printf("[3] Imprimir a tabela de dispersao\n");
    printf("[4] Sair\n");
    puts("==================================");
}

void menu(int entrada) {
    switch (entrada) {
        case 1:
            registro cru;
            printf("Nome > ");
            scanf(" %s", cru.info.nome);
            printf("Curso > ");
            scanf(" %s", cru.info.curso);
            printf("Matricula > ");
            scanf(" %d", &cru.info.matricula);
            inserir(cru);
            break;
        case 2:
            registro resultadoBusca;
            int matricula;
            printf("Matricula > ");
            scanf(" %d", &matricula);
            int encontrou = buscarAluno(matricula, &resultadoBusca);
            if (encontrou == -1) printf("O registro nao existe.\n");
            else {
                printf("Aluno encontrado na posicao %d da tabela.\n", encontrou);
                printf("---------------------------\n");
                printf("Nome: \t\t%s\n", resultadoBusca.info.nome);
                printf("Curso: \t\t%s\n", resultadoBusca.info.curso);
                printf("Matricula: \t%d\n", resultadoBusca.info.matricula);
                printf("---------------------------\n");
            }
            break;
        case 3:
            imprimirHash();
            break;
        default:
            break;
    }
}

int main() {

    int entrada;
    inicializarArquivoBinario();

    while(1) {
        imprimirMenu();
        printf("Selecione > ");
        scanf("%d", &entrada);

        if (entrada == 4) {
            limparArquivoBinario();
            break;
        }

        menu(entrada);
    }

    return 0;
}