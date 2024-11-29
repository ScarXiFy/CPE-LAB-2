#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "main.h"

int main() {
    char inputString[256];

    printf("Input a string: ");
    scanf("%s", inputString);

    printf("\n");
    showAdjMatrix(inputString);
    printf("\n...");
    getche();

    printf("\n");
    showAdjList(inputString);
    printf("\n...");
    getche();


    printf("\n");
    findAllPaths(inputString);
    printf("\n...");
    getche();


    printf("\n");
    showCritPath(inputString);
    printf("\n");
    getche();

    return 0;
}
