#include <stdio.h>
#include "main.h"

long long int fibonacci_iterative(double number) {
    long long int a = 0, b = 1, c;
    if (number == 0)
        return a;
    for (int i = 2; i <= number; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

long long int fibonacci_recursive(double number) {
    if (number <= 1) {
        return number;
    } else {
        return fibonacci_recursive(number - 1) + fibonacci_recursive(number - 2);
    }
}
