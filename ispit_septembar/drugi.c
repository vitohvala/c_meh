#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alociraj(int ***matrix, int kolona, int red){

    (*matrix) =(int **) malloc(kolona * sizeof(int *));
    if((*matrix) == NULL) {
        printf("Nije moguce alocirati memoriju za matricu!");
        exit(1);
    }

    for (int i = 0; i < kolona; i++) {
        (*matrix)[i] = (int *)malloc(red * sizeof(int));
        if ((*matrix)[i] == NULL) {
            printf("Nije moguce alocirati memoriju za %d red matrice!\n", i);
            exit(1);
        }
    }

}

void unesi_matricu(int ***matrix, int kolona, int red){

    printf("Unesite elemente matrice: \n");
    for(int i = 0; i < kolona; i++){
        for(int j = 0; j < red; j++){
            scanf("%d", &(*matrix)[i][j]);
        }
    }
}

void print_matrix(int **matrix, int kolona , int red, char *s){
    puts(s);
    for(int i = 0; i < kolona; i++){
        for(int j = 0; j < red; j++)
            printf("%d\t", matrix[i][j]);
        puts("");
    }
}
int suma(int **matrix, int kolona, int j){
    int suma = 0;
    for(int i = 0; i < kolona; i++)
        suma += matrix[i][j];
    return suma;
}

void swap(int ***matrix, int p_i, int p_j, int d_i, int d_j){
    int temp = (*matrix)[p_i][p_j];
    (*matrix)[p_i][p_j] = (*matrix)[d_i][d_j];
    (*matrix)[d_i][d_j] = temp;
}

void sortiraj(int **matrix, int kolona, int red){
    int min_indeks;
    for(int k = 0; k < red - 1; k++){
        min_indeks = k;
        for(int j = k + 1; j < red; j++){
            if(suma(matrix, kolona, j - 1) < suma(matrix, kolona, j))
                min_indeks = j;
        }
        if(min_indeks != k){
            for(int i = 0; i < kolona; i++)
                swap(&matrix, i, min_indeks, i, k);
        }
        
    }
}

int main(){
    int **matrix,kolona, red;

    printf("Unesi dimenzije matrice (kolona, red): ");
    scanf("%d%d", &kolona, &red);

    alociraj(&matrix, kolona, red);
    unesi_matricu(&matrix, kolona, red);
    
    sortiraj(matrix, kolona, red);
    print_matrix(matrix, kolona, red, "\nSortirana matrica");

    for(int i = 0; i < red; i++)
        free(matrix[i]);
    free(matrix); 

    return 0;
}
