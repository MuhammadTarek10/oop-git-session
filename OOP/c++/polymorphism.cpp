#include <iostream>

class Polymorphism {
   public:
    // virtual function
    virtual void method1() {
        std::cout << "Polymorphism: method1()" << std::endl;
    }

    virtual void method2() {
        std::cout << "Polymorphism: method2()" << std::endl;
    }

    virtual void method2(int a) {
        std::cout << "Polymorphism: method2(int a)" << std::endl;
    }
};

class App : public Polymorphism {
   public:
    void method1() {
        std::cout << "App: method1()" << std::endl;
    }
};

class App2 : public Polymorphism {
   public:
    void method1() {
        std::cout << "App2: method1()" << std::endl;
    }
};

int main() {
    std::cout << "App Started" << std::endl;
    // int choice = 0;
    // Polymorphism *app;
    // while (true) {
    //     std::cin >> choice;
    //     if (choice == 1)
    //         app = new App();
    //     else if (choice == 2)
    //         app = new App2();
    //     else {
    //         std::cout << "Invalid Choice" << std::endl;
    //         break;
    //     }
    //     app->method1();
    //     app->method2();
    //     app->method2(10);
    //     delete app;
    // }
    std::cout << "App Ended" << std::endl;
    return 0;
}