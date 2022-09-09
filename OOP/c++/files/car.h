#ifndef _CAR_H
#define _CAR_H
#include <iostream>

class Car {
 private:
  std::string manufacturer;
  float fuel;
  float speed;
  int registerationNum;
  bool isRunning;

 public:
  Car(const std::string manu, float fuel, int reg);
  void switchOn();
  void switchOff();
  void accelerate();
  void brake();
  void dashboard();
  void fillFuel(float amount);
  float getFuel();
  float getSpeed();
};

// // Include CPP in Header
// #ifndef _CAR_CPP_INCLUDED_
// #define _CAR_CPP_INCLUDED_
// #include "car.cpp"
// #endif
#endif  // CAR_H