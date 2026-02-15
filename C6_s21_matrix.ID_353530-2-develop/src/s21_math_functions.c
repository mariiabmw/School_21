#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (s21_is_valid(A) != OK || s21_is_valid(B) != OK || result == NULL) {
    flag = INVALID_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    flag = ERROR_CALCULATION;
  }

  if (flag == OK) {
    flag = s21_create_matrix(A->rows, A->columns, result);
    if (flag == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }

  return flag;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;

  if (s21_is_valid(A) != OK || s21_is_valid(B) != OK || result == NULL) {
    flag = INVALID_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    flag = ERROR_CALCULATION;
  }

  if (flag == OK) {
    flag = s21_create_matrix(A->rows, A->columns, result);
    if (flag == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }

  return flag;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;

  if (s21_is_valid(A) != OK || s21_is_valid(B) != OK || result == NULL) {
    flag = INVALID_MATRIX;
  } else if (A->columns != B->rows) {
    flag = ERROR_CALCULATION;
  }

  if (flag == OK) {
    flag = s21_create_matrix(A->rows, B->columns, result);
    if (flag == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          result->matrix[i][j] = 0;
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    }
  }

  return flag;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = OK;

  if (s21_is_valid(A) != OK || result == NULL) {
    flag = INVALID_MATRIX;
  }

  if (flag == OK) {
    flag = s21_create_matrix(A->rows, A->columns, result);
  }

  if (flag == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return flag;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = OK;

  if (s21_is_valid(A) != OK || result == NULL) {
    flag = INVALID_MATRIX;
  }
  if (flag == OK) {
    if (A == result) {
      flag = ERROR_CALCULATION;
    }
  }

  if (flag == OK) {
    flag = s21_create_matrix(A->columns, A->rows, result);
    if (flag == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  }

  return flag;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;

  if (!A || !B || !A->matrix || !B->matrix) {
    flag = FAILURE;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    flag = FAILURE;
  } else {
    for (int i = 0; i < A->rows && flag == SUCCESS; i++) {
      for (int j = 0; j < A->columns && flag == SUCCESS; j++) {
        if (fabsl(A->matrix[i][j] - B->matrix[i][j]) > ACCURACY) {
          flag = FAILURE;
        }
      }
    }
  }

  return flag;
}

int s21_determinant(matrix_t *A, double *result) {
  int flag = OK;
  double res = 0.0;

  if (A == NULL || result == NULL) {
    flag = INVALID_MATRIX;
  } else if (s21_is_valid(A) != OK || result == NULL) {
    flag = INVALID_MATRIX;
  } else if (A->columns != A->rows) {
    flag = ERROR_CALCULATION;
  } else if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else {
    for (int j = 0; j < A->columns && flag == OK; j++) {
      matrix_t temp = {0};
      int create_flag = s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
      if (create_flag != OK) {
        flag = INVALID_MATRIX;
      } else {
        trancate(A, &temp, 0, j);

        double minor_det = 0.0;
        int det_flag = s21_determinant(&temp, &minor_det);
        s21_remove_matrix(&temp);

        if (det_flag != OK) {
          flag = det_flag;
        } else {
          double sign = (j % 2 == 0) ? 1.0 : -1.0;
          res += sign * A->matrix[0][j] * minor_det;
        }
      }
    }
    if (flag == OK) {
      *result = res;
    }
  }

  return flag;
}

int trancate(matrix_t *A, matrix_t *result, int i, int j) {
  int flag = OK;

  if (A == NULL || result == NULL || A->matrix == NULL ||
      result->matrix == NULL) {
    flag = INVALID_MATRIX;
  }

  if (flag == OK && (i < 0 || i >= A->rows || j < 0 || j >= A->columns)) {
    flag = ERROR_CALCULATION;
  }

  if (flag == OK) {
    int u = 0;
    for (int k = 0; k < A->rows; k++) {
      if (k != i) {
        int v = 0;
        for (int l = 0; l < A->columns; l++) {
          if (l != j) {
            result->matrix[u][v] = A->matrix[k][l];
            v++;
          }
        }
        u++;
      }
    }
  }

  return flag;
}

int s21_minor(matrix_t *A, int x, int y, double *result) {
  matrix_t temp;
  s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
  trancate(A, &temp, x, y);
  s21_determinant(&temp, result);
  s21_remove_matrix(&temp);
  return OK;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = OK;

  if (s21_is_valid(A) != OK || result == NULL) {
    flag = INVALID_MATRIX;
  } else if (A->rows != A->columns) {
    flag = ERROR_CALCULATION;
  }

  if (flag == OK) {
    flag = s21_create_matrix(A->rows, A->columns, result);
  }

  if (flag == OK) {
    for (int i = 0; i < A->rows && flag == OK; i++) {
      for (int j = 0; j < A->columns && flag == OK; j++) {
        double minor_temp = 0;
        int minor_flag = s21_minor(A, i, j, &minor_temp);
        if (minor_flag != OK) {
          flag = minor_flag;
        } else {
          result->matrix[i][j] = minor_temp * (((i + j) % 2 == 0) ? 1 : -1);
        }
      }
    }
  }
  return flag;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = OK;
  double det = 0.0;
  matrix_t complements = {0};
  matrix_t transposed_complements = {0};
  if (s21_is_valid(A) != OK || result == NULL) {
    flag = INVALID_MATRIX;
  } else if (A->rows != A->columns) {
    flag = ERROR_CALCULATION;
  }
  if (flag == OK) {
    flag = s21_determinant(A, &det);
    if (flag == OK && fabs(det) < ACCURACY) {
      flag = ERROR_CALCULATION;
    }
  }

  if (flag == OK) {
    flag = s21_calc_complements(A, &complements);
  }
  if (flag == OK) {
    flag = s21_transpose(&complements, &transposed_complements);
  }
  if (flag == OK) {
    flag = s21_create_matrix(A->rows, A->columns, result);
  }
  if (flag == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = transposed_complements.matrix[i][j] / det;
      }
    }
  }
  if (complements.matrix != NULL) {
    s21_remove_matrix(&complements);
  }
  if (transposed_complements.matrix != NULL) {
    s21_remove_matrix(&transposed_complements);
  }
  return flag;
}
