#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// IT WORKS DO NOT CHANGE
// Function to convert a hexadecimal digit to its binary representation

int main() {
	char nrzsIn[32000]; // Assuming input won't exceed n characters
    printf("Enter NRZS values: ");
    fgets(nrzsIn, sizeof(nrzsIn), stdin); // Read input from stdin
    int size = strlen(nrzsIn)-1;
	// Convert + to 0 and - to 1
	//printf("size=%d\n",size);
	int i;
	int nrzs[size];
    for (i = 0; i < size; i++) {
        if (nrzsIn[i] == '+') {
            nrzs[i] = 0;
        } else if (nrzsIn[i] == '-') {
            nrzs[i] = 1;
        }
    }
    int binaryNum[size];
    // Initialize state with the first bit (should be 1)
    int state = nrzs[0];
    // Convert NRZS to binaryNum
    int k;
    for (k = 0; k < size; k++) {
        binaryNum[k] = state ^ nrzs[k] ^ 1;
        state = nrzs[k];
    }
    // Print the binaryNum array
    printf("Converted binaryNum: ");
    for (i = 0; i < size; i++) {
        fprintf(stdout,"%d", binaryNum[i]);
    }
    printf("\n");
    
	return 0;
}

