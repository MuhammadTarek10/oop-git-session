#include <iostream>

class Toy {
 protected:
  std::string name;
  float price;

 public:
  virtual void prepareParts() = 0;
  virtual void combineParts() = 0;
  virtual void assembleParts() = 0;
  virtual void applyLabel() = 0;

  virtual void showProduct() = 0;
};

class Car : public Toy {
  virtual void prepareParts() { std::cout << "Car prepared" << std::endl; };
  virtual void combineParts() { std::cout << "Car combined" << std::endl; };
  virtual void assembleParts() { std::cout << "Car assembeled" << std::endl; };
  virtual void applyLabel() {
    std::cout << "Car Labeled" << std::endl;
    name = "Car";
    price = 10;
  };

  virtual void showProduct() {
    std::cout << name << ": " << price << std::endl;
  };
};

class Bike : public Toy {
  virtual void prepareParts() { std::cout << "Bike prepared" << std::endl; };
  virtual void combineParts() { std::cout << "Bike combined" << std::endl; };
  virtual void assembleParts() { std::cout << "Bike assembeled" << std::endl; };
  virtual void applyLabel() {
    std::cout << "Bike Labeled" << std::endl;
    name = "Bike";
    price = 20;
  };

  virtual void showProduct() {
    std::cout << name << ": " << price << std::endl;
  };
};

class Plane : public Toy {
  virtual void prepareParts() { std::cout << "Plane prepared" << std::endl; };
  virtual void combineParts() { std::cout << "Plane combined" << std::endl; };
  virtual void assembleParts() {
    std::cout << "Plane assembeled" << std::endl;
  };
  virtual void applyLabel() {
    std::cout << "Plane Labeled" << std::endl;
    name = "Plane";
    price = 30;
  };

  virtual void showProduct() {
    std::cout << name << ": " << price << std::endl;
  };
};