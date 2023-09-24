#include<stdio.h>
#include <stdlib.h>

void open_and_print(char *filename){
    FILE *fp = fopen(filename, "r");
    int lines = 1;
    char s[256];
    char cats[][128] = {"  _  ,/|    ", " '\\`o.O'   _", "  =(_*_)= ( ", "    )U(  _) ", "   /   \\(   ", "  (/`-'\\)   "};
    if(fp == NULL){
        perror("fopen");
        exit(1);
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            printf("%s    ", cats[i]);
        }
        printf("\n");
    }
    while(fgets(s, sizeof(s), fp)){
        printf("%d %s", lines, s);  
        lines++;
    }

    fclose(fp);
}

int main(int argc, char**argv){
    if(argc < 2){
        printf("Enter filename\n");
    }
    for(int i = 1; i < argc; i++){
        open_and_print(argv[i]);
    }
    return 0;
}
