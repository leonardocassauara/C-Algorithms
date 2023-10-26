#include <stdio.h>

int main()
{
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf(((a % 2 == 0) && (b % 2 == 0)) ? "Ambos sao pares" : (((a % 2 == 0) || (b % 2 == 0)) ? "Um dos valores eh par" : "Os dois valores sao impares")); 

    return 0;
}
