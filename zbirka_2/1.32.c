#include <stdio.h>
#include <string.h>
#define MAX 100

int main(void){
	char s[MAX];
	int i, n, greska=0;
	printf("Unesite string: "); //fgets(s, MAX, stdin);
	gets(s);
	n=strlen(s);
	for(i=0; i<n; i++)
		if(s[i]!=s[n-i-1]) greska=1;
	(greska>=1)? printf("Nije palindrom!\n"): printf("Jeste palindrom\n");
return 0; 
}
