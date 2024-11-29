#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void parseInputString(char str[], Edge edges[], int *numEdges) {
    int i = 0;
    *numEdges = 0;

    while (str[i] != '!') {
        if (str[i] >= 'A' && str[i] <= 'Z' && str[i + 1] >= 'A' && str[i + 1] <= 'Z' && str[i + 2] >= '0' && str[i + 3] >= '0') {
            edges[*numEdges].source = str[i];
            edges[*numEdges].destination = str[i + 1];
            edges[*numEdges].distance = (str[i + 2] - '0') * 10 + (str[i + 3] - '0');
            (*numEdges)++;
            i += 4;
        } else {
            printf("Invalid input format!\n");
            exit(1);
        }
        if (str[i] == ',') {
            i++;
        } else if (str[i] != '!') {
            printf("Invalid input format!\n");
            exit(1);
        }
    }
}

void findAllPathsUtil(int u, int d, int visited[], int path[], int pathIndex, int *pathCount, Edge edges[], int numEdges) {
    visited[u] = 1;
    path[pathIndex] = u;

    if (u == d) {
        (*pathCount)++;
        printf("Path %d: ", *pathCount);
        for (int i = 0; i < pathIndex; i++) {
            printf("%c -> ", 'A' + path[i]);
        }
        printf("%c", 'A' + path[pathIndex]);
        int totalDistance = 0;
        for (int i = 0; i < pathIndex; i++) {
            for (int j = 0; j < numEdges; j++) {
                if (edges[j].source == 'A' + path[i] && edges[j].destination == 'A' + path[i + 1]) {
                    totalDistance += edges[j].distance;
                    break;
                }
            }
        }
        printf(" = %d\n", totalDistance);
    } else {
        for (int i = 0; i < MAX_EDGES; i++) {
            if (!visited[i]) {
                for (int j = 0; j < numEdges; j++) {
                    if (edges[j].source == 'A' + u && edges[j].destination == 'A' + i) {
                        findAllPathsUtil(i, d, visited, path, pathIndex + 1, pathCount, edges, numEdges);
                        break;
                    }
                }
            }
        }
    }

    visited[u] = 0;
}

void findLongestPathUtil(int u, int d, int visited[], int path[], int pathIndex, int *maxDistance, int *maxPath, Edge edges[], int numEdges) {
    visited[u] = 1;
    path[pathIndex] = u;

    if (u == d) {
        int totalDistance = 0;
        for (int i = 0; i < pathIndex; i++) {
            for (int j = 0; j < numEdges; j++) {
                if (edges[j].source == 'A' + path[i] && edges[j].destination == 'A' + path[i + 1]) {
                    totalDistance += edges[j].distance;
                    break;
                }
            }
        }
        if (totalDistance > *maxDistance) {
            *maxDistance = totalDistance;
            memcpy(maxPath, path, (pathIndex + 1) * sizeof(int));
        }
    } else {
        for (int i = 0; i < MAX_EDGES; i++) {
            if (!visited[i]) {
                for (int j = 0; j < numEdges; j++) {
                    if (edges[j].source == 'A' + u && edges[j].destination == 'A' + i) {
                        findLongestPathUtil(i, d, visited, path, pathIndex + 1, maxDistance, maxPath, edges, numEdges);
                        break;
                    }
                }
            }
        }
    }

    visited[u] = 0;
}



