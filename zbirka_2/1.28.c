//funkcija koja uklanja zadati karakter
#include <stdio.h>
#include <string.h>
void uklanjanje(char ch, char s[]){
	int j=0;
	int n = strlen(s);
	for(unsigned int i = 0; i < n; i++)
		if(s[i]==ch){
			//s[i]='\0'; ne znam sta je ovo
			s[j]=s[i];
			j++;
		}
		 s[j]='\0';

	puts(s);
}

int main(){
	char s[100], ch;
	printf("String: "); gets(s);
	printf("karakter koji zelite ukloniti: "); scanf(" %c", &ch);
	uklanjanje(ch, s);
return 0;
}
