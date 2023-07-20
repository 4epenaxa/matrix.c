#include "tests.h"

START_TEST(test_mult_num_ok) {
  matrix_t A, B, RES;
  double num = random_double();
  int cols = rand() % 100 + 1;
  int rows = rand() % 100 + 1;
  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &RES);

  for (int i = 0; i < A.rows; i++)
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = random_double();
      RES.matrix[i][j] = A.matrix[i][j] * num;
    }

  ck_assert_int_eq(s21_mult_number(&A, num, &B), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &RES), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
}
END_TEST

// START_TEST(test_mult_num_uninitialized) {
//   matrix_t A;
//   s21_create_matrix(2, 2, &A);
//   ck_assert_int_eq(s21_mult_number(NULL, 3, NULL), ERROR_MATR);
//   ck_assert_int_eq(s21_mult_number(NULL, 72, &A), ERROR_MATR);
//   s21_remove_matrix(&A);
// }
// END_TEST

Suite *test_mult_number(void) {
  Suite *s = suite_create("\033[41m-=S21_MULT_NUMBER=-\033[0m"RAINBOW_COLORS"test_mult_num_uninitialized");
  TCase *tc = tcase_create("s21_mult_number_tc");

  srand(time(NULL));

  tcase_add_loop_test(tc, test_mult_num_ok, 0, 99);
  // tcase_add_test(tc, test_mult_num_uninitialized);

  suite_add_tcase(s, tc);
  return s;
}