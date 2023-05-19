#include <check.h>

#include "../backend/calc.h"

#define eps 1e-7

START_TEST(test_smart_calc_1) {
  char input[255] = "1+5*2/(3-5)^2";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 3.5, eps);
}
END_TEST

START_TEST(test_smart_calc_2) {
  char input[255] = "2+2+2+4*5*6^7";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 5598726, eps);
}
END_TEST

START_TEST(test_smart_calc_3) {
  char input[255] = "123.123+2*3^4";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 285.123, eps);
}
END_TEST

START_TEST(test_smart_calc_4) {
  char input[255] = "(8+2*5)/(1+3*2-4)";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq(result, 6);
}
END_TEST

START_TEST(test_smart_calc_5) {
  char input[255] =
      "(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/(7-(1+1))*3-(2+(1+1+1-1*2/2)))";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 10, eps);
}
END_TEST

START_TEST(test_smart_calc_6) {
  char input[255] = "cos(1*2)-1";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, -1.41614683655, eps);
}
END_TEST

START_TEST(test_smart_calc_7) {
  char input[255] =
      "cos(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/(7-(1+1))*3-(2+(1+1+1-1*2/"
      "2)))-1";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, -1.83907152908, eps);
}
END_TEST

START_TEST(test_smart_calc_8) {
  char input[255] = "sin(cos(5))";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 0.27987335076, eps);
}
END_TEST

START_TEST(test_smart_calc_9) {
  char input[255] = "2.33mod1";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 0.33, eps);
}
END_TEST

START_TEST(test_smart_calc_10) {
  char input[255] = "3+4*2/1-5+2^2";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 10, eps);
}
END_TEST

START_TEST(test_smart_calc_11) {
  double x = 10;
  char input[255] = "x*x";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 100, 1e-05);
}
END_TEST

START_TEST(test_smart_calc_12) {
  double x = 0.0003;
  char input[255] = "asin(2*x)";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 0.0006, eps);
}
END_TEST

START_TEST(test_smart_calc_13) {
  double x = 0.0019;
  char input[255] = "acos(2*x)";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 1.567, 1e-05);
}
END_TEST

START_TEST(test_smart_calc_14) {
  double x = 0.0019;
  char input[255] = "atan(2*x)";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 0.00379998, eps);
}
END_TEST

START_TEST(test_smart_calc_15) {
  double x = 0.004;
  char input[255] = "tan(2*x)";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 0.00800017, eps);
}
END_TEST

START_TEST(test_smart_calc_16) {
  double x = 25;
  char input[255] = "sqrt(2*x)";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 7.07107, 1e-05);
}
END_TEST

START_TEST(test_smart_calc_17) {
  double x = 2;
  char input[255] = "ln(10*x)";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 2.99573, 1e-05);
}
END_TEST

START_TEST(test_smart_calc_18) {
  double x = 2;
  char input[255] = "log(10*x)";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 1.30103, 1e-05);
}
END_TEST

START_TEST(test_smart_calc_19) {
  char input[255] = "()";
  char postfix[255] = {0};
  int result = getPostfix(input, postfix);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_smart_calc_20) {
  char input[255] = "4-(-4)";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 8, eps);
}
END_TEST

START_TEST(test_smart_calc_21) {
  char input[255] = "3-(+3)";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 0, eps);
}
END_TEST

START_TEST(test_smart_calc_22) {
  char input[255] = "4 + 2 + 1 + 4";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 11, eps);
}
END_TEST

START_TEST(test_smart_calc_23) {
  char input[255] = "4 + 2 - 1 + 4";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 9, eps);
}
END_TEST

START_TEST(test_smart_calc_24) {
  char input[255] = "(4 + 2) - (1 + 4)";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 1, eps);
}
END_TEST

START_TEST(test_smart_calc_25) {
  char input[255] = "5 * (1 + 2)";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 15, eps);
}
END_TEST

START_TEST(test_smart_calc_26) {
  char input[255] = "5 * 1 + 2 * 3";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 11, eps);
}
END_TEST

START_TEST(test_smart_calc_27) {
  char input[255] = "( 4 + 2 ) - ( 1 + 4 )";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 1, eps);
}
END_TEST

START_TEST(test_smart_calc_28) {
  char input[255] = "5 * ( 1 + 2 )";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, 15, eps);
}
END_TEST

START_TEST(test_smart_calc_29) {
  double x = 10;
  char input[255] = "x";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 10, 1e-05);
}
END_TEST

START_TEST(test_smart_calc_30) {
  double x = 10;
  char input[255] = "sin(x)";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, -0.5440211, eps);
}
END_TEST

START_TEST(test_smart_calc_31) {
  double x = 11.123431;
  char input[255] = "x*x*x";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 1376.310095485, eps);
}
END_TEST

START_TEST(test_smart_calc_32) {
  double x = 11.123431;
  char input[255] = "x+x*x";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 134.8541482118, eps);
}
END_TEST

START_TEST(test_smart_calc_33) {
  double x = 134.8541482118;
  char input[255] = "1/x";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 0.007415418904, eps);
}
END_TEST

START_TEST(test_smart_calc_34) {
  double x = 1314;
  char input[255] = "tan(x)";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 1.0594791199, eps);
}
END_TEST

START_TEST(test_smart_calc_35) {
  double x = 1.124;
  char input[255] = "x*sin(x)";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 1.0136636264, eps);
}
END_TEST

START_TEST(test_smart_calc_36) {
  double x = 1.124;
  char input[255] = "sin(sin(sin(sin(1/ln(x^123)))))";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 0.06932760382, eps);
}
END_TEST

START_TEST(test_smart_calc_37) {
  double x = 0;
  char input[255] = "1";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 1, eps);
}
END_TEST

START_TEST(test_smart_calc_38) {
  double x = 0;
  char input[255] = "-1";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, -1, eps);
}
END_TEST

START_TEST(test_smart_calc_39) {
  double x = 1.124;
  char input[255] = "-x*2";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, -2.248, eps);
}
END_TEST

START_TEST(test_smart_calc_40) {
  double x = 1.124;
  char input[255] = "sqrt(-(-x^(-2)))";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, x, &result);
  ck_assert_double_eq_tol(result, 0.8896797153, eps);
}
END_TEST

START_TEST(test_smart_calc_41) {
  char input[255] = "cos(";
  char postfix[255] = {0};
  int result = getPostfix(input, postfix);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_smart_calc_42) {
  char input[255] = "-)";
  char postfix[255] = {0};
  int result = getPostfix(input, postfix);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_smart_calc_43) {
  char input[255] = "cos(sin(tan(";
  char postfix[255] = {0};
  int result = getPostfix(input, postfix);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_smart_calc_44) {
  char input[255] =
      "cos(1.3425/(7.234-(1.123+1))*3-(2+(1+1-1+1*2/23.2))+15/"
      "(7-(1+1.234))*3-(2+(1+1+1-1*2/"
      "2)))-10123.1";
  char postfix[255] = {0};
  getPostfix(input, postfix);
  double result = 0;
  calculate(postfix, 0, &result);
  ck_assert_double_eq_tol(result, -10124.0999978229, eps);
}
END_TEST

START_TEST(test_smart_calc_45) {
  char input[255] = "sdfaasdf";
  char postfix[255] = {0};
  int result = getPostfix(input, postfix);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_smart_calc_46) {
  char input[255] = "5..4+21.1";
  char postfix[255] = {0};
  int result = getPostfix(input, postfix);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_smart_calc_47) {
  double loan = 300000.0;
  int period = 18;
  double rate = 15.0;
  double montAnnuity = monthAnnuity(loan, period, rate);
  ck_assert_double_eq_tol(montAnnuity, 18715.44, 1e-02);
}
END_TEST

Suite *calculate_suite(void) {
  Suite *s1 = suite_create("s21_smart_calc: ");
  TCase *tc1_1 = tcase_create("s21_smart_calc: ");
  tcase_add_test(tc1_1, test_smart_calc_1);
  tcase_add_test(tc1_1, test_smart_calc_2);
  tcase_add_test(tc1_1, test_smart_calc_3);
  tcase_add_test(tc1_1, test_smart_calc_4);
  tcase_add_test(tc1_1, test_smart_calc_5);
  tcase_add_test(tc1_1, test_smart_calc_6);
  tcase_add_test(tc1_1, test_smart_calc_7);
  tcase_add_test(tc1_1, test_smart_calc_8);
  tcase_add_test(tc1_1, test_smart_calc_9);
  tcase_add_test(tc1_1, test_smart_calc_10);
  tcase_add_test(tc1_1, test_smart_calc_11);
  tcase_add_test(tc1_1, test_smart_calc_12);
  tcase_add_test(tc1_1, test_smart_calc_13);
  tcase_add_test(tc1_1, test_smart_calc_14);
  tcase_add_test(tc1_1, test_smart_calc_15);
  tcase_add_test(tc1_1, test_smart_calc_16);
  tcase_add_test(tc1_1, test_smart_calc_17);
  tcase_add_test(tc1_1, test_smart_calc_18);
  tcase_add_test(tc1_1, test_smart_calc_19);
  tcase_add_test(tc1_1, test_smart_calc_20);
  tcase_add_test(tc1_1, test_smart_calc_21);
  tcase_add_test(tc1_1, test_smart_calc_22);
  tcase_add_test(tc1_1, test_smart_calc_23);
  tcase_add_test(tc1_1, test_smart_calc_24);
  tcase_add_test(tc1_1, test_smart_calc_25);
  tcase_add_test(tc1_1, test_smart_calc_26);
  tcase_add_test(tc1_1, test_smart_calc_27);
  tcase_add_test(tc1_1, test_smart_calc_28);
  tcase_add_test(tc1_1, test_smart_calc_29);
  tcase_add_test(tc1_1, test_smart_calc_30);
  tcase_add_test(tc1_1, test_smart_calc_31);
  tcase_add_test(tc1_1, test_smart_calc_32);
  tcase_add_test(tc1_1, test_smart_calc_33);
  tcase_add_test(tc1_1, test_smart_calc_34);
  tcase_add_test(tc1_1, test_smart_calc_35);
  tcase_add_test(tc1_1, test_smart_calc_36);
  tcase_add_test(tc1_1, test_smart_calc_37);
  tcase_add_test(tc1_1, test_smart_calc_38);
  tcase_add_test(tc1_1, test_smart_calc_39);
  tcase_add_test(tc1_1, test_smart_calc_40);
  tcase_add_test(tc1_1, test_smart_calc_41);
  tcase_add_test(tc1_1, test_smart_calc_42);
  tcase_add_test(tc1_1, test_smart_calc_43);
  tcase_add_test(tc1_1, test_smart_calc_44);
  tcase_add_test(tc1_1, test_smart_calc_45);
  tcase_add_test(tc1_1, test_smart_calc_46);
  tcase_add_test(tc1_1, test_smart_calc_47);

  suite_add_tcase(s1, tc1_1);
  return s1;
}

void srunner_test(Suite *s, int *no_failed) {
  SRunner *srunner = srunner_create(s);
  srunner_run_all(srunner, CK_NORMAL);
  *no_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);
}

int main() {
  int no_failed = 0;
  srunner_test(calculate_suite(), &no_failed);

  return (no_failed == 0) ? 0 : 1;
}
