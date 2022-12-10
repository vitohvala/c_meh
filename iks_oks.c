#include <stdio.h>


void ispis(char ttt[3][3]){
    int i,j;
    char d=' ';
        printf("    1   2   3 x\n");
    printf("  -------------\n");
    for (i=0; i<3; i++){
        printf("%d ", i+1);
        printf("| ");
        for(j=0; j<3; j++){
            ttt[i][j]=d;
            printf("%c", ttt[i][j]);
            if (j==0 || j==1 || j==2) printf(" | ");
        }
        printf("\n");
        if (i==0 || i==1) printf("  -------------\n");
        
    }
        printf("y");
    printf(" -------------\n");
}
void ispisznaka(char ttt[3][3],char x, int m, int n){
    int i, j;
    char d= ' ';
    ttt[n-1][m-1]=x;
        printf("    1   2   3 x\n");
    printf("  -------------\n");
    for (i=0; i<3; i++){
        printf("%d ", i+1);
        printf("| ");
        for(j=0; j<3; j++){
            if(ttt[i][j]==' ') ttt[i][j] = d;
            ttt[n-1][m-1]=x;
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
    char d;
    int i, j, px=0, po=0, winner=0, pxt=0;
    for (i=0; i<3; i++){
if (((board[0][0] == 'X') && (board[0][1] == 'X') && (board[0][2] == 'X')) || 
		((board[0][0] == 'X') && (board[1][0] == 'X') && (board[2][0] == 'X')) || 
		((board[0][0] == 'X') && (board[1][1] == 'X') && (board[2][2] == 'X')) || 
		((board[1][0] == 'X') && (board[1][1] == 'X') && (board[1][2] == 'X')) ||
		((board[2][0] == 'X') && (board[2][1] == 'X') && (board[2][2] == 'X')) || 
		((board[0][1] == 'X') && (board[1][1] == 'X') && (board[2][1] == 'X')) || 
		((board[0][2] == 'X') && (board[1][2] == 'X') && (board[2][2] == 'X')) || 
		((board[0][2] == 'X') && (board[1][1] == 'X') && (board[2][0] == 'X')) 
		)
	{
		winner = 1;
	} else if (((board[0][0] == 'O') && (board[0][1] == 'O') && (board[0][2] == 'O')) || 
			   ((board[0][0] == 'O') && (board[1][0] == 'O') && (board[2][0] == 'O')) || 
			   ((board[0][0] == 'O') && (board[1][1] == 'O') && (board[2][2] == 'O')) || 
			   ((board[1][0] == 'O') && (board[1][1] == 'O') && (board[1][2] == 'O')) || 
			   ((board[2][0] == 'O') && (board[2][1] == 'O') && (board[2][2] == 'O')) ||
			   ((board[0][1] == 'O') && (board[1][1] == 'O') && (board[2][1] == 'O')) || 
			   ((board[0][2] == 'O') && (board[1][2] == 'O') && (board[2][2] == 'O')) || 
			   ((board[0][2] == 'O') && (board[1][1] == 'O') && (board[2][0] == 'O'))
			   )
	{
		winner = 2;
	} else {
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++) 
			{
				if (board[i][j] == ' ') {
					pxt= 1; 
				}
			}
		}
		if (pxt == 0) { 
			winner= 3;
		}
	}
}
return winner;

}

int main(){
     int m, n, winner=0, i=1;
    char ttt[3][3], d, o = ' ', x;
    ispis(ttt);
    while(1){
        for(i=1; i<=2; i++){
            if(i==1) x='X';
            else if(i==2) x='O';
       start: printf("\nPlayer %d. Unesitte poziciju na kojoj zelite ispisati %c <x i y>: ", i, x); scanf("%d %d", &m, &n);
       if(ttt[n-1][m-1]=='X' || ttt[n-1][m-1]=='O'){
        printf("\nOdabrana pozicija je zauzeta, pokusajte ponovo!");
        goto start;
       }
       else
        ispisznaka(ttt, x, m, n);
        
        winner=pobednik(ttt);
        if(winner>0){
            if(winner==3) printf("\nNereseno je ");
            else
            printf("\nPobednik je player %d!", winner);
            pocetak: printf("\nDa li zelite da nastavite? < D=da ili N=ne >: ");
            scanf(" %c", &d);
            if(d=='D' || d=='d') ispis(ttt);
            else if (d=='N' || d=='n') goto end;
            else {
                printf("\nUnesite odgovarajuci karakter!");
                goto pocetak;
            }
        }   
        }
    }
    end:
    return 0;
}
