#include <iostream>
#include <string>
#include <vector>

/*
    Exercise: Polymorphism

    TODO:
    1. Add a second pure virtual method to Robot: `reportStatus()`.
    2. Implement reportStatus() in both DeliveryRobot and CleaningRobot,
       each printing a different status message.
    3. Extend the fleet loop in main() to also call reportStatus() on
       every robot, right after performTask().
*/
class Robot {
   protected:
    std::string id;

   public:
    Robot(std::string id) : id(id) {}

    virtual void performTask() = 0;
    // TODO: declare virtual void reportStatus() = 0;

    virtual ~Robot() {}
};

class DeliveryRobot : public Robot {
   public:
    DeliveryRobot(std::string id) : Robot(id) {}

    void performTask() override {
        std::cout << id << " is delivering a package.\n";
    }

    // TODO: implement reportStatus()
};

class CleaningRobot : public Robot {
   public:
    CleaningRobot(std::string id) : Robot(id) {}

    void performTask() override {
        std::cout << id << " is cleaning the warehouse floor.\n";
    }

    // TODO: implement reportStatus()
};

int main() {
    std::vector<Robot*> fleet;
    fleet.push_back(new DeliveryRobot("D-1"));
    fleet.push_back(new CleaningRobot("C-1"));

    for (Robot* robot : fleet) {
        robot->performTask();
        // TODO: also call robot->reportStatus();
    }

    for (Robot* robot : fleet) {
        delete robot;
    }

    return 0;
}
