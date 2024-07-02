# include <stdio.h>
# include <stdlib.h>

typedef struct arvore {
    int info;
    int FB;
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


int calcularAltura(arvore* arv) {
    if (arv == NULL) return 0;
    else {
        int alturaEsquerda = calcularAltura(arv->esq);
        int alturaDireita = calcularAltura(arv->dir);

        if (alturaEsquerda > alturaDireita) return alturaEsquerda + 1;
        else return alturaDireita + 1;
    }
}


void ajustarFB(arvore* arv) {
    if (arv != NULL) {
        int he = calcularAltura(arv->esq);
        int hd = calcularAltura(arv->dir);
        arv->FB = hd-he;

        ajustarFB(arv->esq);
        ajustarFB(arv->dir);
    }
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


arvore* lerAVL(FILE* arq) {
    arvore* arv = lerArvore(arq);
    ajustarFB(arv);
    return arv;
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


arvore* rotacaoEsqSimples(arvore* arv) {

    arvore* aux = arv;
    arvore* aux2 = aux->dir;

    aux->dir = aux2->esq;
    aux2->esq = aux;

    if (aux2->FB == 1) {
        aux->FB = 0;
        aux2->FB = 0;
    }
    else {
        aux->FB = 1;
        aux2->FB = -2;    
    }

    arv = aux2;
    return arv;
}


arvore* rotacaoEsqDupla(arvore* arv) {

    arvore* aux = arv;
    arvore* aux2 = aux->dir;
    arvore* aux3 = aux2->esq;

    aux2->esq = aux3->dir;
    aux->dir = aux3->esq;
    aux3->esq = aux;
    aux3->dir = aux2;

    switch (aux3->FB) {
        case -1:
            aux->FB = 0;
            aux2->FB = 1;
            break;
        case 0:
            aux->FB = 0;
            aux2->FB = 0;
            break;
        case +1:
            aux->FB = -1;
            aux2->FB = 0;
            break;
    }

    aux3->FB = 0;
    arv = aux3;
    return arv;
}


arvore* rotacaoEsq(arvore* arv) {
    if (arv->dir->FB == -1) arv = rotacaoEsqDupla(arv);
    else arv = rotacaoEsqSimples(arv);

    return arv;
}


arvore* rotacaoDirSimples(arvore* arv) {

    arvore* aux = arv->esq;
    arvore* aux2 = arv;

    aux2->esq = aux->dir;
    aux->dir = aux2;

    if (aux->FB == -1) {
        aux->FB = 0;
        aux2->FB = 0;
    }
    else {
        aux->FB = 1;
        aux2->FB = -1;
    }

    arv = aux;
    return arv;
}


arvore* rotacaoDirDupla(arvore* arv) {

    arvore* aux = arv;
    arvore* aux2 = aux->esq;
    arvore* aux3 = aux2->dir;

    aux->esq = aux3->dir;
    aux2->dir = aux3->esq;
    aux3->esq = aux2;
    aux3->dir = aux;

    switch (aux3->FB) {
        case -1:
            aux2->FB = 0;
            aux->FB = 1;
            break;
        case 0:
            aux2->FB = 0;
            aux->FB = 0;
            break;
        case +1:
            aux2->FB = -1;
            aux->FB = 0;
            break;
    }

    aux3->FB = 0;
    arv = aux3;
    return arv;
}


arvore* rotacaoDir(arvore* arv) {
    if (arv->esq->FB == 1) arv = rotacaoDirDupla(arv);
    else arv = rotacaoDirSimples(arv);

    return arv;
}


arvore* inserir(arvore* arv, int info, int* hMudou) {
    
    if (arv == NULL) {
        arv = (arvore*)malloc(sizeof(arvore));
        arv->info = info;
        arv->esq = NULL;
        arv->dir = NULL;
        arv->FB = 0;
        *hMudou = 1;
    }
    else {
        if ((arv->info > info) || (arv->info == info)) {
            arv->esq = inserir(arv->esq, info, hMudou);
            
            if (*hMudou == 1) {
                switch (arv->FB) {
                    case -1:
                        arv = rotacaoDir(arv);
                        *hMudou = 0;
                        break;
                    case 0:
                        arv->FB = -1;
                        *hMudou = 1;
                        break;
                    case +1:
                        arv->FB = 0;
                        *hMudou = 0;
                        break;
                }
            }
        }
        else {
            arv->dir = inserir(arv->dir, info, hMudou);
            if (*hMudou == 1) {
                switch (arv->FB) {
                    case -1:
                        arv->FB = 0;
                        *hMudou = 0;
                        break;
                    case 0:
                        arv->FB = +1;
                        *hMudou = 1;
                        break;
                    case +1:
                        arv = rotacaoEsq(arv);
                        *hMudou = 0;
                        break;
                }
            }
        }
    }
    return arv;
}


arvore* remover(arvore* arv, int info, int* hMudou) {
    if (arv != NULL) {
        if (arv->info == info) {

            if ((arv->esq == NULL) && (arv->dir == NULL)) {
                free(arv);
                *hMudou = 1;
                return NULL;
            }
            else if ((arv->esq == NULL) || (arv->dir == NULL)) {
                arvore* aux;
                if (arv->esq == NULL) {
                    aux = arv->dir;
                }
                else aux = arv->esq;
                free(arv);
                *hMudou = 1;
                return aux;
            }
            else {
                arvore* maiorEsq = arv->esq;
                while (maiorEsq->dir != NULL) maiorEsq = maiorEsq->dir;

                arv->info = maiorEsq->info;
                arv->esq = remover(arv->esq, arv->info, hMudou);

                if (*hMudou == 1) {
                    switch (arv->FB) {
                        case -1:
                            arv->FB = 0;
                            *hMudou = 1;
                            break;
                        case 0:
                            arv->FB = 1;
                            *hMudou = 0;
                            break;
                        case +1:
                            int aux2 = arv->dir->FB;
                            arv = rotacaoEsq(arv);

                            if (aux2 == 0) *hMudou = 0;
                            else *hMudou = 1;
                            break;
                    }
                }
            }
        }
        else if (arv->info > info) {
            arv->esq = remover(arv->esq, info, hMudou);

            if (*hMudou == 1) {
                switch (arv->FB) {
                    case -1:
                        arv->FB = 0;
                        *hMudou = 1;
                        break;
                    case 0:
                        arv->FB = 1;
                        *hMudou = 0;
                        break;
                    case +1:
                        int aux3 = arv->dir->FB;
                        arv = rotacaoEsq(arv);
                        if (aux3 == 0) *hMudou = 0;
                        else *hMudou = 1;
                        break;
                }
            }
        }
        else {
            arv->dir = remover(arv->dir, info, hMudou);
            if (*hMudou == 1) {
                switch (arv->FB) {
                    case +1:
                        arv->FB = 0;
                        *hMudou = 1;
                        break;
                    case 0:
                        arv->FB = -1;
                        *hMudou = 0;
                        break;
                    case -1:
                        int aux4 = arv->esq->FB;
                        arv = rotacaoDir(arv);

                        if (aux4 == 0) *hMudou = 0;
                        else *hMudou = 1;
                        break;
                }
            }
        }
    }

    return arv;
}


void menu(int entrada, arvore** arv, int* hMudou) {
    switch (entrada) {
        case 1:
            if (*arv != NULL) liberarArvore(*arv);
            FILE* arq = fopen("arvore.txt", "rt");
            if (arq == NULL) {
                puts("Erro ao abrir arquivo.");
                break;
            }
            *arv = lerAVL(arq);
            if (*arv != NULL) {
                puts("Leitura feita com sucesso.");
            }
            else {
                puts("Arvore nula.");
            }
            *hMudou = 0;
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
            *arv = inserir(*arv, info6, hMudou);
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
            *arv = remover(*arv, info7, hMudou);
            puts("No removido com sucesso.");
            puts("========================");
            break;
        default:
            break;
    }
}


int main() {
    int entrada;
    int hMudou = 0;
    arvore* arv = NULL;

    while(1) {
        imprimirMenu();
        scanf(" %d", &entrada);

        if (entrada == 8) {
            if (arv) liberarArvore(arv);
            break;
        }
        else menu(entrada, &arv, &hMudou);
    }

    return 0;
}