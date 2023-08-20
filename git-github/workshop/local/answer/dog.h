#ifndef _DOG_H_
#define _DOG_H_

#include <iostream>

#include "animal.h"

class Dog : public Animal {
 public:
  void makeSound();
};

#endif