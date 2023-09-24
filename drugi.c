#include <stdio.h>
#define SIZE 100
int najveci(int niz[], int n){
    int i, j=0;
    for(i=1; i<n; i++)
        if(niz[i]>niz[j])	j=i;
    return j;       
}
int najmanji(int niz[], int n){
    int i, j=0;
    for(i=1; i<n; i++)
        if(niz[i]<niz[j])	j=i;
    return j;
}
int main(){
    int n, niz[SIZE], i, min, max;
    printf("\nn= "); scanf("%d", &n);
    printf("\nniz= "); 
    for(i=0; i<n; i++)
        scanf("%d", &niz[i]);
    min=najmanji(niz, n);
    max=najveci(niz, n);
    if(max>min){
        for(i=min+1; i < max; i++)
            niz[i]++;
    }
    else {
        for(i=max+1; i<min; i++)
            niz[i]++;
    }
    for(i=0; i<n; i++)
        printf("%d ", niz[i]);
    return 0;
}
