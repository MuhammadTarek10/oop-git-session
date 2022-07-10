#include <iostream>

class Inheritance { // can be named parent
   public:
    virtual void virtual_method() {
        std::cout << "Inheritance::virtual_method()" << std::endl;
    }
};

class App : public Inheritance { // can be named child
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