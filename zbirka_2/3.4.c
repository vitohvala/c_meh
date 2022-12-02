#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	int *niz, max,n;

	scanf("%d", &n);

	niz = malloc(n * sizeof(int));
	
	if(niz == NULL){
		printf("Nema memorije\n");
		return 1;
	}

	for(unsigned int i = 0; i < n; ++i)
		scanf("%d", &niz[i]);

	max = niz[0];
	
	for(unsigned int i = 0; i < n; ++i){
		if(niz[i] > max) max = niz[i];	
	}
	free(niz);
	printf("maks = %d\n", max);
	return 0;
}
