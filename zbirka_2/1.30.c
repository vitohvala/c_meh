//pomeranje string aza jedno mesto 
#include <stdio.h>
#include <string.h>

int main(){
	char s[100], ch;
	int i, n;
	printf("Unesite string: "); gets(s);
	n=strlen(s);
	ch=s[0];
	for(i=0; i<n; i++){
		if(i>=1) s[i-1]=s[i];
	}
	s[n-1]=ch;
	puts(s);
return 0;
}
