//funkcija koja vrsi zamenu mesta dve promenljive, zatim u glavnom programu ispisati vrednosti i adrese dve 
//promenljive pre i posle zamene
//
#include <stdio.h>
void zamena(int *br, int *brr){
	int t = *br;
	*br = *brr;
	*brr = t;
}

int main() {
	unsigned int x=4, y=9;
	printf("adresa promenljive x: %d\n", &x);
	printf("promenljiva x: %u\n", x);
	printf("adresa promenljive y: %d\n", &y);
	printf("promenljiva y: %u\n", y);
	zamena(&x, &y);
	printf("adresa promenljive x nakon zamene: %d\n", &x);
	printf("promenljiva x nakon zamene: %u\n", x);
	printf("adresa promenljive y nakon zamene: %d\n", &y);
	printf("promenljiva y nakon zamene: %u\n", y);
	return 0;
}
