#include <stdio.h>

int main(void)
{
    int i;    // 0x005
    char c;   // 0x00A

    int *pi;  // ha sempre 8 byte nel momento della stampa

    i = 10;   // 4 byte
    c = 'c';  // 1 byte
              // totale 5 byte

    printf("La variabile i occupa %d byte in memoria\n", sizeof(i));
    printf("Il tipo char occupa %d byte in memoria\n", sizeof(char)); // c
    printf("Il tipo char occupa %d byte in memoria\n", sizeof(int*)); // pi

    printf("L'indirizzo di i e' %p e contiene %d\n", &i, i);          // contenuto in memoria (indirizzo) , valore/ contenuto dell'indirizzo 
    printf("L'indirizzo di c e' %p e contiene %c\n", &c, c);          // contenuto in memoria (indirizzo) , valore/ contenuto dell'indirizzo 
    printf("L'indirizzo di pi e' %p e contiene %p\n", &pi, pi);       // contenuto in memoria (indirizzo) , valore/ contenuto dell'indirizzo 
    printf("L'indirizzo di pi e' %p e contiene %d\n", &pi, pi);       // contenuto in memoria (indirizzo) , valore/ contenuto dell'indirizzo 

    // ripasso di trasmissione dei parametri per valore e referenza
    // in c non possiamo direttamente mettere ref a nel richiamo dei parametri

    // ma usiamo l'* sia nel richiamo (* a) sia nelle istruzioni del codice *a = 1000

    /* quando stampiamo un vettore v senza specificarne l'elemento (v al posto di v[i] ), 
       viene salvato all'interno della variabile il suo indirizzo in memoria, in c 
       lo stesso risulato ce lo da la sintassi &v[i] cioè il valore dell'indirizzo in memoria */

    /* se facciamo v++ ( v + 1 ) possiamo finire in aree della memoria in cui non volevamo
       o addirittura rischiare di cancellare il vettore 
       per questo conviene sempre lavorare su una copia */

    // int * p o int *p o int* p sono la stessa cosa, e serve per la dichiarazione

    /* con *a noi andiamo a cercare il valore in memoria 0
       per spostarci all'interno della memoria possiamo usare v++ nonostante i rischi
       e solamente dopo assegnamo il valore ad *a
    */

    return 0;
};