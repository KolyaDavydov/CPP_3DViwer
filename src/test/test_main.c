#include "test_main.h"

int main(void) {
  int no_failed = 0;
  SRunner *runner;
  runner = srunner_create(create_suite());
  srunner_add_suite(runner, mult_number_suite());
  srunner_add_suite(runner, maxmin_suite());
  srunner_add_suite(runner, get_data_viewer_suite());
  srunner_add_suite(runner, scaling_obj_suite());
  srunner_add_suite(runner, moving_obj_suite());
  srunner_add_suite(runner, rotation_obj_suite());
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}