#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main.h"

void showNodes() {
    if (maxHeapSize == 0) {
    printf("Heap is currently empty.\n");
    return;
  }

    printf("\nMax Heap: ");
    for (int i = 0; i < maxHeapSize; i++) {
        printf("%s 0%d ", maxHeap[i].word, maxHeap[i].weight);
    }
    printf("\n");

    printf("\nMin Heap: ");
    for (int i = 0; i < minHeapSize; i++) {
        printf("%s 0%d ", minHeap[i].word, minHeap[i].weight);
    }
    printf("\n");
}
