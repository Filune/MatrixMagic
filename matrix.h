#ifndef MATRIX_H
#define MATRIX_H

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
