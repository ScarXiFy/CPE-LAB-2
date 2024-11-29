#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main() {
    char choice, againChoice;
    int num1, num2, result;
    float dnum1, dnum2, dresult;

    do {
        system("cls");
        printf("CALCULATOR MENU:\n");
        printf("   [A]ddition\n");
        printf("   [S]ubtraction\n");
        printf("   [M]ultiplication\n");
        printf("   [D]ivision\n");
        printf("   [E]xit\n");
        printf("Choice? ");

        scanf(" %c", &choice);

        if (choice == 'A' || choice == 'a') {
            do {
                system ("cls");
                printf("Input First Value: ");
                scanf("%d", &num1);
                printf("Input Second Value: ");
                scanf("%d", &num2);

                result = addNum(num1, num2);
                printf("Sum of %d plus %d is equal to %d\n", num1, num2, result);

                printf("\nAgain [Y/N]? ");
                scanf(" %c", &againChoice);
            } while (againChoice == 'Y' || againChoice == 'y');
        }

        if (choice == 'S' || choice == 's') {
            do {
                system ("cls");
                printf("Input First Value: ");
                scanf("%d", &num1);
                printf("Input Second Value: ");
                scanf("%d", &num2);

                result = subNum(num1, num2);
                printf("Difference of %d minus %d is equal to %d\n", num1, num2, result);

                printf("\nAgain [Y/N]? ");
                scanf(" %c", &againChoice);
            } while (againChoice == 'Y' || againChoice == 'y');
        }

        if (choice == 'M' || choice == 'm') {
            do {
                system ("cls");
                printf("Input First Value: ");
                scanf("%d", &num1);
                printf("Input Second Value: ");
                scanf("%d", &num2);

                result = mulNum(num1, num2);
                printf("Product of %d multiplied by %d is equal to %d\n", num1, num2, result);

                printf("\nAgain [Y/N]? ");
                scanf(" %c", &againChoice);
            } while (againChoice == 'Y' || againChoice == 'y');
        }

        if (choice == 'D' || choice == 'd') {
            do {
                system ("cls");
                printf("Input First Value: ");
                scanf("%f", &dnum1);
                printf("Input Second Value: ");
                scanf("%f", &dnum2);

                dresult = divNum(dnum1, dnum2, dresult);
                printf("Quotient of %.2f divided by %.2f is equal to %.2f\n", dnum1, dnum2, dresult);

                printf("\nAgain [Y/N]? ");
                scanf(" %c", &againChoice);
            } while (againChoice == 'Y' || againChoice == 'y');
        }

    } while (choice != 'E' && choice != 'e');

    return 0;
}

