#include "test.h"

// START_TEST(test_sub_uninitialized) {
//   matrix_t A;
//   s21_create_matrix(2, 2, &A);
//   ck_assert_int_eq(s21_sub_matrix(NULL, NULL, &A), ERROR_MATR);
//   ck_assert_int_eq(s21_sub_matrix(NULL, &A, NULL), ERROR_MATR);
//   ck_assert_int_eq(s21_sub_matrix(&A, NULL, NULL), ERROR_MATR);
//   s21_remove_matrix(&A);
// }
// END_TEST


START_TEST(test_sub_rows) {
  matrix_t A, B, C;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &C), ERROR_CALC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_sub(void) {
  Suite *s = suite_create("\033[45m-=S21_SUB=-\033[0m");
  TCase *tc = tcase_create("s21_sub_tc");

  //tcase_add_test(tc, test_sub_uninitialized);
  tcase_add_test(tc, test_sub_rows);

  suite_add_tcase(s, tc);
  return s;
}