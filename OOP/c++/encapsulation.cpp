#include <string.h>

#include <iostream>

class Encapsulation {
   private:
    std::string name;
    int age;

   public:
    Encapsulation() {
        this->name = "";
        this->age = 0;
    }

    void setName(std::string name) {
        this->name = name;
    }
    void setAge(int age) {
        this->age = age;
    }

    std::string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    void print() {
        std::cout << "Name: " << name << " Age: " << age << std::endl;
    }
};

int main() {
    std::cout << "App Started" << std::endl;
    Encapsulation app;
    app.print();
    app.setName("John");
    app.setAge(30);
    app.print();
    // app.age = 5; // // error because age is private
    std::cout << "App Ended" << std::endl;
    return 0;
}