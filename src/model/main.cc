#include <cstring>

#include "expression.h"

int v() {
  std::cout << "calc" << std::endl;
  return 10;
}

int main() {
  // s21::Calculator calc("test");
  s21::Expression expression("2+2");
  std::cout << expression.Calculate(0) << std::endl;
  // std::string str = "123456789asd";
  // auto it = str.begin();
  // std::cout << str.at(10) << std::endl;
  
  // std::cout << strtod(&it[0], &it[0]) << std::endl;

  // for (int i = 0; i < v(); i++) {
  //   std::cout << i << std::endl;
  // }
}
