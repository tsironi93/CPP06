#include "./Base.hpp"
#include <iostream>

int main() {
  Base *obj = generate();

  std::cout << "Identify using pointer: ";
  identify(obj);

  std::cout << "Identify using reference: ";
  identify(*obj);

  delete obj;
  return 0;
}
