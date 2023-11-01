#include "s21_get_data_viewer.h"

void s21_remove_data_viewer(data_viewer_t *data) {
  s21_remove_matrix(&(data->matrix));
  for (int i = 0; i < data->number_f; i++) free(data->polygons[i].v_in_facets);
  free(data->polygons);
}

data_viewer_t s21_get_data_viewer(char *path_to_file, int *error) {
  data_viewer_t data = s21_create_data_viewer(path_to_file, error);
  if (!(*error)) s21_set_data(&data, path_to_file, error);
  return data;
}

data_viewer_t s21_create_data_viewer(char *path_to_file, int *error) {
  FILE *fp = fopen(path_to_file, "r");
  data_viewer_t data = {0, 0, 0, {NULL, 0, 0}, NULL};
  if (fp) {
    char str[1024] = {0};
    unsigned int number_v = 0;
    unsigned int number_f = 0;
    while (fgets(str, 1023, fp)) {
      if (str[0] == 'v' && str[1] == ' ') number_v++;
      if (str[0] == 'f' && str[1] == ' ') number_f++;
    }
    data.number_v = number_v;
    data.number_f = number_f;
    *error = s21_create_matrix(number_v, 3, &data.matrix);
    if (*error) {
      fprintf(stderr, "Error create matrix\n");
    } else {
      data.polygons = calloc(number_f, sizeof(polygon_t));
      if (data.polygons == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        *error = 1;
      }
    }
    fclose(fp);
  } else {
    fprintf(stderr, "File not exist\n");
    *error = 1;
  }
  return data;
}

void s21_set_data(data_viewer_t *data, char *path_to_file, int *error) {
  FILE *fp = fopen(path_to_file, "r");
  if (fp) {
    char str[1024] = {0};
    char trash;
    double x, y, z;
    unsigned int count_v = 0;
    unsigned int count_f = 0;
    unsigned int count_facets_all = 0;
    while (fgets(str, 1023, fp) && !(*error)) {
      if (str[0] == 'v' && str[1] == ' ') {
        sscanf(str, "%c %lf %lf %lf", &trash, &x, &y, &z);
        data->matrix.matrix[count_v][0] = x;
        data->matrix.matrix[count_v][1] = y;
        data->matrix.matrix[count_v][2] = z;
        count_v++;
      }
      if (str[0] == 'f' && str[1] == ' ') {
        data->polygons[count_f].number_v_in_facets =
            s21_get_number_v_in_facets(str);
        count_facets_all += data->polygons[count_f].number_v_in_facets;
        data->polygons[count_f].v_in_facets =
            calloc(data->polygons[count_f].number_v_in_facets, sizeof(int));
        if (data->polygons[count_f].v_in_facets == NULL) {
          fprintf(stderr, "Memory allocation error\n");
          *error = 1;
        } else {
          s21_set_v_in_facets(data->polygons[count_f].v_in_facets, str);
        }
        count_f++;
      }
      for (int i = 0; i < 1023; i++) str[i] = '\n';
    }
    s21_normalize_obj(data);
    data->number_facets_all = count_facets_all;
    fclose(fp);
  } else {
    fprintf(stderr, "File not exist\n");
    *error = 1;
  }
}

unsigned int s21_get_number_v_in_facets(char str[1024]) {
  unsigned int number_v_in_facets = 0;
  for (char *ptr = str; *ptr != '\n'; ptr++)
    if (*ptr == ' ' && *(ptr + 1) >= '0' && *(ptr + 1) <= '9')
      number_v_in_facets++;
  return number_v_in_facets;
}

void s21_set_v_in_facets(int *v_in_facets, char str[1024]) {
  unsigned int count_v = 0;
  for (char *ptr = str; *ptr != '\n'; ptr++)
    if (*ptr == ' ' && *(ptr + 1) >= '0' && *(ptr + 1) <= '9') {
      int v = 0;
      char trash[1024];
      sscanf(ptr, "%d%1023s", &v, trash);
      v_in_facets[count_v++] = v;
    }
}

void s21_normalize_obj(data_viewer_t *data) {
  double max, min;
  int error = s21_get_maxmin_matrix(&(data->matrix), &max, &min);
  if (!error)
    s21_scaling(data, 1 / max);
  else
    fprintf(stderr, "Eror during normalization\n");
}

void s21_scaling(data_viewer_t *data, double scale) {
  matrix_t new_matrix;
  int error = s21_mult_number(&(data->matrix), scale, &new_matrix);
  if (!error) {
    s21_remove_matrix(&(data->matrix));
    data->matrix = new_matrix;
  }
}

// функция принимает изменяемую структуру data, значение расстояния на которое
// нужно переместить фигуру и направление в котором нужно переместить direction
// = 0 - x direction = 1 - y direction = 2 - z s21_moving(&data, 2, 0); -
// смещение по х на 2
void s21_moving(data_viewer_t *data, double distance, int direction) {
  for (int i = 0; i < data->matrix.rows; i++)
    data->matrix.matrix[i][direction] += distance;
}

// функция принимает изменяемую структуру data, значение угла на которое нужно
// повернуть фигуру и ось в которой нужно повернуть direction = 0 - x direction
// = 1 - y direction = 2 - z s21_rotation(&data, 2, 0); - вращение по х на 2
void s21_rotation(data_viewer_t *data, double angle, int direction) {
  matrix_t rotation_matrix;
  int error = s21_create_matrix(3, 3, &rotation_matrix);
  if (!error) {
    s21_set_rotation_matrix(&rotation_matrix, angle, direction);
    for (int i = 0; i < data->matrix.rows; i++) {
      double x = data->matrix.matrix[i][0];
      double y = data->matrix.matrix[i][1];
      double z = data->matrix.matrix[i][2];
      for (int j = 0; j < 3; j++)
        data->matrix.matrix[i][j] = rotation_matrix.matrix[j][0] * x +
                                    rotation_matrix.matrix[j][1] * y +
                                    rotation_matrix.matrix[j][2] * z;
    }
  }
  s21_remove_matrix(&rotation_matrix);
}

void s21_set_rotation_matrix(matrix_t *rotation_matrix, double angle,
                             int direction) {
  if (direction == 0) {
    rotation_matrix->matrix[0][0] = 1;
    rotation_matrix->matrix[1][1] = cos(angle);
    rotation_matrix->matrix[1][2] = -sin(angle);
    rotation_matrix->matrix[2][1] = sin(angle);
    rotation_matrix->matrix[2][2] = cos(angle);
  } else if (direction == 1) {
    rotation_matrix->matrix[0][0] = cos(angle);
    rotation_matrix->matrix[0][2] = sin(angle);
    rotation_matrix->matrix[1][1] = 1;
    rotation_matrix->matrix[2][0] = -sin(angle);
    rotation_matrix->matrix[2][2] = cos(angle);
  } else if (direction == 2) {
    rotation_matrix->matrix[0][0] = cos(angle);
    rotation_matrix->matrix[0][1] = -sin(angle);
    rotation_matrix->matrix[1][0] = sin(angle);
    rotation_matrix->matrix[1][1] = cos(angle);
    rotation_matrix->matrix[2][2] = 1;
  }
}
