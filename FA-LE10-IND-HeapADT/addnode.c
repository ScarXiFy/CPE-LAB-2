#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "main.h"

void addNode(Node* heap[], int* size, int value) {
    Node* newNode = createNode(value);
    heap[*size] = newNode;
    (*size)++;
    printf("Heap after addition:\n");
    printHeapTree(heap, *size);
    printf("\nPress SPACE BAR to heapify up...");
    while (_getch() != ' ') {}
    heapifyUp(heap, *size - 1);
    printf("\nHeap after heapify up:\n");
    printHeapTree(heap, *size);
}
