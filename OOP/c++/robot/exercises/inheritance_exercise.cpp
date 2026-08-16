#include <iostream>
#include <string>

class Robot {
   protected:
    std::string id;
    int batteryLevel;

   public:
    Robot(std::string id) : id(id), batteryLevel(100) {}

    void move() {
        batteryLevel -= 5;
        std::cout << id << " is moving. Battery: " << batteryLevel << "%\n";
    }
};

/*
    Exercise: Inheritance

    TODO:
    1. Make InspectionRobot inherit publicly from Robot.
    2. Add a private field `cameraCount` (int).
    3. Write a constructor that takes (id, cameraCount) and passes id up
       to the Robot constructor.
    4. Add a method `takePhoto()` that prints:
       "<id> takes a photo with <cameraCount> camera(s)."
*/
class InspectionRobot /* TODO: inherit from Robot */ {
   public:
    // TODO: constructor + cameraCount field + takePhoto()
};

int main() {
    InspectionRobot inspector("I-1", 2);

    inspector.move();       // inherited from Robot
    inspector.takePhoto();  // specific to InspectionRobot

    return 0;
}
