#include <stdio.h>

int main (void) 
{
    int v[] = {33, 44, 55};
    int i;
    int *Pv;

    printf("Con l'uso dei cicli: \n");

    for (i = 0; i < 3; i++) {
        //printf("v[%d]: %d con indirizzo: %p\n", i, v[i], &v[i]);
        // un altro metodo per stampare l'indirizzo e il valore
        printf("v[%d]: %d con indirizzo: %p\n", i, *(v + i), (v + i)); // v[i] == *(v + i) e &v[i] == (v + i)
    }

    printf("\nCon l'uso delle forme contratte: \n");
    
    Pv = v;
    //printf("\nPrima cella: %d con indirizzo %p", v[i], &v[0]);
    printf("Prima cella: %d con indirizzo %p\n", *Pv, &Pv);
    Pv++;
    printf("Seconda cella: %d con indirizzo %p\n", *Pv, &Pv);
    Pv++;
    printf("Terza cella: %d con indirizzo %p\n", *Pv, &Pv);
    /* questo v++ non andra a buon fine dato che v viene considerato statico, 
       quindi rischiamo di perdere l'allocazione di tutte le altre celle */
    // per questo creiamo una copia Pv sulla quale lavorare

    return 0;
}