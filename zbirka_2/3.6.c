#include <stdio.h>
#include <stdlib.h>
/*3.6. Саставити програм који учита низ целих бројева дужине n и формира нови низ са обрнутим
редоследом елемената унетог низа. Исписати новодобијени низ. Елементе низа сместити у
динамички алоцирану меморију.*/
int main(void){
	int *niz, n;

	scanf("%d", &n);

	niz = malloc(n * sizeof(int));

	for(unsigned int i = 0; i < n; ++i)
		scanf("%d", &niz[i]);
	
	printf("uneti niz\n");
	for(unsigned int i = 0; i < n; ++i)
		printf("%d ", niz[i]);
	printf("\n");
	

	printf("obrnuti niz\n");
	for(int i = n - 1; i >= 0; --i)
		printf("%d ", niz[i]);
	printf("\n");

	free(niz);
	return 0;
}
