#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

void visualizzaMenu(void);
int verificaPalindroma(char str[]);
void concatenaStringhe(char* str1, char* str2);
void invertiStringa(char* inizio);
void generaStringaCasuale(char* str, int* dim, char min, char max);
void generaStringaCasuale(char* str, int* dim);

int main (void) {

    int* scelta;
    char* str; // ese1
    char* str1; 
    char* str2; // ese6
    char* dimStr; // ese 7 

    srand(time(NULL));
    scelta = (int*) malloc(sizeof(int));

    do {
        visualizzaMenu();
        printf("\nInserisci scelta: ");
        scanf("%d", scelta);
        system("@cls||clear");
        fflush(stdin); // quando diamo un valore a scelta, l'invio successivo viene considerato una stringa resitua e questo faceva aprite il menu più volte, così puliamo il buffer

        switch (*scelta) {
            
            case 1:
                str = (char*)malloc(sizeof(char) * MAX); // in questo modo ho dichiarato un vettore di 100 elementi che occupano lo spazio di 100 celle in memoria 
                printf("Inserisci stringa: ");
                gets(str);
                str = realloc(str, sizeof(char) * (strlen(str)) + 1); // rialloco(resize) per ottimizzare lo spazio in memoria, non free degli altri elementi, + il tappo \ 0
                /* printf("Stringa inserita: %s\n", str);
                printf("Dimensione: %d\n", strlen(str)); */
                if (verificaPalindroma(str) == 1){
                    printf("\nLa stringa %s E' PALINDROMA\n", str);
                } else {
                    printf("\nLa stringa %s NON E' PALINDROMA, quindi mi vado a mangiare le castagne :()\n", str);
                }
                free(str);
                break;

            case 2:
                str = (char*)malloc(sizeof(char) * MAX); // in questo modo ho dichiarato un vettore di 100 elementi che occupano lo spazio di 100 celle in memoria 
                printf("Inserisci stringa: ");
                gets(str);
                str = realloc(str, sizeof(char) * (strlen(str)) + 1); // rialloco(resize) per ottimizzare lo spazio in memoria, non free degli altri elementi, + il tappo \ 0
                /* printf("Stringa inserita: %s\n", str);
                printf("Dimensione: %d\n", strlen(str)); */
                invertiStringa(str);
                printf("\nLa stringa invertita e': %s\n", str);
                free(str);
                break;

            case 3:
                break;
            case 4:
                break;
            case 5:
                break;

            case 6:
                str1 = (char*) malloc(sizeof(char) * MAX);
                str2 = (char*) malloc(sizeof(char) * MAX);

                if (str1 != NULL && str2 != NULL) {

                    printf("Stringa 1: ");
                    gets(str1);
                    str1 = realloc(str1, sizeof(char) * (strlen(str1) + strlen(str2)) + 1); // diamo a str1 gia la lunghezza finale

                    printf("Stringa 2: ");
                    gets(str2);
                    str2 = realloc(str2, sizeof(char) * (strlen(str2)) + 1);

                    concatenaStringhe(str1, str2);
                }

                printf("\nLa stringa concatenata e': %s\n", str1);

                free(str1);
                free(str2);
                break;

            case 7:
                dimStr = (int*) malloc(sizeof(int));
                printf = ("Inserisci dimensione stringa > ");
                scanf("%d", dimStr);
                str = (char*) malloc(sizeof(char) * (*dimStr) + 1);
                *(str + dimStr) = '\0';
                generaStringaCasuale(str, dimStr, 97, 122);
                printf("Stringa finale: %s\n", str);
                convertiInMaiuscola(str, dimStr);
                printf("Stringa maiuscola: %s\n", str);
                free(dimStr);
                break;
                
            case 0:
                printf("\nArrivederci...\n");
                break;
            default:
                printf("\nOpzione non Disponibile!\n");
                break;
        }
        getchar(); // sospende il programma finche non riceve un input
    } while (*scelta != 0);
    free(scelta);

    return 0;
}

void visualizzaMenu() {

    printf("\nESERCITAZIONE - PUNTATORI\n");
    printf("1. Verifica se una stringa è palindroma\n");
    printf("2. Invert una stringa\n");
    printf("3. Conta vocali e consonanti di una stringa\n");
    printf("4. Cerca un valore in un vettore\n");
    printf("5. Calcola minimo, massimo e media di un vettore\n");
    printf("6. Concatena due stringhe\n");
    printf("7. Caricare stringa casuale (a-z) e trasforma in maiuscolo il contenuto\n"); // ascii
    printf("0. ESCI\n");
}

int verificaPalindroma(char* str) {

    char* inizio;
    char* fine;
    inizio = str;
    fine = inizio + (strlen(str) - 1);

    while ((inizio < fine) && (*inizio == *fine)) {
        inizio++; 
        fine--; // cont int fa + 4
    }
    if (*inizio == *fine) {
        return 1;
    }
    return 0;
}

void invertiStringa (char *inizio) {

    char *fine = inizio + (strlen(inizio) - 1);
    char *aus = (char*) malloc(sizeof(char));
    
    while ((inizio < fine) && (*inizio == *fine)) {
        *aus = *inizio;
        *inizio = *fine;
        *fine = *aus;
        
        inizio++; 
        fine--;
    }
}

void concatenaStringhe(char* str1, char* str2) {
    
    char *inizio = str1 + strlen(str1);
    for (; *str2 != '\0'; str2 ++, inizio ++) // la virgola serve a incrementare 2 variabili allo stesso tempo
        *inizio = *str2;
    *inizio = '\0';
}

void generaStringaCasuale(char* str, int* dim, char min, char max){

    int *i;
    i = (int*) malloc(sizeof(int));

    for (*i = 0; *i < *dimStr; (*i)++) {
        *(str + *i) = ((rand() % (max - min + 1)) + min);
    }
}

void generaStringaCasuale(char* str, int* dim){

    int *i;
    i = (int*) malloc(sizeof(int));

    for (*i = 0; *i < *dimStr; (*i)++) {
        // if (*str >= 'a' && *str <= 'z') // serve per controllare se fa parte dell'alfabeto
        // *(str + *i) = (*(str + *i)) - (32);
        *(str + *i) = (*(str + *i)) - ('a' - 'A'); // per trovare il 32 di differenza dell'ascii
    }
}

/* 
all'inizio scelta occupa lo spazio di un puntatore normale
con la malloc scelta viene riallocato in uno spazio di memoria che può contenere un intero
Poiché 'scelta' è già un puntatore (contiene l'indirizzo restituito da malloc), NON si usa l'operatore '&' né l'asterisco '*'.

se sommo l'indirizzo della cella i + la lunghezza del suo vettore andiamo a finire nel tappo, che ci serve per determinare la posizione finale da controllare
*/