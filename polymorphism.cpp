#include <iostream>

class Polymorphism {
   public:
    virtual void virtual_method() {
        std::cout << "Polymorphism::virtual_method()" << std::endl;
    }
};

class Abstraction : public Polymorphism {
   public:
    void abstract_method() {
        std::cout << "Abstraction::abstract_method()" << std::endl;
    }
};

class App : public Abstraction {
   public:
    void virtual_method() {
        std::cout << "App::virtual_method()" << std::endl;
    }
};



int main() {
    std::cout << "App Started" << std::endl;
    std::cout << "App Ended" << std::endl;
    return 0;
}