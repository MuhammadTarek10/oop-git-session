#include <iostream>
#include <string>

class Robot {
   protected:
    std::string id;

   public:
    Robot(std::string id) : id(id) {}
    virtual void performTask() = 0;
    virtual ~Robot() {}
};

class MaintenanceRobot : public Robot {
   public:
    MaintenanceRobot(std::string id) : Robot(id) {}

    void performTask() override {
        std::cout << id << " is running a maintenance check.\n";
    }
};

int main() {
    MaintenanceRobot maintenance("M-1");
    maintenance.performTask();

    return 0;
}
