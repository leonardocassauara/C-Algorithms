# include <stdio.h>
# include <stdlib.h>

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
    printf("[4] Imprimir o nivel de um no\n");
    printf("[5] Imprimir as folhas menores que um valor\n");
    printf("[6] Inserir um no na arvore\n");
    printf("[7] Remover um no da arvore\n");
    printf("[8] Sair\n");
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


void liberarArvore(arvore* arv) {
    if (arv != NULL) {
        liberarArvore(arv->esq);
        liberarArvore(arv->dir);
        free(arv);
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


int existeNaArvore(arvore* arv, int info) {
    if (arv == NULL) return 0;
    else if (info == arv->info) return 1;
    else if (info < arv->info) return existeNaArvore(arv->esq, info);
    else return existeNaArvore(arv->dir, info);
} 


void imprimirNivelNo(arvore* arv, int info, int nivelAtual) {
    if (arv != NULL) {
        if (arv->info == info) {
            printf("O no %d foi encontrado no nivel %d", info, nivelAtual);
            return;
        }
        else if (arv->info < info) imprimirNivelNo(arv->dir, info, nivelAtual+1);
        else imprimirNivelNo(arv->esq, info, nivelAtual+1);
    }
}


void imprimirFolhasMenores(arvore* arv, int info) {
    if (arv != NULL) {
        if (arv->info > info) {
            imprimirFolhasMenores(arv->esq, info);
        }
        else if ((arv->esq == NULL) && (arv->dir == NULL)) {
            printf("%d ", arv->info);
            return;
        }
        else {
            imprimirFolhasMenores(arv->esq, info);
            imprimirFolhasMenores(arv->dir, info);
        }
    }
}


arvore* inserir(arvore* arv, int info) {
    if (arv == NULL) {
        arv = (arvore*)malloc(sizeof(arvore));
        arv->info = info;
        arv->esq = NULL;
        arv->dir = NULL;
    }
    else if (info <= arv->info) {
        arv->esq = inserir(arv->esq, info);
    }
    else arv->dir = inserir(arv->dir, info);
    
    return arv;
}


arvore* remover(arvore* arv, int info) {
    if (arv != NULL) {
        // Encontramos o nó que queremos remover
        if (arv->info == info) {
            // Caso 1: ambos os filhos nulos
            if((arv->esq == NULL) && (arv->dir == NULL)) {
                free(arv);
                return NULL;
            }
            // Caso 2: um dos filhos nulos
            else if (arv->esq == NULL) {
                arvore* aux = arv->dir;
                free(arv);
                return aux;
            }
            else if (arv->dir == NULL) {
                arvore* aux = arv->esq;
                free(arv);
                return aux;
            }
            // Caso 3: nenhum dos filhos nulos
            else {
                arvore* aux = arv->esq;
                while (aux->dir != NULL) {
                    aux = aux->dir;
                }
                arv->info = aux->info;
                arv->esq = remover(arv->esq, aux->info);
            }
        }
        // O nó que queremos remover é menor que o nó atual
        else if (arv->info > info) arv->esq = remover(arv->esq, info);
        // O nó que queremos remover é maior que o nó atual
        else arv->dir = remover(arv->dir, info);
    }
    return arv;
}


void menu(int entrada, arvore** arv) {
    switch (entrada) {
        case 1:
            if (*arv != NULL) liberarArvore(*arv);
            FILE* arq = fopen("arvore.txt", "rt");
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
            int info3;
            puts("===========");
            puts("Qual valor?");
            puts("===========");
            scanf("%d", &info3);
            puts("================================");
            printf(existeNaArvore(*arv, info3) ? "O elemento existe na arvore." : "O elemento nao existe na arvore.");
            puts("");
            puts("================================");
            break;
        case 4:
            int info4;
            puts("===========");
            puts("Qual valor?");
            puts("===========");
            scanf("%d", &info4);
            puts("=========================");
            if (existeNaArvore(*arv, info4)) imprimirNivelNo(*arv, info4, 0);
            else printf("O elemento nao existe na arvore.");
            puts("");
            puts("=========================");
        case 5:
            int info5;
            puts("===========");
            puts("Qual valor?");
            puts("===========");
            scanf("%d", &info5);
            puts("=============");
            imprimirFolhasMenores(*arv, info5);
            puts("No criado e inserido.");
            puts("=============");
            break;
        case 6:
            int info6;
            puts("===========");
            puts("Qual valor?");
            puts("===========");
            scanf("%d", &info6);
            puts("=================================");
            *arv = inserir(*arv, info6);
            puts("No criado e inserido com sucesso.");
            puts("=================================");
            break;
        case 7:
            int info7;
            puts("===========");
            puts("Qual valor?");
            puts("===========");
            scanf("%d", &info7);
            puts("========================");
            *arv = remover(*arv, info7);
            puts("No removido com sucesso.");
            puts("========================");
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

        if (entrada == 8) {
            if (arv) liberarArvore(arv);
            break;
        }
        else menu(entrada, &arv);
    }

    return 0;
}