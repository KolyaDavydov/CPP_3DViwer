#include "test_main.h"

START_TEST(get_data_viewer_1) {
  int error = 0;
  char *path = "cub.obj";
  data_viewer_t data = s21_get_data_viewer(path, &error);
  ck_assert_int_eq(data.number_v, 8);
  ck_assert_int_eq(data.number_f, 12);
  ck_assert_int_eq(data.number_facets_all, 36);
  ck_assert_int_eq(data.matrix.rows, 8);
  ck_assert_int_eq(data.matrix.columns, 3);
  ck_assert_float_eq(data.matrix.matrix[0][0], 0.999999);
  ck_assert_float_eq(data.matrix.matrix[7][2], -0.999999);
  ck_assert_int_eq(data.polygons[0].number_v_in_facets, 3);
  ck_assert_int_eq(data.polygons[11].number_v_in_facets, 3);
  ck_assert_int_eq(data.polygons[0].v_in_facets[0], 2);
  ck_assert_int_eq(data.polygons[0].v_in_facets[2], 4);
  ck_assert_int_eq(data.polygons[11].v_in_facets[0], 5);
  ck_assert_int_eq(data.polygons[11].v_in_facets[2], 8);
  s21_remove_data_viewer(&data);
}
END_TEST

Suite *get_data_viewer_suite(void) {
  Suite *s = suite_create("Get_data_viewer");
  TCase *tc_create = tcase_create("Get_data_viewer");
  tcase_add_test(tc_create, get_data_viewer_1);
  suite_add_tcase(s, tc_create);
  return s;
}
