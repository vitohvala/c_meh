//ispisujemo string unazad
//
#include <stdio.h>
#include <string.h>

int main(){
	char s[100];
	int i, n;
	printf("Unesite string: "); gets(s);
	n=strlen(s);
	for(i=n; i>=0; i--)
		printf("%c", s[i]);
	printf("\n");
return 0;
}
