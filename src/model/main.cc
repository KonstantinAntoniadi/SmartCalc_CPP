#include <cstring>

#include "expression.h"

int v() {
  std::cout << "calc" << std::endl;
  return 10;
}

int main() {
  std::string str = "d4";
  auto start = str.begin();
  // std::string number;
  double number = 0;
  int count;
  sscanf(&start[0], "%le%n", &number, &count);

  std::cout << number << std::endl;
  std::cout << count << std::endl;

  return 0;
}
