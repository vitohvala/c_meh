#include <stdio.h>
#include <stdbool.h>
//library za bool

//funkcija za duzinu broja
int getl(int num){
	int l=1;
	while(num>9){
	l++;
	num/=10;
	}
	return l;
}
//umesto bool mozete koristiti nesto drugo
//funkcija koja proverava da li je uneti broj simetrican
bool palindrom(int num){
	int l=getl(num), r=0; 
	//pola broja obrcemo unazad i smestamo ga u varijablu r
	for(unsigned int i = 0; i < l/2; i++){
		r = r * 10;
		r = r + num%10;
		num/=10;
	} 
	//ako je duzina broja neparna cifra skidamo jednu poslednju cifru sa broja
	if(l%2!=0) num/=10;
	//ovo je isto sto i 'if else' nakon '?' vrce true ako ispunjava uslov  nakon ':' vrce false ako ne ispunjava
	return (r == num) ? true : false;
}
int main(){
	int num;
	while(1){
		printf("Unesite broj: "); scanf("%d", &num);
		if(palindrom(num)==false || num<0) 
			printf("Uneti broj %d nije simetrican\n", num);
		else 
		{ 
			printf("Uneti broj %d je simetrican\n", num);
			break;
		}
	}
    return 0;
}
