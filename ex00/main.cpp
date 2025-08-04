

#include <iostream>
int main(int ac, char **av) {

  (void)av;
  if (ac != 2) {
    std::cerr << "Help" << std::endl;
    return 1;
  }
}
