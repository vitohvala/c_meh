/*napisati program kojim se vrsi zamena najveceg i najmanjeg elementa ispod sporedne dijagonale matrice x. ucitavanje matrice i trazenu obradu realizovati pomocu odvojenih funkcija*/
#include <stdio.h>
#define MAX 100
void unos(int a[MAX][MAX], int n){
    int i,j;
    printf("\nunesite elemente mnatrice: \n");
    for ( i = 0; i < n; i++)
        for (j=0; j<n; j++)
            scanf("%d", &a[i][j]);
}
void ispis (int  a[MAX][MAX], int n){
    int  i, j;
    printf("\nelementi matrice: \n");
    for ( i = 0; i < n; i++){
        for (j=0; j<n; j++){
            printf(" %d ", a[i][j]);
        }
        printf("\n");
        }
}
void zamena(int a[MAX][MAX], int n){
    int i, j, max, min, temp, imax, jmax, i_min, j_min;
    printf("\nzamenjeni elementi: \n");
    for (i = 1; i < n; i++){
        for(j=1; j<n; j++){
            min=max=a[n-j][i];
            if(i+j>=n){
                if(a[i][j]<min) {
                    min=a[i][j];
                    i_min=i;
                    j_min=j;
                    }
                if(a[i][j]>max) {
                    max=a[i][j];
                    imax=i;
                    jmax=j;
                    } 
        }}
    }
    temp = a[j_min][i_min];
    a[j_min][i_min]=a[jmax][imax];
    a[jmax][imax]=temp;
    for (i = 0; i < n; i++){
        for(j=0; j<n; j++){
            printf(" %d ", a[i][j]);
        }
        printf("\n");
        }
}
int main(){
    int n, a[MAX][MAX];
    printf("\nunesite n: "); scanf("%d", &n);
    unos(a, n);
    ispis(a, n);
    zamena(a, n);
    return 0;
}