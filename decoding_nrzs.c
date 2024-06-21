#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char nrzsIn[512]; // Assuming input won't exceed n characters
    //printf("NRZS values: ");
    fgets(nrzsIn, sizeof(nrzsIn), stdin); // Read input from stdin
    int size = strlen(nrzsIn)-1;
	// Convert + to 0 and - to 1
	int i;
	int nrzs[size];
    for (i = 0; i < size; i++) {
        if (nrzsIn[i] == '+') {
            nrzs[i] = 0;
        } else if (nrzsIn[i] == '-') {
            nrzs[i] = 1;
        }
    }
    int binaryNum[512];
    // Initialize state with the first bit (should be 1)
    int state = nrzs[0];
    // Convert NRZS to binaryNum
    int k;
    for (k = 0; k < size; k++) {
        binaryNum[k] = state ^ nrzs[k] ^ 1;
        state = nrzs[k];
    }
    // Print the binaryNum array
    //printf("\nBinary values: ");
    for (i = 0; i < size; i++) {
        fprintf(stdout,"%d", binaryNum[i]);
        //printf("%d", binaryNum[i]);
    }

    //free(binaryNum); free(nrzsIn); free(nrzs);
	return 0;
}
//NRZS values: -++--+++++-+++-----+++++-+--+--+-+++--+-++--+++-+++++-+--+--
//Binary values: 101010111100110111101111000100100011010001010110011110001001
