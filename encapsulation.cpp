#include <iostream>

class Encapsulation {
   private:
    int private_var;

   public:
    int public_var;
    void set_private_var(int value) {
        private_var = value;
    }
    int get_private_var() {
        return private_var;
    }
};

int main() {
    std::cout << "App Started" << std::endl;
    Encapsulation encapsulation;
    // encapsulation.private_var = 10;
    encapsulation.set_private_var(10);
    std::cout << "Private var: " << encapsulation.get_private_var() << std::endl;
    std::cout << "App Ended" << std::endl;
    return 0;
}