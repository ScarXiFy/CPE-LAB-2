#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void showAdjMatrix(char str[]) {
    Edge edges[MAX_EDGES];
    int numEdges = 0;
    int i, j;
    int adjacencyMatrix[MAX_EDGES][MAX_EDGES] = {0};

    parseInputString(str, edges, &numEdges);

    for (i = 0; i < numEdges; i++) {
        int sourceIndex = edges[i].source - 'A';
        int destIndex = edges[i].destination - 'A';
        adjacencyMatrix[sourceIndex][destIndex] = edges[i].distance;
    }


    printf("\nAdjacency Matrix:\n");
    printf("  ");
    for (i = 0; i < MAX_EDGES; i++) {
        if (strchr(str, 'A' + i) != NULL) {
            printf("%c  ", 'A' + i);
        }
    }
    printf("\n");
    for (i = 0; i < MAX_EDGES; i++) {
        if (strchr(str, 'A' + i) != NULL) {
            printf("%c ", 'A' + i);
            for (j = 0; j < MAX_EDGES; j++) {
                if (strchr(str, 'A' + j) != NULL) {
                    printf("%02d ", adjacencyMatrix[i][j]);
                }
            }
            printf("\n");
        }
    }
}
