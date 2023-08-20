#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <string>

class Animal {
 private:
  std::string name;
  int age;

 public:
  virtual void makeSound() = 0;
};

#endif