/*
============================================================================
FILE        : sum.c
AUTHOR      : LAURON, JOHN ENRICO D.
DESCRIPTION : brief description of content/purpose of the file
COPYRIGHT   : 03/18/2024
REVISION HISTORY
Date:               By: 	        Description:
============================================================================
*/
#include "sum.h"

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
void printSumSeriesNonRecursive(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
        printf("%d ", sum);
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
int sumRecursive(int n) {
    if (n == 0) return 0;
    return n + sumRecursive(n - 1);
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
void printSumSeriesRecursive(int n) {
    for (int i = 1; i <= n; ++i) {
        printf("%d ", sumRecursive(i));
    }
    printf("\n");
}
