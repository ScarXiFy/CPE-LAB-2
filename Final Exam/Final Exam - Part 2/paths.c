#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void findAllPaths(char str[]) {
    Edge edges[MAX_EDGES];
    int numEdges = 0;

    parseInputString(str, edges, &numEdges);

    int visited[MAX_EDGES] = {0};
    int path[MAX_EDGES];
    int pathCount = 0;

    printf("\nAll Paths:\n");
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
