# include <stdio.h>
# include <stdlib.h>

// * Grafo
typedef struct lista {
    int destino;
    int custo;
    struct lista* prox;
} lista;

void inicializarGrafo(lista** grafo, int n) {
    int i;
    for (i = 0; i <= n; i++) grafo[i] = NULL;
}

lista* inserirLista(lista* proxNo, int destino, int custo) {
    lista* no = (lista*)malloc(sizeof(lista));
    no->destino = destino;
    no->custo = custo;
    no->prox = proxNo;
    return no;
}

void inserirAresta(lista** grafo, int origem, int destino, int custo) {
    grafo[origem] = inserirLista(grafo[origem], destino, custo);
}

lista* removerLista(lista* l, int destino) {
    while (l != NULL) {
        if ((l->destino == destino)) { // * Achamos o no
            lista* aux = l->prox;
            free(l);
            return aux; // * Linka os nos que foram separados
        }
        else { // * Prossegue com a busca
            return removerLista(l->prox, destino);
        }
    }
    puts("Elemento nao encontrado.");
    return l;
}

void removerAresta(lista** grafo, int origem, int destino) {
    grafo[origem] = removerLista(grafo[origem], destino);
}

void imprimirLista(lista* l) {
    if (l != NULL) {
        printf("-(%d, %d)", l->destino, l->custo);
        imprimirLista(l->prox);
    }
}

void imprimirGrafo(lista** grafo, int n) {
    int i;
    printf("Grafo: ");
    for (i = 1; i <= n; i++) { // ! Ignoramos o 0
        printf("\n\t%d", i);
        imprimirLista(grafo[i]);
    }
    puts("");
}

int contarGrauSaida(lista* l) {
    if (l != NULL) {
        return 1 + contarGrauSaida(l->prox);
    }
    return 0;
}

int contarGrauEntrada(lista* l, int vertice) {
    if (l != NULL) {
        if (l->destino == vertice) return 1 + contarGrauEntrada(l->prox, vertice);
        return contarGrauEntrada(l->prox, vertice);
    }
    return 0;
}

void imprimirGraus(lista** grafo, int vertice, int n) {
    int i;
    int ge = 0;
    int gs = 0;
    for (i = 1; i <= n; i++) {
        if (i == vertice) gs = gs + contarGrauSaida(grafo[i]);
        ge = ge + contarGrauEntrada(grafo[i], vertice);
    }
    printf("Grau de entrada: %d | Grau de saida: %d\n", ge, gs);
}

int contaNos(lista* l) {
    if (l != NULL) return 1 + contaNos(l->prox);
    else return 0;
}

int verificarCompleto(lista** grafo, int totalVertices) {
    int i;
    for (i = 1; i <= totalVertices; i++) {
        if (contaNos(grafo[i]) < totalVertices - 1) return 0;
    }
    return 1;
}

// * Funcoes do Menu
void imprimirMenu() {
    puts("========================================================");
    printf("[1] - Inserir aresta no grafo\n");
    printf("[2] - Remover uma aresta do grafo\n");
    printf("[3] - Imprimir grafo\n");
    printf("[4] - Imprimir os graus de entrada e saida de um vertice\n");
    printf("[5] - Verificar se um grafo eh completo\n");
    printf("[6] - Sair\n");
    puts("========================================================");
    puts("");
    printf("Selecione > ");
}

void menu(int entrada, lista** g, int n) {
    int origem;
    int destino;
    int custo;
    int vertice;

    switch(entrada) {
        case 1: // * Inserir aresta 
            printf("Origem (vertice) > ");
            scanf("%d", &origem);
            printf("Destino > ");
            scanf("%d", &destino);
            printf("Custo > ");
            scanf("%d", &custo);
            inserirAresta(g, origem, destino, custo);
            break;
        case 2: // * Remover aresta
            printf("Origem (vertice) > ");
            scanf("%d", &origem);
            printf("Destino > ");
            scanf("%d", &destino);
            removerAresta(g, origem, destino);
            break;
        case 3: // * Imprimir grafo
            imprimirGrafo(g, n);
            break;
        case 4: // * Imprimir graus
            printf("Qual vertice? > ");
            scanf("%d", &vertice);
            imprimirGraus(g, vertice, n);
            break;
        case 5: // * Verificar completude
            if (verificarCompleto(g, n) == 1) puts("O grafo eh completo");
            else puts("O grafo nao eh completo");
            break;
        default: break;
    }
}

int main() {
    // * Setup
    int entrada;
    int n;
    puts("Um grafo de quantos vertices? > ");
    scanf("%d", &n);
    lista** g = (lista**)malloc((n+1)*sizeof(lista*));
    inicializarGrafo(g, n);
    printf("Foi criado um grafo com vertices de 1 ate %d!\n", n);

    // * Menu
    while(1) {
        imprimirMenu();
        scanf("%d", &entrada);

        if (entrada == 6) break;

        menu(entrada, g, n);
    }

    free(g);
    return 0;
}