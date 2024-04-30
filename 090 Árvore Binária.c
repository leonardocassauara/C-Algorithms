# include <stdio.h>
# include <stdlib.h>

typedef struct arvore {
    int info;
    struct arvore* esq;
    struct arvore* dir;
} arvore;


arvore* lerArvore(FILE* arq) {
    char c;
    int num;

    fscanf(arq, "%c", &c);
    fscanf(arq, "%d", &num);

    if (num == -1) {
        fscanf(arq, "%c", &c);
        return NULL;
    }
    else {
        arvore* a = (arvore*) malloc(sizeof(arvore));
        a->info = num;
        a->esq = lerArvore(arq);
        a->dir = lerArvore(arq);
        fscanf(arq, "%c", &c);
        return a;
    }
}


void imprimirArvore(arvore* arv) {
    if (arv != NULL) {
        printf("%d ", arv->info);
        imprimirArvore(arv->esq);
        imprimirArvore(arv->dir);
    }
}


void liberarArvore(arvore* arv) {
    if (arv != NULL) {
        liberarArvore(arv->esq);
        liberarArvore(arv->dir);
        free(arv);
    }
}


int contaNo(arvore* arv, int cont) {
    if (arv == NULL) return 0;
    else {
        return 1 + contaNo(arv->esq, cont + 1 ) + contaNo(arv->dir, cont + 1);
    }
}


int main() {

    FILE* arq;
    arvore* a;
    int nos;

    arq = fopen("arvoreMaior.txt", "rt");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    a = lerArvore(arq);
    imprimirArvore(a);
    nos = contaNo(a, 0);
    printf("\n %d \n", nos);
    liberarArvore(a);

    fclose(arq);
    return 0;
}