#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void showCritPath(char str[]) {
    Edge edges[MAX_EDGES];
    int numEdges = 0;

    parseInputString(str, edges, &numEdges);

    int visited[MAX_EDGES] = {0};
    int path[MAX_EDGES];
    int maxDistance = 0;
    int maxPath[MAX_EDGES];

    findLongestPathUtil(0, MAX_EDGES - 1, visited, path, 0, &maxDistance, maxPath, edges, numEdges);

    printf("\nCritical Path: ");
    int totalDistance = 0;
    for (int i = 0; i < MAX_EDGES; i++) {
        if (strchr(str, 'A' + i) != NULL) {
            if (maxPath[i] == MAX_EDGES - 1) {
                printf("%c = %d\n", 'A' + maxPath[i], totalDistance);
                break;
            }
            printf("%c > ", 'A' + maxPath[i]);
            for (int j = 0; j < numEdges; j++) {
                if (edges[j].source == 'A' + maxPath[i] && edges[j].destination == 'A' + maxPath[i + 1]) {
                    totalDistance += edges[j].distance;
                    break;
                }
            }
        }
    }
}
