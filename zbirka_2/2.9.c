#include <stdio.h>
void fff(int x, int y, int *p, int *pp){
	*p=x/y;
	*pp=x%y;
}
int main (){
	int x = 15, y=3, p, pp;
	fff(x, y, &p, &pp);
	printf("p = %d, pp = %d\n", p, pp);
return 0;
}
