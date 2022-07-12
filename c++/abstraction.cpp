#include <iostream>

// It's also an example of polymorphism
class Abstraction {
   public:
   // virtual function
    virtual void method1() {
        std::cout << "Abstract Method" << std::endl;
    }
    // pure virtual function
    virtual void method2() = 0;
};

class Implementation : public Abstraction {
   public:
    virtual void method1() {
        std::cout << "Implementation1 Method1" << std::endl;
    }
    virtual void method2() {
        std::cout << "Implementation1 Method1" << std::endl;
    }
};
class Implementation2 : public Abstraction {
   public:
    virtual void method2() {
        std::cout << "Implementation2 Method2" << std::endl;
    }
};

// It's also an example of polymorphism
class Interface {
   public:
   // pure virtual function
    virtual void method1() = 0;
    // pure virtual function
    virtual void method2() = 0;
};

class InterfaceImplementation : public Interface {
   public:
    void method1() {
        std::cout << "Interface Method1" << std::endl;
    }
    void method2() {
        std::cout << "Interface Method2" << std::endl;
    }
};

int main() {
    std::cout << "App Started" << std::endl;
    // Abstraction *app1 = new Implementation();
    // app1->method1();
    // app1->method2();
    // Abstraction *app2 = new Implementation2();
    // app2->method1();
    // app2->method2();
    // Interface *app3Interface = new InterfaceImplementation();
    // app3Interface->method1();
    // app3Interface->method2();
    std::cout << "App Ended" << std::endl;
    return 0;
}