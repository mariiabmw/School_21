#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = OK;

  if (result == NULL) {
    flag = INVALID_MATRIX;
  } else if (rows <= 0 || columns <= 0) {
    result->matrix = NULL;
    result->rows = 0;
    result->columns = 0;
    flag = INVALID_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      flag = INVALID_MATRIX;
    } else {
      for (int i = 0; i < rows && flag == OK; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          s21_remove_matrix(result);
          flag = INVALID_MATRIX;
        }
      }
    }
  }

  return flag;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->rows > 0 && A->columns > 0 && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) {
        free(A->matrix[i]);
        A->matrix[i] = NULL;
      }
    }
    free(A->matrix);
    A->matrix = NULL;
  }
  if (A != NULL) {
    A->rows = 0;
    A->columns = 0;
  }
}