#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "queueDLL.h"

void show(Queue* queue)
{
    if(queue->front == NULL) {
        printf("\n\n\tQueue is currently empty.\n");
    } else {
        Node* current = queue->front;
        printf("LN\tFN\tMN\tPN\tEA\n");
        printf("=====================================================================================\n");
        while(current != NULL) {
            printf("\n%-10s%-10s%-10s%-10s%-10s\n", current->lastName, current->firstName, current->middleName, current->mobileNumber, current->emailAddress);
            current = current->next;
        }
    }
}
