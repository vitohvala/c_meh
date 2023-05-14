#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main(){
    int k = 0;
    long long binar, bin[2048];
    char s[256];

    printf("Enter string: \n");
    fgets(s, sizeof(s), stdin);

    int len = strlen(s);
    for(size_t i = 0; i < len; i++){
        int n = s[i], w = 1;
        binar = 0;

        //ignore newline
        if(n == 10) break;
        while(n){
            int rem = n % 2;
            n /= 2;
            binar += rem * w;
            w *= 10;
        }
        bin[k] = binar;
        k++;
    }
    
    for(size_t i = 0; i < k; i++)
        printf("%lld ", bin[i]);

    puts("");

    return 0;
}
