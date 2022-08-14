//sastaviti program koji u stringu vrsi konverziju svih malih slova u velika a ostala ne menja
//`
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void){
	char s[100], ch;
	int n;
	printf("Unesite string: "); gets(s);
	n=strlen(s);
	for(int i=0; i<n; i++){
		ch=s[i];
		if(islower(ch)) {
			putchar(toupper(ch));
			s[i]=ch;
		}
		if(isupper(ch)) 
			printf("%c", ch);

	}
	printf("\n");
return 0;
}
