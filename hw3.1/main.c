#include <stdio.h>

/*
 * @author Noah Howard
 * @assignment Homework 3
 *
 * @brief
 * This program takes 3 different integers that are inputted by the user and figures out which value is in the middle.
 * It then sets the other variables to the middle variable value. Pointers are used so that the middle method can set
 * the values for the variables without typical scope rules.
 */


int customFunction(int a, int b) {
    return (a*a) + 2*a*b + (b*b);
}

int baseToThePower(int a, int b) {
    int i, result = 1;
    for (i = 0; i < a; i++) {
        result *= b;
    }
    return result;
}

void runProgram() {
    int a, b;

    printf("NAME: Tony Stark\n\n");
    printf("Please enter the first number (a): ");
    scanf(" %d", &a);

    printf("\n\nPlease enter the second number (b): ");
    scanf(" %d", &b);

    printf("\n\nFollowing are your results:\n\n");
    printf("(1) The result of implementing the customFunction is: %d\n", customFunction(a, b));
    printf("(2) The result of raising %d to the power of %d is: %d\n", b, a, baseToThePower(a, b));
}

int main() {
    runProgram();
}