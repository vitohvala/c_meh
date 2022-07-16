#include <stdio.h>

int main(){
    int j, s, d, h, i;
    while(1){
    printf("unesite broj: "); scanf("%d", &i);
        h=i/1000;//h1ljada ide gas
        s=(i/100)%10;//stotine
        j=i%10;//jedinice
        d=(i/10)%10;//desetice
        if(h==j && d==s)  {
            printf("uneti broj %d, je simetrican\n", i);
            break;
        }  
        else {
            printf("uneti broj %d, nije simetrican\n", i);
            continue;
        }
        }
    return 0;
}