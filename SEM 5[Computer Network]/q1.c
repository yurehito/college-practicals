// Write a C program to show the Stop-and-Wait Algorithm.

#include <stdio.h>

int main()
{
    int n, i;
    int ack;

    printf("Enter the number of frames: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("\nSending Frame %d...", i);

        printf("\nDid Frame %d receive acknowledgement? (1 = Yes, 0 = No): ", i);
        scanf("%d", &ack);

        if(ack == 1)
        {
            printf("Acknowledgement received for Frame %d.\n", i);
        }
        else
        {
            printf("Acknowledgement not received.\n");
            printf("Retransmitting Frame %d...\n", i);

            printf("Acknowledgement received for Frame %d.\n", i);
        }
    }

    printf("\nAll frames transmitted successfully.\n");

    return 0;
}