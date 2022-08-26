#include <stdio.h>
#include <stdlib.h>

int main(){
	int *a, *b;
	a=(int *)malloc(sizeof(int));
	b=(int *)malloc(sizeof(int));
	if(a==NULL || b==NULL) return 1;
	printf("dva broja koja zelite sabrati: "); scanf("%d%d", a, b);
	printf("rezultat: %d\n", (*a)+(*b));
	free(a); 
	free(b);
	return 0;
}
