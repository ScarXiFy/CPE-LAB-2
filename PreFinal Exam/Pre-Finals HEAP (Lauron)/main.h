#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define MAX_NODES 100

typedef struct {
    char word[4];
    int weight;
} Node;

Node maxHeap[MAX_NODES];
Node minHeap[MAX_NODES];

int maxHeapSize;
int minHeapSize;

void addToMaxHeap(Node newNode);
void addtoMinHeap(Node newNode);
void addNode();
void deleteNode();
void showNodes();
void heapifyMax(int i);
void heapifyMin(int i);


#endif // MAIN_H_INCLUDED
