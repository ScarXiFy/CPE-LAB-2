#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "main.h"


/*void createNode(*Node, char userInput)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL) {
        printf("Memory allocation failed.\n");
    }

    printf("Input an equation: ");
    scanf(" %[^\n]", userInput);

}*/

void expressionTree(char userInput[])
{
    printf("\nExpression Tree: %s\n",  userInput);
}

int evaluateExpression(int x, int y, int z, char userInput)
{
    printf("\nInput the value of x = ");
    scanf(" %d", &x);
    printf("\nInput the value of y = ");
    scanf(" %d", &y);

    for (int i = 0; i < userInput; i++)
    {

    }

    z = 8 * x + 4 * y - 28;

    printf("\nz = %d", z);
}
