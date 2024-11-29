#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "queueDLL.h"

void dequeue(Queue* queue)
{
    if(queue->front == NULL) {
        printf("\n\n\tQueue is currently empty. Dequeue failed.\n");
    } else {
        Node* temp = queue->front;
        if(queue->front == queue->back) {
            queue->front = NULL;
            queue->back = NULL;
        } else {
            queue->front = queue->front->next;
            queue->front->prev = NULL;
        }

        free(temp);
        printf("\n\n\tItem Removed!\n");
    }
}
