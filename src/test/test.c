#include "s21_get_data_viewer.c"
#include "s21_matrix.c"

int main(void) {
  char *path = "./spider.obj";
  int error = 0;
  data_viewer_t data = s21_get_data_viewer(path, &error);
  printf("main: %d\n", data.number_f);
  // printf("%d\n", data.number_facets_all);
  // for (int i = 0; i < data.number_f; i++) {
  //   for (int j = 0; j < data.polygons[i].number_v_in_facets; j++) {
  //     unsigned number = data.polygons[i].v_in_facets[j] - 1;
  //     printf("%d|", number);
  //     // printf("%d-%d: %f %f %f\n", i, j, data.matrix.matrix[number][0],
  //     data.matrix.matrix[number][1], data.matrix.matrix[number][2]);
  //   }
  // }

  // printf("main: %f %f %f\n", data.matrix.matrix[0][0],
  // data.matrix.matrix[0][1], data.matrix.matrix[0][2]); printf("main: %f %f
  // %f\n", data.matrix.matrix[data.number_v - 1][0],
  // data.matrix.matrix[data.number_v - 1][1], data.matrix.matrix[data.number_v
  // - 1][2]); printf("main: %i\n", data.polygons[1].number_v_in_facets);
  // printf("main: %i\n", data.polygons[data.number_f].number_v_in_facets);
  // printf("main: %i %i ", data.polygons[1].v_in_facets[0],
  // data.polygons[1].v_in_facets[1]); printf("%i %i\n",
  // data.polygons[1].v_in_facets[2], data.polygons[1].v_in_facets[3]);
  // printf("main: %i %i ", data.polygons[data.number_f].v_in_facets[0],
  // data.polygons[data.number_f].v_in_facets[1]); printf("%i %i\n",
  // data.polygons[data.number_f].v_in_facets[2],
  // data.polygons[data.number_f].v_in_facets[3]); printf("%d | %d | %d | ",
  // data.number_v, data.number_f, data.matrix.columns); printf("%d | %p |
  // %p\n", data.matrix.rows, (void *)data.matrix.matrix, (void
  // *)data.polygons); s21_scaling(&data, 0.5); printf("scaling: %f %f %f\n",
  // data.matrix.matrix[1][0], data.matrix.matrix[1][1],
  // data.matrix.matrix[1][2]); printf("scaling: %f %f %f\n",
  // data.matrix.matrix[data.number_v][0], data.matrix.matrix[data.number_v][1],
  // data.matrix.matrix[data.number_v][2]); s21_moving(&data, 2, 1);
  // printf("moving: %f %f %f\n", data.matrix.matrix[1][0],
  // data.matrix.matrix[1][1], data.matrix.matrix[1][2]); printf("moving: %f %f
  // %f\n", data.matrix.matrix[data.number_v][0],
  // data.matrix.matrix[data.number_v][1],
  // data.matrix.matrix[data.number_v][2]); s21_rotation(&data, 2, 0);
  // printf("rotation: %f %f %f\n", data.matrix.matrix[1][0],
  // data.matrix.matrix[1][1], data.matrix.matrix[1][2]); printf("rotation: %f
  // %f %f\n", data.matrix.matrix[data.number_v][0],
  // data.matrix.matrix[data.number_v][1],
  // data.matrix.matrix[data.number_v][2]);
}
