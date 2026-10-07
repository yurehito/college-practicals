#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TOTAL_FRAMES 5
#define TIMEOUT 2 

int receive_ack() {
    return rand() % 10 < 7;
}

int main() {
    int frame = 1;
    int ack_received;
    
       srand(time(NULL)); 
    
    printf("--- Stop and Wait Protocol Simulation ---\n\n");
    
    while (frame <= TOTAL_FRAMES) {
        printf("[SENDER]  Sending Frame %d...\n", frame);
        
       
        sleep(TIMEOUT); 
        
        ack_received = receive_ack();
        
        if (ack_received) {
            printf("[RECEIVER] Frame %d received successfully.\n", frame);
            printf("[SENDER]   ACK received for Frame %d.\n\n", frame);
            frame++; 
        } else {
            printf("[TIMEOUT]  No ACK received for Frame %d. Resending...\n\n", frame);
           
        }
    }
    
    printf("All %d frames sent and acknowledged successfully.\n", TOTAL_FRAMES);
    return 0;
}