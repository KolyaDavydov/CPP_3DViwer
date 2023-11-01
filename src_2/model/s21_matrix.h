#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows, columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_get_maxmin_matrix(matrix_t *A, double *max, double *min);
int s21_is_create(matrix_t A);

#endif  // S21_MATRIX_H
