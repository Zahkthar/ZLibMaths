#include <assert.h>
#include <stdlib.h>
#include <math.h>

#include "distance.h"

double distance_euclidean(Matrix *a, Matrix *b)
{
    assert(a->n == 1 && b->n == 1);

    double distance = 0.0;
    for (size_t i = 0; i < a->n; ++i)
    {
        distance += pow(MATRIX_AT(a, 0, i) - MATRIX_AT(b, 0, i), 2);
    }
    return sqrt(distance);
}