#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// Dato un vettore di interi grandi n (chiesto in input)
// a. Caricare il vettore con valori casuali (1-10)
// b. Dire se è palindromo

void stampaVett(int *v, int *dim);
void caricaVett(int *v, int *dim);
void caricaVettPalind(int *v, int *dim);
// void caricaVett(int *v, dim) perche devo ancora dichiararlo

int main (void) {

    int *pV;
    int *dim;
    srand(time(NULL)); // oppure (null), mischiamo le carte e cerchiamo un valore casuale

    dim = (int*)malloc(sizeof(int));
    printf("Inserisci dimensione array: ");
    scanf("%d", dim);

    // allocazione spazio in memoria per array
    pV = (int*)malloc(sizeof(int) * (*dim)); // senza l'* avremmo moltiplicato per un indirizzo 0x001 (dim)

    //caricaVett(pV, dim); // primo parametro gli passo il puntatore alla prima cella
                         // secondo parametro passo l'indirizzo
    caricaVettPalind(pV, dim);
    stampaVett(pV, dim);

    return 0;
}

void stampaVett(int *v, int *dim) {

    int *i = (int*)malloc(sizeof(int)); // area di memoria per rispettare l'indice
    for (*i = 0; *i < *dim; (*i)++) {
        printf("v[%d]: %d\n", *i, *(v + *i));
    }
}

void caricaVett(int *v, int *dim) {

    int *i = (int*)malloc(sizeof(int)); // area di memoria per rispettare l'indice
    for (*i = 0; *i < *dim; (*i)++) {
        *(v + *i) = 1 + rand()%10;
    }
}

void caricaVettPalind(int *v, int *dim) {

    int *i = (int*)malloc(sizeof(int)); // area di memoria per rispettare l'indice
    for (*i = 0; *i < *dim; (*i)++) {
        *(v + *i) = 0;
    }
}