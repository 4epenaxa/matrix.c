#include "tests.h"

int main(void) {
  Suite *s21_matrix_test[] = {test_create_remove(),
                              test_equal(),
                              test_sum(),
                              test_sub(),
                              test_mult_number(),
                              test_mult_matrix(),
                              test_transpose(),
                              test_determinant(),
                              test_calc_complements(),
                              test_inverse(),

                              NULL};
  for (int i = 0; s21_matrix_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_matrix_test[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
  }
  return 0;
}

double random_double(void) {
  return (DBL_MIN + ((double)rand() / RAND_MAX) * (DBL_MAX - DBL_MIN)) *
         (rand() % 2 ? 1 : -1);
}
