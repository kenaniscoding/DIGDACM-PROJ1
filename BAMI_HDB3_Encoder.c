#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void toHDB3(char* rawInput, int inputLength) {
    int zerosCount= 0;
    int onesCount = 0;
    bool prevVoltage = false;
    char *output = (char*)malloc(inputLength * sizeof(char));
    char *finalOutput = (char*)malloc(inputLength * 2 * sizeof(char)); // double characters
    int index = 0;

    for(int i = 0; i < inputLength; i++){
        if(rawInput[i] == '1'){
            onesCount++;
            zerosCount = 0;

            if (prevVoltage == true){
                output[i] = '-';
                prevVoltage = false;
            } else {
                output[i] = '+';
                prevVoltage = true;
            }
        } else if (rawInput[i] == '0'){
            zerosCount++;
            
            if (zerosCount < 4) {
                output[i] = '0';
            } else if (zerosCount == 4) {
                if (onesCount % 2 == 0 && !prevVoltage) { // even-negative t
                    output[i] = '+';
                    output[i-3] = '+';
                    prevVoltage = true;
                } else if (onesCount % 2 == 0 && prevVoltage) { // even-positive t
                    output[i] = '-';
                    output[i-3] = '-';
                    prevVoltage = false;
                } else if (onesCount % 2 != 0 && !prevVoltage) { // odd-negative t
                    output[i] = '-';
                } else if (onesCount % 2 != 0 && prevVoltage) { // odd-positive t
                    output[i] = '+';
                }
                onesCount = 0;
                zerosCount = 0;
            } 
        } else if (rawInput[i] == '\0') {
            output[i] = ' ';
        }
    }

    for (int i = 0; i < inputLength; i++) {
        finalOutput[index++] = output[i];
        finalOutput[index++] = output[i];
    }
    
    for (int i = 0; i < index; i++) {
        fprintf(stdout, "%c", finalOutput[i]);
    }
    
    free(output);
    free(finalOutput);
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

    toHDB3(input, size); // Call toHDB3 function with the input array and its size

    free(input); // Free dynamically allocated memory
    return 0;
}
