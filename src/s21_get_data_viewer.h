#ifndef S21_GET_DATA_VIEWER_H_
#define S21_GET_DATA_VIEWER_H_

#include <math.h>
#include <stdio.h>

#include "s21_matrix.h"

typedef struct facets {
  int *v_in_facets;
  int number_v_in_facets;
} polygon_t;

typedef struct data_viewer {
  int number_v;
  int number_f;
  int number_facets_all;
  matrix_t matrix;
  polygon_t *polygons;
} data_viewer_t;

data_viewer_t s21_get_data_viewer(char *path_to_file, int *error);
data_viewer_t s21_create_data_viewer(char *path_to_file, int *error);
void s21_set_data(data_viewer_t *data, char *path_to_file, int *error);
unsigned int s21_get_number_v_in_facets(char str[1024]);
void s21_set_v_in_facets(int *v_in_facets, char str[1024]);
void s21_moving(data_viewer_t *data, double distance, int direction);
void s21_rotation(data_viewer_t *data, double angle, int direction);
void s21_normalize_obj(data_viewer_t *data);
void s21_scaling(data_viewer_t *data, double scale);
void s21_set_rotation_matrix(matrix_t *rotation_matrix, double angle,
                             int direction);
void s21_remove_data_viewer(data_viewer_t *data);

#endif  // S21_GET_DATA_VIEWER_H_
