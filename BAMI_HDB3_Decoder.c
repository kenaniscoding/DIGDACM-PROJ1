#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void decode(char *bamiInput, int inputLength)
{
    char oneChar[(inputLength / 2)]; // one char representation per bit
    int index = 0;
    char decoded[inputLength / 2];
    int zerosCount = 0;
    bool prevVoltage = false; // false for - true for +
    for (int i = 0; i < sizeof(oneChar); i++) // turn "++" into "+"
    {
        oneChar[i] = bamiInput[index];
        index += 2;
    }


    for (int i = 0; i < sizeof(oneChar); i++)
    {

        if (oneChar[i] == '+')
        {
            if (prevVoltage == false)
            {
                decoded[i] = '1';
            }
            else if (prevVoltage == true)
            {
                if (zerosCount == 2)
                {
                    decoded[i] = '0';
                    decoded[i - 3] = '0';
                }
                else if (zerosCount == 3)
                {
                    decoded[i] = '0';
                }
            }

            zerosCount = 0;
            prevVoltage = true;
        }
        else if (oneChar[i] == '-')
        {

            if (prevVoltage == true)
            {
                decoded[i] = '1';
            }
            else if (prevVoltage == false)
            {
                if (zerosCount == 2)
                {
                    decoded[i] = '0';
                    decoded[i - 3] = '0';
                }
                else if (zerosCount == 3)
                {
                    decoded[i] = '0';
                }
            }
            zerosCount = 0;
            prevVoltage = false;
        }
        else if (oneChar[i] == '0')
        {
            zerosCount++;
            decoded[i] = '0';
        }
        else if (oneChar[i] == '\0' || oneChar[i] == ' ')
        {
            decoded[i] = ' ';
        }
    }

    for (int i = 0; i < sizeof(decoded); i++)
    {
        fprintf(stdout,"%c", decoded[i]);
    }
   
}

int main()
{
    char input[512]; 
    for(int i = 0; i < sizeof(input); i++){
         scanf("%c",&input[i]);
    }
    
    decode(input, sizeof(input));
    return 0;
}