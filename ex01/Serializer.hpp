#pragma once

#include <cstdint>
#include <string>

struct Data {
  bool malaka;
};

class Serializer {
private:
  Serializer() = delete;
  Serializer(const std::string &) = delete;
  ~Serializer();
  Serializer(const Serializer &other) = delete;
  Serializer operator=(const Serializer &other) = delete;

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};
