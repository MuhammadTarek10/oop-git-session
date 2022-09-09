#include <iostream>

class Inheritance {  // can be named parent
   public:
    int age;

    Inheritance() {
        this->age = 0;
    }

    // virtual function
    virtual void method1() {
        std::cout << "Inheritance: method1()" << std::endl;
    }
    virtual void method2() {
        std::cout << "Inheritance: method2()" << std::endl;
    }
};

class App : public Inheritance {  // can be named child
   public:
    void method1() {
        std::cout << "App: method1()" << std::endl;
    }
};

int main() {
    std::cout << "App Started" << std::endl;
    App app;
    app.method1();
    std::cout << "Age: " << app.age << std::endl;
    app.method2();
    std::cout << "App Ended" << std::endl;
    return 0;
}