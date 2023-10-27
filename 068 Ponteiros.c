# include <stdio.h>


void main() {
	int a = 521;
	int* p = &a;
	int** p1 = &p;
	
	printf("%d", **p1);
}
