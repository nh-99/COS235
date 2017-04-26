#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
 * @author Noah Howard
 * @assignment Homework 3
 *
 * @brief
 * This program takes 3 different integers that are inputted by the user and figures out which value is in the middle.
 * It then sets the other variables to the middle variable value. Pointers are used so that the middle method can set
 * the values for the variables without typical scope rules.
 */


int middle(int *a, int *b, int *c) {
    if((*a < *b && *b < *c) || (*c < *b && *b < *a)) {
        *a = *b;
        *c = *b;
    } else if((*b < *a && *a < *c) || (*c < *a && *a < *b)) {
        *b = *a;
        *c = *a;
    } else if((*b < *c && *c < *a) || (*a < *c && *c < *b)) {
        *a = *c;
        *b = *c;
    }

    return 0;
}

int main() {
    int a, b, c;

    printf("Please enter 3 different integers separated by spaces.\n");
    scanf("%d %d %d", &a, &b, &c);

    middle(&a, &b, &c);

    printf("%d %d %d", a, b, c);

    return 0;
}