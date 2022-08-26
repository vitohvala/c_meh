#include <stdio.h>
#define BMG 12
int main(void){

	int obicna[BMG] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	
	int prestupna[BMG] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	
	int d, m, y, *t, br=0;
	printf("date[day month year]: "); scanf("%d%d%d", &d, &m, &y);
	t = (y%400==0 || y%100!=0 && y%4==0)? prestupna: obicna;
	//printf("%d", t);
	for(unsigned int i = 0; i<m-1; i++)
		br+=t[i];
	br+=d;
	printf(": %d \n", br);
	return 0;
}
