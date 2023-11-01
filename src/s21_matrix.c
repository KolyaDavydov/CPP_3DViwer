#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int answer = 0;
  result->rows = rows;
  result->columns = columns;
  if (rows <= 0 || columns <= 0) {
    answer = 1;
  } else {
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      answer = 1;
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) answer = 1;
      }
    }
  }
  return answer;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
  free(A->matrix);
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int answer = s21_create_matrix(A->rows, A->columns, result);
  if (!answer && s21_is_create(*A)) {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] * number;
  } else {
    answer = 1;
  }
  return answer;
}

int s21_get_maxmin_matrix(matrix_t *A, double *max, double *min) {
  int answer = 0;
  *max = 0;
  *min = 0;
  if (s21_is_create(*A)) {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        if (A->matrix[i][j] > *max) *max = A->matrix[i][j];
        if (A->matrix[i][j] < *min) *min = A->matrix[i][j];
      }
  } else {
    answer = 1;
  }
  return answer;
}

int s21_is_create(matrix_t A) {
  int answer = 0;
  if (A.rows > 0 && A.columns > 0) answer = 1;
  return answer;
}
