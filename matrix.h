#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dimension;
    int* matrix;
} Matrix;

/**
 * @brief Create a matrix.
 *
 * This function creates a matrix with the given dimension and allocates memory for the matrix data.
 *
 * @param matrix    Pointer to the matrix struct.
 * @param dimension The dimension of the matrix.
 */
void create_matrix(Matrix* matrix, int dimension);

/**
 * @brief Populate the matrix with values.
 *
 * This function prompts the user to input values for each element of the matrix.
 *
 * @param matrix    Pointer to the matrix struct.
 */
void populate_matrix(Matrix* matrix);

/**
 * @brief Finds the maximum width of numbers in the matrix.
 *
 * This function calculates the maximum width of numbers in the matrix, which is
 * useful for ensuring neat formatting when displaying the matrix.
 *
 * @param matrix Pointer to the matrix.
 * @param max_width Pointer to an integer that will store the maximum width.
 */
void find_max_width(const Matrix* matrix, int* max_width);

/**
 * @brief Prints a single row of the matrix.
 *
 * This function prints a single row of the matrix, with each element formatted
 * according to the maximum width provided.
 *
 * @param matrix Pointer to the matrix.
 * @param row The index of the row to be printed.
 * @param max_width The maximum width of numbers in the matrix.
 */
void print_matrix_row(const Matrix* matrix, int row, int max_width);

/**
 * @brief Display the matrix.
 *
 * This function displays the elements of the matrix.
 *
 * @param matrix    Pointer to the matrix struct.
 */
void display_matrix(const Matrix* matrix);

/**
 * @brief Perform matrix addition.
 *
 * This function performs matrix addition on two matrices and displays the result.
 *
 * @param matrix_one    Pointer to the first matrix.
 * @param matrix_two    Pointer to the second matrix.
 */
void matrix_addition(const Matrix* matrix_one, const Matrix* matrix_two);

/**
 * @brief Transpose the matrix.
 *
 * This function transposes the given matrix and stores the result in the result_matrix.
 *
 * @param matrix            Pointer to the matrix struct.
 * @param result_matrix     Pointer to the result matrix struct.
 */
void matrix_transpose(const Matrix* matrix, Matrix* result_matrix);

/**
 * @brief Perform matrix multiplication.
 *
 * This function performs matrix multiplication on two matrices and displays the result.
 *
 * @param matrix_one    Pointer to the first matrix.
 * @param matrix_two    Pointer to the second matrix.
 */
void matrix_multiplication(const Matrix* matrix_one, const Matrix* matrix_two);

/**
 * @brief Find the determinant of the matrix.
 *
 * This function calculates the determinant of the given matrix.
 *
 * @param matrix    Pointer to the matrix struct.
 * @return          The determinant of the matrix.
 */
int find_determinant(const Matrix* matrix);

/**
 * @brief Calculate the determinant of a minor matrix.
 *
 * This function calculates the determinant of a minor matrix of the given matrix.
 *
 * @param matrix    Pointer to the matrix struct.
 * @param row       The row index to exclude from the minor matrix.
 * @param col       The column index to exclude from the minor matrix.
 * @return          The determinant of the minor matrix.
 */
int determinant_of_minor(const Matrix* matrix, int row, int col);

/**
 * @brief Free the memory allocated for the matrix.
 *
 * This function frees the memory allocated for the matrix data.
 *
 * @param matrix    Pointer to the matrix struct.
 */
void free_matrix(Matrix* matrix);

#endif

void create_matrix(Matrix* matrix, int dimension) {
    matrix->dimension = dimension;
    matrix->matrix = malloc(dimension * dimension * sizeof(int));
}

void populate_matrix(Matrix* matrix) {
    int value;
    for (int row = 0; row < matrix->dimension; row++) {
        for (int col = 0; col < matrix->dimension; col++) {
            printf("Please input value for row %d, col %d\n", row, col);
            scanf("%d", &value);
            int index = row * matrix->dimension + col;
            matrix->matrix[index] = value;
        }
    }
}

void find_max_width(const Matrix* matrix, int* max_width) {
    for (int i = 0; i < matrix->dimension * matrix->dimension; i++) {
        int num = matrix->matrix[i];
        int width = 0;
        while (num != 0) {
            num /= 10;
            width++;
        }
        if (width > *max_width) {
            *max_width = width;
        }
    }
}

void print_matrix_row(const Matrix* matrix, int row, int max_width) {
    for (int col = 0; col < matrix->dimension; col++) {
        int index = row * matrix->dimension + col;
        printf("%*d ", max_width, matrix->matrix[index]);
    }
    printf("\n");
}

void display_matrix(const Matrix* matrix) {
    int max_width = 0;
    find_max_width(matrix, &max_width);

    for (int row = 0; row < matrix->dimension; row++) {
        print_matrix_row(matrix, row, max_width);
    }
}

void matrix_addition(const Matrix* matrix_one, const Matrix* matrix_two) {
    Matrix result_matrix;
    create_matrix(&result_matrix, matrix_one->dimension);
    for (int i = 0; i < matrix_one->dimension * matrix_one->dimension; i++) {
        result_matrix.matrix[i] = matrix_one->matrix[i] + matrix_two->matrix[i];
    }
    display_matrix(&result_matrix);
}

void matrix_transpose(const Matrix* matrix, Matrix* result_matrix) {
    create_matrix(result_matrix, matrix->dimension);
    for (int row = 0; row < matrix->dimension; row++) {
        for (int col = 0; col < matrix->dimension; col++) {
            int original_index = row * matrix->dimension + col;
            int transpose_index = col * matrix->dimension + row;
            result_matrix->matrix[transpose_index] = matrix->matrix[original_index];
        }
    }
}

void matrix_multiplication(const Matrix* matrix_one, const Matrix* matrix_two) {
    Matrix result_matrix;
    create_matrix(&result_matrix, matrix_one->dimension);

    Matrix matrix_two_T;
    matrix_transpose(matrix_two, &matrix_two_T);

    for (int row = 0; row < matrix_one->dimension; row++) {
        for (int col = 0; col < matrix_two_T.dimension; col++) {
            int value = 0;
            for (int k = 0; k < matrix_one->dimension; k++) {
                int index1 = row * matrix_one->dimension + k;
                int index2 = col * matrix_two_T.dimension + k;
                value += matrix_one->matrix[index1] * matrix_two_T.matrix[index2];
            }
            int result_index = row * result_matrix.dimension + col;
            result_matrix.matrix[result_index] = value;
        }
    }

    display_matrix(&result_matrix);
}

int find_determinant(const Matrix* matrix) {
    int dimension = matrix->dimension;

    if (dimension == 1) {
        return matrix->matrix[0];
    }

    int det = 0;
    int sign = 1;

    for (int j = 0; j < dimension; j++) {
        int cofactor = sign * matrix->matrix[j] * determinant_of_minor(matrix, 0, j);
        det += cofactor;
        sign *= -1;
    }

    return det;
}

int determinant_of_minor(const Matrix* matrix, int row, int col) {
    int dimension = matrix->dimension;
    Matrix minor_matrix;
    create_matrix(&minor_matrix, dimension - 1);

    int minor_row = 0;
    for (int i = 0; i < dimension; i++) {
        if (i != row) {
            int minor_col = 0;
            for (int j = 0; j < dimension; j++) {
                if (j != col) {
                    int minor_index = minor_row * (dimension - 1) + minor_col;
                    int original_index = i * dimension + j;
                    minor_matrix.matrix[minor_index] = matrix->matrix[original_index];
                    minor_col++;
                }
            }
            minor_row++;
        }
    }

    int minor_determinant = find_determinant(&minor_matrix);

    return minor_determinant;
}

void free_matrix(Matrix* matrix) {
    free(matrix->matrix);
}