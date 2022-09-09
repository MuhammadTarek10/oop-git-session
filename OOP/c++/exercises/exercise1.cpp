/*
    1. Imagine a tollbooth at a bridge. Cars passing by the booth are expected
   to pay a 50 cent toll. Mostly they do, but sometimes a car goes by without
   paying. The tollbooth keeps track of the number of cars that have gone by,
   and of the total amount of money collected Model this tollbooth with a class
   called tollBooth. The two data items are a type unsigned int to hold the
   total number of cars, and a type double to hold the total amount of money
   collected. A constructor initializes both of these to 0. A member function
   called payingCar() increments the car total and adds 0.50 to the cash total.
    Another function, called nopayCar(), increments the car total but adds
   nothing to the cash total. Finally, a member function called display()
   displays the two totals. Make appropriate member functions const. Include a
   program to test this class. This program should allow the user to push one
   key to count a paying car, and another to count a nonpaying car. Pushing the
   Esc key should cause the program to print out the total cars and total cash
   and then exit
*/

#include <iostream>

class TollBooth {
 private:
  unsigned int cars;
  float money;

 public:
  TollBooth() {
    cars = 0;
    money = 0;
  };
  ~TollBooth(){};

  void payingCar() {
    ++cars;
    money += 0.5;
  };
  void nonPayingCar() { ++cars; };
  void display() {
    std::cout << "Cars: " << cars << " " << std::endl;
    std::cout << "Money: " << money << " " << std::endl;
  };
};


int main(){
    TollBooth booth;

    int input;

    while(true){
        std::cout << "Enter Option (1. Paying, 2. Non-Paying, 3. Exit)";
        std::cin >> input;

        if(input == 1) booth.payingCar();
        else if(input == 2) booth.nonPayingCar();
        else if(input == 3) break;
    }

    booth.display();

    return 0;
};