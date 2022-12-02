#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 

/*3.10. Саставити функцију која креира динамички стринг надовезивањем два стринга ѕ1 и ѕ2.
Адреса низа се враћа као повратна вредност. Затим саставити програм који помоћу претходно
формиране функције надовезује два унета стринга и исписује резултујући стринг*/
void *spoji(char *s, char *ret, int od, int dokle,int k){
	size_t i;
	for(i = od; i < dokle; ++i){
		ret[k] = s[i];
		k++;
	}
}
void err(char *s){
	if(s == NULL){
		printf("Nedovoljno memorije\n");
		exit(1);
	}
}
char *spojeni(char *s1, char *s2){
	int lens1 = strlen(s1);
	int lens2 = strlen(s2);
	lens2 += lens1;
	char *ret;
	
	ret = malloc(lens2 * sizeof(char));
	err(ret);

	spoji(s1, ret, 0, lens1,0);
	spoji(s2, ret, 0, strlen(s2),lens1);
	
	return ret;
}

int main(void){
	char s1[MAX], s2[MAX], *s;


	scanf("%s", &s1);
	scanf("%s", &s2);

	s = spojeni(s1, s2);
	
	puts(s);

	free(s);
	
	return 0;
}
