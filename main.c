#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include <unistd.h>

const int SLEEP_DURATION = 3;

/**
 * @brief Perform matrix operations on two square matrices.
 *
 * This function performs a matrix operation by taking the dimension of the square matrices
 * and a function pointer to the operation function.
 *
 * @param dimension  The dimension of the square matrices.
 * @param operation  The function pointer to the operation function.
 */
void perform_multi_matrix_operation(int dimension, void (*operation)(const Matrix *, const Matrix *));

/**
 * @brief Performs a single matrix operation based on the given choice.
 *
 * @param choice The choice of the matrix operation.
 *               - 3: Find determinant of a matrix.
 *               - 4: Transpose a matrix.
 */
void perform_single_matrix_operation(int choice);

void perform_multi_matrix_operation(int dimension, void (*operation)(const Matrix *, const Matrix *))
{
    Matrix matrix_one;
    Matrix matrix_two;

    printf("What is the dimension of the square matrices?\n");
    scanf("%d", &dimension);

    printf("\n--------------\n");
    printf("Please enter the values for the first matrix.\n");
    create_matrix(&matrix_one, dimension);
    populate_matrix(&matrix_one);
    printf("\nThe first matrix is:\n");
    display_matrix(&matrix_one);

    printf("\n--------------\n");
    printf("Please enter the values for the second matrix.\n");
    create_matrix(&matrix_two, dimension);
    populate_matrix(&matrix_two);
    printf("\nThe second matrix is:\n");
    display_matrix(&matrix_two);

    printf("\n--------------\n");
    printf("Will now perform calculation...\n");
    sleep(SLEEP_DURATION);

    printf("\n--------------\n");
    printf("The result is:\n");
    operation(&matrix_one, &matrix_two);

    free_matrix(&matrix_one);
    free_matrix(&matrix_two);
}

void perform_single_matrix_operation(int choice)
{
    Matrix matrix;
    int dimension;

    printf("What is the dimension of the square matrices?\n");
    scanf("%d", &dimension);

    printf("\n--------------\n");
    printf("Please enter the values for the matrix.\n");
    create_matrix(&matrix, dimension);
    populate_matrix(&matrix);
    printf("\nThe matrix is:\n");
    display_matrix(&matrix);

    printf("\n--------------\n");
    printf("Will now perform calculation...\n");
    sleep(SLEEP_DURATION);

    printf("\n--------------\n");

    switch (choice) {
        case 3: {
            printf("The determinant is:\n");
            int determinant = find_determinant(&matrix);
            printf("%d\n", determinant);
            break;
        }
        case 4: {
            printf("The transpose is:\n");
            Matrix matrix_T;
            matrix_transpose(&matrix, &matrix_T);
            display_matrix(&matrix_T);
            break;
        }
    }

    free_matrix(&matrix);
}

/**
 * @brief Main function to perform matrix operations.
 *
 * This function prompts the user to choose a matrix operation and performs the selected operation
 * based on the user's input.
 *
 * @return The exit status of the program.
 */
int main()
{
    int choice = 0;
    int dimension = 0;

    printf("What operation would you like to perform?\n");
    printf("1. Matrix addition/subtraction\n");
    printf("2. Matrix multiplication\n");
    printf("3. Find determinant of a matrix\n");
    printf("4. Find matrix transpose\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            perform_multi_matrix_operation(dimension, matrix_addition);
            break;

        case 2:
            perform_multi_matrix_operation(dimension, matrix_multiplication);
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