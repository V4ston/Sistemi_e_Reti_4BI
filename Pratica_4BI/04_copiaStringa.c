/*
Dichiarare due stringhe di uguale dimensione.
Acquisire in una stringa una sequenza di caratteri,
quindi copiare, usando i puntatori, tutti i caratteri dalla
stringa acquisita all'altra, accedendo in modo indiretto a ciascuna
delle locazioni delle due stringhe
*/

#include <stdio.h>

int main (void) {

    char c1[6] = "Panno";
    char c2[6];

    char* Pv1 = c1;
    char* Pv2 = c2;

    while (*Pv1 != '\0') {
        *Pv2 = *Pv1;
        Pv1++;
        Pv2++;
    }

    *Pv2 = '\0';

    printf("La stringa c1 : %s e' stata copiata in c2 : %s", c1, c2);

    return 0;
}