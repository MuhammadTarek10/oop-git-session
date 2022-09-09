#include <iostream>

class Parent {
 private:
  int x;
  int y;
  void privateFunc();

 protected:
  int z;
  void protectedFunc();

 public:
  Parent(){};
  int w;
  void publicFunc() { std::cout << "Parent\n"; };
};

class Child : public Parent {
 public:
  void publicFunc() { std::cout << "Child\n"; }
};

int main() {
  Parent parent;
  Child child;

  Parent s = Child();

  parent.publicFunc();
  child.publicFunc();
  s.publicFunc();

  return 0;
}