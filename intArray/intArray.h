#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

char * toString(int array[], int arraySize); // Restituisce gli elementi del vettore come puntatore ad una stringa
void generateElements(int array[], int arraySize, int min, int max); // genera gli elementi in un range specificato
int sum(int array[], int arraySize); // Calcola la somma degli elementi
float average(int array[], int arraySize); // Calcola la media degli elementi 
int min(int array[], int arraySize); // Determina l'elemento minore
int max(int array[], int arraySize); // Determina l'elemento maggiore
void bubbleSort(int array[], int arraySize); // Ordina l'array in modo crescente
int linearSearch(const int array[], int arraySize, int element); // Cerca un elemento con la ricerca lineare
int binarySearch(const int array[], int arraySize, int element); // Cerca un elemento con la ricerca binaria
int frequency(const int array[], int arraySize, int element); // Conta le occorrenze di un elemento
void swap(int array[], int arraySize, int index1, int index2); // Scambia gli elementi nelle posizioni specificate
void reverse(int array[], int arraySize); // Inverte gli elementi
void rightShift(int array[], int arraySize, int n); // Sposta gli elementi verso destra di un numero n di posizioni
void leftShift(int array[], int arraySize, int n); // Sposta gli elemetni verso sinistra di un numero n di posizioni
void copy(int source[], int sourceSize, int destination[], int destinationSize); // Copia gli elementi di un array in un altro

char * toString(int array[], int arraySize) {
    static char string[255];
    short i;

    for (i = 0; i < 255; i++) {
        string[i] = 0;
    }

    for (i = 0; i < arraySize; i++) {
        sprintf(&string[strlen(string)],  "%d ", array[i]);
    }
    
    return string;
}

void generateElements(int array[], int arraySize, int min, int max) {
    int i, hold;

    srand(time(NULL));

    if (min > max) {
        // Swap min and max
        hold = min;
        min = max;
        max = hold;
    }

    for (i = 0; i < arraySize; i++) {
        array[i] = min + rand() % (max - min + 1) ;
    }

}

int sum(int array[], int arraySize) {
    int i, sum;

    sum = 0;

    for (i = 0; i < arraySize; i++) {
        sum = sum + array[i];
    }

    return sum;
}

float average(int array[], int arraySize) {
    float average;

    average = (float) sum(array, arraySize) / arraySize;

    return average;
}

int min(int array[], int arraySize) {
    int i, min;

    min = array[0];

    for (i = 1; i < arraySize; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }

    return min;
}

int max(int array[], int arraySize) {
    int i, max;

    max = array[0];

    for (i = 1; i < arraySize; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}

void bubbleSort(int array[], int arraySize) {
    short int i, j, scan, hold;

    scan = arraySize;
    // Bubble sort
    for (i = 0; i < arraySize; i++) {
        for (j = 0; j < scan-1; j++) {
            if (array[j] > array[j+1]) {
                hold = array[j];
                array[j] = array[j+1];
                array[j+1] = hold;
            }
        }
        /*
        Siccome ad ogni scansione l'elemento più grande va in coda, posso evitare ogni volta di fare
        l'ultimo controllo, visto che certamente sarà maggiore del precedente.
        */
        scan = scan - 1;
    }

}

int linearSearch(const int array[], int arraySize, int element) {
    bool found;
    int i, j;

    i = 0;
    j = -1;
    found = false;
    while (found == false && i < arraySize) {     
        if (array[i] == element) {
            found = true;
            j = i;
        }
        i = i + 1;
    }

    return j;
}

int binarySearch(const int array[], int arraySize, int element) {
    int start, middle, end;
    int j;
    bool found;

    found = false;
    j = -1;
    start = 0;
    end = arraySize-1;

    while (found == false && start < end) {
        middle = (start + end) / 2;

        if (array[middle] == element) {
            found = true;
            j = middle;
        } else {
            if (element > array[middle]) {
                start = middle + 1;
            } else {
                end = middle - 1;
            }
        }
    }

    return j;
}

int frequency(const int array[], int arraySize, int element) {
    int i, frequency;

    frequency = 0;

    for (i = 0; i < arraySize; i++) {
        if (array[i] == element) {
            // Se l'elemento in posizione 'i' corrisponde al parametro element, viene incrementata la frequenza
            frequency = frequency + 1;
        }
    }

    return frequency;
}

void swap(int array[], int arraySize, int index1, int index2) {
    int hold;

    hold = array[index1];
    array[index1] = array[index2];
    array[index2] = hold;
}

void reverse(int array[], int arraySize) {
    int i, lastElement, hold;

    lastElement = arraySize - 1;

    for (i = 0; i < arraySize/2; i++) {
        hold = array[lastElement];
        array[lastElement] = array[i];
        array[i] = hold;

        lastElement = lastElement - 1;
    }
}

void rightShift(int array[], int arraySize, int n) {
    short i;
    int hold;

    i = arraySize;
    while (i > n) {
        hold = array[i % arraySize];
        array[i % arraySize] = array[(i + n) % arraySize];
        array[(i + n) % arraySize] = hold;
        
        i = i - 1;
    }
}

void leftShift(int array[], int arraySize, int n) {
    short i;
    int hold;

    i = 0;
    while (i < arraySize - n) {
        hold = array[i % arraySize];
        array[i % arraySize] = array[(i + n) % arraySize];
        array[(i + n) % arraySize] = hold;
        
        i = i + 1;
    }
}

void copy(int source[], int sourceSize, int destination[], int destinationSize) {
    int i;
    int endLoop;

    if (sourceSize <= destinationSize) {
        /*
        Se l'array sorgente è di dimensione minore rispetto a quella dell'array di destinazione
        allora verrano copiati tutti gli elementi fino alla dimensione massima dell'array di destinazione. 

        Ad esempio:
        Source:        a[0], a[1], a[2], a[3], a[4]
        Destination:   a[0], a[1], a[2]
        
        In questo caso nell'array di destinazione saranno copiati tutti gli elementi fino a quello di indice 2.
        
        */
        endLoop = destinationSize;
    } else {
        /*
        Se l'array sorgente è di dimensione maggiore rispetto a quella dell'array di destinazione
        allora verrano copiati tutti gli elementi fino alla dimensione massima dell'array sorgente. 

        Ad esempio:
        Source:        a[0], a[1], a[2]
        Destination:   a[0], a[1], a[2], a[3], a[4]
        
        In questo caso nell'array di destinazione saranno copiati tutti gli elementi fino a quello di indice 2.
        Le celle di indice 3 e 4 non saranno considerate.
        */
        endLoop = sourceSize;
    }

    for (i = 0; i < endLoop; i++) {
        destination[i] = source[i];
    }
}
 