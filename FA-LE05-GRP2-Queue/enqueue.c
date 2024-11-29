#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "queueDLL.h"

void enqueue(Queue* queue, const char* firstName, const char* middleName, const char* lastName, const char* mobileNumber, const char* emailAddress)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode != NULL) {
        if(queue->front == NULL) {
            queue->front = newNode;
            queue->back = newNode;
        } else {
            newNode->prev = queue->back;
            queue->back->next = newNode;
            queue->back = newNode;
        }
        printf("\nInput First Name: ");
        scanf(" %[^\n]s", newNode->firstName);
        printf("\nInput Middle Name: ");
        scanf(" %[^\n]s", newNode->middleName);
        printf("\nInput Last Name: ");
        scanf(" %[^\n]s", newNode->lastName);
        printf("\nInput Mobile No.: ");
        scanf(" %[^\n]s", newNode->mobileNumber);
        printf("\nInput Email Address: ");
        scanf(" %[^\n]s", newNode->emailAddress);
    } else {
        printf("\n\n\tFailed to enqueue. Memory allocation failed.\n");
    }

    newNode->next = NULL;
    newNode->prev = NULL;

    printf("\n\n\tEnqueued successfully!\n");

}
