#ifndef MATRIX_H
#define MATRIX_H

/**
 * @brief Represents a matrix.
 *
 * The Matrix struct encapsulates a matrix, which consists of a dimension and a dynamic array
 * of integer values representing the matrix elements.
 */
typedef struct {
    int dimension;
    int* matrix;
} Matrix;

#endif
