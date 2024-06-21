#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(char *binaryNum, int size) {
    int nrzs[size];
    // Initialize state with the first bit (should be 1)
    int state = 1;
    // Convert binaryNum to NRZS
    for (int k = 0; k < size; k++) {
        nrzs[k] = state ^ (binaryNum[k] - '0') ^ 1;
        state = nrzs[k]; // used to compare the previous state if its (1 or 0)
    } // state can be either -47 or 1
    // Print the NRZS array
    for (int i = 0; i < size; i++) {
        fprintf(stdout,"%c", nrzs[i] ? '-' : '+');
    }
}
int main() {
    char* binaryNum = NULL; // Initialize pointer to NULL
    int capacity = 32000; // Initial capacity
    int size = 0; // Actual number of elements in the array

    binaryNum = (char*)malloc(capacity * sizeof(char)); // Allocate memory

    if (binaryNum == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    char input;
    while (scanf("%c", &input) == 1 && input != '\n') {
        binaryNum[size++] = input; // Store input character
        if (size >= capacity) {
            capacity *= 2; // Double the capacity
            binaryNum = (char*)realloc(binaryNum, capacity * sizeof(char)); // Reallocate memory
            if (binaryNum == NULL) {
                printf("Memory allocation failed");
                return 1;
            }
        }
    }

    encode(binaryNum, size);

    free(binaryNum); // Free dynamically allocated memory
    return 0;
}