#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <stdlib.h>

// +----------------+
// | LINEAR ALGEBRA |
// +----------------+

typedef struct Matrix {
    size_t n; // Rows
    size_t m; // Cols
    double *data;
} Matrix;

#endif // STRUCTS_H_INCLUDED