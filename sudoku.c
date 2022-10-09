//idk

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void igra(void);
void check(void);

int sudoku[9][9];
int s[10][10];
int devetke[9];
int brojevi[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
void brojac() {
	size_t i, j, k;
	for(i = 0; i < 9; i++)
		devetke[i]=9;
	for(i = 0; i < 9; i++)
		for(j = 0; j < 9; j++)
			for(k=0; k<9; k++)
			if(sudoku[i][j] == brojevi[k])
				devetke[k]--;
}
int nule(){
	size_t i,j;
	int brr = 0;
	for(i = 0; i < 9; i++)
		for(j = 0; j < 9; j++)
			if(sudoku[i][j]==0) brr++;
	return brr;

}
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
	brojac();
	// sat();
	system("clear");
	fflush(stdout);
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
                (sudoku[i][j]==0)? printf(" %d ", sudoku[i][j]): printf("\033[38;5;208m %d \033[0m", sudoku[i][j]);
                if(j==2 || j==5 || j==8) printf("|");
                
            }
            printf("\n");
            if(i==2 || i==5) printf(" -------------------------------\n");
            }
    printf("y");
    printf("-------------------------------\n");
    printf("|");
    for(unsigned int i = 0; i < 9; i++)
	    printf(" %d :\033[38;5;208m %d \033[38;5;255m|", brojevi[i], devetke[i]);

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
void casedva(){
int i,j, br=0;
printf("\nFill sudoku table <<0 as a empty>>");
for(i=0; i<9; i++){
    for(j=0; j<9; j++){
        scanf("%d", &sudoku[i][j]);
        if(resi(i, j)==0) crtaj();
        else br++;
    }}
    if(br>0) printf("\nno solution exists\n");
}

int main(){
    int options;
    start: printf("\nWhat do you want to do?");
    printf("\n1: Play Sudoku");
    printf("\n2: Solve Sudoku");
    printf("\n3: Get random Sudoku board");
    printf("\n4: Quit");
    printf("\nYour Choice: ");
    scanf("%d", &options);
    if(options==4) exit(0);
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
    default:
        goto start;
        break;
    }
    return 0;
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
                    sudoku[y-1][x-1]=z;
                    crtaj();
                }
                else{
                    printf("UPS, wrong one! Try again");
                    sudoku[y-1][x-1]=0;
                    greska++;
                    if(greska>5){
                    system("clear");
                    printf("\nYou lost!\n");
                    nastavi:
                        printf("Do You want to see the solution? [Y/N] ");
                        scanf(" %c", &da);
                        if(da=='Y' || da=='y') {
                            for(i=0; i<9; i++)
                                for(j=0; j<9; j++)
                                    sudoku[i][j]=s[i][j];
                                    crtaj();
                                    main();
                        }
                    else if(da=='n' || da=='N') main();
                    else goto nastavi;
                    }
                goto start;
                }
         }
    else {
        printf("\nPosition is already taken! Please, try again"); 
        goto start;

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
void easy(){
        int random = rand()%9, rendom = rand()%9, brr=nule();
        sudoku[random][rendom]=0;
	if(brr<29) easy();
}
void medium(){
        int random = rand()%9, rendom = rand()%9, brr=nule();
	sudoku[random][rendom]=0;
	if(brr<39) medium();
}
void hard(){
        int random = rand()%9, rendom = rand()%9, brr=nule();
	sudoku[random][rendom]=0;
	if(brr<51) hard();

}
void insane() {
        int random = rand()%9, rendom = rand()%9, brr=nule();
	sudoku[random][rendom]=0;
	if(brr < 63) insane();

}
void check(){
    int k, options, random = rand()%8, rendom = rand()%8;
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
	    easy();
            crtaj();
            igra();
            break;
        case 2:
            generator();
	    medium();
            crtaj();
            igra();
            break;
        case 3:
            generator();
	    hard();
	    crtaj();
            igra();
            break;
        case 4:
            generator();
	    insane();
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
