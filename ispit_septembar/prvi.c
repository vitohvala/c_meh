#include <stdio.h>
#include <string.h>

void get_int(char *s, int *x, int *y){
    printf("%s", s);
    if(y == NULL) scanf("%d", x);
    else scanf("%d%d", x, y);
}


int main(){
    int x, y, cilj_x, cilj_y, n;
    get_int("Unesite pocetne koordinate (x, y): ", &x, &y);
    get_int("Unesite ciljne koordinate (x, y): ", &cilj_x, &cilj_y);
    get_int("Unesite broj instrukcija za kretanje: ", &n, NULL); //null kao argument jer ne zelim da se smaram sa va_list arg i slicno
                                                                 //ovako je jednostavnije
    for (int i = 1; i <= n; i++) {
        char smer[10]; 
        int duzina;
        
        printf("Unesite instrukciju: ");
        scanf("%s %d", smer, &duzina);
        
        if (strcmp(smer, "desno") == 0) {
            x += duzina;
        } else if (strcmp(smer, "levo") == 0) {
            x -= duzina;
        } else if (strcmp(smer, "gore") == 0) {
            y += duzina;
        } else if (strcmp(smer, "dole") == 0) {
            y -= duzina;
        } else {
            printf("Nepoznat smer: %s\n", smer);
            return 1; 
        }
        
    }
    //ostatak zadatka ne razumem
    return 0;
}
