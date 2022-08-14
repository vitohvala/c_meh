#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int main(){
	char s[MAX][MAX], cha[MAX];
	int i, n;
	printf("unesite n: "); scanf("%d", &n);
	fgetc(stdin);
	printf("spisak\n");
	for(i=0; i<n; i++)
	//	gets(s[i]);
	fgets(s[i], MAX, stdin);
	strcpy(cha, s[0]);
	for(i=0; i<n-1; i++)
		strcpy(s[i], s[i+1]);
	strcpy(s[n-1], cha);
	//s[strlen(s[n])-1][strlen(s[n])-1] = 0;
	for(i=0; i<n; i++)
		puts(s[i]);
return 0;
}
