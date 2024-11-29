#include <stdio.h>
#include <stdlib.h>
#include "main.h"

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printNodes(Node* heap[], int size) {
    printf("Heap: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]->data);
    }
    printf("\n");
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(Node* heap[], int index) {
    if (index == 0)
        return;
    int parentIndex = (index - 1) / 2;
    if (heap[parentIndex]->data > heap[index]->data) {
        swap(&heap[parentIndex]->data, &heap[index]->data);
        heapifyUp(heap, parentIndex);
    }
}

void heapifyDown(Node* heap[], int size, int index) {
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int smallest = index;

    if (leftChildIndex < size && heap[leftChildIndex]->data < heap[smallest]->data)
        smallest = leftChildIndex;

    if (rightChildIndex < size && heap[rightChildIndex]->data < heap[smallest]->data)
        smallest = rightChildIndex;

    if (smallest != index) {
        swap(&heap[index]->data, &heap[smallest]->data);
        heapifyDown(heap, size, smallest);
    }
}
