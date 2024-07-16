# include <stdlib.h>
# include <stdio.h>

void imprimirMenu() {
    puts("================================================================================================================");
    printf("[1] - Todas as combinacoes de {a, e, i}, de tamanho 3, em que 'a' aparece mais vezes que 'e' e 'i' juntos\n");
    printf("[2] - Todas as combinações de {15, 31, 55, 44}, de tamanho 3, em que a soma dos algarimos da combinação seja par\n");
    printf("[3] - Imprimir todas as maneiras de representar um valor em centavos (1, 5, 10, 25 e 50 centavos)\n");
    printf("[4] - Sair\n");
    puts("================================================================================================================");
    puts("");
    printf("Selecione > ");
}

// * Backtracking em vetores de char com verificacao (mais 'a')
void maisAs(char* output, int pos, int tamanhoOutput, char* input, int tamanhoInput) {
    if (pos == tamanhoOutput) {
        int i;

        int as = 0;
        for (i = 0; i < tamanhoOutput; i++) if (output[i] == 'a') as++; // ! Contador de 'a'
        if (as > tamanhoOutput / 2) { // ! Verificador
            printf("%s", output);
            puts("");
        }
    }
    else {
        int j;
        for (j = 0; j < tamanhoInput; j++) {
            output[pos] = input[j];
            maisAs(output, pos + 1, tamanhoOutput, input, tamanhoInput);
        }
    }
}

// * Backtracking em vetores de char com verificacao (soma da combinacao par)
void somaCombinacaoPar(int* output, int pos, int tamanhoOutput, int* input, int tamanhoInput) {
    if (pos == tamanhoOutput) {
        int i;
        int acumulador = 0;

        for (i = 0; i < tamanhoOutput; i++) acumulador = acumulador + output[i]; // ! Somatorio
        if (acumulador % 2 == 0) { // ! Verificacao
            for (i = 0; i < tamanhoOutput; i++) printf("%d", output[i]);
            printf(" | Soma: %d ", acumulador);
            puts("");
        }
    }
    else {
        int j;
        for (j = 0; j < tamanhoInput; j++) {
            output[pos] = input[j];
            somaCombinacaoPar(output, pos + 1, tamanhoOutput, input, tamanhoInput);
        }
    }
}

void imprimeCombinacao(int um, int cinco, int dez, int vintecinco, int cinquenta) {
    int algumaZero = 0;
    
    if (um != 0) printf("%d moedas de 1  ", um);
    else algumaZero = 1;
    if (cinco != 0) printf("%d moedas de 5  ", cinco);
    else algumaZero = 1;
    if (dez != 0) printf("%d moedas de 10  ", dez);
    else algumaZero = 1;
    if (vintecinco != 0) printf("%d moedas de 55  ", vintecinco);
    else algumaZero = 1;
    if (cinquenta != 0) printf("%d moedas de 50  ", cinquenta);
    else algumaZero = 1;

    if (algumaZero) printf("(nenhuma das restantes)");

    puts("");
}

// * Backtraking em todas as maneiras de representar um dado valor com números específicos (moedas)
void combinacaoEmCentavos(int acumulador, int pos, int* output, int* input, int centavosUsuario, int indiceInput) {
    // * Condição de parada para combinações indesejadas
    if (acumulador > centavosUsuario) return;

    // * Imprimir combinação obtida
    if (acumulador == centavosUsuario) {
        int i;
        int um = 0; 
        int cinco = 0; 
        int dez = 0; 
        int vintecinco = 0; 
        int cinquenta = 0;

        for (i = 0; i < pos; i++) {
            if (output[i] == 1) um++;
            else if (output[i] == 5)  cinco++;
            else if (output[i] == 10) dez++;
            else if (output[i] == 25) vintecinco++;
            else if (output[i] == 50) cinquenta++;
        }
        
        imprimeCombinacao(um, cinco, dez, vintecinco, cinquenta);
        return;
    }
    // * Formar combinação
    int i;
    for (i = indiceInput; i < 5; i++) {
        output[pos] = input[i];
        combinacaoEmCentavos(acumulador + input[i], pos + 1, output, input, centavosUsuario, i);
    }
    return;
}

void menu(int entrada) {
    switch(entrada) {
        case 1:
            char inputCaracteres[4] = {'a', 'e', 'i', '\0'};
            char outputCaracteres[4] = {'z', 'z', 'z', '\0'};
            maisAs(outputCaracteres, 0, 3, inputCaracteres, 3); 
            break;
        case 2:
            int inputNumeros[4] = {15, 31, 55, 44};
            int outputNumeros[3] = {0, 0, 0};
            somaCombinacaoPar(outputNumeros, 0, 3, inputNumeros, 4); 
            break;
        case 3:
            int inputCentavos[5] = {1, 5, 10, 25, 50};
            int outputCentavos[5];
            int centavos;
            printf("\nQuanto centavos? > ");
            scanf("%d", &centavos);
            combinacaoEmCentavos(0, 0, outputCentavos, inputCentavos, centavos, 0);
            break;
        default: break;
    }
}

int main() {

    int entrada;

    while(1) {
        imprimirMenu();
        scanf("%d", &entrada);

        if (entrada == 4) break;

        menu(entrada);
    }

    return 0;
}