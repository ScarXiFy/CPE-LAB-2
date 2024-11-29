#include <stdio.h>
#include "main.h"

int main() {
    int choice;
    double base, exponent, number, fib_number;
    char again;

    while (1)
    {
        system("cls");
        printf("MAIN MENU:\n");
        printf("[1] Power\n");
        printf("[2] Factorial\n");
        printf("[3] Fibonacci\n");
        printf("[4] Exit\n");
        printf("Choice? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    system("cls");
                    printf("POWER OPTION:\n");
                    printf("Input base: ");
                    scanf("%lf", &base);
                    printf("Input exponent: ");
                    scanf("%lf", &exponent);
                    printf("Iterative Results: %lld\n", power_iterative(base, exponent));
                    printf("Recursive Results: %lld\n", power_recursive(base, exponent));
                    fflush(stdin);
                    printf("\n\nAgain [Y/N]? ");
                    scanf(" %c", &again);
                } while (again != 'N' && again != 'n');
                break;
            case 2:
                do {
                    system("cls");
                    printf("FACTORIAL OPTION:\n");
                    printf("Input number: ");
                    scanf("%lf", &number);
                    printf("Iterative Results: %lld\n", factorial_iterative(number));
                    printf("Recursive Results: %lld\n", factorial_recursive(number));
                    fflush(stdin);
                    printf("\n\nAgain [Y/N]? ");
                    scanf(" %c", &again);
                } while (again != 'N' && again != 'n');
                break;
            case 3:
                do {
                    system("cls");
                    printf("FIBONACCI OPTION:\n");
                    printf("Input number: ");
                    scanf("%lf", &fib_number);
                    printf("Iterative Results: %lld\n", fibonacci_iterative(fib_number));
                    printf("Recursive Results: %lld\n", fibonacci_recursive(fib_number));
                    fflush(stdin);
                    printf("\n\nAgain [Y/N]? ");
                    scanf(" %c", &again);
                } while (again != 'N' && again != 'n');
                break;
            case 4:
                printf("\nExiting Program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
