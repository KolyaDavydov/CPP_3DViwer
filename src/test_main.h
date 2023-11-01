#ifndef TEST_MAIN_H_
#define TEST_MAIN_H_

#include <check.h>
#include <stdlib.h>

#include "s21_get_data_viewer.h"
#include "s21_matrix.h"

Suite *create_suite(void);
Suite *mult_number_suite(void);
Suite *maxmin_suite(void);
Suite *get_data_viewer_suite(void);
Suite *scaling_obj_suite(void);
Suite *moving_obj_suite(void);
Suite *rotation_obj_suite(void);

#endif  // TEST_MAIN_H_
