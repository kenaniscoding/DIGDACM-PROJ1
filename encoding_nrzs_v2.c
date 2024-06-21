#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char binaryIn[32000]; // Assuming input won't exceed n characters
    //printf("Enter binary values: ");
    fgets(binaryIn, sizeof(binaryIn), stdin); // Read input from stdin
    int size = strlen(binaryIn) - 1;
    //printf("\nsize=%d\n",size);
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
    // Print the binaryNum array
    int binaryNum[1000]; // Array to store binary digits
    //printf("\nBinary input (reversed): ");
    for (i = size - 1, j = 0; i >= 0; i--, j++) {
        binaryNum[j] = binary[i];
        printf("%d", binaryNum[j]);
    }
    //printf("\nSize=%d\n",size);
    // NRZS
	int NRZS[size]; // Create an array for NRZS
    int state = binaryNum[0]; // Initialize state with the first bit (should be 1)
    int k=size-1;
    //printf("\nsizeofbinaryNum[size]=%d\n",sizeof(binaryNum));
    //printf("sizeofbinaryNum=%d\n",sizeof(binaryNum[size]));
    //printf("\nPreNRZ: ");
    for (k; k >= 0; k--) {
        state ^= binaryNum[k] ^ 1; // XOR operation to compute NRZS
        NRZS[k] = state; // Store the result in NRZS array
        //printf("%d",NRZS[k]);
    }
    // Print the NRZS array
    //printf("\nNRZS: ");
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
    	printf("%c",nrzs[m]);
	}
    

    return 0;
}
//Enter a hexadecimal value: abc
//Decimal value: 2748
//Binary representation: 101010111100
//Size=12
//PreNRZ: 011001111101
//NRZS: +--++-----+-
