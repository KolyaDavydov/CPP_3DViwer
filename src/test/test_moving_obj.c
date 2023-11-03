#include "test_main.h"

START_TEST(moving_obj_1) {
  int error = 0;
  char *path = "cub.obj";
  data_viewer_t data = s21_get_data_viewer(path, &error);
  s21_moving(&data, 2, 0);
  ck_assert_int_eq(data.number_v, 8);
  ck_assert_int_eq(data.number_f, 12);
  ck_assert_int_eq(data.number_facets_all, 36);
  ck_assert_int_eq(data.matrix.rows, 8);
  ck_assert_int_eq(data.matrix.columns, 3);
  ck_assert_float_eq(data.matrix.matrix[0][0], 0.999999 + 2);
  ck_assert_float_eq(data.matrix.matrix[7][0], -0.999999 + 2);
  ck_assert_int_eq(data.polygons[0].number_v_in_facets, 3);
  ck_assert_int_eq(data.polygons[11].number_v_in_facets, 3);
  ck_assert_int_eq(data.polygons[0].v_in_facets[0], 2);
  ck_assert_int_eq(data.polygons[0].v_in_facets[2], 4);
  ck_assert_int_eq(data.polygons[11].v_in_facets[0], 5);
  ck_assert_int_eq(data.polygons[11].v_in_facets[2], 8);
  s21_remove_data_viewer(&data);
}
END_TEST

START_TEST(moving_obj_2) {
  int error = 0;
  char *path = "cub.obj";
  data_viewer_t data = s21_get_data_viewer(path, &error);
  s21_moving(&data, 2, 1);
  ck_assert_int_eq(data.number_v, 8);
  ck_assert_int_eq(data.number_f, 12);
  ck_assert_int_eq(data.number_facets_all, 36);
  ck_assert_int_eq(data.matrix.rows, 8);
  ck_assert_int_eq(data.matrix.columns, 3);
  ck_assert_float_eq(data.matrix.matrix[0][1], -0.999999 + 2);
  ck_assert_float_eq(data.matrix.matrix[7][1], 0.999999 + 2);
  ck_assert_int_eq(data.polygons[0].number_v_in_facets, 3);
  ck_assert_int_eq(data.polygons[11].number_v_in_facets, 3);
  ck_assert_int_eq(data.polygons[0].v_in_facets[0], 2);
  ck_assert_int_eq(data.polygons[0].v_in_facets[2], 4);
  ck_assert_int_eq(data.polygons[11].v_in_facets[0], 5);
  ck_assert_int_eq(data.polygons[11].v_in_facets[2], 8);
  s21_remove_data_viewer(&data);
}
END_TEST

START_TEST(moving_obj_3) {
  int error = 0;
  char *path = "cub.obj";
  data_viewer_t data = s21_get_data_viewer(path, &error);
  s21_moving(&data, 2, 2);
  ck_assert_int_eq(data.number_v, 8);
  ck_assert_int_eq(data.number_f, 12);
  ck_assert_int_eq(data.number_facets_all, 36);
  ck_assert_int_eq(data.matrix.rows, 8);
  ck_assert_int_eq(data.matrix.columns, 3);
  ck_assert_float_eq(data.matrix.matrix[0][2], -0.999999 + 2);
  ck_assert_float_eq(data.matrix.matrix[7][2], -0.999999 + 2);
  ck_assert_int_eq(data.polygons[0].number_v_in_facets, 3);
  ck_assert_int_eq(data.polygons[11].number_v_in_facets, 3);
  ck_assert_int_eq(data.polygons[0].v_in_facets[0], 2);
  ck_assert_int_eq(data.polygons[0].v_in_facets[2], 4);
  ck_assert_int_eq(data.polygons[11].v_in_facets[0], 5);
  ck_assert_int_eq(data.polygons[11].v_in_facets[2], 8);
  s21_remove_data_viewer(&data);
}
END_TEST

Suite *moving_obj_suite(void) {
  Suite *s = suite_create("Moving_obj");
  TCase *tc_create = tcase_create("Moving_obj");
  tcase_add_test(tc_create, moving_obj_1);
  tcase_add_test(tc_create, moving_obj_2);
  tcase_add_test(tc_create, moving_obj_3);
  suite_add_tcase(s, tc_create);
  return s;
}
