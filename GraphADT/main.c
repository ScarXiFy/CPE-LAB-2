#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX_EDGES 26

typedef struct {
    char source;
    char destination;
    int distance;
} Edge;

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


    printf("Adjacency Matrix:\n");
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

void showAdjList(char str[]) {
    Edge edges[MAX_EDGES];
    int numEdges = 0;
    int i;

    parseInputString(str, edges, &numEdges);

    printf("Adjacency List:\n");
    for (i = 0; i < MAX_EDGES; i++) {
        if (strchr(str, 'A' + i) != NULL) {
            printf("%c -> ", 'A' + i);
            int printed = 0;
            for (int j = 0; j < numEdges; j++) {
                if (edges[j].source == 'A' + i) {
                    if (printed) {
                        printf(" > ");
                    }
                    printf("%c", edges[j].destination);
                    printed = 1;
                }
            }
            printf("\n");
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

void findAllPaths(char str[]) {
    Edge edges[MAX_EDGES];
    int numEdges = 0;

    parseInputString(str, edges, &numEdges);

    int visited[MAX_EDGES] = {0};
    int path[MAX_EDGES];
    int pathCount = 0;

    printf("All Paths:\n");
    for (int i = 0; i < MAX_EDGES; i++) {
        if (strchr(str, 'A' + i) != NULL) {
            for (int j = 0; j < MAX_EDGES; j++) {
                if (strchr(str, 'A' + j) != NULL) {
                    findAllPathsUtil(i, j, visited, path, 0, &pathCount, edges, numEdges);
                    memset(visited, 0, sizeof(visited));
                }
            }
        }
    }
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

void showCritPath(char str[]) {
    Edge edges[MAX_EDGES];
    int numEdges = 0;

    parseInputString(str, edges, &numEdges);

    int visited[MAX_EDGES] = {0};
    int path[MAX_EDGES];
    int maxDistance = 0;
    int maxPath[MAX_EDGES];

    findLongestPathUtil(0, MAX_EDGES - 1, visited, path, 0, &maxDistance, maxPath, edges, numEdges);

    printf("Critical Path: ");
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

void waitForEnter() {
    printf("\n...");
    getch();
    printf("\n");
}

int main() {
    char inputString[100];

    printf("Input a string: ");
    scanf("%s", inputString);

    printf("\n");
    showAdjMatrix(inputString);
    printf("\n");
    waitForEnter();
    printf("\n");
    showAdjList(inputString);
    printf("\n");
    waitForEnter();
    printf("\n");
    findAllPaths(inputString);
    printf("\n");
    waitForEnter();
    printf("\n");
    showCritPath(inputString);
    printf("\n");
    waitForEnter();
    printf("\n");

    return 0;
}
