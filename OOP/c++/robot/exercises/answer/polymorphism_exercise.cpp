#include <iostream>
#include <string>
#include <vector>

class Robot {
   protected:
    std::string id;

   public:
    Robot(std::string id) : id(id) {}

    virtual void performTask() = 0;
    virtual void reportStatus() = 0;

    virtual ~Robot() {}
};

class DeliveryRobot : public Robot {
   public:
    DeliveryRobot(std::string id) : Robot(id) {}

    void performTask() override {
        std::cout << id << " is delivering a package.\n";
    }

    void reportStatus() override {
        std::cout << id << " status: cargo bay operational.\n";
    }
};

class CleaningRobot : public Robot {
   public:
    CleaningRobot(std::string id) : Robot(id) {}

    void performTask() override {
        std::cout << id << " is cleaning the warehouse floor.\n";
    }

    void reportStatus() override {
        std::cout << id << " status: bin at 40% capacity.\n";
    }
};

int main() {
    std::vector<Robot*> fleet;
    fleet.push_back(new DeliveryRobot("D-1"));
    fleet.push_back(new CleaningRobot("C-1"));

    for (Robot* robot : fleet) {
        robot->performTask();
        robot->reportStatus();
    }

    for (Robot* robot : fleet) {
        delete robot;
    }

    return 0;
}
