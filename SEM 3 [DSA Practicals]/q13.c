// Question 13:
// Write a program to implement queue using array. Add new elements to the queue and
// remove elements from the queue represented by array. Check whether the queue is full or empty.

#include <stdio.h>
#define MAXQ 100

int main() {
    int q[MAXQ], front = 0, rear = 0, choice, x;
    while (1) {
        printf("1.enqueue 2.dequeue 3.display 4.exit: "); if(!(scanf("%d",&choice))) break;
        if (choice == 1) {
            if (rear - front == MAXQ) { printf("Queue full\n"); continue; }
            printf("Value: "); scanf("%d",&x);
            q[rear++ % MAXQ] = x;
        } else if (choice == 2) {
            if (rear == front) { printf("Queue empty\n"); continue; }
            printf("Dequeued %d\n", q[front++ % MAXQ]);
        } else if (choice == 3) {
            if (rear == front) { printf("Queue empty\n"); continue; }
            for (int i = front; i < rear; i++) printf("%d ", q[i % MAXQ]);
            printf("\n");
        } else break;
    }
    return 0;
}
