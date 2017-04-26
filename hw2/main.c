#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
 * @author Noah Howard
 * @assignment Homework 2
 *
 * @brief
 * This program accepts any non negative base 10 integer number and a base that is either 2, 3, 4, 8, or 16. It then
 * uses the quotient remainder method to convert the base 10 number to the new base.
 */

char* convertToBaseChar(int number) {
    // Converts a certain number to the character of it's base (changes numbers to letters in base 16)
    char* toReturn = (char*)malloc(13 * sizeof(char));
    const char* letterValues[6] = {"A", "B", "C", "D", "E", "F"};
    if(number < 10) {
        sprintf(toReturn, "%d", number);
    } else {
        sprintf(toReturn, letterValues[number - 10]);
    }

    return toReturn;
}

char* convertToBase(int number, int base) {
    // Converts a given number to it's new base using the quotient remainder method
    // Setup variables to store calculations in
    int remainders[100];
    int nextToDivide = number;
    int count = 0;
    char* finalValue = (char*)malloc(13 * sizeof(char));

    do {
        // Loop through and do the division, pushing the remainders into an array
        remainders[count] = nextToDivide % base;
        nextToDivide = nextToDivide / base;
        count += 1;
    } while(nextToDivide >= base);
    // Put the last number into the final value char first
    strcat(finalValue, convertToBaseChar(nextToDivide));

    // Put each remainder into the final value char
    for(; count > 0; count--) {
        strcat(finalValue, convertToBaseChar(remainders[count - 1]));
    }

    return finalValue;
}

int main() {
    int number = -5;
    int base = -5;

    // Loop until the user enters -1
    do {
        printf("Please enter a number to convert. It must be greater than 0. If you enter a -1, the program will end.\n");
        // Get the number that the user would like to convert
        do {
            scanf("%d", &number);
            if(number == -1) {
                break;
            }
            if (number <= 0) {
                printf("Please enter a number to convert. It must be greater than 0.\n");
            }
        } while (number <= 0);

        if(number == -1) {
            break;
        }

        // Get the base that the user wants to convert the number to
        printf("Please enter a base to convert to. It must be 2, 3, 4, 8, or 16..\n");
        do {
            scanf("%d", &base);
            if (!(base == 2 || base == 3 || base == 4 || base == 8 || base == 16)) {
                printf("Please enter a base to convert to. It must be 2, 3, 4, 8, or 16..\n");
            }
        } while (!(base == 2 || base == 3 || base == 4 || base == 8 || base == 16));

        // Print out the number in it's new base and go again
        printf("%s\n", convertToBase(number, base));
    } while(number != -1);

    return 0;
}