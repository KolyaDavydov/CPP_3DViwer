#include "test_main.h"

START_TEST(maxmin_1) {
  int rows = 3;
  int columns = 4;
  matrix_t A;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -7.369244237136674869;
  A.matrix[0][1] = 5.112106443900664488;
  A.matrix[0][2] = -0.826997361531013553;
  A.matrix[0][3] = 0.655344748243384956;
  A.matrix[1][0] = -5.620816273438192567;
  A.matrix[1][1] = -9.059107675710277974;
  A.matrix[1][2] = 3.577294337366378585;
  A.matrix[1][3] = 3.585928116732244320;
  A.matrix[2][0] = 8.693857918816551233;
  A.matrix[2][1] = -2.329958450202810560;
  A.matrix[2][2] = 0.388327441359091807;
  A.matrix[2][3] = 6.619306922247311320;
  double max, min;
  int answer = s21_get_maxmin_matrix(&A, &max, &min);
  ck_assert_int_eq(0, answer);
  ck_assert_double_eq(max, A.matrix[2][0]);
  ck_assert_double_eq(min, A.matrix[1][1]);
  s21_remove_matrix(&A);
}
END_TEST

Suite *maxmin_suite(void) {
  Suite *s = suite_create("MAXMIN");
  TCase *tc_create = tcase_create("MAXMIN");
  tcase_add_test(tc_create, maxmin_1);
  suite_add_tcase(s, tc_create);
  return s;
}
