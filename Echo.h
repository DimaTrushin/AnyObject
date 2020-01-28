#ifndef ECHO_H
#define ECHO_H

#include <iostream>

class Echo {
public:
  Echo() {
    std::cout << "R()" << std::endl;
  }
  template<class T>
  Echo(T) {
    std::cout << "R(T)" << std::endl;
  }
  ~Echo() {
    std::cout << "~R()" << std::endl;
  }
  Echo(const Echo&) {
    std::cout << "R(constR&)" << std::endl;

  }
  Echo(Echo&&) noexcept {
    std::cout << "R(R&&)" << std::endl;
  }
  Echo& operator=(const Echo&) {
    std::cout << "=(constR&)" << std::endl;
    return *this;
  }
  Echo& operator=(Echo&&) noexcept {
    std::cout << "=(R&&)" << std::endl;
    return *this;
  }
};

#endif // ECHO_H
