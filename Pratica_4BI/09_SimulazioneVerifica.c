#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void visualizzaMenu(char* scelta);

void caricaElementiVettoreInt(int* puntV, int* dimensione, int min, int max);
void caricaMultipli(int* puntV, int* dimensione, int* mult);

void caricaElementiVettoreChar(char* puntV, int* dimensione, char min, char max);
void gnomeSort(char* v, int* n); // convenzionale per il copia-incolla

void contaVocali(char* puntC);


int main (void){

    srand(time(NULL));
    char* scelta = (char*)malloc(sizeof(char));
    char* puntC;

    int* dimensione;  
    int* puntV; 
    int* mult;

    do {

        visualizzaMenu(scelta);
        system("@cls||clear");
        fflush(stdin);

        switch(*scelta) {
    
            case 'a':
                dimensione = (int*)malloc(sizeof(int));
                do {
                printf("Inserisci la lunghezza del vettore: ");
                scanf("%d", dimensione);      
                } while(*dimensione < 1); 
                
                puntV = (int*)calloc(*dimensione, sizeof(int));
                caricaElementiVettoreInt(puntV, dimensione, -100, 100);
                                
                mult = (int*)malloc(sizeof(int));
                printf("\nInserisci il multiplo di uno degli elementi: ");
                scanf("%d", mult);
                
                caricaMultipli(puntV, dimensione, mult);
                
                free(dimensione);
                free(puntV);
                free(mult);
                break;

            case 'b':
                dimensione = (int*)malloc(sizeof(int));
                do {
                printf("Inserisci la lunghezza del vettore: ");
                scanf("%d", dimensione);      
                } while(*dimensione < 1);

                puntC = (char*)calloc(*dimensione, sizeof(char));
                caricaElementiVettoreChar(puntC, dimensione, 'a', 'z');

                gnomeSort(puntC, dimensione);

                free(dimensione);
                free(puntC);
                break;
            
            case 'c': {
                dimensione = (int*)malloc(sizeof(int));
                do {
                printf("Inserisci la lunghezza della stringa: ");
                scanf("%d", dimensione);      
                } while(*dimensione < 1);

                puntC = (char*)calloc(*dimensione + 1, sizeof(char));
                printf("\nInserisci frase: ");
                scanf("%s", puntC);

                contaVocali(puntC);

                free(puntC);
                free(dimensione);
                break;
            }
            
            case 'q':
                break;
            
            default:
                break;
        }
        getchar();
    } while(*scelta != 'q');

    free(scelta);
    return 0;
}


void visualizzaMenu(char* scelta){

    printf("\na. Svolgi Esercizio 1\n");
    printf("b. Svolgi Esercizio 2\n");
    printf("c. Svolgi Esercizio 3\n");
    printf("q. Termina\n");
    printf("Scelta: ");
    scanf("%c", scelta); 
}

// ese 1

void caricaElementiVettoreInt(int* puntV, int* dimensione, int min, int max){

    int* i = (int*)malloc(sizeof(int));
    *i = 0;
    for (; *i < *dimensione; (*i)++) {
        *(puntV + *i) = min + rand() % (max - min + 1);
        printf("%d ", *(puntV + *i));
    }
    free(i);
}

void caricaMultipli(int* puntV, int* dimensione, int* mult){

    int* puntMult;
    int* nuovoEl;
    int* i;

    puntMult = (int*)calloc(*dimensione, sizeof(int));
    nuovoEl = (int*)calloc(1, sizeof(int));
    i = (int*)calloc(1, sizeof(int)); 

    printf("\nMultipli trovati: ");

    for (; *i < *dimensione; (*i)++) {
        if (*(puntV + *i) % (*mult) == 0) {
            *(puntMult + *nuovoEl) = *(puntV + *i);
            printf("%d ", *(puntMult + *nuovoEl));
            (*nuovoEl)++;
        }
    }

    free(puntMult);
    free(nuovoEl);
    free(i);
}

// ese 2

void caricaElementiVettoreChar(char* puntC, int* dimensione, char min, char max){

    int* i = (int*)malloc(sizeof(int));
    *i = 0;
    for (; *i < *dimensione; (*i)++) {
        *(puntC + *i) = min + rand() % (max - min + 1);
        printf("%c ", *(puntC + *i));
    }
    free(i);
}

void gnomeSort(char* v, int* n) {
    
    int* index = (int*)calloc(1,sizeof(int));
    char* tmp;

    while (*index < *n) {
        if (*index == 0) {
            (*index)++;
        }
        if (*(v + *index) >= *(v + (*index - 1))) {
            (*index)++;
        } else {
            tmp = (char*)malloc(sizeof(char));
            *tmp = *(v + *index);
            *(v + *index) = *(v + (*index - 1));
            *(v + (*index - 1)) = *tmp;
            (*index)--;
            free(tmp);
        }
    }
    int* i = (int*)malloc(sizeof(int));
    *i = 0;
    printf("\nVettore ordinato: ");
    for (; *i < *n; (*i)++) {
        printf("%c ", *(v + *i));
    }
    free(index);
    free(i);
}

// ese 3

void contaVocali(char* puntC){

    int* cont = (int*)calloc(1, sizeof(int));
    int* i = (int*)calloc(1, sizeof(int));
    int* dentro = (int*)calloc(1, sizeof(int));

    while(*(puntC + *i) != '\0') {
        if (*(puntC + *i) == '*') {
            *dentro = !(*dentro);
        } else if (*dentro == 1) {
            char c = *(puntC + *i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                (*cont)++;
            }
        }
        (*i)++;
    }
    
    printf("\nIl numero di vocali tra asterischi e': %d\n", *cont);

    free(cont);
    free(i);
    free(dentro);
}