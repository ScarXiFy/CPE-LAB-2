#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main.h"

void addNode() {
    char word[4];
    printf("\nInsert value to add: ");
    scanf("%s", word);

    for (int i = 0; i < 3; i++) {
        word[i] = toupper(word[i]);
    }

    int weight = 0;
    for (int i = 0; i < 3; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            weight += word[i] - 'A' + 1;
        } else {
            printf("\n\nInvalid character entered: %c\n", word[i]);
            return;
        }
    }

    Node newNode;
    strcpy(newNode.word, word);
    newNode.weight = weight;

    addToMaxHeap(newNode);
    addToMinHeap(newNode);

    printf("\n%s = 0%d\n", newNode.word, newNode.weight);

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
