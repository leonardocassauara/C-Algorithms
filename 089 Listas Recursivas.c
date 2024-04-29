# include <stdio.h>
# include <stdlib.h>


typedef struct lista {
    int info;
    struct lista* prox;
} lista;

lista* inserirFinal(lista* l, int info) {
    if (l == NULL) {
        lista* no = (lista*) malloc(sizeof(lista));
        no->info = info;
        no->prox = NULL;
        return no;
    }
    else {
        l->prox = inserirFinal(l->prox, info);
        return l;
    }
}


int somarTudo(lista* l) {
    if (l == NULL) {
        return 0;
    }
    else {
        return l->info + somarTudo(l->prox);
    }
}


int contarFrequencia(lista* l, int info) {
    if (l == NULL) {
        return 0;
    }
    else {
        if (l->info == info) return 1 + contarFrequencia(l->prox, info);
        else return contarFrequencia(l->prox, info);
    }
}


lista* removerNoEspecifico(lista* l, int info) {
    // Supondo que o elemento exista na lista...
    if (l->info == info) {
        lista* novaCabeca = l->prox;
        free(l);
        return novaCabeca;
    }
    else {
        l->prox = removerNoEspecifico(l->prox, info);
        return l;
    }
}

void imprimirLista(lista* l) {
    if (l == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", l->info);
    imprimirLista(l->prox);
}

int main() {
    lista* nos = NULL;
    nos = inserirFinal(nos, 3);
    nos = inserirFinal(nos, 4);
    nos = inserirFinal(nos, 4);
    nos = inserirFinal(nos, 6);
    nos = inserirFinal(nos, 6);
    nos = inserirFinal(nos, 4);

    int soma = somarTudo(nos);
    int quatro = contarFrequencia(nos, 4);
    printf("Soma: %d\n", soma);
    printf("Frequencia do 4: %d\n", quatro);

    imprimirLista(nos);
    nos = removerNoEspecifico(nos, 4);
    nos = removerNoEspecifico(nos, 4);
    imprimirLista(nos);

    soma = somarTudo(nos);
    quatro = contarFrequencia(nos, 4);
    printf("Soma: %d\n", soma);
    printf("Frequencia do 4: %d\n", quatro);

    free(nos);
    return 0;
}