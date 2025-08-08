#include "./Serializer.hpp"
#include <exception>
#include <ios>
#include <iostream>

int main() {

  Data *ptr = new Data;

  ptr->malaka = true;

  if (ptr->malaka)
    std::cout << Serializer::serialize(ptr) << std::endl;

  Data *nullPtr = nullptr;
  std::cout << Serializer::serialize(nullPtr) << std::endl;

  try {
    Data *a = Serializer::deserialize(Serializer::serialize(ptr));
    std::cout << std::boolalpha << "The Malaka is: " << a->malaka << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  delete ptr;

  return 0;
}
