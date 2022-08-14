//sastaviti program koji ucitava string, koji predstavlja recenicu, i koji proverava da li je recenica ispravno uneta.
//ispravno uneta recenica ispunjava ove uslove:
//recenica mora poceti sa velikim slovom i zavrsiti se tackom
//reci su proizvoljni podstringovi koji mogu da sadrzati samo mala slova.
//reci mogu biti razdvojene jednim razmakom (SPACE), zarezom ili tacka-zarezom.
//na izlazu ispisati obavestenje da li je recenica ispravno uneta.
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	char s[100], ch;
	int greska=0, n, i;
	printf("Unesite recenicu: "); gets(s);
	n=strlen(s);
	ch=s[0];
	if(islower(ch)) greska=1;
	else
	for(i=1; i<n; i++){
		if(s[n-1]!='.') greska=1;
		if((s[i]=='?' || s[i]=='.' || s[i]=='!' || s[i]==';') && i+2<n-1){	
			ch=s[i+2];
			if(islower(ch)) greska=1;
		}
		else {
		 ch=s[i];
		 if(isupper(ch)) greska=1;
		}
	}
	(greska==1)? printf("Neispravno!"): printf("Ispravno");
		
return 0;
}
