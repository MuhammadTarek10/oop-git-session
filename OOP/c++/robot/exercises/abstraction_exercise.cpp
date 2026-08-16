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

/*
    Exercise: Abstraction

    MaintenanceRobot inherits from Robot but does not yet implement
    performTask(), so it currently won't compile (it's still abstract).

    TODO: implement performTask() so it prints:
    "<id> is running a maintenance check."
*/
class MaintenanceRobot : public Robot {
   public:
    MaintenanceRobot(std::string id) : Robot(id) {}

    // TODO: implement performTask() here
};

int main() {
    MaintenanceRobot maintenance("M-1");
    maintenance.performTask();

    return 0;
}
