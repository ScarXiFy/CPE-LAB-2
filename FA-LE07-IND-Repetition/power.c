#include <stdio.h>
#include "main.h"

long long int power_iterative(double base, double exponent) {
    long long int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

long long int power_recursive(double base, double exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * power_recursive(base, exponent - 1);
    }
}
