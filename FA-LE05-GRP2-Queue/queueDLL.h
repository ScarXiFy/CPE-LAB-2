// Lauron - queueDLL.c, queueDLL.h, enqueue.c, main.c
// Requirme - dequeue.c, show.c

#ifndef QUEUEDLL_H_INCLUDED
#define QUEUEDLL_H_INCLUDED

typedef struct Node {
    char firstName[100];
    char middleName[100];
    char lastName[100];
    char mobileNumber[100];
    char emailAddress[100];
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {

    Node* front;
    Node* back;

} Queue;

void initialize(Queue* queue);
void enqueue(Queue* queue, const char* firstName, const char* middleName, const char* lastName, const char* mobileNumber, const char* emailAddress);
void dequeue(Queue* queue);
void show(Queue* queue);

#endif // QUEUEDLL_H_INCLUDED
