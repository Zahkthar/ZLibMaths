#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <stdlib.h>

#include "structs.h"

// +--------------------------+
// | Matrix creation and free |
// +--------------------------+

Matrix *matrix_create_zeros(size_t n, size_t m);
Matrix *matrix_create_ones(size_t n, size_t m);
Matrix *matrix_create_custom(size_t n, size_t m, double data[n][m]);

Matrix *matrix_copy(Matrix *matrix);
void matrix_free(Matrix *matrix);

// +--------------------------+
// | Matrix simple operations |
// +--------------------------+

#define MATRIX_AT(matrix, i, j) (matrix)->data[(i) * (matrix)->m + (j)]

void matrix_add(Matrix *destination, Matrix *other);
void matrix_sub(Matrix *destination, Matrix *other);
void matrix_mulScalar(Matrix *destination, double scalar);
Matrix *matrix_mulMatrix(Matrix *a, Matrix *b);

// +---------------+
// | Matrix in/out |
// +---------------+

void matrix_print(Matrix *m);

#endif // MATRIX_H_INCLUDED