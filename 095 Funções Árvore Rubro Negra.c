# include <stdio.h>
# include <stdlib.h>

typedef struct arvore {
    int info;
    char cor; // p v
    struct arvore* esq;
    struct arvore* dir;
} arvore;


void imprimirMenu() {
    puts("================================================");
    printf("[1] Ler arvore\n");
    printf("[2] Imprimir arvore in-order\n");
    printf("[3] Verificar se existe um elemento na arvore\n");
    printf("[4] Imprimir altura negra da arvore\n");
    printf("[8] Sair\n");
    puts("================================================");
}


void inOrder(arvore* arv) {
    if (arv != NULL) {
        inOrder(arv->esq);
        printf("%d ", arv->info);
        inOrder(arv->dir);
    }
} 


void liberarArvore(arvore* arv) {
    if (arv != NULL) {
        liberarArvore(arv->esq);
        liberarArvore(arv->dir);
        free(arv);
    }
}

// Falha
arvore* lerArvore(FILE* arq) {
    char c;
    int num;
    char cor;

    fscanf(arq, "%c", &c);
    fscanf(arq, "%d", &num);

    if (num == -1) {
        fscanf(arq, "%c", &c);
        return NULL;
    }
    else {
        fscanf(arq, "%c", &cor);
        arvore* a = (arvore*) malloc(sizeof(arvore));
        a->info = num;
        a->esq = lerArvore(arq);
        a->dir = lerArvore(arq);
        a->cor = cor;
        fscanf(arq, "%c", &c);
        return a;
    }
}


int existe(arvore* arv, int info) {
    if (arv != NULL) {
        if (arv->info == info) return 1;
        else if (arv->info > info) return existe(arv->esq, info);
        else return existe(arv->dir, info);
    }
    return 0;
}


int alturaNegra(arvore* arv) {
    if (arv != NULL) {
        return 1 + alturaNegra(arv->esq);
    }
    return 0;
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
            if (*arv != NULL) {
                puts("Leitura feita com sucesso.");
            }
            else {
                puts("Arvore nula.");
            }
            fclose(arq);
            break;
        case 2:
            puts("");
            inOrder(*arv);
            puts("");
            break;
        case 3:
            int info3;
            printf("Qual valor? > ");
            scanf("%d", &info3);
            puts("");
            printf(existe(*arv, info3) ? "O elemento existe na arvore." : "O elemento nao existe na arvore.");
            puts("");
            break;
        case 4:
            puts("");
            printf("A altura negra da arvore eh %d", alturaNegra(*arv));
            puts("");
            break;
    }
}


int main() {
    int entrada;
    arvore* arv = NULL;

    while(1) {
        imprimirMenu();
        printf("Selecione > ");
        scanf("%d", &entrada);

        if (entrada == 8) {
            liberarArvore(arv);
            break;
        }

        menu(entrada, &arv);
    }

    return 0;
}