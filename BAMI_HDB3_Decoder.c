#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void decode(char *bamiInput, int inputLength) {
    int oneCharLength = inputLength / 2;
    char oneChar[oneCharLength]; // one char representation per bit
    char decoded[oneCharLength];
    int zerosCount = 0;
    bool prevVoltage = false; // false for - true for +
    int index = 0;

    // Convert "++" to "+"
    for (int i = 0; i < oneCharLength; i++) {
        oneChar[i] = bamiInput[index];
        index += 2;
    }

    // Decode the oneChar array
    for (int i = 0; i < oneCharLength; i++) {
        if (oneChar[i] == '+') {
            if (prevVoltage == false) {
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
            if (prevVoltage == true) {
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
        } else {
            decoded[i] = ' ';
        }
    }

    // Print the decoded array
    for (int i = 0; i < oneCharLength; i++) {
        fprintf(stdout, "%c", decoded[i]);
    }
}

int main() {
    char input[512];
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character if present
        input[strcspn(input, "\n")] = '\0';
        decode(input, strlen(input));
    }
    return 0;
}
