#include <check.h>

#include "s21_matrix.h"

START_TEST(test_create_matrix_1) {
  int rows = 2, columns = 2;
  matrix_t A = {0};
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_ptr_null(A.matrix);
}

START_TEST(test_create_matrix_2) {
  int rows = -1, columns = -1;
  matrix_t A = {0};
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, INVALID_MATRIX);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_ptr_null(A.matrix);
}

START_TEST(test_create_matrix_3) {
  int rows = 0, columns = 0;
  matrix_t A = {0};
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, INVALID_MATRIX);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_ptr_null(A.matrix);
}

START_TEST(test_create_matrix_4) {
  int rows = 0, columns = 1;
  matrix_t A = {0};
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, INVALID_MATRIX);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_ptr_null(A.matrix);
}

START_TEST(test_create_matrix_5) {
  int rows = 1, columns = 0;
  matrix_t A = {0};
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, INVALID_MATRIX);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_ptr_null(A.matrix);
}

START_TEST(test_create_matrix_6) {
  int rows = 1, columns = 1;
  matrix_t A = {0};
  int result = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_ptr_null(A.matrix);
}

START_TEST(test_create_matrix_7) {
  int rows = 1, columns = 1;
  int result = s21_create_matrix(rows, columns, NULL);
  ck_assert_int_eq(result, INVALID_MATRIX);
}

START_TEST(test_create_matrix_8) {
  matrix_t A = {NULL, 0, 0};
  s21_remove_matrix(&A);
}

START_TEST(test_eq_matrix_1) {
  int rows = 1, columns = 2;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &B);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_eq_matrix_2) {
  int rows = 1, columns = 2;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  int result = s21_eq_matrix(&A, NULL);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
}

START_TEST(test_eq_matrix_3) {
  int rows = -1, columns = 2;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_eq_matrix_4) {
  int rows = 0, columns = -2;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_eq_matrix_5) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 100;
  A.matrix[0][1] = 100;
  A.matrix[1][0] = 100;
  A.matrix[1][1] = 100;
  B.matrix[0][0] = 100;
  B.matrix[0][1] = 100;
  B.matrix[1][0] = 100;
  B.matrix[1][1] = 100;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_eq_matrix_6) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 100;
  A.matrix[0][1] = 100;
  A.matrix[1][0] = 100;
  A.matrix[1][1] = 100;
  B.matrix[0][0] = 100.0000001;
  B.matrix[0][1] = 100;
  B.matrix[1][0] = 100;
  B.matrix[1][1] = 100;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_eq_matrix_7) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 100;
  A.matrix[0][1] = 100;
  A.matrix[1][0] = 100;
  A.matrix[1][1] = 100;
  B.matrix[0][0] = 100.00001;
  B.matrix[0][1] = 100;
  B.matrix[1][0] = 100;
  B.matrix[1][1] = 100;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_sum_matrix_1) {
  int rows = 0, columns = 0;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_matrix_2) {
  int rows = 3, columns = 4;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &B);
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_matrix_3) {
  int rows = 3, columns = 4;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, rows, NULL);
  int res = s21_sum_matrix(&A, NULL, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_matrix_4) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 100;
  A.matrix[0][1] = 100;
  A.matrix[1][0] = 100;
  A.matrix[1][1] = 100;
  B.matrix[0][0] = 100;
  B.matrix[0][1] = 100;
  B.matrix[1][0] = -100;
  B.matrix[1][1] = -100;
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], A.matrix[0][0] + B.matrix[0][0],
                          0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], A.matrix[0][1] + B.matrix[0][1],
                          0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], A.matrix[1][0] + B.matrix[1][0],
                          0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], A.matrix[1][1] + B.matrix[1][1],
                          0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_matrix_5) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 100.1295129341;
  A.matrix[0][1] = 100.000102401240;
  A.matrix[1][0] = 100.312;
  A.matrix[1][1] = 100.0;
  B.matrix[0][0] = 100.0000002;
  B.matrix[0][1] = 100;
  B.matrix[1][0] = -100;
  B.matrix[1][1] = -100;
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], A.matrix[0][0] + B.matrix[0][0],
                          0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], A.matrix[0][1] + B.matrix[0][1],
                          0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], A.matrix[1][0] + B.matrix[1][0],
                          0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], A.matrix[1][1] + B.matrix[1][1],
                          0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_sub_matrix_1) {
  int rows = 0, columns = 0;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  int res = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_sub_matrix_2) {
  int rows = 3, columns = 4;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &B);
  int res = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(res, ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_sub_matrix_3) {
  int rows = 3, columns = 4;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, rows, NULL);
  int res = s21_sub_matrix(&A, NULL, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(test_sub_matrix_4) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 100;
  A.matrix[0][1] = 100;
  A.matrix[1][0] = 100;
  A.matrix[1][1] = 100;
  B.matrix[0][0] = 100;
  B.matrix[0][1] = 100;
  B.matrix[1][0] = -100;
  B.matrix[1][1] = -100;
  int res = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], A.matrix[0][0] - B.matrix[0][0],
                          0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], A.matrix[0][1] - B.matrix[0][1],
                          0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], A.matrix[1][0] - B.matrix[1][0],
                          0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], A.matrix[1][1] - B.matrix[1][1],
                          0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_sub_matrix_5) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 100.1295129341;
  A.matrix[0][1] = 100.000102401240;
  A.matrix[1][0] = 100.312;
  A.matrix[1][1] = 100.0;
  B.matrix[0][0] = 100.0000002;
  B.matrix[0][1] = 100;
  B.matrix[1][0] = -100;
  B.matrix[1][1] = -100;
  int res = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], A.matrix[0][0] - B.matrix[0][0],
                          0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], A.matrix[0][1] - B.matrix[0][1],
                          0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], A.matrix[1][0] - B.matrix[1][0],
                          0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], A.matrix[1][1] - B.matrix[1][1],
                          0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_number_1) {
  int rows = 0, columns = 0;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  int res = s21_mult_number(&A, 5, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_number_2) {
  int rows = 0, columns = -1;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  int res = s21_mult_number(&A, 5, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_number_3) {
  matrix_t result = {0};
  int res = s21_mult_number(NULL, 5, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_number_4) {
  int rows = 2, columns = 2, number = 5;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 100.1295129341;
  A.matrix[0][1] = 100.000102401240;
  A.matrix[1][0] = 100.312;
  A.matrix[1][1] = -100.0;
  int res = s21_mult_number(&A, number, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], A.matrix[0][0] * number,
                          0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], A.matrix[0][1] * number,
                          0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], A.matrix[1][0] * number,
                          0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], A.matrix[1][1] * number,
                          0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_matrix_1) {
  int rows = 0, columns = 0;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  int res = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_matrix_2) {
  int rows = 0, columns = 0;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  int res = s21_mult_matrix(&A, NULL, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_matrix_3) {
  int rows1 = 2, columns1 = 3, rows2 = 50, columns2 = 2;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows1, columns1, &A);
  s21_create_matrix(rows2, columns2, &B);
  int res = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(res, ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_matrix_4) {
  int rows1 = 1, columns1 = 2, rows2 = 2, columns2 = 3;
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(rows1, columns1, &A);
  s21_create_matrix(rows2, columns2, &B);
  A.matrix[0][0] = 5.6;
  A.matrix[0][1] = 100;
  B.matrix[0][0] = -3;
  B.matrix[0][1] = 4;
  B.matrix[0][2] = 5;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = 7;
  B.matrix[1][2] = -8;
  int res = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 583.2, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], 722.4, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], -772, 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_transpose_1) {
  int rows = 0, columns = 0;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  int res = s21_transpose(&A, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(test_transpose_2) {
  int rows = 0, columns = -1;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  int res = s21_transpose(&A, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(test_transpose_3) {
  matrix_t result = {0};
  int res = s21_transpose(NULL, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  s21_remove_matrix(&result);
}

START_TEST(test_transpose_4) {
  int rows = 3, columns = 2;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1.0001;
  A.matrix[0][1] = -4;
  A.matrix[1][0] = 2.99;
  A.matrix[1][1] = 5.0;
  A.matrix[2][0] = 300;
  A.matrix[2][1] = -6.99;
  int res = s21_transpose(&A, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], A.matrix[0][0], 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], A.matrix[1][0], 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], A.matrix[2][0], 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], A.matrix[0][1], 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], A.matrix[1][1], 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][2], A.matrix[2][1], 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(test_determinant_1) {
  int rows = 0, columns = -1;
  matrix_t A = {0};
  double result = 0;
  s21_create_matrix(rows, columns, &A);
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_2) {
  double result = 0;
  int res = s21_determinant(NULL, &result);
  ck_assert_int_eq(res, INVALID_MATRIX);
}

START_TEST(test_determinant_3) {
  int rows = 2, columns = 3;
  matrix_t A = {0};
  double result = 0;
  s21_create_matrix(rows, columns, &A);
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, ERROR_CALCULATION);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_4) {
  int rows = 2, columns = 2;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  int res = s21_determinant(&A, NULL);
  ck_assert_int_eq(res, INVALID_MATRIX);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_5) {
  int rows = 2, columns = 2;
  matrix_t A = {0};
  double result = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 100;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 200;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result, 0.0, 0.0000001);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_6) {
  int rows = 2, columns = 2;
  matrix_t A = {0};
  double result = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 100;
  A.matrix[1][1] = 200;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result, 0.0, 0.0000001);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_7) {
  int rows = 1, columns = 1;
  matrix_t A = {0};
  double result = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -123.456789;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result, -123.456789, 0.0000001);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_8) {
  int rows = 2, columns = 2;
  matrix_t A = {0};
  double result = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -100;
  A.matrix[0][1] = 69;
  A.matrix[1][0] = 420.69;
  A.matrix[1][1] = 15;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result, -30527.61, 0.0000001);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_9) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  double result = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -100;
  A.matrix[0][1] = 69;
  A.matrix[0][2] = 420.69;
  A.matrix[1][0] = -100;
  A.matrix[1][1] = 69;
  A.matrix[1][2] = 420.69;
  A.matrix[2][0] = -100;
  A.matrix[2][1] = 69;
  A.matrix[2][2] = 420.69;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result, 0.0, 0.0000001);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_10) {
  int rows = 4, columns = 4;
  matrix_t A = {0};
  double result = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -100;
  A.matrix[0][1] = 69;
  A.matrix[0][2] = 420.69;
  A.matrix[0][3] = 1337;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 3;
  A.matrix[1][3] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 69;
  A.matrix[2][2] = 7;
  A.matrix[2][3] = 8;
  A.matrix[3][0] = 9;
  A.matrix[3][1] = 10;
  A.matrix[3][2] = 11;
  A.matrix[3][3] = 12;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result, 661212.72, 0.0000001);
  s21_remove_matrix(&A);
}

START_TEST(test_determinant_11) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  double result = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -100;
  A.matrix[0][1] = 69;
  A.matrix[0][2] = 123;
  A.matrix[1][0] = -100;
  A.matrix[1][1] = 57;
  A.matrix[1][2] = 175;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result, 0.0, 0.0000001);
  s21_remove_matrix(&A);
}

START_TEST(test_calc_complements_1) {
  int rows = 2, columns = 3;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_calc_complements_2) {
  int rows = 0, columns = -1;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_calc_complements_3) {
  int rows = 0, columns = -1;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_calc_complements_4) {
  matrix_t result = {0};
  int status = s21_calc_complements(NULL, &result);
  ck_assert_int_eq(status, INVALID_MATRIX);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_calc_complements_5) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 4, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], -3, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], -2, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], 1, 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_calc_complements_6) {
  int rows = 3, columns = 3;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], 10, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], -20, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], 4, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], -14, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][2], 8, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][0], -8, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][1], -2, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][2], 4, 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix_1) {
  int rows = 2, columns = 3;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix_2) {
  int rows = 0, columns = -1;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix_3) {
  int rows = 0, columns = -1;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, INVALID_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix_4) {
  matrix_t result = {0};
  int status = s21_inverse_matrix(NULL, &result);
  ck_assert_int_eq(status, INVALID_MATRIX);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix_5) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, ERROR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix_6) {
  int rows = 3, columns = 3;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 1, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], -1, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], 1, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], -38, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], 41, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][2], -34, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][0], 27, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][1], -29, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[2][2], 24, 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_inverse_matrix_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("test_inverse_matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_inverse_matrix_1);
  tcase_add_test(tc_core, test_inverse_matrix_2);
  tcase_add_test(tc_core, test_inverse_matrix_3);
  tcase_add_test(tc_core, test_inverse_matrix_4);
  tcase_add_test(tc_core, test_inverse_matrix_5);
  tcase_add_test(tc_core, test_inverse_matrix_6);

  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_calc_complements_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("test_calc_complements");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_calc_complements_1);
  tcase_add_test(tc_core, test_calc_complements_2);
  tcase_add_test(tc_core, test_calc_complements_3);
  tcase_add_test(tc_core, test_calc_complements_4);
  tcase_add_test(tc_core, test_calc_complements_5);
  tcase_add_test(tc_core, test_calc_complements_6);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_determinant_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("test_determinant");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_determinant_1);
  tcase_add_test(tc_core, test_determinant_2);
  tcase_add_test(tc_core, test_determinant_3);
  tcase_add_test(tc_core, test_determinant_4);
  tcase_add_test(tc_core, test_determinant_5);
  tcase_add_test(tc_core, test_determinant_6);
  tcase_add_test(tc_core, test_determinant_7);
  tcase_add_test(tc_core, test_determinant_8);
  tcase_add_test(tc_core, test_determinant_9);
  tcase_add_test(tc_core, test_determinant_10);
  tcase_add_test(tc_core, test_determinant_11);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_transpose_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("test_transpose");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_transpose_1);
  tcase_add_test(tc_core, test_transpose_2);
  tcase_add_test(tc_core, test_transpose_3);
  tcase_add_test(tc_core, test_transpose_4);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_mult_matrix_test(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("test_mult_matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_mult_matrix_1);
  tcase_add_test(tc_core, test_mult_matrix_2);
  tcase_add_test(tc_core, test_mult_matrix_3);
  tcase_add_test(tc_core, test_mult_matrix_4);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_mult_number_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("test_mult_number");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_mult_number_1);
  tcase_add_test(tc_core, test_mult_number_2);
  tcase_add_test(tc_core, test_mult_number_3);
  tcase_add_test(tc_core, test_mult_number_4);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_sub_matrix_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sub_matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_sub_matrix_1);
  tcase_add_test(tc_core, test_sub_matrix_2);
  tcase_add_test(tc_core, test_sub_matrix_3);
  tcase_add_test(tc_core, test_sub_matrix_4);
  tcase_add_test(tc_core, test_sub_matrix_5);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_sum_matrix_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sum_matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_sum_matrix_1);
  tcase_add_test(tc_core, test_sum_matrix_2);
  tcase_add_test(tc_core, test_sum_matrix_3);
  tcase_add_test(tc_core, test_sum_matrix_4);
  tcase_add_test(tc_core, test_sum_matrix_5);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_eq_matrix_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("eq_matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_eq_matrix_1);
  tcase_add_test(tc_core, test_eq_matrix_2);
  tcase_add_test(tc_core, test_eq_matrix_3);
  tcase_add_test(tc_core, test_eq_matrix_4);
  tcase_add_test(tc_core, test_eq_matrix_5);
  tcase_add_test(tc_core, test_eq_matrix_6);
  tcase_add_test(tc_core, test_eq_matrix_7);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_create_matrix_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("create_matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_create_matrix_1);
  tcase_add_test(tc_core, test_create_matrix_2);
  tcase_add_test(tc_core, test_create_matrix_3);
  tcase_add_test(tc_core, test_create_matrix_4);
  tcase_add_test(tc_core, test_create_matrix_5);
  tcase_add_test(tc_core, test_create_matrix_6);
  tcase_add_test(tc_core, test_create_matrix_7);
  tcase_add_test(tc_core, test_create_matrix_8);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  Suite *list_tests[] = {s21_inverse_matrix_test(),
                         s21_calc_complements_test(),
                         s21_determinant_test(),
                         s21_transpose_test(),
                         s21_mult_matrix_test(),
                         s21_mult_number_test(),
                         s21_sub_matrix_test(),
                         s21_sum_matrix_test(),
                         s21_eq_matrix_test(),
                         s21_create_matrix_test(),
                         NULL};

  int number_failed = 0;
  SRunner *runner = srunner_create(list_tests[0]);

  for (int i = 1; list_tests[i] != NULL; i++) {
    srunner_add_suite(runner, list_tests[i]);
  }

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
