# include <stdio.h>
# include <stdlib.h>

float* transforma(float* U, int N, float (*f)(float)) {

    float* d = malloc(N*sizeof(float));

    int i;

    for (i = 0; i < N; i++) {

        d[i] = f(U[i]);
    }

    return d;
}


float teste(float x){
    return 0.5*x*x - 0.7*x + 2.1;
}


int main(){
    int i;

    float u[5] = {2.5, 4.8, 4.9, 3.98, 4.7};

    float* v = transforma(u, 5, teste);

    for(i = 0; i < 5; i++)

        printf("%g ", v[i]);

    free(v);

    return 0;
}
