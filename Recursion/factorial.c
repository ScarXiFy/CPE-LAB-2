/*
============================================================================
FILE        : factorial.c
AUTHOR      : LAURON, JOHN ENRICO D.
DESCRIPTION : brief description of content/purpose of the file
COPYRIGHT   : 03/18/2024
REVISION HISTORY
Date:               By: 	        Description:
============================================================================
*/
#include "factorial.h"

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
int factorialNonRecursive(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
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
int factorialRecursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorialRecursive(n - 1);
    }
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
void printFactorialSeriesNonRecursive(int n) {
    for (int i = 1; i <= n; ++i) {
        printf("%d ", factorialNonRecursive(i));
    }
    printf("\n");
}

void printFactorialSeriesRecursive(int n) {
    for (int i = 1; i <= n; ++i) {
        printf("%d ", factorialRecursive(i));
    }
    printf("\n");
}
