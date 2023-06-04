#include "test.h"

namespace s21 {
class s21CalcTest : public testing::Test {
 protected:
  Expression expression_;

  std::string number_ = "21";
  double number_result_ = 21;
  std::string plus_ = "1+2+3+4";
  double plus_result_ = 1 + 2 + 3 + 4;
  std::string minus_ = "234-45-23434";
  double minus_result_ = 234 - 45 - 23434;
  std::string mul_ = "234*43";
  double mul_result_ = 234 * 43;
  std::string div_ = "23.234/1212.41";
  double div_result_ = 23.234 / 1212.41;
  std::string pow_ = "2^2^3";
  double pow_result_ = std::pow(2, std::pow(2, 3));
  std::string mod_ = "123.132mod24.01";
  double mod_result_ = std::fmod(123.132, 24.01);

  std::string all_binary_operatrions_ =
      "234.12/23.4+2.234*3.234-5.234^0.12mod234.1";
  double all_binary_operatrions_result_ =
      234.12 / 23.4 + 2.234 * 3.234 - std::fmod(std::pow(5.234, 0.12), 234.1);
  std::string brackets_ =
      "(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/(7-(1+1))*3-(2+(1+1+1-1*2/2)))";
  double brackets_result_ =
      (15 / (7 - (1 + 1)) * 3 - (2 + (1 + 1 - 1 + 1 * 2 / 2)) +
       15 / (7 - (1 + 1)) * 3 - (2 + (1 + 1 + 1 - 1 * 2 / 2)));

  std::string cos_ = "cos(1*2)-1";
  double cos_result_ = std::cos(1 * 2) - 1;
  std::string sin_ = "sin(12243.2343)";
  double sin_result_ = std::sin(12243.2343);
  std::string tan_ = "tan(5423.234)";
  double tan_result_ = std::tan(5423.234);
  std::string acos_ = "acos(0)";
  double acos_result_ = std::acos(0);
  std::string asin_ = "asin(1)";
  double asin_result_ = std::asin(1);
  std::string atan_ = "atan(5.0 / 10.0)";
  double atan_result_ = std::atan(5.0 / 10.0);
  std::string sqrt_ = "sqrt(32443)";
  double sqrt_result_ = std::sqrt(32443);
  std::string ln_ = "ln(123)";
  double ln_result_ = std::log(123);
  std::string log_ = "log(2343.123)";
  double log_result_ = std::log10(2343.123);

  std::string x_mul_ = "x*x";
  double x_for_mul_ = 10;
  double x_mul_result_ = x_for_mul_ * x_for_mul_;
  std::string many_trigonometry_ = "sin(sin(sin(sin(1.0/ln(x^123)))))";
  double x_for_many_trigonometry_ = 1.124;
  double many_trigonometry_result_ = std::sin(std::sin(std::sin(
      std::sin(1.0 / std::log(std::pow(x_for_many_trigonometry_, 123))))));

  std::string unar_minus_start_ = "-4+1";
  double unar_minus_start_result_ = -4 + 1;
  std::string unar_minus_after_bracket_ = "4-(-4)";
  double unar_minus_after_bracket_result_ = 4 - (-4);
  std::string unar_minus_before_bracket_ = "sqrt(-(-x^(-2)))";
  double x_for_unar_minus_before_bracket_ = 1.124;
  double unar_minus_before_bracket_result =
      std::sqrt(-(-std::pow(x_for_unar_minus_before_bracket_, (-2))));

  std::string unar_plus_start_ = "+4+1";
  double unar_plus_start_result_ = +4 + 1;
  std::string unar_plus_after_bracket_ = "4-(+4)";
  double unar_plus_after_bracket_result_ = 4 - (+4);
  std::string unar_plus_before_bracket_ = "sqrt(+(x^(-2)))";
  double x_for_unar_plus_before_bracket_ = 1.124;
  double unar_plus_before_bracket_result =
      std::sqrt(+(std::pow(x_for_unar_plus_before_bracket_, (-2))));

  std::string brackets_invalid_ = "()";
  std::string trigonometry_invalid_ = "cos(sin(tan(";
  std::string minus_bracket_invalid_ = "-)";
  std::string expression_invalid = "aezakmi";
};

TEST_F(s21CalcTest, NumberTest) {
  expression_.SetExpression(number_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), number_result_);
}

TEST_F(s21CalcTest, PlusTest) {
  expression_.SetExpression(plus_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), plus_result_);
}

TEST_F(s21CalcTest, MinusTest) {
  expression_.SetExpression(minus_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), minus_result_);
}

TEST_F(s21CalcTest, MulTest) {
  expression_.SetExpression(mul_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), mul_result_);
}

TEST_F(s21CalcTest, DivTest) {
  expression_.SetExpression(div_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), div_result_);
}

TEST_F(s21CalcTest, PowTest) {
  expression_.SetExpression(pow_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), pow_result_);
}

TEST_F(s21CalcTest, ModTest) {
  expression_.SetExpression(mod_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), mod_result_);
}

TEST_F(s21CalcTest, AllOperandsTest) {
  expression_.SetExpression(all_binary_operatrions_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), all_binary_operatrions_result_);
}

TEST_F(s21CalcTest, BracketsTest) {
  expression_.SetExpression(brackets_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), brackets_result_);
}

TEST_F(s21CalcTest, CosTest) {
  expression_.SetExpression(cos_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), cos_result_);
}

TEST_F(s21CalcTest, SinTest) {
  expression_.SetExpression(sin_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), sin_result_);
}

TEST_F(s21CalcTest, TanTest) {
  expression_.SetExpression(tan_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), tan_result_);
}

TEST_F(s21CalcTest, AcosTest) {
  expression_.SetExpression(acos_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), acos_result_);
}

TEST_F(s21CalcTest, AsinTest) {
  expression_.SetExpression(asin_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), asin_result_);
}

TEST_F(s21CalcTest, AtanTest) {
  expression_.SetExpression(atan_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), atan_result_);
}

TEST_F(s21CalcTest, SqrtTest) {
  expression_.SetExpression(sqrt_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), sqrt_result_);
}

TEST_F(s21CalcTest, LnTest) {
  expression_.SetExpression(ln_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), ln_result_);
}

TEST_F(s21CalcTest, LogTest) {
  expression_.SetExpression(log_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), log_result_);
}

TEST_F(s21CalcTest, ManyTrigonometryTest) {
  expression_.SetExpression(many_trigonometry_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(x_for_many_trigonometry_),
                   many_trigonometry_result_);
}

TEST_F(s21CalcTest, XMulTest) {
  expression_.SetExpression(x_mul_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(x_for_mul_), x_mul_result_);
}

TEST_F(s21CalcTest, UnarMinusStartTest) {
  expression_.SetExpression(unar_minus_start_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), unar_minus_start_result_);
}

TEST_F(s21CalcTest, UnarMinusAfterBracketTest) {
  expression_.SetExpression(unar_minus_after_bracket_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), unar_minus_after_bracket_result_);
}

TEST_F(s21CalcTest, UnarMinusBeforeBracketTest) {
  expression_.SetExpression(unar_minus_before_bracket_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(x_for_unar_minus_before_bracket_),
                   unar_minus_before_bracket_result);
}

TEST_F(s21CalcTest, UnarPlusStartTest) {
  expression_.SetExpression(unar_plus_start_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), unar_plus_start_result_);
}

TEST_F(s21CalcTest, UnarPlusAfterBracketTest) {
  expression_.SetExpression(unar_plus_after_bracket_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(), unar_plus_after_bracket_result_);
}

TEST_F(s21CalcTest, UnarPlusBeforeBracketTest) {
  expression_.SetExpression(unar_plus_before_bracket_);
  EXPECT_DOUBLE_EQ(expression_.Calculate(x_for_unar_plus_before_bracket_),
                   unar_plus_before_bracket_result);
}

TEST_F(s21CalcTest, BracketsInvalidTest) {
  expression_.SetExpression(brackets_invalid_);
  EXPECT_FALSE(expression_.IsValidExpression());
}

TEST_F(s21CalcTest, TrigonometryInvalidTest) {
  expression_.SetExpression(trigonometry_invalid_);
  EXPECT_FALSE(expression_.IsValidExpression());
}

TEST_F(s21CalcTest, MinusBracketInvalidTest) {
  expression_.SetExpression(minus_bracket_invalid_);
  EXPECT_FALSE(expression_.IsValidExpression());
}

TEST_F(s21CalcTest, ExpressionInvalidTest) {
  expression_.SetExpression(expression_invalid);
  EXPECT_FALSE(expression_.IsValidExpression());
}

}  // namespace s21
