#include <stdio.h>
#include <math.h>

/*
 * @author Noah Howard
 * @assignment Homework 1
 *
 * @brief
 * Write a program that asks the user for two inputs, a power between 1 and 4 and a base between 20 and 30, and computes
 * the base^power and prints the result to the user.
 */
int main() {
    // Create variables
    float power;
    float base;

    // Read value for power
    printf("Please enter a power between 1 and 4\n");
    scanf("%f", &power);

    // Check that power value is allowed, otherwise terminate
    if(power < 1 || power > 4) {
        printf("You must enter a value between 1 and 4. Terminating.");
        return 0;
    }

    // Read value for base
    printf("Please enter a base between 20 and 30\n");
    scanf("%f", &base);

    // Check that base value is allowed, otherwise terminate
    if(base < 20 || base > 30) {
        printf("You must enter a value between 20 and 30. Terminating.");
        return 0;
    }

    // Print result to user
    printf("\n\nResult: %f", pow(base, power));

    return 0;
}