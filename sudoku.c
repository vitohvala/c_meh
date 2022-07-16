//idk

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int sudoku[9][9];
int s[10][10];
int provera (int i, int j, int r){
    int red, kolona;
    for(red=0; red<9; red++)
    if(sudoku[red][j]==r) return 0;

    for(kolona=0; kolona<9; kolona++)
    if(sudoku[i][kolona]==r) return 0;

    int rs=i-i%3, ks=j-j%3;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            if(sudoku[i+rs][j+ks]==r) return 0;

    return 1;
    }
int resi(int i, int j){
    int num;
        if(i==9-1 && j==9) return 1;
        if(j==9){
            i++;
            j=0;
        }
        if(sudoku[i][j]>0) return resi(i, j+1);
        for(num=1; num<=9; num++){
        if(provera(i, j, num)==1) 
        {
        sudoku[i][j]=num;
        if(resi(i, j+1)==1) return 1;
        }
        sudoku[i][j]=0;
        }
    return 0;
}
void crtaj(){
         printf("0 ");
         for (int i=0; i<9; i++){
              printf(" %d ", i+1);
        if(i==2 || i==5 ) printf("|");
        if(i==8) printf("X");
         }
    printf("\n -------------------------------\n");
    for (int i=0; i<9; i++){
        printf("%d", i+1);
        printf("|");
        for (int j=0; j<9; j++){
                printf(" %d ", sudoku[i][j]);
                if(j==2 || j==5 || j==8) printf("|");
                
            }
            printf("\n");
            if(i==2 || i==5) printf(" -------------------------------\n");
            }
    printf("y");
    printf("-------------------------------\n");
}
void generator(){
    srand(time(NULL));
    int r, j, i;
    //sudoku[0][0]=rand()%9+1;
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            r=rand()%9+1;
            if(provera(i, j, r)==1) sudoku[i][j]=r;
            if(sudoku[i][j]==0) resi(i, j);
            s[i][j]=sudoku[i][j];
        }
    }
}
void luzer(){
    char da;
    nastavi:
        printf("\nDo You want to see the solution? [Y/N]");
        scanf(" %c", &da);
        if(da=='y' || da=='Y') {
                for(int i=0; i<9; i++)
                    for(int j=0; j<9; j++)
                        sudoku[i][j]=s[i][j];
                crtaj();
                main();
            }
        else if(da=='n' || da=='N') main();
        else goto nastavi;
    
}
void igra(){
    int x, y, z, i, j, greska=0, pobeda=0;
    char d, da;
    while(1){
    start: printf("\nEnter the positions of a number <<x i y>>: "); scanf("%d %d", &x, &y);
    if(sudoku[y-1][x-1]==0) {
         printf("\nEnter the number: "); scanf("%d", &z);
            sudoku[y-1][x-1]=z;
                if(sudoku[y-1][x-1]==s[y-1][x-1]) {
                    system("clear");
                    sudoku[y-1][x-1]=z;
                    crtaj();
                }
                else{
                    printf("UPS, wrong one! Try again");
                    sudoku[y-1][x-1]=0;
                    greska++;
                    goto start;
                }
         }
    else {
        printf("\nPosition is already taken! Please, try again"); 
        goto start;

    }
    if(greska==3 || greska==6 || greska>9){
        nastavi:
        printf("\nDo You want to see the solution? [Y/N] ");
        scanf(" %c", &da);
        if(da=='Y' || da=='Y') {
                for(i=0; i<9; i++)
                    for(j=0; j<9; j++)
                        sudoku[i][j]=s[i][j];
                crtaj();
                main();
            }
        else if(da=='n' || da=='N') continue;
        else goto nastavi;
    }
    if(greska>11) {
        luzer();
        main();
    }
    for(i=0; i<9; i++)
    for(j=0; j<9; j++)
    if(sudoku[i][j]==0){
         pobeda++;
    }
   if(pobeda==0){ 
    printf("\nYOU WON!!!!");
    pitanje:
    printf("\nDo you want to continue? [Y/N] ");
    scanf(" %c", &d);
    if(d=='y' || d=='Y') check();
    else if(d=='N' || d=='n') break;
    else {
        printf("\nPlease enter a valid character!");
        goto pitanje;
    }}
    pobeda=0;
}}   
void casedva(){
int i,j;
printf("\nFill sudoku table <<0 as a empty>>");
for(i=0; i<9; i++){
    for(j=0; j<9; j++){
        scanf("%d", &sudoku[i][j]);
        if(resi(i, j)==0) crtaj();
        else printf("\nNo solution exists!");
    }}
}
void check(){
    int k, options;
    start:
    printf("\nChoose difficulty:");
    printf("\n1: Easy");
    printf("\n2: Medium");
    printf("\n3: Hard");
    printf("\n4: Insane");
    printf("\n5: Go to the main menu");
    printf("\nYour Choice: ");
    scanf("%d", &options);
    switch(options){
        case 1:
            generator();
            for(k=1; k<=30; k++)
            sudoku[rand()%8][rand()%8]=0;
            crtaj();
            igra();
            break;
        case 2:
            generator();
            for(k=1; k<=40; k++)
            sudoku[rand()%8][rand()%8]=0;
            crtaj();
            igra();
            break;
        case 3:
            generator();
            for(k=1; k<=60; k++)
            sudoku[rand()%8][rand()%8]=0;
            crtaj();
            igra();
            break;
        case 4:
            generator();
            for(k=1; k<=71; k++)
            sudoku[rand()%8][rand()%8]=0;
            crtaj();
            igra();
            break;
        case 5: 
        main();
        break;
    default: 
        goto start;
        break;
    }
}
int main(void){
    int options;
    start: printf("\nWhat do you want to do?");
    printf("\n1: Play Sudoku");
    printf("\n2: Solve Sudoku");
    printf("\n3: Get random Sudoku board");
    printf("\n4: Quit");
    printf("\nYour Choice: ");
    scanf("%d", &options);
    switch (options)
    {
    case 1:
        check();
        break;
    case 2: 
        casedva();
        break;
    case 3:
        generator();
        crtaj();
        break;
    case 4: 
        goto end;
        break;
    default:
        goto start;
        break;
    }
    end:
    return 0;
}
