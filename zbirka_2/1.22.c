#include <stdio.h>
#include <string.h>

int main() {
	int br=1, i, n, max=0; 
	char s[100], s1;
	system("clear");
	printf("\nUnesite string: "); gets(s);
	n=strlen(s);
	for(i=0; i<n; i++){
		if(s[i]==s[i+1]) {
			br++;
			if(br>max){
			max=br;
			s1=s[i];
			}
		}
		else br=1;
	}
	printf("duzina najveceg: %d\n", max);
	printf("niz: ");
	for(i=0; i<max; i++) printf("%c", s1);

	printf("\n");
	return 0;
}
