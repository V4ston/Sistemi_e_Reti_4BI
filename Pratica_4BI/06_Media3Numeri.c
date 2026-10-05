#include <stdio.h>
#include <stdlib.h>

// dati 3 numeri interi in input stampare in output la media
// non serve avere celle consecutive perchè variabili singole

int main (void) {

    float *media;
    int *n1, *n2, *n3; // trova un area abbastanza grande da ospitare un puntatore
                       // l'indirizzo sara il nome della cella in cui si alloca
    media = (float*)malloc(sizeof(float));

    n1 = (int*)malloc(sizeof(int));
    n2 = (int*)malloc(sizeof(int));
    n3 = (int*)malloc(sizeof(int));
                       // con la malloc vengono riservare 4 celle nella heap per l'allocazione in memoria dell'int n1
    printf("Inserisci n1: ");
    scanf("%d", n1);   // che è come scrivere &*n1 ma in questo modo i due indicatori si annullano
    printf("Inserisci n2: ");
    scanf("%d", n2);
    printf("Inserisci n3: ");
    scanf("%d", n3);

    *media = (*n1 + *n2 + *n3)/3;

    printf("n1: %d\nn2: %d\nn3: %d\n", *n1, *n2, *n3);
    printf("La media e' %.2f\n", *media);

    return 0;
}

/*
int a
&a = 0x7467
a = 10
print(a) (= 10)

int *p
&p = 0x7473
p = &a
print(*p) (= 50)
se il valore assegnato è 50

le d%, %s, %p sono detti buffer

0x002 e 0x7467 sono le aree della heap e della stack, che si passano i valori e gli indirizzi
per trovare il valore dell'indirizzo o l'indirizzo stesso allocato della heap devo passare per la stack;
mentre posso accedere direttamente alla stack per cercare i suoi valori

Gli indirizzi 0x002 e 0x7467 sono singoli puntatori di memoria, non le intere aree di Stack e Heap.
Alla Stack si accede direttamente per leggerne i valori (variabili locali), gestiti dalla CPU. 
Per accedere alla Heap, invece, serve un accesso indiretto: devi dereferenziare un puntatore contenente il suo indirizzo, 
che viene solitamente salvato sulla Stack (o in una variabile globale). 
*/