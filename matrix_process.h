#ifndef MATRIX_PROCESS_H
#define MATRIX_PROCESS_H

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
void perform_multi_matrix_operation(void (*operation)(const Matrix *, const Matrix *));

/**
 * @brief Performs a single matrix operation based on the given choice.
 *
 * @param choice The choice of the matrix operation.
 *               - 3: Find determinant of a matrix.
 *               - 4: Transpose a matrix.
 */
void perform_single_matrix_operation(int choice);

/**
 * @brief Performs shared matrix operations on a given square matrix.
 *
 * This function performs shared matrix operations on a given square matrix.
 *
 * @param dimension Pointer to the dimension of the square matrix.
 * @param matrix_one Pointer to the matrix on which the operations will be performed.
 *
 */
void perform_shared_matrix_operations(int* dimension, const Matrix* matrix_one);


#endif
