#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void visualizzaMenu(char* input);
void caricaMultipli(int* lunghezza, int* vetInt, int* mult);
void contaVocali(char* frase);

int main (void) {

    srand((unsigned int)time(NULL));
    char* input = (char*)malloc(sizeof(char));

    // var
    int* lunghezza = NULL;

    do {
        visualizzaMenu(input);
        system("@cls||clear");
        switch(*input) {
    
            case 'a':
                lunghezza = (int*)malloc(sizeof(int));
                printf("Inserisci la lunghezza del vettore: ");
                scanf("%d", lunghezza);            
                
                int* vetInt = (int*)calloc(*lunghezza, sizeof(int));
                int* i = (int*)malloc(sizeof(int)); 
                for (*i = 0; *i < *lunghezza; (*i)++) {
                    *(vetInt + *i) = (rand() % 201) - 100;
                    printf("%d ", *(vetInt + *i));
                }
                free(i);
                printf("\n");
                
                int* mult = (int*)malloc(sizeof(int));
                printf("Inserisci un multiplo: ");
                scanf("%d", mult);
                
                caricaMultipli(lunghezza, vetInt, mult);
                
                free(vetInt);
                free(lunghezza);
                free(mult);
                break;

            case 'b':
                break;
            
            case 'c': {
                lunghezza = (int*)malloc(sizeof(int));
                printf("\nInserisci lunghezza stringa: ");
                scanf("%d", lunghezza);

                char* frase = (char*)calloc(*lunghezza, sizeof(char));
                int* newElem = (int*)malloc(sizeof(int));
                *newElem = 0;

                printf("\nInserisci frase: ");
                scanf("%s", frase);

                while(*(frase + *newElem) != '\0') {
                    (*newElem)++;
                }

                frase = (char*)realloc(frase, (*newElem + 1) * sizeof(char));
                
                contaVocali(frase);

                free(frase);
                free(newElem);
                free(lunghezza);
                break;
            }
            
            case 'q':
                break;
            
            default:
                break;
        }
    } while(*input != 'q');

    free(input);
    return 0;
}

void contaVocali(char* frase) {
    printf("\n%s\n", frase);
    
    int* cont = (int*)malloc(sizeof(int));
    *cont = 0;
    
    int* i = (int*)malloc(sizeof(int));
    *i = 0;
    
    int* start = (int*)malloc(sizeof(int));
    *start = 1;

    while(*(frase + *i) != '\0') {
        if (*(frase + *i) == '*') {
            (*start)++;
        } 
        if (*start % 2 == 0) {
            char c = *(frase + *i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                (*cont)++;
            }
        }
        (*i)++;
    }
    
    printf("\nIl totale delle vocali presenti nella sotto stringa e': %d\n", *cont);

    free(cont);
    free(i);
    free(start);
}

void caricaMultipli(int* lunghezza, int* vetInt, int* mult) {

    int* vetSec = (int*)calloc(*lunghezza, sizeof(int));
    int* newEl = (int*)malloc(sizeof(int));
    *newEl = 0;
    int* i = (int*)malloc(sizeof(int)); 

    printf("\nMultipli trovati: ");
    for (*i = 0; *i < *lunghezza; (*i)++) {
        if (*(vetInt + *i) % (*mult) == 0) {
            *(vetSec + *newEl) = *(vetInt + *i);
            printf("%d ", *(vetSec + *newEl));
            (*newEl)++;
        }
    }
    printf("\n");

    free(vetSec);
    free(newEl);
    free(i);
}

void visualizzaMenu(char* scelta) {

    printf("\na. Svolgi Esercizio 1\n");
    printf("b. Svolgi Esercizio 2\n");
    printf("c. Svolgi Esercizio 3\n");
    printf("\nq. Termina\n");
    
    scanf(" %c", scelta); 
}