#ifndef _CAT_H_
#define _CAT_H_

#include <iostream>

#include "animal.h"

class Cat : public Animal {
 public:
  void makeSound();
};

#include "cat.cpp"

#endif