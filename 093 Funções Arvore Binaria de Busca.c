#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
    int info;
    struct arvore* esq;
    struct arvore* dir;
} arvore;


void imprimirMenu() {
    puts("===============================");
    printf("[1] Ler Arvore\n");
    printf("[2] Contar nos internos\n");
    printf("[3] Imprimir filhos de um elemento\n");
    printf("[4] Imprimir pai de um elemento\n");
    printf("[5] Verificar ordenacao\n");
    printf("[6] Sair\n");
    puts("===============================");
}


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


void liberarArvore(arvore* arv) {
    if (arv != NULL) {
        liberarArvore(arv->esq);
        liberarArvore(arv->dir);
        free(arv);
    }
}


int contarNosInternos(arvore* arv) {
    if (arv == NULL) return 0;
    else {
        if ((arv->esq == NULL) && (arv->dir == NULL)) return 0;
        else {
            return 1 + contarNosInternos(arv->esq) + contarNosInternos(arv->dir);
        }
    }
}

// Implementação para ABB
void imprimirFilhosNo(arvore* arv, int info) {
    if (arv != NULL) {
        if (arv->info == info) {
            if (arv->esq) printf("%d ", arv->esq->info);
            if (arv->dir) printf("%d ", arv->dir->info);
            return;
        }
        else if (arv->info > info) imprimirFilhosNo(arv->esq, info);
        else imprimirFilhosNo(arv->dir, info);
    }
}

// Implementação para ABB
void imprimirPaiNo(arvore* arv, arvore* pai, int info) {
    if (arv != NULL) {
        if (arv->info == info) {
            if (pai == NULL) printf("0");
            else printf("%d ", pai->info);
            return;
        }
        else {
            arvore* pai = arv;
            
            if (arv->info > info) imprimirPaiNo(arv->esq, pai, info);
            else imprimirPaiNo(arv->dir, pai, info);
        }
    }
}


int contaNos(arvore* arv) {
    if (arv == NULL) return 0;
    else {
        return 1 + contaNos(arv->esq) + contaNos(arv->dir);
    }
}


void nosInOrder(arvore* arv, int** nos, int i) {
    if (arv) {
        nosInOrder(arv->esq, nos, i);
        (*nos)[i] = arv->info;
        nosInOrder(arv->dir, nos, i+1);
    }
}


int estaOrdenada(arvore* arv) {
    int numNos = contaNos(arv);
    int* nos = (int*)malloc(numNos*sizeof(int));
    nosInOrder(arv, &nos, 0);
    int i;
    int ordenado = 1;
    for (i = 1; i < numNos; i++) {
        if (nos[i] < nos[i-1]) ordenado = 0;
    }
    free(nos);
    return ordenado;
}


void menu(int entrada, arvore** arv) {
    switch (entrada) {
        case 1:
            if (*arv != NULL) liberarArvore(*arv);
            FILE* f = fopen("arvore.txt", "rt");
            *arv = lerArvore(f);
            if (*arv == NULL) puts("Arvore nula");
            puts("Leitura feita com sucesso.");
            break;
        case 2:
            printf("%d\n", contarNosInternos(*arv));
            break;
        case 3:
            int info3;
            printf("\nQual elemento? > ");
            scanf("%d", &info3);
            imprimirFilhosNo(*arv, info3);
            puts("");
            break;
        case 4:
            int info4;
            printf("\nQual elemento? > ");
            scanf("%d", &info4);
            arvore* pai = NULL;
            imprimirPaiNo(*arv, pai, info4);
            liberarArvore(pai);
            puts("");
        case 5:
            printf(estaOrdenada(*arv) ? "A arvore esta ordenada." : "A arvore nao esta ordenada.");
            puts("");
            break;
        default:
            break;
    }
}


int main()
{
    arvore* arv = NULL;
    int entrada;

    while(1) {
        imprimirMenu();
        printf("Valor > ");
        scanf("%d", &entrada);
        
        if (entrada == 6) {
            if (arv) liberarArvore(arv);
            break;
        }
        
        menu(entrada, &arv);
    }

    return 0;
}