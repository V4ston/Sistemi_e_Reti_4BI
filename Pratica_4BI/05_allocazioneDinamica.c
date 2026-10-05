#include <stdio.h>
#include <stdlib.h>

/*
Memoria statica: Stack
Memoria dinamica: Heap
*/

void stampaVett(int a[], int dim);

int main (void) 
{
    int v[] = { 1, 2, 3, 4, 5 };
    int dimV = 5;
    
    /*
    int dimV = 5;
    ...
    int *dim;
    dim = (int*) malloc(sizeof(int));
    *dim = 5;
    */

    printf("Array statico di %d elementi\n", dimV);
    stampaVett(v, dimV);

    // allocazione dinamica
    int numElem = 10;
    int *p;

    // malloc = malloc(nuByte) (Memory Allocation)
    p = (int*)malloc(sizeof(int) * numElem); 
    stampaVett(p, numElem);

    /* calloc = calloc (numero di celle per tipo, dimensione singolo elemento/tipo) */
    p = (int*)calloc(numElem, sizeof(int));
    stampaVett(p, numElem);

    /* calloc = realloc (indirizzo della prima cella, nuova dimensione) */
    numElem = 15;
    p = (int*)realloc(p, numElem * sizeof(int));
    stampaVett(p, numElem);

    /* free = free (indirizzo) */
    free(p);

    return 0;
}

void stampaVett(int a[], int dim) {

    int i;
    for (i = 0; i < dim; i++) {
        printf("v[%d]: %d - %p\n", i, a[i], &a[i]);
    }
    printf("\n");
}

/* 
int *p;

// addr = malloc(sizeof(int)*s) // da come risultato sempre un indirizzo
p = (int*)malloc(sizeof(int)*s)

p = (int*)calloc(1, sizeof(int))

p = (int*)realloc(p, 5*sizeof(int))

free(p)

malloc() è una funzione, quando creiamo il nostro vettore, 
dobbiamo calcolare se lo spazio in memoria sia sufficiente

dove l'unico parametro passato è il numero di elementi del vettore moltiplicata per la lunghezza di ogni cella
per sapere meglio quanto occupa il vettore possiamo usare il size, direttamente della funzione
se abbiamo un int (star) probabilmente non andra a buon fine, quindi usiamo un cast di int
la malloc mantiene il valore "sporco"
restituira un null se non abbiamo memoria a disposizione

//

la calloc() è una funzione, , 
il primo è il numero di elementi
la seconda è la lunghezza della varibile

la calloc tiene conto delle 4 posizione e il valore allocato sara uguale a 0

//

la realloc() ha lo scopo di riallocare memoria, una sorta di resize, 
se voglio modificare la memoria il primo indirizzo non viene cancellato

il primo parametro è l'indirizzo della prima cella
il secondo parametro è la nuova dimensione

non necessita un  forzato, restituisce sempre il primo indirizzo passato
se non c'è più spazio o è ridotta rispetto a quella necessaria nella posizione richiesta
vengono cercate un numero di celle necessarie per allocarlo
e cambierà l'indirizzo della prima cella con un nuovo valore

//

free() richiede un solo parametro, la variabile viene riallocata, non è più di suo possesso
nasce perchè un volta era importante salvare memoria
in c# non abbiamo il garbage collector, più moderno, più "versatile"
in c si sceglie per la rapidità

*/