#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decode(char *nrzsIn, int size) {
    int nrzs[size];
    for (int i = 0; i < size; i++) {
        if (nrzsIn[i] == '+') {
            nrzs[i] = 0;
        } else if (nrzsIn[i] == '-') {
            nrzs[i] = 1;
        }
    }
    int binaryNum[size];
    int state = nrzs[0];
    for (int k = 0; k < size; k++) {
        binaryNum[k] = state ^ nrzs[k] ^ 1;
        state = nrzs[k];
    }
    // Print the binaryNum array
    for (int i = 0; i < size; i++) {
        fprintf(stdout,"%d", binaryNum[i]);
    }
}


int main() {
    char* nrzsIn = NULL; // Initialize pointer to NULL
    int capacity = 32000; // Initial capacity
    int size = 0; // Actual number of elements in the array

    nrzsIn = (char*)malloc(capacity * sizeof(char)); // Allocate memory

    if (nrzsIn == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    char input;
    while (scanf("%c", &input) == 1 && input != '\n') {
        nrzsIn[size++] = input; // Store input character
        if (size >= capacity) {
            capacity *= 2; // Double the capacity
            nrzsIn = (char*)realloc(nrzsIn, capacity * sizeof(char)); // Reallocate memory
            if (nrzsIn == NULL) {
                printf("Memory allocation failed");
                return 1;
            }
        }
    }

    decode(nrzsIn, size);

    free(nrzsIn); // Free dynamically allocated memory
    return 0;
}
