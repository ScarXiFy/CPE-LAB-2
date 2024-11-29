#include <stdio.h>
#include "main.h"

long long int factorial_iterative(double number) {
    long long int result = 1;
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}

long long int factorial_recursive(double number) {
    if (number == 0) {
        return 1;
    } else {
        return number * factorial_recursive(number - 1);
    }
}
