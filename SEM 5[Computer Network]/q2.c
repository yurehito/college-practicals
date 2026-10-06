//Write a C program to show the CRC Algorithm.

#include <stdio.h>
#include <string.h>

void crc(char data[], char divisor[], char remainder[])
{
    int i, j;
    int dataLen = strlen(data);
    int divisorLen = strlen(divisor);

    char temp[100];

    strcpy(temp, data);

    for(i = 0; i <= dataLen - divisorLen; i++)
    {
        if(temp[i] == '1')
        {
            for(j = 0; j < divisorLen; j++)
            {
                if(temp[i + j] == divisor[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    strcpy(remainder, temp + dataLen - divisorLen + 1);
}

int main()
{
    char data[100], divisor[100];
    char appendedData[100];
    char remainder[100];
    char codeword[100];

    int dataLen, divisorLen;

    printf("Enter the data bits: ");
    scanf("%s", data);

    printf("Enter the divisor bits: ");
    scanf("%s", divisor);

    dataLen = strlen(data);
    divisorLen = strlen(divisor);

    strcpy(appendedData, data);

    for(int i = 0; i < divisorLen - 1; i++)
    {
        appendedData[dataLen + i] = '0';
    }

    appendedData[dataLen + divisorLen - 1] = '\0';

    printf("\nData after appending zeros: %s", appendedData);

    crc(appendedData, divisor, remainder);

    printf("\nCRC: %s", remainder);

    strcpy(codeword, data);
    strcat(codeword, remainder);

    printf("\nTransmitted Codeword: %s\n", codeword);

    return 0;
}