#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include "matrix.h"

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

#endif
