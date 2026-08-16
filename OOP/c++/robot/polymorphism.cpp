#include <iostream>
#include <string>
#include <vector>

class Robot {
   protected:
    std::string id;
    int batteryLevel;

   public:
    Robot(std::string id) : id(id), batteryLevel(100) {}

    virtual void performTask() = 0;

    virtual ~Robot() {}

    std::string getId() const {
        return id;
    }
};

class DeliveryRobot : public Robot {
   public:
    DeliveryRobot(std::string id) : Robot(id) {}

    void performTask() override {
        std::cout << id << " is delivering a package.\n";
    }
};

class CleaningRobot : public Robot {
   public:
    CleaningRobot(std::string id) : Robot(id) {}

    void performTask() override {
        std::cout << id << " is cleaning the warehouse floor.\n";
    }
};

int main() {
    // The fleet holds pointers to the ABSTRACT base type Robot.
    // Each call to performTask() runs the CORRECT version for the
    // actual (concrete) type of the object, decided at runtime.
    std::vector<Robot*> fleet;
    fleet.push_back(new DeliveryRobot("D-1"));
    fleet.push_back(new CleaningRobot("C-1"));
    fleet.push_back(new DeliveryRobot("D-2"));

    for (Robot* robot : fleet) {
        robot->performTask();  // same call, different behavior per type
    }

    for (Robot* robot : fleet) {
        delete robot;
    }

    return 0;
}
