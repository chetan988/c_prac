#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int main()
{
    struct queue *q = createqueue(5);
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    printqueue(q);
    printf("dequeue : %d\n",dequeue(q));
    printf("dequeue : %d\n",dequeue(q));
    printqueue(q);
    enqueue(q,50);
    enqueue(q,60);
    printqueue(q);
    printf("dequeue : %d\n",dequeue(q));
    printf("dequeue : %d\n",dequeue(q));
    printf("dequeue : %d\n",dequeue(q));
    printf("dequeue : %d\n",dequeue(q));
    deletequeue(q);
}
