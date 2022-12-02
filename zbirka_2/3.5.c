/*3.5Саставити програм који учита низ целих бројева дужине n и проналази и исписује
аритметичку средину елемената. Елементе низа сместити у динамички алоцирану меморију.*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *niz, n, s = 0;
	
	scanf("%d", &n);

	niz = malloc(n * sizeof(int));

	for(unsigned int i = 0; i < n; ++i)
		scanf("%d", &niz[i]);

	for(unsigned int i = 0; i < n; ++i)
		s += niz[i];

	double ars = s / n;

	printf("ars = %lf\n", ars);

	free(niz);

	return 0;
}
