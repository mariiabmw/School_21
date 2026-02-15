#include "s21_matrix.h"

int s21_is_valid(matrix_t *A) {
  return (A != NULL && A->columns > 0 && A->rows > 0) ? OK : INVALID_MATRIX;
}
