#include "./ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <exception>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>

ScalarConverter::~ScalarConverter() {}

enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID };

static Type findType(const std::string &s) {
  if (s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]))
    return CHAR;

  if (s == "nan" || s == "+inf" || s == "-inf")
    return DOUBLE;

  if (s == "nanf" || s == "+inff" || s == "-inff")
    return FLOAT;

  size_t i = 0;

  if (s[i] == '-' || s[i] == '+')
    ++i;

  bool dot = false;
  bool f = false;

  for (; i < s.length(); ++i) {
    if (s[i] == '.' && !dot)
      dot = true;
    else if (s[i] == 'f' && i == s.length() - 1)
      f = true;
    else if (!isdigit(s[i]))
      return INVALID;
  }

  if (f && dot)
    return FLOAT;
  if (dot)
    return DOUBLE;
  return INT;
}

void ScalarConverter::convert(std::string l) {

  Type t = findType(l);
  char cVal;
  int iVal;
  float fVal;
  double dVal;

  try {
    switch (t) {
    case CHAR:
      cVal = l[0];
      iVal = static_cast<int>(cVal);
      fVal = static_cast<float>(cVal);
      dVal = static_cast<double>(cVal);
      break;
    case INT:
      iVal = std::stoi(l);
      fVal = static_cast<float>(iVal);
      dVal = static_cast<double>(iVal);
      cVal = static_cast<char>(iVal);
      break;
    case FLOAT:
      fVal = std::stof(l);
      iVal = static_cast<int>(fVal);
      dVal = static_cast<double>(fVal);
      cVal = static_cast<char>(fVal);
      break;
    case DOUBLE:
      dVal = std::stod(l);
      iVal = static_cast<int>(dVal);
      fVal = static_cast<float>(dVal);
      cVal = static_cast<char>(dVal);
      break;
    case INVALID:
    default:
      std::cout << "Invalid literal." << std::endl;
      return;
    }
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
    return;
  }

  std::cout << "char: ";
  if (std::isnan(dVal) || dVal < 0 || dVal > 127)
    std::cout << "impossible" << std::endl;
  else if (!std::isprint(cVal))
    std::cout << "Non displayable" << std::endl;
  else
    std::cout << cVal << std::endl;

  std::cout << "int: ";
  if (std::isnan(dVal) || dVal > std::numeric_limits<int>::max() ||
      dVal < std::numeric_limits<int>::min())
    std::cout << "impossible" << std::endl;
  else
    std::cout << iVal << std::endl;

  std::cout << "float: " << std::fixed << std::setprecision(1) << fVal << "f"
            << std::endl;

  std::cout << "double: " << std::fixed << std::setprecision(1) << dVal
            << std::endl;
}
