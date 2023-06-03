#include "test.h"

namespace s21 {
constexpr double eps = 1e-02;
class s21CreditTest : public testing::Test {
 protected:
  double loan_ = 300000;
  int period_ = 18;
  double rate_ = 15;
  Credit credit_{loan_, period_,
                 rate_};  //  почему нельзя круглые скобки применить?

  double MonthPaymenAnnuity_ = 18715.44;
  double OverpaymentAnnuity_ = 36877.85;
  double TotalPayoutAnnuity_ = 336877.85;

  double FirstPaymentDifferentiated_ = 20416.67;
  double LastPaymentDifferentiated_ = 16875.00;
  double OverpaymentDifferentiated_ = 35625.00;
  double TotalPayoutDifferentiated_ = 335625.00;
};

TEST_F(s21CreditTest, AnnuityTest) {
  credit_.CalcAnnuity();
  EXPECT_LT(std::abs(credit_.GetMonthPayment() - MonthPaymenAnnuity_), eps);
  EXPECT_LT(std::abs(credit_.GetOverpayment() - OverpaymentAnnuity_), eps);
  EXPECT_LT(std::abs(credit_.GetTotalPayment() - TotalPayoutAnnuity_), eps);
}

TEST_F(s21CreditTest, DifferentiatedTest) {
  credit_.CalcDifferentiated();
  EXPECT_LT(std::abs(credit_.GetFirstPayment() - FirstPaymentDifferentiated_),
            eps);
  EXPECT_LT(std::abs(credit_.GetLastPayment() - LastPaymentDifferentiated_),
            eps);
  EXPECT_LT(std::abs(credit_.GetOverpayment() - OverpaymentDifferentiated_),
            eps);
  EXPECT_LT(std::abs(credit_.GetTotalPayment() - TotalPayoutDifferentiated_),
            eps);
}
}  // namespace s21
