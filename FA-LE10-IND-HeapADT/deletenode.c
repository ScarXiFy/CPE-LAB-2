#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "main.h"

void deleteNode(Node* heap[], int* size) {
    if (*size == 0) {
        printf("Heap is empty\n");
        return;
    }
    free(heap[0]);
    heap[0] = heap[*size - 1];
    (*size)--;
    printf("Heap after deletion:\n");
    printHeapTree(heap, *size);
    printf("\nPress SPACE BAR to heapify down...");
    while (_getch() != ' ') {}
    heapifyDown(heap, *size, 0);
    printf("\nHeap after heapify down:\n");
    printHeapTree(heap, *size);
}
