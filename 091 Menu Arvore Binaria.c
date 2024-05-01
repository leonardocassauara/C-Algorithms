# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct arvore {
    int info;
    struct arvore* esq;
    struct arvore* dir;
} arvore;


void imprimirMenu() {
    puts("================================================");
    printf("[1] Ler arvore\n");
    printf("[2] Imprimir arvore\n");
    printf("[3] Verificar se existe um elemento na arvore\n");
    printf("[4] Contar nos da arvore\n");
    printf("[5] Imprimir nos folhas da arvore\n");
    printf("[6] Verificar se arvore esta balanceada\n");
    printf("[7] Verificar se arvore esta cheia\n");
    printf("[8] Imprimir o nivel de um no\n");
    printf("[9] Sair\n");
    puts("================================================");
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


void preOrder(arvore* arv) {
    if (arv != NULL) {
        printf("%d ", arv->info);
        preOrder(arv->esq);
        preOrder(arv->dir);
    }
}


void inOrder(arvore* arv) {
    if (arv != NULL) {
        inOrder(arv->esq);
        printf("%d ", arv->info);
        inOrder(arv->dir);
    }
} 


void posOrder(arvore* arv) {
    if (arv != NULL) {
        posOrder(arv->esq);
        posOrder(arv->dir);
        printf("%d ", arv->info);
    }
}


int calcularAltura(arvore* arv) {
    if (arv == NULL) return 0;
    else {
        int alturaEsquerda = calcularAltura(arv->esq);
        int alturaDireita = calcularAltura(arv->dir);

        if (alturaEsquerda > alturaDireita) return alturaEsquerda + 1;
        else return alturaDireita + 1;
    }
}


void imprimirElementosNivel(arvore* arv, int nivelAtual, int nivelAlvo) {
    if (arv != NULL) {
        if (nivelAtual == nivelAlvo) {
            printf("%d ", arv->info);
        }
        else {
            imprimirElementosNivel(arv->esq, nivelAtual+1, nivelAlvo);
            imprimirElementosNivel(arv->dir, nivelAtual+1, nivelAlvo);
        }
    }
}


void largura(arvore* arv, int nivelAtual, int altura) {
    imprimirElementosNivel(arv, 0, nivelAtual);
    if (nivelAtual < altura) largura(arv, nivelAtual+1, altura);
}


void menuImprimirArvore(arvore* arv) {
    int modo;
    puts("==============");
    printf("[1] Pre-order\n");
    printf("[2] In-order\n");
    printf("[3] Pos-order\n");
    printf("[4] Em largura\n");
    puts("==============");
    scanf("%d", &modo);
    printf("Arvore: ");
    if (modo == 1) {
        preOrder(arv);
    }
    else if (modo == 2) {
        inOrder(arv);
    }
    else if (modo == 3) {
        posOrder(arv);
    }
    else {
        int altura = calcularAltura(arv);
        largura(arv, 0, altura);
    }
    puts("");
}


void liberarArvore(arvore* arv) {
    if (arv != NULL) {
        liberarArvore(arv->esq);
        liberarArvore(arv->dir);
        free(arv);
    }
}


int estaNaArvore(arvore* arv, int alvo) {
    if (arv == NULL) return 0;
    else {
        if (arv->info == alvo) return 1;
        else {
            int returnEsquerdo = estaNaArvore(arv->esq, alvo);
            if (returnEsquerdo == 1) return 1;
            return estaNaArvore(arv->dir, alvo);
        }
    }
}


int contarNo(arvore* arv, int cont) {
    if (arv == NULL) return 0;
    else {
        return 1 + contarNo(arv->esq, cont + 1 ) + contarNo(arv->dir, cont + 1);
    }
}


void imprimirFolhas(arvore* arv) {
    if (arv != NULL) {
        imprimirFolhas(arv->esq);
        imprimirFolhas(arv->dir);
        if ((arv->esq == NULL) && (arv->dir == NULL)) printf("%d ", arv->info);
    }
}


int estaBalanceada(arvore* arv) {
    if (arv == NULL) return 1;
    
    int he = calcularAltura(arv->esq);
    int hd = calcularAltura(arv->dir);
    if (abs(he - hd) > 1) return 0;
    else {
        int re = estaBalanceada(arv->esq);
        int rd = estaBalanceada(arv->dir);
        if ((re == 0) || (rd == 0)) return 0;
        return 1;
    }
}


int contarElementosNivel(arvore* arv, int nivelAtual, int nivelAlvo) {
    if (arv != NULL) {
        return ((nivelAtual == nivelAlvo) ? 1 : 0) + contarElementosNivel(arv->esq, nivelAtual+1, nivelAlvo) + contarElementosNivel(arv->dir, nivelAtual+1, nivelAlvo);
    }
    else return 0;
}


int estaCheia(arvore* arv, int altura) {
    if (arv == NULL) return 1;
    int folhas = contarElementosNivel(arv, 0, altura-1);
    if (folhas == pow(2, altura-1)) return 1;
    else return 0;
}


void imprimirNivelNo(arvore* arv, int alvo, int nivelAtual) {
    if (arv != NULL) {
        if (arv->info == alvo) {
            printf("%d ", nivelAtual);
            return;
        }
        imprimirNivelNo(arv->esq, alvo, nivelAtual+1);
        imprimirNivelNo(arv->dir, alvo, nivelAtual+1);
    }
}


void menu(int entrada, arvore** arv) {
    switch (entrada) {
        case 1:
            if (*arv != NULL) liberarArvore(*arv);
            FILE* arq = fopen("arvoreMaior.txt", "rt");
            if (arq == NULL) {
                puts("Erro ao abrir arquivo.");
                break;
            }
            *arv = lerArvore(arq);
            if (*arv != NULL) puts("Leitura feita com sucesso.");
            else {
                puts("Arvore nula.");
            }
            fclose(arq);
            break;
        case 2:
            menuImprimirArvore(*arv);
            break;
        case 3:
            int existe;
            int alvo3;
            puts("===========");
            puts("Qual valor?");
            puts("===========");
            scanf("%d", &alvo3);
            existe = estaNaArvore(*arv, alvo3);
            printf("O elemento %d ", alvo3);
            printf((existe) ? "esta na arvore.\n" : "nao esta na arvore.\n");
            break;
        case 4:
            puts("=======================");
            printf("A arvore possui %d nos.\n", contarNo(*arv, 0));
            puts("=======================");
            break;
        case 5:
            puts("=======================");
            imprimirFolhas(*arv);
            puts("");
            puts("=======================");
            break;
        case 6:
            puts("=============================");
            printf((estaBalanceada(*arv)) ? "A arvore esta balanceada.\n" : "A arvore nao esta balanceada\n");
            puts("=============================");
            break;
        case 7:
            puts("=============================");
            int altura = calcularAltura(*arv);
            printf((estaCheia(*arv, altura)) ? "A arvore esta cheia.\n" : "A arvore nao esta cheia\n");
            puts("=============================");
            break;
        case 8:
            int alvo8;
            puts("=========================");
            puts("Por qual no busca na arvore?");
            scanf("%d", &alvo8);
            printf("Nivel do no %d: ", alvo8);
            imprimirNivelNo(*arv, alvo8, 0);
            puts("");
            puts("=========================");
            break;
        default:
            break;
    }
}


int main() {
    int entrada;
    arvore* arv = NULL;

    while(1) {
        imprimirMenu();
        scanf("%d", &entrada);

        if (entrada == 9) {
            liberarArvore(arv);
            break;
        }
        else menu(entrada, &arv);
    }

    return 0;
}