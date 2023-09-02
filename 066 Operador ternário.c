#include <stdio.h>

int main()
{
    int a, b, soma;
    const char* e;
    
    scanf("%d %d", &a, &b);
    soma = a + b;
    
    e = soma % 3 == 0? "A soma eh multiplo de 3":"A soma nao eh multiplo de 3";
    
    printf("Soma = %d\n%s", soma, e);

    return 0;
}
