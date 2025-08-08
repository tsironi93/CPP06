#include "./Serializer.hpp"
#include <cstdint>
#include <exception>
#include <iostream>
#include <stdexcept>

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr) {
  return [ptr]() -> uintptr_t {
    try {
      if (!ptr)
        throw std::invalid_argument("NULL PTR");
      return reinterpret_cast<uintptr_t>(ptr);
    } catch (const std::exception &e) {
      std::cerr << "Serialization Error: " << e.what() << std::endl;
      return 0;
    }
  }();
}

Data *Serializer::deserialize(uintptr_t raw) {

  if (raw > static_cast<unsigned long>(~uintptr_t(0))) {
    throw std::out_of_range("Value too large for uintptr_t");
  }

  if (raw == 0) {
    throw std::invalid_argument("Cannot deserialize null pointer");
  }

  uintptr_t ptrVal = static_cast<uintptr_t>(raw);

  return reinterpret_cast<Data *>(ptrVal);
}
