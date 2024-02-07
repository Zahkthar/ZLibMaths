#include "matrix.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

// +--------------------------+
// | Matrix creation and free |
// +--------------------------+

Matrix *matrix_create_zeros(size_t n, size_t m)
{
    Matrix *newMatrix = malloc(sizeof(Matrix));

    newMatrix->n = n;
    newMatrix->m = m;
    newMatrix->data = calloc(n * m, sizeof(*newMatrix->data));

    return newMatrix;
}

Matrix *matrix_create_ones(size_t n, size_t m)
{
    Matrix *newMatrix = malloc(sizeof(Matrix));

    newMatrix->n = n;
    newMatrix->m = m;
    newMatrix->data = malloc(n * m * sizeof(*newMatrix->data));

    for (size_t i = 0; i < n * m; i++)
    {
        newMatrix->data[i] = 1;
    }

    return newMatrix;
}

Matrix *matrix_create_custom(size_t n, size_t m, double data[n][m])
{
    Matrix *newMatrix = malloc(sizeof(Matrix));

    newMatrix->n = n;
    newMatrix->m = m;
    newMatrix->data = malloc(n * m * sizeof(*newMatrix->data));

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            MATRIX_AT(newMatrix, i, j) = data[i][j];
        }
    }

    return newMatrix;
}

Matrix *matrix_copy(Matrix *matrix)
{
    Matrix *newMatrix = matrix_create_zeros(matrix->n, matrix->m);

    memcpy(newMatrix->data, matrix->data, matrix->n * matrix->m);

    return newMatrix;
}

void matrix_free(Matrix *matrix)
{
    free(matrix->data);
    free(matrix);
}

// +--------------------------+
// | Matrix simple operations |
// +--------------------------+

void matrix_add(Matrix *destination, Matrix *other)
{
    assert(destination->n == other->n && destination->m == other->m);
    for (int i = 0; i < destination->n; ++i)
    {
        for (int j = 0; j < destination->m; ++j)
        {
            MATRIX_AT(destination, i, j) += MATRIX_AT(other, i, j);
        }
    }
}

void matrix_sub(Matrix *destination, Matrix *other)
{
    assert(destination->n == other->n && destination->m == other->m);
    for (int i = 0; i < destination->n; ++i)
    {
        for (int j = 0; j < destination->m; ++j)
        {
            MATRIX_AT(destination, i, j) -= MATRIX_AT(other, i, j);
        }
    }
}

void matrix_mulScalar(Matrix *destination, double scalar)
{
    for (int i = 0; i < destination->n; ++i)
    {
        for (int j = 0; j < destination->m; ++j)
        {
            MATRIX_AT(destination, i, j) *= scalar;
        }
    }
}

Matrix *matrix_mulMatrix(Matrix *a, Matrix *b)
{
    assert(a->m == b->n);

    Matrix *result = matrix_create_zeros(a->n, b->m);

    for (size_t i = 0; i < a->n; ++i)
    {
        for (size_t j = 0; j < b->m; ++j)
        {
            double sum = 0;
            for (size_t k = 0; k < a->m; ++k)
            {
                sum += MATRIX_AT(a, i, k) * MATRIX_AT(b, k, j);
            }
            MATRIX_AT(result, i, j) = sum;
        }
    }

    return result;
}

// +---------------+
// | Matrix in/out |
// +---------------+

void matrix_print(Matrix *m)
{
    for (size_t i = 0; i < m->n; ++i)
    {
        printf("| ");
        for (size_t j = 0; j < m->m; ++j)
        {
            printf("%.5f | ", MATRIX_AT(m, i, j));
        }
        printf("\n");
    }
}