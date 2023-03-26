#include <stdio.h>

void ispis(char ttt[3][3]){
    int i,j;
    printf("    1   2   3 x\n");
    printf("  -------------\n");
    for (i=0; i<3; i++){
        printf("%d ", i+1);
        printf("| ");
        for(j=0; j<3; j++){
            printf("%c", ttt[i][j]);
            if (j==0 || j==1 || j==2) printf(" | ");
        }
        printf("\n");
        if (i==0 || i==1) printf("  -------------\n");

    }
    printf("y");
    printf(" -------------\n");
}


int pobednik(char board[3][3]){
    int i, j, winner=0, pxt=0;

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') 
            winner = (board[i][0] == 'X') ? 1 : 2;
        else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            winner = (board[0][i] == 'X') ? 1 : 2;
    }

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                pxt= 1; 
            }
        }
    }
    if (pxt == 0) 
        winner= 3;
    return winner;

}
void novi(char ttt[3][3]){
    for(size_t i = 0; i < 3; i++)
        for(size_t j = 0; j < 3; j++)
            ttt[i][j] = ' ';
}

int main(){
    int m, n, winner=0, i=1, perr;
    char ttt[3][3], d, x;
    novi(ttt);
    ispis(ttt);
    while(1){
        for(i=1; i<=2; i++){
            if(i==1) x='X';
            else if(i==2) x='O';
start: printf("\nPlayer %d. Unesitte poziciju na kojoj zelite ispisati %c <x i y>: ", i, x);
       perr = scanf("%d%d", &m , &n); 
       if(perr == 0){
            while (getchar() != '\n');
            printf("Unesite broj!");
            goto start;
       }
       if(ttt[n-1][m-1]=='X' || ttt[n-1][m-1]=='O'){
           printf("Odabrana pozicija je zauzeta, pokusajte ponovo!\n");
           goto start;
       }
       else{
            ttt[n - 1][m - 1] = x;
            ispis(ttt);
       }
       winner=pobednik(ttt);
       if(winner>0){
           if(winner==3) printf("Nereseno je\n");
           else
               printf("Pobednik je player %d!\n", winner);
pocetak: printf("Da li zelite da nastavite? < D=da ili N=ne >: ");
         scanf(" %c", &d);
         if(d=='D' || d=='d'){
             novi(ttt);
             ispis(ttt);
         }
         else if (d=='N' || d=='n') goto end;
         else {
             printf("Unesite odgovarajuci karakter!\n");
             goto pocetak;
         }
       }   
        }
    }
end:
    return 0;
}
