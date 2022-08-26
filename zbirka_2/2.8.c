#include <stdio.h>
#define PI 3.14
void op(float *o, float *p){
	*o=2*PI*(*o);
	*p=(*p)*(*p)*PI;
}
int main(){
	float r=6, pov=r;
	printf("Obim za %.2f je: ", r); op(&r, &pov); printf("%.2f\n", r);
	printf("Povrsina= %.2f\n", pov);
return 0;
}
