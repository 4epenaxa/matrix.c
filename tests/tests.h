#ifndef SRC_TESTS_TEST_H
#define SRC_TESTS_TEST_H

#include <check.h>
#include <stdlib.h>
#include "../s21_matrix.h"

Suite *test_create_remove(void);
Suite *test_equal(void);
Suite *test_sum(void);
Suite *test_sub(void);
Suite *test_mult_number(void);
Suite *test_mult_matrix(void);
Suite *test_transpose(void);
Suite *test_calc_complements(void);
Suite *test_determinant(void);
Suite *test_inverse(void);

#endif  // SRC_TESTS_TEST_H
