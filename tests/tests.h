#ifndef SRC_TESTS_TEST_H
#define SRC_TESTS_TEST_H

#include <check.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "../s21_matrix.h"

#define RAINBOW_COLORS "\033[48;2;255;165;0m     \033[43m     \033[42m     \033[46m     \033[44m     \033[45m     \033[0m"

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

double random_double(void);

#endif  // SRC_TESTS_TEST_H
