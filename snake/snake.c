#include <asm-generic/ioctls.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>


#define ROW 20
#define COL 50

typedef enum {
    LEFT = 1,
    RIGHT,
    UP,
    DOWN,
    EXIT
}DIRECTION;

typedef struct {
    int x[ROW * COL], y[ROW * COL];
    int snake_size;
    int score;
} SNAKE;

static struct termios old_termios;

int usleep(unsigned int usec);

void clear(void){
    printf("\x1b[2J");
    printf("\x1b[H");
}

void reset_terminal(void){
    fflush(stdout);
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
    printf("\x1b[?25h");
}

void terminal_config(void){
    int res = 0;
    printf("\x1b[?25l");
    res = tcgetattr(STDIN_FILENO, &old_termios);
    assert(res == 0);
    struct termios new_termios = old_termios;
 
    new_termios.c_lflag &= ~(ICANON | ECHO);
    new_termios.c_cc[VMIN] = 1;
    new_termios.c_cc[VTIME] =  1;

    res = tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
    assert(res == 0);

    atexit(reset_terminal);
}

bool kbhit(void){
    int btw;
    ioctl(0, FIONREAD, &btw);
    return btw > 0;
}

void draw(SNAKE *snake, int x_fruit, int y_fruit){
    int  sem = 0;
    printf("Press q to quit, W, A, S, D to move\r\n");
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(i == 0 || i == ROW - 1) printf("-");
            else if(j == 0 || j == COL - 1) printf("|");
            else if(j == y_fruit && i == x_fruit) printf("\033[38;5;119mX\033[0m");
            else {
                sem = 0;
                for(int k = 0; k < snake->snake_size; k++){
                    if(snake->x[k] == j && snake->y[k] == i){
                        printf("%s", (k == 0) ? "\033[38;5;167mS\033[0m" : "S");
                        sem = 1;
                    }
                }
                if(sem == 0) printf(" ");
            }
        }
        printf("\r\n");
    } 
    printf("score [%d]\r\n", snake->score);
}

int check_pos(int *x, int *y, SNAKE *snake){
    if(*x < 1 || *x > COL - 1) return 1;
    if(*y < 1 || *y > ROW - 1) return 1;
    for(int i = 0; i < snake->snake_size; i++){
        if(*x == snake->x[i] && *y == snake->y[i]) return 1;
    }
    return 0;
}

void put_fruit(SNAKE *snake, int *x_fruit, int *y_fruit){
    srand(time(0));
    do {
        *x_fruit = (rand()%COL - 2) + 1;
        *y_fruit = (rand()%ROW - 2) + 1;
    } while(check_pos(x_fruit, y_fruit, snake));
}

void unesi_score(int score){
    FILE *dat = fopen("skor.txt", "a");
    if(dat == NULL){
        perror("fopen");
        exit(1);
    }
    fprintf(dat, "%d\n", score);
    fclose(dat);
}
int maxx(void){
    FILE *dat;
    int m, max = 0;
    dat = fopen("skor.txt", "r");
    if(dat == NULL){
        return 0;
    }

    max = 0;
    while(!feof(dat)){
        fscanf(dat, "%d", &m);
        if(m > max) max = m;
    }
    fclose(dat);
    return max;
}

void move_snake(SNAKE *snake, int strana){
    if(strana){
        for(int i = snake->snake_size - 1; i > 0; i--){
            snake->x[i] = snake->x[i - 1];
            snake->y[i] = snake->y[i - 1];
        }
    }
    switch (strana) {
        case LEFT:
            snake->x[0]--;
            break;
        case RIGHT:
            snake->x[0]++;
            break;
        case UP:
            snake->y[0]--;
            break;
        case DOWN:
            snake->y[0]++;
            break;
    }
    if(snake->y[0] > ROW - 2) snake->y[0] = 1;
    if(snake->y[0] <= 0) snake->y[0] = ROW - 2;
    if(snake->x[0] <= 0) snake->x[0] = COL - 2;
    if(snake->x[0] > COL - 2) snake->x[0] = 1;
}

void input_control(int *strana){
    int c = getchar();
    switch(c){
        case 'A':
        case 'a':
            if(*strana != RIGHT) *strana = LEFT;
            break;
        case 's':
        case 'S':
            if(*strana != UP) *strana = DOWN;
            break;
        case 'D':
        case 'd':
            if(*strana != LEFT) *strana = RIGHT;
            break;
        case 'W':
        case 'w':
            if(*strana != DOWN) *strana = UP;
            break;
        case 'Q':
        case 'q':
            (*strana) = EXIT;
            break;
    }
}

void collision_det(uint8_t *end, SNAKE *snake, int *x, int *y){
    if(snake->x[0] == *x && snake->y[0] == *y) {
        put_fruit(snake, x, y);
        snake->score += (snake->score % 30 == 0 && snake->score != 0) ? 10 : 5;
        snake->snake_size++;
    }
    for(int i = 2; i < snake->snake_size; i++){
        if(snake->x[0] == snake->x[i] && snake->y[0] == snake->y[i]) *end = 0;
    }
}

void init(SNAKE *snake){
    snake->x[0] = COL / 2 - 1;
    snake->y[0] = ROW / 2 - 1;
    snake->snake_size = 6; 
    for(int i = 1; i < snake->snake_size; i++){
        snake->y[i] = snake->y[i - 1] - 1;
        snake->x[i] = COL / 2 - 1;

    }
    snake->score = 0;
}
int main(void){
    int strana = 0, x_fruit = -1, y_fruit = -1;
    uint8_t end = 1;
    SNAKE snake;

    init(&snake);
    put_fruit(&snake, &y_fruit, &x_fruit);
    terminal_config();
    
    while(end){
        clear();
        draw(&snake, x_fruit, y_fruit);
        if(kbhit()){
            input_control(&strana);
        }
        if(strana == EXIT) end = 0;
        move_snake(&snake, strana);
        collision_det(&end, &snake, &y_fruit, &x_fruit);
        usleep(150000); 
    }
    int max = 0;
    max = maxx();
    if(snake.score > max) printf("New high score: %d\r\n", snake.score);
    else {
        printf("Your score: %d\r\n", snake.score);
        printf("Max score: %d\r\n", max);
    }
    unesi_score(snake.score);
    return 0;
}
