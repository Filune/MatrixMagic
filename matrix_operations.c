#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

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

    if (matrix->dimension == 1) {
        return matrix->matrix[0];
    }

    int det = 0;
    int sign = 1;

    for (int j = 0; j < matrix->dimension; j++) {
        int cofactor = sign * matrix->matrix[j] * determinant_of_minor(matrix, 0, j);
        det += cofactor;
        sign *= -1;
    }

    return det;
}

int determinant_of_minor(const Matrix* matrix, int row, int col) {
    Matrix minor_matrix;
    create_matrix(&minor_matrix, matrix->dimension - 1);

    int minor_row = 0;
    for (int i = 0; i < matrix->dimension; i++) {
        if (i != row) {
            int minor_col = 0;
            for (int j = 0; j < matrix->dimension; j++) {
                if (j != col) {
                    int minor_index = minor_row * (matrix->dimension - 1) + minor_col;
                    int original_index = i * matrix->dimension + j;
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
