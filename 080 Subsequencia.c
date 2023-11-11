#include<stdio.h>
#include<string.h>

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/1507

int sub (char vetO[], char vetM[], int sizeO, int sizeM){

    int j = 0;

    for(int i= 0; i< sizeO ; i++){

       if(vetO[i] == vetM[j]){

         j++;
       }
    }

    if (j==sizeM) return 1;
    
    return 0;
}

int main()
{
    int n;
    char test [100000];

    scanf("%d", &n);

    for(int i = 0; i < n ; i++){

       int k;

       scanf("%s%d", test, &k);

       for (int j = 0; j < k; j++){

          char ks[100];
          scanf("%s", ks);

          int sizeO = strlen(test);
          int sizeM = strlen(ks);

          if(sub(test, ks, sizeO, sizeM)){

            printf ("Yes\n");
          }
          else{

           printf("No\n");
          }
       }
    }
    return 0;
}