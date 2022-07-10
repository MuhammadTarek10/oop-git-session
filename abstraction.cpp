#include <iostream>

class AbsractClass {
   public:
    virtual void method1() {
        std::cout << "ImplementedMethod" << std::endl;
    }
    virtual void mehtod2() = 0;
};

class ConcreteClass : public AbsractClass {
   public:
    void mehtod2() {
        std::cout << "NotImplementedMethod" << std::endl;
    }
};

class Interface {
   public:
    virtual void method1() = 0;
    virtual void method2() = 0;
};

class ConcreteClass2 : public Interface {
   public:
    void method1() {
        std::cout << "Method1" << std::endl;
    }
    void method2() {
        std::cout << "Method2" << std::endl;
    }
};

int main() {
    std::cout << "App Started" << std::endl;
    ConcreteClass fromAbsract;
    fromAbsract.method1();
    fromAbsract.mehtod2();
    ConcreteClass2 fromInterface;
    fromInterface.method1();
    fromInterface.method2();
    std::cout << "App Ended" << std::endl;
    return 0;
}