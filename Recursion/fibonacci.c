/*
============================================================================
FILE        : fibonacci.c
AUTHOR      : LAURON, JOHN ENRICO D.
DESCRIPTION : brief description of content/purpose of the file
COPYRIGHT   : 03/18/2024
REVISION HISTORY
Date:               By: 	        Description:
============================================================================
*/
#include "fibonacci.h"

/*
============================================================================
FUNCTION    : function name
DESCRIPTION : brief description of the what the function does
ARGUMENTS   : (list all parameters pass in the function)
				dataType variableName - brief description			   
				dataType variableName - brief description
				.
				.
				.
				dataType variableName - brief description 
RETURNS     : (no return) 	void
 		       (with return)dataType - brief description
===========================================================================
*/
void printFibonacciSeriesNonRecursive(int n) {
    int a = 1, b = 1, c;
    for (int i = 0; i < n; ++i) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

/*
============================================================================
FUNCTION    : function name
DESCRIPTION : brief description of the what the function does
ARGUMENTS   : (list all parameters pass in the function)
				dataType variableName - brief description			   
				dataType variableName - brief description
				.
				.
				.
				dataType variableName - brief description 
RETURNS     : (no return) 	void
 		       (with return)dataType - brief description
===========================================================================
*/
int fibonacciRecursive(int n) {
    if (n == 0 || n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

/*
============================================================================
FUNCTION    : function name
DESCRIPTION : brief description of the what the function does
ARGUMENTS   : (list all parameters pass in the function)
				dataType variableName - brief description			   
				dataType variableName - brief description
				.
				.
				.
				dataType variableName - brief description 
RETURNS     : (no return) 	void
 		       (with return)dataType - brief description
===========================================================================
*/
void printFibonacciSeriesRecursive(int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", fibonacciRecursive(i));
    }
    printf("\n");
}
