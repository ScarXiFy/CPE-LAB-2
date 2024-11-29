#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main.h"

void deleteNode() {
  if (maxHeapSize == 0) {
    printf("Heap is currently empty.\n");
    return;
  }

  printf("Deleting from Max Heap: %s %d\n", maxHeap[0].word, maxHeap[0].weight);
  maxHeap[0] = maxHeap[maxHeapSize - 1];
  maxHeapSize--;
  heapifyMax(0);

  printf("Deleting from Min Heap: %s %d\n", minHeap[0].word, minHeap[0].weight);
  minHeap[0] = minHeap[minHeapSize - 1];
  minHeapSize--;
  heapifyMin(0);
}
