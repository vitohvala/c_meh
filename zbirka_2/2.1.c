#include <stdio.h>

int main(){
	int x=1, y=1;
	int *ip, *yp;
	ip = &x;
	yp = &y;
	y  = *ip;
	printf("x=%d, y=%d\n", x, y);
	*ip =0; 
	printf("x=%d, y=%d\n", x, y);
	*ip+=10;
	*yp+=9;
	printf("x=%d, y=%d\n", x, y);
}
