#include "test.h"

// namespace s21 {
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// }  // namespace s21
