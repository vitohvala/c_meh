#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char s[100], sd;
	unsigned int br=0;
	printf("\nUnesite rec: "); gets(s);
	printf("\nUnesite karakter:"); scanf(" %c", &sd);
	unsigned int l = strlen(s);
	for(unsigned int i =0; i<l; i++)
		if(sd==s[i])  br++;
	(br==0)? printf("Karakter %c se ne pojavljuje u stringu\n", sd):
	printf("\nKarakter %c se ponavlja %d puta\n", sd, br);
return 0;
}
