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

class InspectionRobot : public Robot {
   private:
    int cameraCount;

   public:
    InspectionRobot(std::string id, int cameraCount)
        : Robot(id), cameraCount(cameraCount) {}

    void takePhoto() {
        std::cout << id << " takes a photo with " << cameraCount << " camera(s).\n";
    }
};

int main() {
    InspectionRobot inspector("I-1", 2);

    inspector.move();
    inspector.takePhoto();

    return 0;
}
