// remove if you included the cpp in header
#include "car.h"

Car::Car(const std::string manu, float fuel, int reg) {
    manufacturer = manu;
    registerationNum = reg;
    this->fuel = fuel;
    speed = 0;
    isRunning = false;
}

void Car::switchOn() {
    isRunning = true;
}

void Car::switchOff() {
    isRunning = false;
}

void Car::accelerate() {
    if (!isRunning)
        return;
    ++speed;
    fuel -= 1.5f;
}

void Car::brake() {
    speed = 0;
}

void Car::dashboard() {
    std::cout << "Speed: " << speed << std::endl;
    std::cout << "Fuel: " << fuel << std::endl;
}

void Car::fillFuel(float amount) {
    fuel += amount;
}

float Car::getFuel() {
    return fuel;
}

float Car::getSpeed() {
    return speed;
}