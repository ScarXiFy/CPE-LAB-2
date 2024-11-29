#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "main.h"

int main()
{
    Node* node;
    int x, y, z;
    char userInput[256];

    printf("Input an equation: ");
    scanf(" %[^\n]", userInput);

    expressionTree(userInput);
    evaluateExpression(x, y, z, userInput);


    return 0;
}
