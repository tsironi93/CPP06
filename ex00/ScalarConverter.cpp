#include "./ScalarConverter.hpp"
#include <ostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

static void ScalarConverter::convert(std::string l) {

  int i = <cast int> l;
  std::cout << "int: " << i << std::endl;
}
