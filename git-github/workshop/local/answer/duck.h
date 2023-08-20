#ifndef _DUCK_H_
#define _DUCK_H_

#include <iostream>

#include "animal.h"

class Duck : public Animal {
 public:
  void makeSound();
};

#include "duck.cpp"

#endif