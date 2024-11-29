/*
============================================================================
FILE        : main.c
AUTHOR      : LAURON, JOHN ENRICO D.
DESCRIPTION : A C Program that solve the following mathematical problems using non-recursive (iterative) and recursive functions.
COPYRIGHT   : 03/18/2024
REVISION HISTORY
Date:               By: 	        Description:
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"
#include "fibonacci.h"
#include "sum.h"

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("\nFactorial series using non-recursive function:\n");
    printFactorialSeriesNonRecursive(n);

    printf("\nFactorial series using recursive function:\n");
    printFactorialSeriesRecursive(n);

    printf("\nFibonacci series using non-recursive function:\n");
    printFibonacciSeriesNonRecursive(n);

    printf("\nFibonacci series using recursive function:\n");
    printFibonacciSeriesRecursive(n);

    printf("\nSum series using non-recursive function:\n");
    printSumSeriesNonRecursive(n);

    printf("\nSum series using recursive function:\n");
    printSumSeriesRecursive(n);

    return 0;
}
