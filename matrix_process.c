#include <unistd.h>
#include <stdio.h>
#include "matrix_process.h"
#include "matrix_operations.h"

const int SLEEP_DURATION = 3;

void perform_multi_matrix_operation(void (*operation)(const Matrix *, const Matrix *))
{
    Matrix matrix_one;
    Matrix matrix_two;
    int dimension;

    perform_shared_matrix_operations(&dimension, &matrix_one);

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

    perform_shared_matrix_operations(&dimension, &matrix);

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

void perform_shared_matrix_operations(int* dimension, const Matrix* matrix_one) {
    printf("What is the dimension of the square matrices?\n");
    scanf("%d", dimension);

    printf("\n--------------\n");
    printf("Please enter the values for the first matrix.\n");
    create_matrix((Matrix*)matrix_one, *dimension);
    populate_matrix((Matrix*)matrix_one);
    printf("\nThe first matrix is:\n");
    display_matrix(matrix_one);
}
