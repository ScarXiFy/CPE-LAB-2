#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define MAX_EDGES 26

// Node Structure
typedef struct {
    char source;
    char destination;
    int distance;
} Edge;

// Main Function Prototypes
void showAdjacencyMatrix(char str[]);
void showAdjacencyList(char str[]);
void showAllPaths(char str[]);
void showCritPath(char str[]);

// Extra Function Prototypes
void parseInputString(char str[], Edge edges[], int *numEdges);
void findAllPathsUtil(int u, int d, int visited[], int path[], int pathIndex, int *pathCount, Edge edges[], int numEdges);
void findLongestPathUtil(int u, int d, int visited[], int path[], int pathIndex, int *maxDistance, int *maxPath, Edge edges[], int numEdges);
void findAllPaths(char str[]);

#endif // MAIN_H_INCLUDED
