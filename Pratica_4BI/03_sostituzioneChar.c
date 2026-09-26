/*
Si scriva un programma che manipoli un array
di char tramite un puntatore
L'array deve avere valore iniziale ['L', 'U', 'C', 'A']
e, applicando le nozioni di aritmetica dei puntatori, si trasformi
in ['A', 'N', 'N', 'A']
*/

#include <stdio.h>

int main (void) {

    char v[] = {'L', 'U', 'C', 'A', '\0'};
    char* Pv = v;

    *Pv = 'A';
    Pv++;
    *Pv = 'N';
    Pv++;
    *Pv = 'N';
    Pv++;
    *Pv = 'A';

    printf("Il nuovo nome e': %s", v);

    return 0;
}