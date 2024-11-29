#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void showAdjList(char str[]) {
    Edge edges[MAX_EDGES];
    int numEdges = 0;
    int i;

    parseInputString(str, edges, &numEdges);

    printf("\nAdjacency List:\n");
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
