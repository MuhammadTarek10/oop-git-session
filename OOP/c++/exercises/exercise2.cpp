/*
    2. Write a program that defines a shape class with a constructor that gives
   value to width and height. The define two sub-classes triangle and rectangle,
   that calculate the area of the shape area (). In the main, define two
   variables a triangle and a rectangle and then call the area() function in
   this two varibles.
*/

#include <iostream>

class Shape {
 protected:
  float height;
  float width;

 public:
  Shape(float h, float w) {
    height = h;
    width = w;
  };

  Shape() {
    height = 0;
    width = 0;
  };

  virtual void area() = 0;
};

class Triangle : public Shape {
 public:
  Triangle(float h, float w) : Shape(h, w){};

  virtual void area() { std::cout << (0.5 * height * width) << std::endl; }
};

class Rectangle : public Shape {
 public:
  Rectangle(float h, float w) : Shape(h, w){};

  virtual void area() { std::cout << height * width << std::endl; }
};

int main() {
  Triangle t = Triangle(5, 2);
  Rectangle r = Rectangle(5, 2);

  t.area();
  r.area();

  return 0;
}

