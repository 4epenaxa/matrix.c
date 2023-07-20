#include "tests.h"

START_TEST(s21_create_remove) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(INT_MAX, 1, &A), ERROR_MATR);
  ck_assert_int_eq(s21_create_matrix(1, INT_MAX, &A), ERROR_MATR);
  ck_assert_int_eq(s21_create_matrix(0, 3, &A), ERROR_MATR);
  ck_assert_int_eq(s21_create_matrix(3, 0, &A), ERROR_MATR);
  ck_assert_int_eq(s21_create_matrix(INT_MAX, INT_MAX, &A), ERROR_MATR);
  ck_assert_int_eq(s21_create_matrix(0, 0, &A), ERROR_MATR);
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&A);
  s21_remove_matrix(NULL);
}
END_TEST

Suite *test_create_remove(void) {
  Suite *s = suite_create("\033[41m-=S21_CREATE_REMOVE=-\033[0m"RAINBOW_COLORS);
  TCase *tc = tcase_create("s21_remove_tc");

  tcase_add_test(tc, s21_create_remove);

  suite_add_tcase(s, tc);
  return s;
}