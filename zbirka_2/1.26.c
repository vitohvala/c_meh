//program koji ce reci zadate recenice ispisati jednu ispod druge 

#include <stdio.h>
#include <string.h>

int main() {
	char s[100];
	printf("Unesite recenicu: "); gets(s);
	int n=strlen(s), t=0;
	unsigned int i, k;
	for(i = 0; i<=n; i++){
		if(s[i]==' ' || i==n){	
			for(k=t; k<i; k++)
				printf("%c", s[k]);
			t=k+1;
		printf("\n");
		}
	}
return 0;
}
