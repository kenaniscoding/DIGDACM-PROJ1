#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char binaryIn[512]; // Assuming input won't exceed n characters
    //printf("Binary values: ");
    fgets(binaryIn, sizeof(binaryIn), stdin); // Read input from stdin
    int size = strlen(binaryIn) - 1;
    int i;
    int binary[size];
    // Convert '0' to 0 and '1' to 1
    for (i = 0; i < size; i++) {
        if (binaryIn[i] == '0') {
            binary[i] = 0;
        } else if (binaryIn[i] == '1') {
            binary[i] = 1;
        }
    }
    int binaryNum[512]; // Array to store binary digits
    for (int i = size - 1, j = 0; i >= 0; i--, j++) {
        binaryNum[j] = binary[i]; //reverse the array
    }
	int NRZS[size]; // Create an array for NRZS
    int state = binaryNum[0]; // Initialize state with the first bit (should be 1)
    int k=size-1;
    for (k; k >= 0; k--) {
        state ^= binaryNum[k] ^ 1; // XOR operation to compute NRZS
        NRZS[k] = state; // Store the result in NRZS array
    }
    // Print the NRZS array
    //printf("\nNRZS values: ");
    int l=size-1;
    char nrzs[l];
    int m;
    m=0;
    // reverse the order to a new array
    for (l; l >= 0; l--) {
        if(NRZS[l]==1){
        	nrzs[m]='-';
		} else if (NRZS[l]==0){
			nrzs[m]='+';
		}
		m++;
    }
    for (m=0; m<size; m++){
    	fprintf(stdout,"%c",nrzs[m]);
        //printf("%c",nrzs[m]);
	}
    //free(nrzs); free(NRZS); free(binaryNum); free(binary); free(binaryIn);
    return 0;
}
//Binary values: 101010111100110111101111000100100011010001010110011110001001
//NRZS values: -++--+++++-+++-----+++++-+--+--+-+++--+-++--+++-+++++-+--+--