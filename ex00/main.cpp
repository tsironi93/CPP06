#include "./ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av) {

  (void)av;
  if (ac != 2) {
    std::cerr << "Help" << std::endl;
    return 1;
  }

  ScalarConverter::convert(av[1]);
  return 0;
}
