#include "./Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {}

Base *generate() {
  std::srand(static_cast<unsigned int>(std::time(0)));
  int r = std::rand() % 3;
  switch (r) {
  case 0:
    return new A;
  case 1:
    return new B;
  default:
    return new C;
  }
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A\n";
  else if (dynamic_cast<B *>(p))
    std::cout << "B\n";
  else if (dynamic_cast<C *>(p))
    std::cout << "C\n";
  else
    std::cout << "Unknown\n";
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A\n";
    return;
  } catch (...) {
  }

  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "B\n";
    return;
  } catch (...) {
  }

  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "C\n";
    return;
  } catch (...) {
  }

  std::cout << "Unknown\n";
}
