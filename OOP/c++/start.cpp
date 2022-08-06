#include <string.h>

#include <iostream>

class Person {
    // access modifiers
   private:
    // private members
    std::string name;
    int age;

   public:
    // Constructor
    Person() {
        std::cout << "Person constructor" << std::endl;
    };

    // Destructor
    ~Person() {
        std::cout << "Person destructor" << std::endl;
    };

    // Member function
    void doSomething() {
        std::cout << "doSomething" << std::endl;
    };
};

int main() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}