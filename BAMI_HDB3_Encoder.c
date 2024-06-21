#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void toHDB3(char* rawInput, int inputLength) {
    int zerosCount= 0;
    int onesCount = 0;
    bool prevVoltage = false;
    char output[inputLength];
    char finalOutput[inputLength*2]; //double characters
    int index = 0;

    for(int i = 0; i < inputLength; i++){
        if(rawInput[i] == '1'){
            onesCount++;
            zerosCount = 0;

            if (prevVoltage == true){
                output[i] = '-';
                prevVoltage =false;
                
            }else {
                output[i] = '+';
                prevVoltage = true;
            }
            
        }else if (rawInput[i] == '0'){
                zerosCount++;
                
                if (zerosCount < 4)
                {
                    output[i] = '0';
                }
                else if (zerosCount ==  4){
                   if (onesCount % 2 ==0 && prevVoltage == false) //even-negative t
                   {
                    output[i] = '+';
                    output[i-3] = '+';
                    prevVoltage = true;
                    onesCount =0;
                    zerosCount = 0;
                   }
                   else if (onesCount % 2 ==0 && prevVoltage == true)  // even-positive t
                   {
                    output[i] = '-';
                    output[i-3] = '-';
                    prevVoltage = false;
                    onesCount =0;
                    zerosCount = 0;
                   }
                   else if (onesCount % 2 !=0 && prevVoltage == false)  // odd-negative t
                   {
                    output[i] = '-';
                    prevVoltage = false;
                    onesCount =0;
                    zerosCount = 0;
                   }
                    else if (onesCount % 2 !=0 && prevVoltage == true)  // odd-positive t
                   {
                    output[i] = '+';
                    prevVoltage = true;
                    onesCount =0;
                    zerosCount = 0;
                   }
                } 
            } else if (rawInput[i] == '\0')
            {
                output[i] = ' ';
            }
              
    }
    for (int i = 0; i < sizeof(output); i++)
    {
        finalOutput[index++] = output[i];
        finalOutput[index++] = output[i];
    }
    for (int i = 0; i < sizeof(finalOutput); i++){
        printf("%c",finalOutput[i]);
    }
    
}

int main() {
    char input[256];
    for(int i = 0; i < sizeof(input); i++){
         scanf("%c",&input[i]);
    }
    toHDB3(input, sizeof(input));
    return 0;
}