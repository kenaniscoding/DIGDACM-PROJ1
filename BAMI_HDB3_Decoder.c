#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void decode(char *bamiInput, int inputLength) {
    int oneCharLength = inputLength / 2;
    char *oneChar = (char*)malloc(oneCharLength * sizeof(char)); // one char representation per bit
    char *decoded = (char*)malloc(oneCharLength * sizeof(char));
    int index = 0;
    int zerosCount = 0;
    bool prevVoltage = false; // false for - true for +

    for (int i = 0; i < oneCharLength; i++) { // turn "++" into "+"
        oneChar[i] = bamiInput[index];
        index += 2;
    }

    for (int i = 0; i < oneCharLength; i++) {
        if (oneChar[i] == '+') {
            if (!prevVoltage) {
                decoded[i] = '1';
            } else {
                if (zerosCount == 2) {
                    decoded[i] = '0';
                    decoded[i - 3] = '0';
                } else if (zerosCount == 3) {
                    decoded[i] = '0';
                }
            }
            zerosCount = 0;
            prevVoltage = true;
        } else if (oneChar[i] == '-') {
            if (prevVoltage) {
                decoded[i] = '1';
            } else {
                if (zerosCount == 2) {
                    decoded[i] = '0';
                    decoded[i - 3] = '0';
                } else if (zerosCount == 3) {
                    decoded[i] = '0';
                }
            }
            zerosCount = 0;
            prevVoltage = false;
        } else if (oneChar[i] == '0') {
            zerosCount++;
            decoded[i] = '0';
        } else if (oneChar[i] == '\0' || oneChar[i] == ' ') {
            decoded[i] = ' ';
        }
    }

    for (int i = 0; i < oneCharLength; i++) {
        fprintf(stdout, "%c", decoded[i]);
    }

    free(oneChar);
    free(decoded);
}

int main() {
    char *input = NULL; // Initialize pointer to NULL
    int capacity = 512; // Initial capacity
    int size = 0; // Actual number of elements in the array

    input = (char*)malloc(capacity * sizeof(char)); // Allocate memory

    if (input == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    char c;
    while (scanf("%c", &c) == 1 && c != '\n') {
        input[size++] = c; // Store input character
        if (size >= capacity) {
            capacity *= 2; // Double the capacity
            input = (char*)realloc(input, capacity * sizeof(char)); // Reallocate memory
            if (input == NULL) {
                printf("Memory allocation failed");
                return 1;
            }
        }
    }

    decode(input, size); // Call decode function with the input array and its size

    free(input); // Free dynamically allocated memory
    return 0;
}
