#include <stdio.h>
#include  <string.h>
#include <ctype.h>

int main() {
	char s[100];
	unsigned int i, br=1, n;
	printf("\nUnesite recenicu: "); gets(s);
	n=strlen(s);
	for(i=0; i<n; i++)
		if(s[i]==' ' && s[i+1]!=' ') br++;
	(br==1)? printf("\n%u rec\n", br): printf("recenica ima %u reci", br);

return 0; 
}
