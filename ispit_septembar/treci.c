#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 20
#define MAX 100

typedef struct {
    char dolazni_grad[MAX_CHAR];
    int broj_autobusa;
    char oznaka_autobusa[MAX_CHAR];
}ODLASCI;

typedef struct{
    char oznaka_autobusa[MAX_CHAR];
    int broj_sedista;
}AUTOBUS;

void open_file(FILE **fp, char *filename){
    *fp = fopen(filename, "r");
    if(*fp == NULL){
        perror("fopen");
        exit(1);
    }
}

void get_string(char *ispis, char *input){
    printf("%s", ispis);
    scanf("%s", input);
}

int get_bs(ODLASCI odlazak[], AUTOBUS autobus[], int autobus_vel, int i){
    int temp = 0;
    for(int j = 0; j < autobus_vel; j++){
        if(strcmp(odlazak[i].oznaka_autobusa, autobus[j].oznaka_autobusa) == 0){
            temp += autobus[j].broj_sedista;
            temp *= odlazak[i].broj_autobusa;
        }
    }
    return temp;
}

int main(){
    FILE *odlasci, *autobusi;
    char user_input[MAX_CHAR];
    ODLASCI odlazak[MAX];
    AUTOBUS autobus[MAX];
    int odlazak_vel = 0, autobus_vel = 0, ukupan_broj_sedista = 0;

    open_file(&odlasci, "odlasci.txt");
    open_file(&autobusi, "autobusi.txt");
    
    while(fscanf(odlasci, "%s", odlazak[odlazak_vel].dolazni_grad) != EOF){
        fscanf(odlasci, "%d", &odlazak[odlazak_vel].broj_autobusa);
        fscanf(odlasci, "%s", odlazak[odlazak_vel].oznaka_autobusa);
        odlazak_vel++;
    }
    fclose(odlasci);
    
    while(fscanf(autobusi, "%s", autobus[autobus_vel].oznaka_autobusa) != EOF){
        fscanf(autobusi, "%d", &autobus[autobus_vel].broj_sedista);
        autobus_vel++;
    }
    fclose(autobusi);

    get_string("Unesite ime dolaznog grada: ", user_input);

    for(int i = 0; i < odlazak_vel; i++){
        if(strcmp(user_input, odlazak[i].dolazni_grad) == 0){
            ukupan_broj_sedista += get_bs(odlazak, autobus, autobus_vel, i);
        }
    }
    
    printf("Ukupan broj sedista za grad %s je %d\n", user_input, ukupan_broj_sedista);
    
    return 0;
}
