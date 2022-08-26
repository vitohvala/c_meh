#include <stdio.h>
#include <stdlib.h>
int main(){
	int *p;
	p=(int *)malloc(sizeof(int));
	if(p==NULL) return 1;
	printf("unesite p: "); scanf("%d", p);
	*p+=1;
	printf("%d\n", *p);
	free(p);
	return 0;
}
