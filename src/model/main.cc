#include "expression.h"
#include <cstring>

  int v(){
    std::cout << "calc" << std::endl;
    return 10;
  }

int main() {
  // s21::Calculator calc("test");
  // s21::Expression expression("2+2");
  std::string str = "123456789";
  auto it = str.begin();
  // std::cout << str.at(10) << std::endl;

  std::cout << !strncmp(&it[0], "123", 3) << std::endl;


  // for (int i = 0; i < v(); i++) {
  //   std::cout << i << std::endl;
  // }
}

