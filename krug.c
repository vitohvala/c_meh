#include <stdio.h>

int main(){
    int z = 0, r = 5;
    
    for(int i = 0; i < r * r; i++){
            for(int j = 0; j < r * r; j++){
            int dx = r - i;
            int dy = r - j;
            if( (dx * dx + dy * dy)  <= r * r) z = 125;
            else z = 4;
            if(z < 10)
                printf(" %d ", z);
            else
                printf("%d", z);
        }
        printf("\n");
    }

    return 0;
}
