#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main.h"

void heapifyMax(int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < maxHeapSize && maxHeap[left].weight > maxHeap[largest].weight) {
    largest = left;
  }
  if (right < maxHeapSize && maxHeap[right].weight > maxHeap[largest].weight) {
    largest = right;
  }

  if (largest != i) {
    Node temp = maxHeap[i];
    maxHeap[i] = maxHeap[largest];
    maxHeap[largest] = temp;
    heapifyMax(largest);
  }
}

void heapifyMin(int i) {
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < minHeapSize && minHeap[left].weight < minHeap[smallest].weight) {
    smallest = left;
  }
  if (right < minHeapSize && minHeap[right].weight < minHeap[smallest].weight) {
    smallest = right;
  }

  if (smallest != i) {
    Node temp = minHeap[i];
    minHeap[i] = minHeap[smallest];
    minHeap[smallest] = temp;
    heapifyMin(smallest);
  }
}

void addToMaxHeap(Node newNode) {
    int i = maxHeapSize;
    maxHeap[i] = newNode;
    maxHeapSize++;
    while (i > 0 && maxHeap[(i - 1) / 2].weight < maxHeap[i].weight) {
        Node temp = maxHeap[i];
        maxHeap[i] = maxHeap[(i - 1) / 2];
        maxHeap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void addToMinHeap(Node newNode) {
    int i = minHeapSize;
    minHeap[i] = newNode;
    minHeapSize++;
    while (i > 0 && minHeap[(i - 1) / 2].weight > minHeap[i].weight) {
        Node temp = minHeap[i];
        minHeap[i] = minHeap[(i - 1) / 2];
        minHeap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}
