#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>

#define ROW 50
#define COL 25

#ifdef __WIN32__

#include <conio.h>
#define CLEAR "@cls"

#else

#define CLEAR "clear"
#include "tastatura.h"

#endif

int msleep(long tms){
    struct timespec ts;
    int ret;

    if (tms < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = tms / 1000;
    ts.tv_nsec = (tms % 1000) * 1000000;

    do {
        ret = nanosleep(&ts, &ts);
    } while (ret && errno == EINTR);

    return ret;
}

void crtaj(int x_voc, int y_voc, int score, int tailX[], int tailY[], int k, int x, int y){
    uint16_t i, j;
    system(CLEAR);
    for(i = 0; i < COL + 1; i++){
        for(j = 0; j < ROW + 1; j++){
            if(i == 0) printf("_");
            else if(j == 0 || j == ROW) printf("|");
            else if(i == COL) printf("-");
            else if(i == x && j == y) printf("S");
            else if(x_voc == i && y_voc == j)printf("\033[38;5;208mX\033[0m");
            else {
                int semafor = 0;
                for(int w = 0; w < k; w++){
                    if(tailX[w] == i && tailY[w] == j){
                        printf("S");
                        semafor = 1;
                    }
                }
                if(semafor == 0) printf(" ");
            }
        }
        printf("\n");
    }
    printf("score: [%d]\n", score);
}

bool provera(int x, int y, int tx[], int ty[], int k){
    int i, br = 0;
    for(i = 0; i < k; i++)
        if(x != tx[i] && ty[i] != y) br++;
    return (br == k) ? true : false;
}


void voce(int *poz, int *poz2, int tailX[], int tailY[], int k, int x, int y){
    srand(time(NULL));
    int dd = COL - 2;
    int yy = ROW - 2;
    int x_poz, y_poz;
opet:
     x_poz = rand() % dd + 1;
     y_poz = rand() % yy + 1;
    if(provera(x_poz, y_poz, tailX, tailY, k) && (x != x_poz && y != y_poz)) {
        *poz = x_poz;
        *poz2 = y_poz;
    }
    else goto opet;
}

void unesi_score(int score){
    FILE *dat;
    if((dat = fopen("skor.dat", "a")) == NULL){
        printf("Greska!\n");
        exit(1);
    }
    fprintf(dat, "%d\n", score);
    fclose(dat);
}
int maxx(){
    FILE *dat;
    int m, max;
    dat = fopen("skor.dat", "r");
    if(dat == NULL){
        printf("Greska!\n");
        exit(1);
    }

    max = 0;
    while(!feof(dat)){
        fscanf(dat, "%d", &m);
        if(m > max) max = m;
    }
    fclose(dat);
    return max;
}
int main(void){

    int tailX[10000], tailY[10000];

    printf("\033[?25l");
    int poz = 0, x_voc, y_voc, end  = 1,  k = 6,
        score = 0, c = 0, brzina = 70;

    int x, y;

    x = COL / 2;
    y = ROW / 2;

    voce(&x_voc, &y_voc, tailX, tailY, k, x, y);
    while(end){
        crtaj(x_voc, y_voc,score, tailX, tailY, k, x, y);
        if(kbhit()) c = getch();
        if((c == 'A' || c == 'a') && poz != 3) {
            poz = 1;
        }
        else if((c == 'S' || c == 's') && poz != 4) {
            poz = 2;
        }
        else if((c == 'd' || c == 'D') && poz != 1) {
            poz = 3;
        }
        else if((c == 'w' || c == 'W') && poz != 2) {
            poz = 4;
        }
        else if(c == 'q') end = 0;
        switch(poz){
            case 1:
                y--;
                if(y < 1) y = ROW - 1;
                break;
            case 2:
                x++;
                if(x > COL - 1) x = 1;
                break;
            case 3:
                y++;
                if(y > ROW - 1) y = 1;
                break;
            case 4:
                x--;
                if(x < 1) x = COL - 1;
                break;
            default:
                break;
        }
        if(k > 6)
            for(int i = 0; i < k; i++){
                if(tailX[i] == x && tailY[i] == y)
                    end = 0;
            }
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;
        for (int i = 1; i < k; i++){
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }

        if(x == x_voc && y == y_voc){
            score += 5;
            k++;
            voce(&x_voc, &y_voc, tailX, tailY, k, x, y);
        }
        (poz == 1 || poz == 3 ) ? msleep(brzina) : msleep(brzina * 2);

    }
    system("clear");
    unesi_score(score);
    int max = maxx();
    if(max == score) printf("Novi rekord: %d!\n", score);
    else{
        printf("Maksimalan score: %d\n", max);
        printf("Trenutni score: %d\n", score);
    }
    printf("\033[?25h");
    printf("GAME OVER\n");

    return 0;
}
