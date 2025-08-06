#pragma once

#include <string>

class ScalarConverter {
private:
  ScalarConverter() = delete;
  ScalarConverter(const std::string l) = delete;
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter &other) = delete;
  ScalarConverter &operator=(const ScalarConverter &other) = delete;

public:
  static void convert(std::string l);
};
