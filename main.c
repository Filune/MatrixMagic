#include <stdlib.h>
#include <stdio.h>
#include "matrix_process.h"
#include "matrix_operations.h"

/**
 * @brief Main function to perform matrix operations.
 *
 * This function prompts the user to choose a matrix operation and performs the selected operation
 * based on the user's input.
 *
 * @return The exit status of the program.
 */
int main(void)
{
    int choice = 0;

    printf("What operation would you like to perform?\n");
    printf("1. Matrix addition/subtraction\n");
    printf("2. Matrix multiplication\n");
    printf("3. Find determinant of a matrix\n");
    printf("4. Find matrix transpose\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            perform_multi_matrix_operation(matrix_addition);
            break;

        case 2:
            perform_multi_matrix_operation(matrix_multiplication);
            break;

        case 3:
            perform_single_matrix_operation(choice);
            break;
        case 4:
            perform_single_matrix_operation(choice);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
