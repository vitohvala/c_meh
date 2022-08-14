//uklanjamo sve razmake
#include <stdio.h>
#include <string.h>

int main(void){
	char s[100];
	int n, i;
	printf("Unesite string: "); gets(s);
	n=strlen(s);
	for(i=0; i<=n; i++){
		if(s[i]==' ') s[i]="";
	}
	puts(s);
return 0;
}
