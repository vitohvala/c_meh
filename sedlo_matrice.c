/* element matrice se naziva sedlo ako je istovremeno najveci u svojoj koloni i najmanji u svojoj vrsti. formirati matricu c ciji su elementi: 1 ako je a[i][j] sedlo, i 0 ako nije sedlo*/
#include <stdio.h>
#define MAX 50
void unos(int a[MAX][MAX], int n)
{
    int i, j; 
    printf("unesite elemente matrice a: \n");
    for (i = 0; i < n; i++)
    for(j=0;j<n; j++)
    scanf("%d", &a[i][j]);
    
}
void ispis(int a[MAX][MAX], int n){
    int i, j;
    for (i = 0; i < n; i++){
        for ( j = 0; j < n; j++){
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }
}
void provera(int c[MAX][MAX],int a[MAX][MAX], int n){
    int min, max, j, k, i; 
        for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            min=max=a[i][j];
            for(k=0; k<n; k++){
                if(a[i][k]<min ) min =a[i][k];
                if(a[k][j]>max) max=a[k][j];
            }
            if(min==a[i][j] && max==a[i][j]) c[i][j]=1;
            else c[i][j]=0;
        }
        
    }
}
int main(){
    int  n, a[MAX][MAX], c[MAX][MAX];
    printf("\n n= "); scanf("%d", &n);
    unos(a, n);
    provera(c, a, n);
    printf("\nc matrica: \n");
    ispis(c, n);
    return 0;
    }
